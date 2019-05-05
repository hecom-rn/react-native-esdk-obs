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

#ifndef OBSSetBucketNotificationModel_h
#define OBSSetBucketNotificationModel_h

#import "OBSBaseModel.h"
#import "OBSBaseNetworking.h"
#import "OBSClient.h"
#import "OBSServiceBaseModel.h"
#import "OBSServiceCommonEntities.h"

#pragma mark - entities


#pragma mark - request

/**
 设置桶的消息通知
 */
@protocol OBSSetBucketNotificationProtocol
@required

/**
 桶名
 */
@property (nonatomic, strong, nonnull) NSString *bucketName;

/**
 配置列表
 */
@property (nonatomic, strong, nonnull) NSMutableArray<OBSNotificationTopicConfiguration*> *configurationList;
@end


/**
 设置桶的消息通知配置request
 */
@interface OBSSetBucketNotificationRequest: OBSBaseRequest<OBSSetBucketNotificationProtocol>

/**
 桶名
 */
@property (nonatomic, strong, nonnull) NSString *bucketName;

/**
 配置列表
 */
@property (nonatomic, strong, nonnull) NSMutableArray<OBSNotificationTopicConfiguration*> *configurationList;

/**
 初始化设置桶的消息通知配置request

 @param bucketName 桶名
 @return request对象
 */
-(instancetype)initWithBucketName:(NSString*) bucketName;
@end

#pragma mark - networking request
@interface OBSSetBucketNotificationRequestNetworking : OBSServiceNetworkingCommandRequest
@end

    //response
#pragma mark - response

/**
 设置桶的消息通知配置response
 */
@interface OBSSetBucketNotificationResponse: OBSServiceResponse
@end


#pragma mark - client method
@interface OBSClient(setBucketNotification)

/**
 设置桶的消息通知配置

 @param request 设置桶的消息通知配置request
 @param completionHandler 设置桶的消息通知回调
 @return OBSBFTask
 */
- (OBSBFTask*)setBucketNotification:(__kindof OBSBaseRequest<OBSSetBucketNotificationProtocol>*)request
                completionHandler:(void (^)(OBSSetBucketNotificationResponse  * response, NSError * error))completionHandler;
@end
#endif /* OBSSetBucketNotificationModel_h */
