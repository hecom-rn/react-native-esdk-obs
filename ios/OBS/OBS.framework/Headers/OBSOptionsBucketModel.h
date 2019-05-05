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

#ifndef OBSOptionsBucketModel_h
#define OBSOptionsBucketModel_h

#import "OBSBaseNetworking.h"
#import "OBSClient.h"
#import "OBSServiceBaseModel.h"
#import "OBSServiceConstDefinition.h"


/**
 预请求桶
 */
@protocol OBSOptionsBucketProtocol <NSObject>
@end

#pragma mark - request

/**
 预请求桶创建request
 */
@interface OBSOptionsBucketRequest : OBSBaseRequest<OBSOptionsBucketProtocol>

/**
 桶名
 */
@property (nonatomic, strong, nonnull) NSString *bucketName;

/**
 跨域请求origin(通常为域名)
 */
@property (nonatomic, strong, nonnull) NSString *origin;

/**
 HTTP头域列表
 */
@property (nonatomic, strong, nonnull) NSArray<NSString*> *accessControlRequestHeadersList;

/**
 HTTP方法
 */
@property (nonatomic, strong, nonnull) NSString *accessControlRequestMethod;


/**
 初始化创建预请求桶request

 @param bucketName 桶名
 @param origin 域名
 @param method HTTP方法
 @return 创建预请求桶request
 */
-(instancetype)initWithBucketName:(NSString*) bucketName
                           origin:(NSString*) origin
       accessControlRequestMethod:(NSString*) method;
@end

#pragma mark - networking request
@interface OBSNetworkingOptionsBucketRequest : OBSServiceNetworkingCommandRequest
@end

    //response
#pragma mark - response

/**
 设置预请求桶response
 */
@interface OBSOptionsBucketResponse: OBSCORSResponse
@end

    //client method
#pragma mark - client method
@interface OBSClient(optionsBucket)

/**
 设置预请求桶

 @param request 设置预请求桶request
 @param completionHandler 设置预请求桶回调
 @return OBSBFTask
 */
- (OBSBFTask*)optionsBucket:(__kindof OBSBaseRequest<OBSOptionsBucketProtocol>*)request
              completionHandler:(void (^)(OBSOptionsBucketResponse  * response, NSError * error))completionHandler;
@end



#endif /* OBSOptionsBucketModel_h */
