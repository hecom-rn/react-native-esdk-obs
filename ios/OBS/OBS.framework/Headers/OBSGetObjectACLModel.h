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

#ifndef OBSGetObjectACLModel_h
#define OBSGetObjectACLModel_h

#define OBSGetObjectACLModel_h
#import "OBSBaseModel.h"
#import "OBSBaseNetworking.h"
#import "OBSClient.h"
#import "OBSServiceBaseModel.h"
#import "OBSServiceCommonEntities.h"


#pragma mark - request

/**
 获取对象访问策略
 */
@protocol OBSGetObjectACLProtocol
@required

/**
 桶名
 */
@property (nonatomic, strong, nonnull) NSString *bucketName;

/**
 对象名
 */
@property (nonatomic, strong, nonnull) NSString *objectKey;

/**
 多版本ID
 */
@property (nonatomic, strong, nonnull) NSString *versionID;
@end


/**
 获取对象访问策略request
 */
@interface OBSGetObjectACLRequest: OBSBaseRequest<OBSGetObjectACLProtocol>

/**
 桶名
 */
@property (nonatomic, strong, nonnull) NSString *bucketName;

/**
 对象key
 */
@property (nonatomic, strong, nonnull) NSString *objectKey;

/**
 多版本ID
 */
@property (nonatomic, strong, nonnull) NSString *versionID;

/**
 初始化获取对象访问策略request

 @param bucketName 桶名
 @param objectKey 对象key
 @return 获取对象访问策略request
 */
-(instancetype)initWithBucketName:(NSString*) bucketName objectKey:(NSString*) objectKey ;
@end

#pragma mark - networking request
@interface OBSGetObjectACLRequestNetworking : OBSServiceNetworkingCommandRequest
@end

    //response
#pragma mark - response

/**
 获取对象访问策略response
 */
@interface OBSGetObjectACLResponse: OBSServiceResponse

/**
 多版本ID
 */
@property (nonatomic, strong, nonnull) NSString *versionID;

/**
 对象访问策略
 */
@property (nonatomic, strong, nonnull) OBSAccessControlPolicy *accessControlPolicy;
@end


#pragma mark - client method
@interface OBSClient(getObjectACL)

/**
 获取对象访问策略

 @param request 获取对象访问策略 request
 @param completionHandler 获取对象访问策略回调
 @return OBSBFTask
 */
- (OBSBFTask*)getObjectACL:(__kindof OBSBaseRequest<OBSGetObjectACLProtocol>*)request
         completionHandler:(void (^)(OBSGetObjectACLResponse  * response, NSError * error))completionHandler;
@end
#endif /* OBSGetObjectACLModel_h */
