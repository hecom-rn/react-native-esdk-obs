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

#ifndef OBSSetBucketVersioningModel_h
#define OBSSetBucketVersioningModel_h
#import "OBSBaseModel.h"
#import "OBSBaseNetworking.h"
#import "OBSClient.h"
#import "OBSServiceBaseModel.h"
#import "OBSServiceCommonEntities.h"

#pragma mark - entities


#pragma mark - request

/**
 设置桶多版本
 */
@protocol OBSSetBucketVersioningProtocol
@required

/**
 桶名
 */
@property (nonatomic, strong, nonnull) NSString *bucketName;

/**
 桶多版本配置
 */
@property (nonatomic, strong, nonnull) OBSBucketVersioningConfiguration  *configuration;
@end

/**
 设置桶多版本 request
 */
@interface OBSSetBucketVersioningRequest: OBSBaseRequest<OBSSetBucketVersioningProtocol>

/**
 桶名
 */
@property (nonatomic, strong, nonnull) NSString *bucketName;

/**
 桶多版本配置
 */
@property (nonatomic, strong, nonnull) OBSBucketVersioningConfiguration  *configuration;

/**
 设置桶多版本request初始化

 @param bucketName 桶名
 @param configuration 桶多版本配置
 @return 桶多版本请求对象
 */
-(instancetype)initWithBucketName:(NSString*) bucketName configuration:(OBSBucketVersioningConfiguration *) configuration;
@end

#pragma mark - networking request
@interface OBSSetBucketVersioningRequestNetworking : OBSServiceNetworkingCommandRequest
@end

    //response
#pragma mark - response

/**
 设置桶多版本response
 */
@interface OBSSetBucketVersioningResponse: OBSServiceResponse
@end


#pragma mark - client method
@interface OBSClient(setBucketVersioning)

/**
 桶多版本设置

 @param request 桶多版本request对象
 @param completionHandler 桶多版本回调
 @return task对象
 */
- (OBSBFTask*)setBucketVersioning:(__kindof OBSBaseRequest<OBSSetBucketVersioningProtocol>*)request
         completionHandler:(void (^)(OBSSetBucketVersioningResponse  * response, NSError * error))completionHandler;
@end

#endif  /* OBSSetBucketVersioningModel_h */
