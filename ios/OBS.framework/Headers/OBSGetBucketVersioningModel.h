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

#ifndef OBSGetBucketVersioningModel_h
#define OBSGetBucketVersioningModel_h
#import "OBSBaseModel.h"
#import "OBSBaseNetworking.h"
#import "OBSClient.h"
#import "OBSServiceBaseModel.h"
#import "OBSServiceCommonEntities.h"
#import "OBSServiceConstDefinition.h"


#pragma mark - request

@protocol OBSGetBucketVersioningProtocol
@required
@property (nonatomic, strong, nonnull) NSString *bucketName;
@end
// 获取桶多版本
@interface OBSGetBucketVersioningRequest: OBSBaseRequest<OBSGetBucketVersioningProtocol>

/**
 桶名
 */
@property (nonatomic, strong, nonnull) NSString *bucketName;

/**
 获取桶多版本request初始化

 @param bucketName 桶名
 @return request对象
 */
-(instancetype)initWithBucketName:(NSString*) bucketName;
@end

#pragma mark - networking request
@interface OBSGetBucketVersioningRequestNetworking : OBSServiceNetworkingCommandRequest
@end

    //response
#pragma mark - response

/**
 获取桶多版本response
 */
@interface OBSGetBucketVersioningResponse: OBSServiceResponse

/**
 桶多版本配置
 */
@property (nonatomic, strong, nonnull)  OBSBucketVersioningConfiguration *configuration;
@end


#pragma mark - client method
@interface OBSClient(getBucketVersioning)

/**
 获取桶多版本

 @param request 获取桶多版本request对象
 @param completionHandler 获取桶多版本回调
 @return task
 */
- (OBSBFTask*)getBucketVersioning:(__kindof OBSBaseRequest<OBSGetBucketVersioningProtocol>*)request
             completionHandler:(void (^)(OBSGetBucketVersioningResponse  * response, NSError * error))completionHandler;
@end

#endif /* OBSGetBucketVersioningModel_h */
