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

#ifndef OBSGetBucketPolicyModel_h
#define OBSGetBucketPolicyModel_h


#import "OBSBaseModel.h"
#import "OBSBaseNetworking.h"
#import "OBSClient.h"
#import "OBSServiceBaseModel.h"
#import "OBSServiceCommonEntities.h"
#import "OBSServiceConstDefinition.h"


#pragma mark - request

/**
 获取桶策略
 */
@protocol OBSGetBucketPolicyProtocol
@required

/**
 桶名
 */
@property (nonatomic, strong, nonnull) NSString *bucketName;
@end


/**
 获取桶策略
 */
@interface OBSGetBucketPolicyRequest: OBSBaseRequest<OBSGetBucketPolicyProtocol>

/**
 桶名
 */
@property (nonatomic, strong, nonnull) NSString *bucketName;

/**
 初始化获取桶策略request

 @param bucketName 桶名
 @return 获取桶策略request对象
 */
-(instancetype)initWithBucketName:(NSString*) bucketName;
@end

#pragma mark - networking request
@interface OBSGetBucketPolicyRequestNetworking : OBSServiceNetworkingCommandRequest
@end

    //response
#pragma mark - response

/**
 获取桶策略response
 */
@interface OBSGetBucketPolicyResponse: OBSServiceResponse

/**
 桶策略列表
 */
@property (nonatomic, strong, nonnull) NSArray<OBSPolicyStatement*> *policyStatementList;
@end


#pragma mark - client method
@interface OBSClient(getBucketPolicy)

/**
 获取桶策略

 @param request 获取桶策略request
 @param completionHandler 获取桶策略回调
 @return OBSBFTask
 */
- (OBSBFTask*)getBucketPolicy:(__kindof OBSBaseRequest<OBSGetBucketPolicyProtocol>*)request
            completionHandler:(void (^)(OBSGetBucketPolicyResponse  * response, NSError * error))completionHandler;
@end

#endif /* OBSGetBucketPolicyModel_h */
