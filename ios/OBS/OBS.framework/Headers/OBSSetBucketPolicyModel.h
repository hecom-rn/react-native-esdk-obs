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

#ifndef OBSSetBucketPolicyModel_h
#define OBSSetBucketPolicyModel_h

#import "OBSBaseModel.h"
#import "OBSBaseNetworking.h"
#import "OBSClient.h"
#import "OBSServiceBaseModel.h"
#import "OBSServiceCommonEntities.h"
#import "OBSServiceConstDefinition.h"


#pragma mark - request

/**
 设置桶策略
 */
@protocol OBSSetBucketPolicyProtocol
@required

/**
 桶名
 */
@property (nonatomic, strong, nonnull) NSString *bucketName;
@end


/**
 使用字符串设置桶策略request
 */
@interface OBSSetBucketPolicyWithStringRequest: OBSBaseRequest<OBSSetBucketPolicyProtocol>

/**
 桶名
 */
@property (nonatomic, strong, nonnull) NSString *bucketName;

/**
 桶策略字符串
 */
@property (nonatomic, strong, nonnull) NSString *policyString;

/**
 初始化字符串设置桶策略request

 @param bucketName 桶名
 @param policyString 策略字符串
 @return 字符串设置桶策略request对象
 */
-(instancetype)initWithBucketName:(NSString*) bucketName policyString:(NSString*) policyString;
@end


/**
 设置桶策略request
 */
@interface OBSSetBucketPolicyRequest: OBSBaseRequest<OBSSetBucketPolicyProtocol>

/**
 桶名
 */
@property (nonatomic, strong, nonnull) NSString *bucketName;

/**
 桶策略版本
 */
@property (nonatomic, strong, nonnull) NSString* policyVersion;

/**
 策略声明数组
 */
@property (nonatomic, strong, nonnull) NSMutableArray<OBSPolicyStatement*> *statementList;

/**
 初始化设置桶策略request

 @param bucketName 桶名
 @return 设置桶策略request
 */
-(instancetype)initWithBucketName:(NSString*) bucketName;
@end


#pragma mark - networking request
@interface OBSSetBucketPolicyRequestNetworking : OBSServiceNetworkingCommandRequest
@end

@interface OBSSetBucketPolicyWithStringRequestNetworking : OBSServiceNetworkingCommandRequest
@end

    //response
#pragma mark - response

/**
 设置桶策略response
 */
@interface OBSSetBucketPolicyResponse: OBSServiceResponse
@end


#pragma mark - client method
@interface OBSClient(setBucketPolicy)

/**
 设置桶策略

 @param request 设置桶策略request对象
 @param completionHandler 设置桶策略回调
 @return OBSBFTask
 */
- (OBSBFTask*)setBucketPolicy:(__kindof OBSBaseRequest<OBSSetBucketPolicyProtocol>*)request
         completionHandler:(void (^)(OBSSetBucketPolicyResponse  * response, NSError * error))completionHandler;
@end
#endif /* OBSSetBucketPolicyModel_h */
