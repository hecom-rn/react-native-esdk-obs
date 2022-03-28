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

#ifndef OBSDeleteBucketWebsiteModel_h
#define OBSDeleteBucketWebsiteModel_h

#import "OBSBaseModel.h"
#import "OBSBaseNetworking.h"
#import "OBSClient.h"
#import "OBSServiceBaseModel.h"
#import "OBSServiceCommonEntities.h"
#import "OBSServiceConstDefinition.h"


#pragma mark - request

/**
 删除网站托管配置
 */
@protocol OBSDeleteBucketWebsiteProtocol
@required

/**
 桶名
 */
@property (nonatomic, strong, nonnull) NSString *bucketName;
@end


/**
 删除网站托管配置request
 */
@interface OBSDeleteBucketWebsiteRequest: OBSBaseRequest<OBSDeleteBucketWebsiteProtocol>

/**
 桶名
 */
@property (nonatomic, strong, nonnull) NSString *bucketName;

/**
 初始化删除网站托管配置request

 @param bucketName 桶名
 @return 删除网站托管配置request
 */
-(instancetype)initWithBucketName:(NSString*) bucketName;
@end

#pragma mark - networking request
@interface OBSDeleteBucketWebsiteRequestNetworking : OBSServiceNetworkingCommandRequest
@end

    //response
#pragma mark - response

/**
 删除网站托管配置response
 */
@interface OBSDeleteBucketWebsiteResponse: OBSServiceResponse
@end


#pragma mark - client method
@interface OBSClient(deleteBucketWebsite)

/**
 删除托管配置

 @param request 删除托管配置request
 @param completionHandler 删除托管配置回调
 @return OBSBFTask
 */
- (OBSBFTask*)deleteBucketWebsite:(__kindof OBSBaseRequest<OBSDeleteBucketWebsiteProtocol>*)request
               completionHandler:(void (^)(OBSDeleteBucketWebsiteResponse  * response, NSError * error))completionHandler;
@end
#endif /* OBSDeleteBucketWebsiteModel_h */
