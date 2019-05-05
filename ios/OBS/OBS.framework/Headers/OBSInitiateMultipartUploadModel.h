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

#ifndef OBSInitiateMultipartUploadModel_h
#define OBSInitiateMultipartUploadModel_h

#import "OBSBaseNetworking.h"
#import "OBSClient.h"
#import "OBSServiceBaseModel.h"
#import "OBSServiceConstDefinition.h"

@class OBSAbstractEncryption;
    //request
#pragma mark - request

/**
 初始化多段上传任务
 */
@protocol OBSInitiateMultipartUploadProtocol<NSObject>
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
 对象访问策略
 */
@property (nonatomic, assign) OBSACLPolicy objectACLPolicy;

/**
 存储类型
 */
@property (nonatomic, assign) OBSStorageClass storageClass;

/**
 元数据
 */
@property (nonatomic, strong, nullable) NSDictionary *metaDataDict;

/**
 对象重定向
 */
@property (nonatomic, strong, nonnull) NSString *websiteRedirectLocation;

/**
 加密方式
 */
@property (nonatomic, strong, nonnull) __kindof OBSAbstractEncryption *encryption;
@end



/**
 初始化多段上传任务request
 */
@interface OBSInitiateMultipartUploadRequest : OBSBaseRequest<OBSInitiateMultipartUploadProtocol>

/**
 桶名
 */
@property (nonatomic, strong, nonnull) NSString *bucketName;

/**
 对象KEY
 */
@property (nonatomic, strong, nonnull) NSString *objectKey;

/**
 对象ACL
 */
@property (nonatomic, assign) OBSACLPolicy objectACLPolicy;

/**
 存储模式
 */
@property (nonatomic, assign) OBSStorageClass storageClass;

/**
 元数据
 */
@property (nonatomic, strong, nullable) NSDictionary *metaDataDict;

/**
 重定向网址
 */
@property (nonatomic, strong, nonnull) NSString *websiteRedirectLocation;

/**
 加密方式
 */
@property (nonatomic, strong, nullable) __kindof OBSAbstractEncryption *encryption;

/**
 初始化多段上传任务request

 @param bucketName 桶名
 @param objectKey 对象KEY
 @return 初始化多段上传任务request
 */
-(instancetype)initWithBucketName:(NSString*) bucketName objectKey: (NSString*) objectKey;
@end

#pragma mark - networking request
@interface OBSNetworkingInitiateMultipartUploadRequest : OBSServiceNetworkingCommandRequest
@end

    //response
#pragma mark - response

/**
 初始化多段上传任务response
 */
@interface OBSInitiateMultipartUploadResponse: OBSServiceResponse

/**
 桶名
 */
@property (nonatomic, strong, nonnull) NSString *bucketName;

/**
 对象名
 */
@property (nonatomic, strong, nonnull) NSString *objectKey;

/**
 多段上传ID
 */
@property (nonatomic, strong, nonnull) NSString *uploadID;

/**
 存储类型
 */
@property (nonatomic, assign) OBSStorageClass storageClass;

/**
 加密方式
 */
@property (nonatomic, strong, nonnull) __kindof OBSAbstractEncryption *encryption;
@end

    //client method
#pragma mark - client method
@interface OBSClient(initiateMultipartUpload)

/**
 初始化多段上传任务

 @param request 初始化多段上传任务request
 @param completionHandler 初始化多段上传任务回调
 @return OBSBFTask
 */
- (OBSBFTask*)initiateMultipartUpload:(__kindof OBSBaseRequest<OBSInitiateMultipartUploadProtocol>*)request
      completionHandler:(void (^)(OBSInitiateMultipartUploadResponse  * response, NSError * error))completionHandler;
@end
#endif /* OBSInitiateMultipartUploadModel_h */
