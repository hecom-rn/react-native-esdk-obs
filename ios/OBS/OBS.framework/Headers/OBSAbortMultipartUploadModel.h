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

#ifndef OBSAbortMultipartUploadModel_h
#define OBSAbortMultipartUploadModel_h

#import "OBSBaseNetworking.h"
#import "OBSClient.h"
#import "OBSServiceBaseModel.h"
#import "OBSServiceConstDefinition.h"

@class OBSAbstractEncryption;
    //request
#pragma mark - request

/**
 取消多段上传任务
 */
@protocol OBSAbortMultipartUploadProtocol<NSObject>
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
 多段上传任务ID
 */
@property (nonatomic, strong, nonnull) NSString *uploadID;
@end


/**
 取消多段上传任务request
 */
@interface OBSAbortMultipartUploadRequest : OBSBaseRequest<OBSAbortMultipartUploadProtocol>

/**
 桶名
 */
@property (nonatomic, strong, nonnull) NSString *bucketName;

/**
 对象key
 */
@property (nonatomic, strong, nonnull) NSString *objectKey;

/**
 多段上传任务ID
 */
@property (nonatomic, strong, nonnull) NSString *uploadID;

/**
 初始化取消多段上传任务request

 @param bucketName 桶名
 @param objectKey 对象KEY
 @param uploadID 多段上传任务ID
 @return 取消多段上传request
 */
-(instancetype)initWithBucketName:(NSString*) bucketName objectKey: (NSString*) objectKey uploadID:(NSString*) uploadID;
@end

#pragma mark - networking request
@interface OBSNetworkingAbortMultipartUploadRequest : OBSServiceNetworkingCommandRequest
@end

    //response
#pragma mark - response

/**
 取消多段上传response
 */
@interface OBSAbortMultipartUploadResponse: OBSServiceResponse
@end

    //client method
#pragma mark - client method
@interface OBSClient(abortMultipartUpload)

/**
 取消多段上传

 @param request 取消多段上传request
 @param completionHandler 取消多段上传回调
 @return OBSBFTask
 */
- (OBSBFTask*)abortMultipartUpload:(__kindof OBSBaseRequest<OBSAbortMultipartUploadProtocol>*)request
                    completionHandler:(void (^)(OBSAbortMultipartUploadResponse  * response, NSError * error))completionHandler;
@end
#endif /* OBSAbortMultipartUploadModel_h */
