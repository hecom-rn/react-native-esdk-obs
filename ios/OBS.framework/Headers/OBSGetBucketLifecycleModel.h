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

#ifndef OBSGetBucketLifecycleModel_h
#define OBSGetBucketLifecycleModel_h

#import "OBSBaseModel.h"
#import "OBSBaseNetworking.h"
#import "OBSClient.h"
#import "OBSServiceBaseModel.h"
#import "OBSServiceCommonEntities.h"


#pragma mark - entity


#pragma mark - request

/**
 获取桶生命周期
 */
@protocol OBSGetBucketLifecycleProtocol
@required

/**
 桶名
 */
@property (nonatomic, strong, nonnull) NSString *bucketName;
@end


/**
 获取桶生命周期的request
 */
@interface OBSGetBucketLifecycleRequest: OBSBaseRequest<OBSGetBucketLifecycleProtocol>

/**
 桶名
 */
@property (nonatomic, strong, nonnull) NSString *bucketName;

/**
 初始化获取桶生命周期的request

 @param bucketName 桶名
 @return 获取桶生命周期request
 */
-(instancetype)initWithBucketName:(NSString*) bucketName;
@end

#pragma mark - networking request
@interface OBSGetBucketLifecycleRequestNetworking : OBSServiceNetworkingCommandRequest
@end

    //response
#pragma mark - response

/**
 获取桶生命周期response
 */
@interface OBSGetBucketLifecycleResponse: OBSServiceResponse

/**
 桶生命周期列表
 */
@property (nonatomic, strong, nonnull) NSMutableArray<OBSLifecycleRule*> *lifecycleRuleList;
@end


#pragma mark - client method
@interface OBSClient(getBucketLifecycle)

/**
 获取桶的生命周期

 @param request 获取桶生命周期request
 @param completionHandler 获取桶生命周期回调
 @return OBSBFTask
 */
- (OBSBFTask*)getBucketLifecycle:(__kindof OBSBaseRequest<OBSGetBucketLifecycleProtocol>*)request
             completionHandler:(void (^)(OBSGetBucketLifecycleResponse * response, NSError * error))completionHandler;
@end
#endif /* OBSGetBucketLifecycleModel_h */
