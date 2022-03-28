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

#ifndef OBSSetBucketWebsiteModel_h
#define OBSSetBucketWebsiteModel_h

#import "OBSBaseModel.h"
#import "OBSBaseNetworking.h"
#import "OBSClient.h"
#import "OBSServiceBaseModel.h"
#import "OBSServiceCommonEntities.h"
#import "OBSServiceConstDefinition.h"


#pragma mark - request

/**
 静态网站托管
 */
@protocol OBSSetBucketWebsiteProtocol
@required

/**
 桶名
 */
@property (nonatomic, strong, nonnull) NSString *bucketName;
@end


/**
 静态网站托管
 */
@interface OBSSetBucketWebsiteRequest: OBSBaseRequest<OBSSetBucketWebsiteProtocol>

/**
 桶名
 */
@property (nonatomic, strong, nonnull) NSString *bucketName;

/**
 桶托管配置
 */
@property (nonatomic, strong, nonnull) __kindof OBSAbstractWebsiteConf *configuration;

/**
 初始化设置静态网站托管request

 @param bucketName 桶名
 @param configuration 桶托管配置
 @return 设置桶的网站配置request
 */
-(instancetype)initWithBucketName:(NSString*) bucketName  configuration:(__kindof OBSAbstractWebsiteConf*) configuration;
@end


#pragma mark - networking request
@interface OBSSetBucketWebsiteRequestNetworking : OBSServiceNetworkingCommandRequest
@end


    //response
#pragma mark - response

/**
 设置桶托管配置response
 */
@interface OBSSetBucketWebsiteResponse: OBSServiceResponse
@end


#pragma mark - client method
@interface OBSClient(setBucketWebsite)

/**
 设置桶静态网站托管

 @param request 设置桶的网站配置request
 @param completionHandler 设置桶静态网站托管回调
 @return OBSBFTask
 */
- (OBSBFTask*)setBucketWebsite:(__kindof OBSBaseRequest<OBSSetBucketWebsiteProtocol>*)request
            completionHandler:(void (^)(OBSSetBucketWebsiteResponse  * response, NSError * error))completionHandler;
@end
#endif /* OBSSetBucketWebsiteModel_h */
