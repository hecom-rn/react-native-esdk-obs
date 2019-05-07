#import "RNOBS+UPLOAD.h"

@import Photos;
@import MobileCoreServices;

@implementation RNOBS (UPLOAD)

/**
 * Asynchronous uploading
 */
RCT_REMAP_METHOD(upload,
                 asyncUploadWithBucketName:(NSString *)bucketName
                 objectKey:(NSString *)objectKey
                 filepath:(NSString *)filepath
                 options:(NSDictionary*)options
                 resolver:(RCTPromiseResolveBlock)resolve
                 rejecter:(RCTPromiseRejectBlock)reject) {
    [self beginUploadingWithFilepath:filepath resultBlock:^(NSData *data) {
        OBSPutObjectWithDataRequest *put = [[OBSPutObjectWithDataRequest alloc] initWithBucketName:bucketName objectKey:objectKey uploadData:data];
        put.objectACLPolicy = OBSACLPolicyPublicRead;
        // optional fields
        put.uploadProgressBlock = ^(int64_t bytesSent, int64_t totalBytesSent, int64_t totalBytesExpectedToSend) {
            NSLog(@"%lld, %lld, %lld", bytesSent, totalBytesSent, totalBytesExpectedToSend);
            // Only send events if anyone is listening
            if (self.hasListeners) {
                [self sendEventWithName:@"uploadProgress" body:@{
                                                                 @"currentSize": [NSString stringWithFormat:@"%lld",totalBytesSent],
                                                                 @"totalSize": [NSString stringWithFormat:@"%lld",totalBytesExpectedToSend]}];
            }
        };
        [self.client putObject:put completionHandler:^(OBSPutObjectResponse *response, NSError *error) {
            if (!error) {
                NSLog(@"upload object success!");
                resolve(@"success");
            } else {
                NSLog(@"upload object failed, error: %@" , error);
                reject(@"Error", @"Upload failed", error);
            }
        }];
    }];
}

/**
 * Begin a new uploading task
 * Currently, support AssetLibrary, PhotoKit, and pure File for uploading
 * Also, will convert the HEIC image to JPEG format
 * @param filepath passed from reacit-native side, it might be a path started with 'assets-library://', 'localIdentifier://', 'file:'
 * @param callback a block waiting to be called right after the binary data of asset is found
 */
- (void)beginUploadingWithFilepath:(NSString *)filepath resultBlock:(void (^) (NSData *))callback {
    // read asset data from filepath
    if ([filepath hasPrefix:@"assets-library://"]) {
        PHAsset *asset = [PHAsset fetchAssetsWithALAssetURLs:@[[NSURL URLWithString:filepath]] options:nil].firstObject;
        [self convertToNSDataFromAsset:asset withHandler:callback];
    } else if ([filepath hasPrefix:@"localIdentifier://"]) {
        NSString *localIdentifier = [filepath stringByReplacingOccurrencesOfString:@"localIdentifier://" withString:@""];
        PHAsset *asset = [PHAsset fetchAssetsWithLocalIdentifiers:@[localIdentifier] options:nil].firstObject;
        [self convertToNSDataFromAsset:asset withHandler:callback];
        
    } else {
        filepath = [filepath stringByReplacingOccurrencesOfString:@"file://" withString:@""];
        NSData *data = [NSData dataWithContentsOfFile:filepath];
        callback(data);
    }
}

/**
 * a helper method to do the file convertion*
 * @param asset PHAsset
 * @param handler a callback block
 */
- (void)convertToNSDataFromAsset:(PHAsset *)asset withHandler:(void (^) (NSData *))handler {
    PHImageManager *imageManager = [PHImageManager defaultManager];
    switch (asset.mediaType) {
        case PHAssetMediaTypeImage: {
            PHImageRequestOptions *options = [[PHImageRequestOptions alloc] init];
            options.networkAccessAllowed = YES;
            [imageManager requestImageDataForAsset:asset options:options resultHandler:^(NSData * _Nullable imageData, NSString * _Nullable dataUTI, UIImageOrientation orientation, NSDictionary * _Nullable info) {
                if ([dataUTI isEqualToString:(__bridge NSString *)kUTTypeJPEG]) {
                    handler(imageData);
                } else {
                    //if the image UTI is not JPEG, then do the convertion to make sure its compatibility
                    CGImageSourceRef source = CGImageSourceCreateWithData((__bridge CFDataRef)imageData, NULL);
                    NSDictionary *imageInfo = (__bridge NSDictionary*)CGImageSourceCopyPropertiesAtIndex(source, 0, NULL);
                    NSDictionary *metadata = [imageInfo copy];
                    
                    NSMutableData *imageDataJPEG = [NSMutableData data];
                    
                    CGImageDestinationRef destination = CGImageDestinationCreateWithData((__bridge CFMutableDataRef)imageDataJPEG, kUTTypeJPEG, 1, NULL);
                    CGImageDestinationAddImageFromSource(destination, source, 0, (__bridge CFDictionaryRef)metadata);
                    CGImageDestinationFinalize(destination);
                    
                    handler([NSData dataWithData:imageDataJPEG]);
                }
            }];
            break;
        }
        case PHAssetMediaTypeVideo:{
            PHVideoRequestOptions *options = [[PHVideoRequestOptions alloc] init];
            options.networkAccessAllowed = YES;
            [imageManager requestExportSessionForVideo:asset options:options exportPreset:AVAssetExportPresetHighestQuality resultHandler:^(AVAssetExportSession * _Nullable exportSession, NSDictionary * _Nullable info) {
                
                //generate a temporary directory for caching the video (MP4 Only)
                NSString *filePath = [[self getTemporaryDirectory] stringByAppendingString:[[NSUUID UUID] UUIDString]];
                filePath = [filePath stringByAppendingString:@".mp4"];
                
                exportSession.shouldOptimizeForNetworkUse = YES;
                exportSession.outputFileType = AVFileTypeMPEG4;
                exportSession.outputURL = [NSURL fileURLWithPath:filePath];
                
                [exportSession exportAsynchronouslyWithCompletionHandler:^{
                    handler([NSData dataWithContentsOfFile:filePath]);
                }];
            }];
            break;
        }
        default:
            break;
    }
}

@end
