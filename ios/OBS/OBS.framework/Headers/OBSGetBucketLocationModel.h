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

#ifndef OBSGetBucketLocationModel_h
#define OBSGetBucketLocationModel_h
#import "OBSBaseNetworking.h"
#import "OBSClient.h"
#import "OBSServiceBaseModel.h"
#import "OBSServiceConstDefinition.h"
#import "OBSServiceCommonEntities.h"

@class OBSEncryptionTypeCustomer;

/**
 获取桶区域
 */
@protocol OBSGetBucketLocationProtocol <NSObject>
@end

#pragma mark - request

/**
 获取桶区域
 */
@interface OBSGetBucketLocationRequest : OBSBaseRequest<OBSGetBucketLocationProtocol>

/**
 桶名
 */
@property (nonatomic, strong, nonnull) NSString *bucketName;

/**
 获取桶区域request初始化
 
 @param bucketName 桶名
 @return 获取桶位置request对象
 */
-(instancetype)initWithBucketName:(NSString*) bucketName;
@end

#pragma mark - networking request
@interface OBSNetworkingGetBucketLocationRequest : OBSServiceNetworkingCommandRequest
@end

    //response
#pragma mark - response

/**
 获取桶区域response
 */
@interface OBSGetBucketLocationResponse: OBSServiceResponse

/**
 桶配置
 */
@property (nonatomic, strong, nonnull) OBSBucketConfiguration *configuration;

/**
 桶区域
 */
@property (nonatomic, strong, nonnull) NSDictionary *location;
@end

    //client method
#pragma mark - client method
@interface OBSClient(getBucketLocation)

/**
 获取桶区域
 
 @param request 获取桶位置request对象
 @param completionHandler 获取桶区域回调
 @return OBSBFTask
 */
- (OBSBFTask*)getBucketLocation:(__kindof OBSBaseRequest<OBSGetBucketLocationProtocol>*)request
              completionHandler:(void (^)(OBSGetBucketLocationResponse  * response, NSError * error))completionHandler;
@end

#endif /* OBSGetBucketLocationModel_h */
