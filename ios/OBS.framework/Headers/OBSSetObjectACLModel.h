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

#ifndef OBSSetObjectACLModel_h
#define OBSSetObjectACLModel_h
#import "OBSBaseModel.h"
#import "OBSBaseNetworking.h"
#import "OBSClient.h"
#import "OBSServiceBaseModel.h"
#import "OBSServiceCommonEntities.h"


#pragma mark - request

/**
 设置对象访问策略
 */
@protocol OBSSetObjectACLProtocol
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

/**
 访问策略
 */
//@property (nonatomic, strong, nonnull) OBSAccessControlPolicy *accessControlPolicy;
@end


/**
 设置对象访问策略request
 */
@interface OBSSetObjectACLRequest: OBSBaseRequest<OBSSetObjectACLProtocol>

/**
 桶名
 */
@property (nonatomic, strong, nonnull) NSString *bucketName;

/**
 对象key
 */
@property (nonatomic, strong, nonnull) NSString *objectKey;

/**
 对象多版本ID
 */
@property (nonatomic, strong, nonnull) NSString *versionID;

/**
 访问权限控制
 */
@property (nonatomic, strong, nonnull) OBSAccessControlPolicy *accessControlPolicy;

/**
 初始化设置对象访问策略 request

 @param bucketName 桶名
 @param objectKey 对象key
 @param accessControlPolicy 访问权限控制
 @return 设置对象访问策略 request
 */
-(instancetype)initWithBucketName:(NSString*) bucketName objectKey:(NSString*) objectKey accessControlPolicy:(OBSAccessControlPolicy*) accessControlPolicy;
@end

/**
 预定义头域设置桶访问策略       //**添加了以头域方式对已存在对象设置ACL的方式
 */
@interface OBSSetObjectACLWithCannedACLRequest: OBSBaseRequest<OBSSetObjectACLProtocol>

/**
 桶名
 */
@property (nonatomic, strong, nonnull) NSString *bucketName;

/**
 对象key
 */
@property (nonatomic, strong, nonnull) NSString *objectKey;

/**
 对象多版本ID
 */
@property (nonatomic, strong, nonnull) NSString *versionID;

/**
 ACL种类
 
 OBSACLPolicyPrivate 桶或对象的所有者拥有完全控制的权限，其他任何人都没有访问权限,
 OBSACLPolicyPublicRead 桶或对象的所有者拥有完全控制的权限，其他所有用户包括匿名用户拥有读的权限,
 OBSACLPolicyPublicReadWrite 桶或对象的所有者拥有完全控制的权限，其他所有用户包括匿名用户拥有读和写的权限,
 OBSACLPolicyAuthenticatedRead 桶或对象的所有者拥有完全控制的权限，其他OBS授权用户拥有读权限,
 OBSACLPolicyBucketOwnerRead 对象的所有者拥有完全控制的权限，桶的所有者拥有只读的权限,
 OBSACLPolicyBucketOwnerFullControl 对象的所有者拥有完全控制的权限，桶的所有者拥有完全控制的权限,
 OBSACLPolicyLogDeliveryWrite 日志投递用户组拥有对桶的写权限以及读 ACP的权限,
 */
@property (nonatomic, assign) OBSACLPolicy cannedACL;

/**
 初始化预定义设置桶访问策略 request
 
 @param bucketName 桶名
 @param cannedACL 预定义策略对象
 @return 预定义设置桶策略 request
 
 */
-(instancetype)initWithBucketName:(NSString*) bucketName objectKey:(NSString*) objectKey cannedACL:(OBSACLPolicy) cannedACL;
@end

#pragma mark - networking request
@interface OBSSetObjectACLRequestNetworking : OBSServiceNetworkingCommandRequest
@end

    //response
#pragma mark - response

/**
 设置对象访问策略response
 */
@interface OBSSetObjectACLResponse: OBSServiceResponse

/**
 版本ID
 */
@property (nonatomic, strong, nonnull) NSString *versionID;
@end


#pragma mark - client method
@interface OBSClient(setObjectACL)

/**
 设置对象的ACL

 @param request 设置对象访问策略 request
 @param completionHandler 设置对象访问策略回调
 @return OBSBFTask
 */
- (OBSBFTask*)setObjectACL:(__kindof OBSBaseRequest<OBSSetObjectACLProtocol>*)request
                 completionHandler:(void (^)(OBSSetObjectACLResponse  * response, NSError * error))completionHandler;
@end


#endif  /* OBSSetObjectACLModel_h */
