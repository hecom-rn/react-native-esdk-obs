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

#ifndef OBSGetBucketWebsiteModel_h
#define OBSGetBucketWebsiteModel_h
#import "OBSBaseModel.h"
#import "OBSBaseNetworking.h"
#import "OBSClient.h"
#import "OBSServiceBaseModel.h"
#import "OBSServiceCommonEntities.h"
#import "OBSServiceConstDefinition.h"


#pragma mark - request

/**
 获取网站托管配置
 */
@protocol OBSGetBucketWebsiteProtocol
@required

/**
 桶名
 */
@property (nonatomic, strong, nonnull) NSString *bucketName;
@end


/**
 获取桶静态网站托管配置
 */
@interface OBSGetBucketWebsiteRequest: OBSBaseRequest<OBSGetBucketWebsiteProtocol>

/**
 桶名
 */
@property (nonatomic, strong, nonnull) NSString *bucketName;

/**
 初始化获取桶静态网站托管配置request

 @param bucketName 桶名
 @return 获取桶静态网站托管配置
 */
-(instancetype)initWithBucketName:(NSString*) bucketName;
@end

#pragma mark - networking request
@interface OBSGetBucketWebsiteRequestNetworking : OBSServiceNetworkingCommandRequest
@end

    //response
#pragma mark - response

/**
 获取桶静态网站托管配置response
 */
@interface OBSGetBucketWebsiteResponse: OBSServiceResponse

/**
 静态网站托管配置
 */
@property (nonatomic, strong, nonnull) __kindof OBSAbstractWebsiteConf *configuration;
@end


#pragma mark - client method
@interface OBSClient(getBucketWebsite)

/**
 获取桶静态网站托管配置

 @param request 获取桶静态网站托管配置request
 @param completionHandler 获取桶静态网站托管配置回调
 @return OBSBFTask
 */
- (OBSBFTask*)getBucketWebsite:(__kindof OBSBaseRequest<OBSGetBucketWebsiteProtocol>*)request
            completionHandler:(void (^)(OBSGetBucketWebsiteResponse  * response, NSError * error))completionHandler;
@end

#endif /* OBSGetBucketWebsiteModel_h */
