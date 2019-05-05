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

#ifndef OBSSetBucketLifecycleModel_h
#define OBSSetBucketLifecycleModel_h

#import "OBSBaseModel.h"
#import "OBSBaseNetworking.h"
#import "OBSClient.h"
#import "OBSServiceBaseModel.h"
#import "OBSServiceCommonEntities.h"
#import "OBSServiceConstDefinition.h"


#pragma mark - request

/**
 设置桶生命周期
 */
@protocol OBSSetBucketLifecycleProtocol
@required

/**
 桶名
 */
@property (nonatomic, strong, nonnull) NSString *bucketName;
@end


/**
 设置桶生命周期request
 */
@interface OBSSetBucketLifecycleRequest: OBSBaseRequest<OBSSetBucketLifecycleProtocol>

/**
 桶名
 */
@property (nonatomic, strong, nonnull) NSString *bucketName;

/**
 生命周期配置
 */
@property (nonatomic, strong, nonnull) NSMutableArray<OBSLifecycleRule*> *lifecycleRuleList;

/**
 初始化设置桶生命周期request

 @param bucketName 桶名
 @return 设置桶生命周期request
 */
-(instancetype)initWithBucketName:(NSString*) bucketName ;
@end

#pragma mark - networking request
@interface OBSSetBucketLifecycleRequestNetworking : OBSServiceNetworkingCommandRequest
@end

    //response
#pragma mark - response

/**
 设置桶生命周期response
 */
@interface OBSSetBucketLifecycleResponse: OBSServiceResponse
@end


#pragma mark - client method
@interface OBSClient(setBucketLifecycle)

/**
 设置桶的生命周期

 @param request 设置桶生命期request
 @param completionHandler 设置桶生命周期回调
 @return OBSBFTask
 */
- (OBSBFTask*)setBucketLifecycle:(__kindof OBSBaseRequest<OBSSetBucketLifecycleProtocol>*)request
         completionHandler:(void (^)(OBSSetBucketLifecycleResponse  * response, NSError * error))completionHandler;
@end

#endif /* OBSSetBucketLifecycleModel_h */
