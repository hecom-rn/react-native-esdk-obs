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

#ifndef OBSSetBucketStoragePolicyModel_h
#define OBSSetBucketStoragePolicyModel_h

#import "OBSBaseModel.h"
#import "OBSBaseNetworking.h"
#import "OBSClient.h"
#import "OBSServiceBaseModel.h"
#import "OBSServiceCommonEntities.h"


#pragma mark - request entity

#pragma mark - request

/**
 设置桶存储策略
 */
@protocol OBSSetBucketStoragePolicyProtocol
@required

/**
 桶名
 */
@property (nonatomic, strong, nonnull) NSString *bucketName;

/**
 存储策略
 */
@property (nonatomic, strong, nonnull) OBSStoragePolicy* storagePolicy;
@end


/**
 设置桶存储策略
 */
@interface OBSSetBucketStoragePolicyRequest: OBSBaseRequest<OBSSetBucketStoragePolicyProtocol>

/**
 桶名
 */
@property (nonatomic, strong, nonnull) NSString *bucketName;

/**
 存储策略
 */
@property (nonatomic, strong, nonnull) OBSStoragePolicy* storagePolicy;

/**
 存储类型
 */
@property (nonatomic, assign) OBSStorageClass storageClass;




/**
 设置桶存储策略request初始化

 @param bucketName 桶名
 @param storagePolicy 存储策略
 @return 桶存储策略对象
 */
-(instancetype)initWithBucketName:(NSString*) bucketName storagePolicy:(OBSStoragePolicy*) storagePolicy;
@end

#pragma mark - networking request
@interface OBSSetBucketStoragePolicyRequestNetworking : OBSServiceNetworkingCommandRequest
@end

    //response
#pragma mark - response

/**
 设置桶存储策略response
 */
@interface OBSSetBucketStoragePolicyResponse: OBSServiceResponse
@end


#pragma mark - client method
@interface OBSClient(setBucketStoragePolicy)

/**
 设置桶存储策略

 @param request 桶存储策略request对象
 @param completionHandler 设置桶存储策略回调
 @return task
 */
- (OBSBFTask*)setBucketStoragePolicy:(__kindof OBSBaseRequest<OBSSetBucketStoragePolicyProtocol>*)request
          completionHandler:(void (^)(OBSSetBucketStoragePolicyResponse * response, NSError * error))completionHandler;
@end
#endif /* OBSSetBucketStoragePolicyModel_h */
