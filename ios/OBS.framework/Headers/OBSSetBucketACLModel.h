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

#ifndef OBSSetBucketACLModel_h
#define OBSSetBucketACLModel_h

#import "OBSBaseModel.h"
#import "OBSBaseNetworking.h"
#import "OBSClient.h"
#import "OBSServiceBaseModel.h"
#import "OBSServiceCommonEntities.h"
#import "OBSServiceConstDefinition.h"


#pragma mark - request

/**
 设置桶访问策略
 */
@protocol OBSSetBucketACLProtocol
@required

/**
 桶名
 */
@property (nonatomic, strong, nonnull) NSString *bucketName;
@end


/**
 直接设置桶访问策略request
 */
@interface OBSSetBucketACLWithPolicyRequest: OBSBaseRequest<OBSSetBucketACLProtocol>

/**
 桶名
 */
@property (nonatomic, strong, nonnull) NSString *bucketName;

/**
 访问控制权限策略
 */
@property (nonatomic, strong, nonnull) OBSAccessControlPolicy *accessControlPolicy;

/**
 初始化直接设置桶访问策略request

 @param bucketName 桶名
 @param accessControlPolicy 访问控制权限策略对象
 @return 设置桶ACL的request对象
 */
-(instancetype)initWithBucketName:(NSString*) bucketName accessControlPolicy:(OBSAccessControlPolicy*) accessControlPolicy;
@end


/**
 预定义设置桶访问策略
 */
@interface OBSSetBucketACLWithCannedACLRequest: OBSBaseRequest<OBSSetBucketACLProtocol>

/**
 桶名
 */
@property (nonatomic, strong, nonnull) NSString *bucketName;

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
-(instancetype)initWithBucketName:(NSString*) bucketName cannedACL:(OBSACLPolicy) cannedACL;
@end

#pragma mark - networking request
@interface OBSSetBucketACLRequestNetworking : OBSServiceNetworkingCommandRequest
@end

    //response
#pragma mark - response

/**
 设置桶访问策略response
 */
@interface OBSSetBucketACLResponse: OBSServiceResponse
@end


#pragma mark - client method
@interface OBSClient(setBucketACL)

/**
 设置桶访问策略

 @param request 设置桶访问策略request
 @param completionHandler 设置桶访问策略回调
 @return OBSBFTask
 */
- (OBSBFTask*)setBucketACL:(__kindof OBSBaseRequest<OBSSetBucketACLProtocol>*)request
         completionHandler:(void (^)(OBSSetBucketACLResponse  * response, NSError * error))completionHandler;
@end
#endif /* OBSSetBucketACLModel_h */
