// Copyright 2019 Huawei Technologies Co.,Ltd.
// Licensed under the Apache License, Version 2.0 (the "License"); you may not use
// this file except in compliance with the License.  You may obtain a copy of the
// License at
//
// http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software distributed
// under the License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
// CONDITIONS OF ANY KIND, either express or implied.  See the License for the
// specific language governing permissions and limitations under the License.

#ifndef OBSUploadPartModel_h
#define OBSUploadPartModel_h
#import "OBSBaseNetworking.h"
#import "OBSClient.h"
#import "OBSServiceBaseModel.h"
#import "OBSServiceConstDefinition.h"

@class OBSAbstractEncryption;
    //request
#pragma mark - request

/**
 多段数据上传
 */
@protocol OBSUploadPartProtocol<NSObject>
@required

/**
 桶名
 */
@property (nonatomic, strong, nonnull) NSString *bucketName;

/**
 对象名
 */
@property (nonatomic, strong, nonnull) NSString *objectKey;

/**
 分段号
 */
@property (nonatomic, strong, nonnull) NSNumber *partNumber; // 1 to 10000

/**
 多段上传任务ID
 */
@property (nonatomic, strong, nonnull) NSString *uploadID;

/**
 加密方式
 */
@property (nonatomic, strong, nonnull) __kindof OBSAbstractEncryption *encryption;

/**
 上传进度
 */
@property (nonatomic, copy, nonnull) OBSNetworkingUploadProgressBlock uploadProgressBlock;
@end


/**
 多段上传父类
 */
@interface OBSAbstractUploadPartRequest : OBSBaseRequest<OBSUploadPartProtocol>

/**
 桶名
 */
@property (nonatomic, strong, nonnull) NSString *bucketName;

/**
 对象名
 */
@property (nonatomic, strong, nonnull) NSString *objectKey;

/**
 分段号
 */
@property (nonatomic, strong, nonnull) NSNumber *partNumber; // 1 to 10000

/**
 多段上传任务ID
 */
@property (nonatomic, strong, nonnull) NSString *uploadID;

/**
 加密方式
 */
@property (nonatomic, strong, nonnull) __kindof OBSAbstractEncryption *encryption;

/**
 上传进度
 */
@property (nonatomic, copy, nonnull) OBSNetworkingUploadProgressBlock uploadProgressBlock;

/**
 Content-MD5
 */
@property (nonatomic, strong, nonnull) NSString *contentMD5;
@end


/**
 多段数据上传request
 */
@interface OBSUploadPartWithDataRequest: OBSAbstractUploadPartRequest

/**
 上传的数据
 */
@property (nonatomic, strong, nonnull) NSData *uploadData;

- (void) freeUploadData;
/**
 初始化多段数据上传request

 @param bucketName 桶名
 @param objectkey 对象KEY
 @param partNumber 上传段的段号
 @param uploadID 多段上传任务ID
 @param data 上传的数据
 @return 多段数据上传request
 */
-(instancetype)initWithBucketName:(NSString*) bucketName
                        objectkey:(NSString*) objectkey
                       partNumber:(NSNumber*) partNumber
                         uploadID:(NSString*) uploadID
                       uploadData:(NSData*) data;

/**
 初始化多段数据上传request
 
 @param bucketName 桶名
 @param objectkey 对象KEY
 @param partNumber 上传段的段号
 @param uploadID 多段上传任务ID
 @param data 上传的数据URL
 @return 多段数据上传request
 */
-(instancetype)initWithBucketName:(NSString*) bucketName
                        objectkey:(NSString*) objectkey
                       partNumber:(NSNumber*) partNumber
                         uploadID:(NSString*) uploadID
                    uploadDataURL:(NSURL*) dataURL;
@end


/**
 多段文件上传request
 */
@interface OBSUploadPartWithFileRequest: OBSAbstractUploadPartRequest
/**
 上传数据
 */
@property (nonatomic, weak) __weak NSData *uploadAllData; 
@property (nonatomic, weak) __weak NSFileHandle *fileHandle;

/**
 文件路径
 */
@property (nonatomic, strong, nonnull) NSString *uploadFilePath;

/**
 开始的位置
 */
@property (nonatomic, strong, nonnull) NSNumber *bytesStart;

/**
 数据大小
 */
@property (nonatomic, strong, nonnull) NSNumber *bytesLength;

/**
 是否后台上传
 */
@property (nonatomic, assign) BOOL background;

@property (nonatomic, strong) OBSUploadPartWithDataRequest * dataRequest;


@property (nonatomic, strong) OBSBaseNetworkingRequest * dataRequest1;


/**
 初始化多段文件上传request

 @param bucketName 桶名
 @param objectkey 对象KEY
 @param partNumber 上传段的段号
 @param uploadID 多段上传任务ID
 @param uploadFilePath 文件路径
 @return 多段文件上传request
 */
-(instancetype)initWithBucketName:(NSString*) bucketName
                        objectkey:(NSString*) objectkey
                       partNumber:(NSNumber*) partNumber
                         uploadID:(NSString*) uploadID
                   uploadFilePath:(NSString*) uploadFilePath;

/**
 初始化多段文件上传request

 @param bucketName 桶名
 @param objectkey 对象KEY
 @param partNumber 上传段的段号
 @param uploadID 多段上传任务ID
 @param uploadFilePath 文件路径
 @param bytestStart 开始位置
 @param bytestLength 文件大小
 @return 多段文件上传request
 */
-(instancetype)initWithBucketName:(NSString*) bucketName
                        objectkey:(NSString*) objectkey
                       partNumber:(NSNumber*) partNumber
                         uploadID:(NSString*) uploadID
                   uploadFilePath:(NSString*) uploadFilePath
                       bytesStart:(NSNumber*) bytestStart // long
                      bytesLength:(NSNumber*) bytestLength; //long
@end

#pragma mark - networking request
@interface OBSNetworkingUploadPartWithDataRequest : OBSServiceNetworkingUploadDataRequest
@end

@interface OBSNetworkingUploadPartWithFileRequest : OBSServiceNetworkingUploadFileRequest
@end

    //response
#pragma mark - response

/**
 多段上传response
 */
@interface OBSUploadPartResponse: OBSServiceResponse

/**
 加密方式
 */
@property (nonatomic, strong, nonnull) __kindof OBSAbstractEncryption *encryption;

/**
 上传段的etag
 */
@property (nonatomic, strong, nonnull) NSString *etag;
@end

    //client method
#pragma mark - client method
@interface OBSClient(uploadPart)

/**
 多段上传

 @param request 多段上传request
 @param completionHandler 多段上传回调
 @return OBSBFTask
 */
- (OBSBFTask*)uploadPart:(__kindof OBSBaseRequest<OBSUploadPartProtocol>*)request
      completionHandler:(void (^)(OBSUploadPartResponse  * response, NSError * error))completionHandler;
@end

#endif /* OBSUploadPartModel_h */
