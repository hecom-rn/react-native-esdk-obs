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

#ifndef OBSGetBucketStoragePolicyModel_h
#define OBSGetBucketStoragePolicyModel_h

#import "OBSBaseModel.h"
#import "OBSBaseNetworking.h"
#import "OBSClient.h"
#import "OBSServiceBaseModel.h"
#import "OBSServiceCommonEntities.h"


#pragma mark - request entity

#pragma mark - request

/**
 获取桶存储策略
 */
@protocol OBSGetBucketStoragePolicyProtocol
@required

/**
 桶名
 */
@property (nonatomic, strong, nonnull) NSString *bucketName;
@end


/**
 获取桶存储策略
 */
@interface OBSGetBucketStoragePolicyRequest: OBSBaseRequest<OBSGetBucketStoragePolicyProtocol>

/**
 桶名
 */
@property (nonatomic, strong, nonnull) NSString *bucketName;

/**
 获取桶存储策略request初始化

 @param bucketName 桶名
 @return 获取桶存储策略request对象
 */
-(instancetype)initWithBucketName:(NSString*) bucketName;
@end

#pragma mark - networking request
@interface OBSGetBucketStoragePolicyRequestNetworking : OBSServiceNetworkingCommandRequest
@end

    //response
#pragma mark - response

/**
 获取桶存储策略response
 */
@interface OBSGetBucketStoragePolicyResponse: OBSServiceResponse

/**
 桶存储策略
 */
@property (nonatomic, strong, nonnull) OBSStoragePolicy* storagePolicy;
@property (nonatomic, strong, nonnull) NSDictionary* storageClass;

@end


#pragma mark - client method
@interface OBSClient(getBucketStoragePolicy)

/**
 获取桶存储策略

 @param request 获取桶存储策略request对象
 @param completionHandler 获取桶存储策略回调
 @return OBSBFTask
 */
- (OBSBFTask*)getBucketStoragePolicy:(__kindof OBSBaseRequest<OBSGetBucketStoragePolicyProtocol>*)request
                   completionHandler:(void (^)(OBSGetBucketStoragePolicyResponse * response, NSError * error))completionHandler;
@end
#endif /* OBSGetBucketStoragePolicyModel_h */
