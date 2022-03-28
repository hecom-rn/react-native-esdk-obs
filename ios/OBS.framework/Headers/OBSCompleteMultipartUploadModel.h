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

#ifndef OBSCompleteMultipartUploadModel_h
#define OBSCompleteMultipartUploadModel_h
#import "OBSBaseNetworking.h"
#import "OBSClient.h"
#import "OBSServiceBaseModel.h"
#import "OBSServiceConstDefinition.h"
#import "OBSServiceCommonEntities.h"

@class OBSAbstractEncryption;
    //request


#pragma mark - request

/**
 合并段
 */
@protocol OBSCompleteMultipartUploadProtocol<NSObject>
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

/**
 多段任务列表
 */
@property (nonatomic, strong, nonnull) NSMutableArray<OBSPart*> *partsList;
@end


/**
 合并段request
 */
@interface OBSCompleteMultipartUploadRequest : OBSBaseRequest<OBSCompleteMultipartUploadProtocol>

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

/**
 多段上传对象列表
 */
@property (nonatomic, strong, nonnull) NSMutableArray<OBSPart*> *partsList;

/**
 初始化合并段request

 @param bucketName 桶名
 @param objectKey 对象名
 @param uploadID 多段上传任务ID
 @return 合并段request
 */
-(instancetype)initWithBucketName:(NSString*) bucketName objectKey: (NSString*) objectKey uploadID:(NSString*) uploadID;
@end

#pragma mark - networking request
@interface OBSNetworkingCompleteMultipartUploadRequest : OBSServiceNetworkingCommandRequest
@end

    //response
#pragma mark - response

/**
 合并段response
 */
@interface OBSCompleteMultipartUploadResponse: OBSServiceResponse

/**
 桶名
 */
@property (nonatomic, strong, nonnull) NSString *bucketName;

/**
 对象名
 */
@property (nonatomic, strong, nonnull) NSString *objectKey;

/**
 区域位置
 */
@property (nonatomic, strong, nonnull) NSString *location;

/**
 对象etag
 */
@property (nonatomic, strong, nonnull) NSString *etag;

/**
 多版本ID
 */
@property (nonatomic, strong, nonnull) NSString *versionID;

/**
 加密方式
 */
@property (nonatomic, strong, nonnull) __kindof OBSAbstractEncryption *encryption;
@end

    //client method
#pragma mark - client method
@interface OBSClient(completeMultipartUpload)

/**
 合并段

 @param request 合并段request
 @param completionHandler 合并段回调
 @return OBSBFTask
 */
- (OBSBFTask*)completeMultipartUpload:(__kindof OBSBaseRequest<OBSCompleteMultipartUploadProtocol>*)request
                    completionHandler:(void (^)(OBSCompleteMultipartUploadResponse  * response, NSError * error))completionHandler;
@end

#endif /* OBSCompleteMultipartUploadModel_h */
