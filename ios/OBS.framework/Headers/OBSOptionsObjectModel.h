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

#ifndef OBSOptionsObjectModel_h
#define OBSOptionsObjectModel_h

#import "OBSBaseNetworking.h"
#import "OBSClient.h"
#import "OBSServiceBaseModel.h"
#import "OBSServiceConstDefinition.h"

/**
 预请求对象
 */
@protocol OBSOptionsObjectProtocol <NSObject>
@end

#pragma mark - request

/**
 预请求对象request
 */
@interface OBSOptionsObjectRequest : OBSBaseRequest<OBSOptionsObjectProtocol>

/**
 桶名
 */
@property (nonatomic, strong, nonnull) NSString *bucketName;

/**
 对象KEY
 */
@property (nonatomic, strong, nonnull) NSString *objectKey;

/**
 跨域请求域名
 */
@property (nonatomic, strong, nonnull) NSString *origin;

/**
 实际请求可以带的HTTP头域
 */
@property (nonatomic, strong, nonnull) NSArray<NSString*> *accessControlRequestHeadersList;

/**
 实际请求可以带的HTTP方法
 */
@property (nonatomic, strong, nonnull) NSString *accessControlRequestMethod;


/**
 初始化预请求对象request

 @param bucketName 桶名
 @param key 对象KEY
 @param origin 跨域请求域名
 @param method 可以带的方法
 @return 预请求对象request
 */
-(instancetype)initWithBucketName:(NSString*) bucketName
                        objectKey:(NSString*) key
                           origin:(NSString*) origin
       accessControlRequestMethod:(NSString*) method;
@end

#pragma mark - networking request
@interface OBSNetworkingOptionsObjectRequest : OBSServiceNetworkingCommandRequest
@end

    //response
#pragma mark - response

/**
 预请求对象response
 */
@interface OBSOptionsObjectResponse: OBSCORSResponse
@end

    //client method
#pragma mark - client method

@interface OBSClient(optionsObject)

/**
 预请求对象

 @param request 预请求对象request
 @param completionHandler 预请求对象回调
 @return OBSBFTask
 */
- (OBSBFTask*)optionsObject:(__kindof OBSBaseRequest<OBSOptionsObjectProtocol>*)request
          completionHandler:(void (^)(OBSOptionsObjectResponse  * response, NSError * error))completionHandler;
@end


#endif /* OBSOptionsObjectModel_h */
