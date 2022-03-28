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

#ifndef OBSGetBucketNotificationModel_h
#define OBSGetBucketNotificationModel_h

#import "OBSBaseModel.h"
#import "OBSBaseNetworking.h"
#import "OBSClient.h"
#import "OBSServiceBaseModel.h"
#import "OBSServiceCommonEntities.h"
#import "OBSServiceConstDefinition.h"


#pragma mark - request

/**
 获取桶的消息通知配置
 */
@protocol OBSGetBucketNotificationProtocol
@required

/**
 桶名
 */
@property (nonatomic, strong, nonnull) NSString *bucketName;
@end


/**
 获取桶的消息通知配置request
 */
@interface OBSGetBucketNotificationRequest: OBSBaseRequest<OBSGetBucketNotificationProtocol>

/**
 桶名
 */
@property (nonatomic, strong, nonnull) NSString *bucketName;

/**
 初始化获取桶的消息通知配置request

 @param bucketName 桶名
 @return 获取桶消息通知配置request
 */
-(instancetype)initWithBucketName:(NSString*) bucketName;
@end

#pragma mark - networking request
@interface OBSGetBucketNotificationRequestNetworking : OBSServiceNetworkingCommandRequest
@end

    //response
#pragma mark - response

/**
 获取桶的消息通知配置response
 */
@interface OBSGetBucketNotificationResponse: OBSServiceResponse

/**
 桶的消息通知配置数组
 */
@property (nonatomic, strong, nonnull)  NSMutableArray<OBSNotificationTopicConfiguration*> *configurationList;
@end


#pragma mark - client method
@interface OBSClient(getBucketNotification)

/**
 获取桶的消息通知配置

 @param request 获取桶的消息通知配置request
 @param completionHandler 获取桶的消息通知配置回调
 @return OBSBFTask
 */
- (OBSBFTask*)getBucketNotification:(__kindof OBSBaseRequest<OBSGetBucketNotificationProtocol>*)request
                completionHandler:(void (^)(OBSGetBucketNotificationResponse  * response, NSError * error))completionHandler;
@end
#endif /* OBSGetBucketNotificationModel_h */
