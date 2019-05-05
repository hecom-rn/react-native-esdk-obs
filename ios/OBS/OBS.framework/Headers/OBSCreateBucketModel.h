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

#ifndef OBSCreateBucketModel_h
#define OBSCreateBucketModel_h
#import "OBSBaseModel.h"
#import "OBSBaseNetworking.h"
#import "OBSClient.h"
#import "OBSServiceBaseModel.h"
#import "OBSServiceConstDefinition.h"
#import "OBSServiceCommonEntities.h"
#import "OBSServiceCredentialProvider.h"

    //request
#pragma mark - request entity


#pragma mark - request



/**
 创建桶的
 */
@protocol OBSCreateBucketProtocol
@required

/**
 桶名
 */
@property (nonatomic, strong, nonnull) NSString *bucketName;
@end


/**
 创建桶request  
 */
@interface OBSCreateBucketRequest: OBSBaseRequest<OBSCreateBucketProtocol>

/**
 //区域配置
 */
@property (nonatomic, strong, nullable) OBSBucketConfiguration *configuration;

/**
 ACL设置
 
 OBSACLPolicyNULL0,
 OBSACLPolicyPrivate,
 OBSACLPolicyPublicRead,
 OBSACLPolicyPublicReadWrite,
 OBSACLPolicyAuthenticatedRead,
 OBSACLPolicyBucketOwnerRead,
 OBSACLPolicyBucketOwnerFullControl,
 OBSACLPolicyLogDeliveryWrite,
 */
@property (nonatomic, assign) OBSACLPolicy bucketACLPolicy;

/**
 桶存储类型
 
 OBSStorageClassNULL0,
 OBSStorageClassStandard,
 OBSStorageClassStandardIA,
 OBSStorageClassGlacier,
 */
@property (nonatomic, assign) OBSStorageClass defaultStorageClass;
@property (nonatomic, strong, nonnull) NSString *bucketName;

//**********************自研协议*******************************
/**
 授权给指定domain下的所有用户有READ权限。
 */
@property (nonatomic, strong, nonnull) NSString *grantRead;
/**
 授权给指定domain下的所有用户有WRITE权限。
 */
@property (nonatomic, strong, nonnull) NSString *grantWrite;
/**
 授权给指定domain下的所有用户有READ_ACP权限。
 */
@property (nonatomic, strong, nonnull) NSString *grantReadAcp;
/**
 授权给指定domain下的所有用户有WRITE_ACP权限，允许修改桶的ACL信息。
 */
@property (nonatomic, strong, nonnull) NSString *grantWriteAcp;
/**
 授权给指定domain下的所有用户有FULL_CONTROL权限。
 */
@property (nonatomic, strong, nonnull) NSString *grantfullControl;
/**
 授权给指定domain下的所有用户有READ权限，并且在默认情况下，该READ权限将传递给桶内所有对象。
 */
@property (nonatomic, strong, nonnull) NSString *grantreadDelivered;
/**
 授权给指定domain下的所有用户有FULL_CONTROL权限，并且在默认情况下，该FULL_CONTROL权限将传递给桶内所有对象。
 */
@property (nonatomic, strong, nonnull) NSString *grantfullControlDelivered;


/**
 初始化创建桶的request对象

 @param bucketName 桶名
 @return request实例
 */
-(instancetype)initWithBucketName:(NSString*) bucketName;
@end

#pragma mark - networking request
@interface OBSCreateBucketRequestNetworking : OBSServiceNetworkingCommandRequest
@end

    //response
#pragma mark - response

/**
 创建桶response
 */
@interface OBSCreateBucketResponse: OBSServiceResponse

/**
 桶区域位置
 */
@property (nonatomic, strong, nullable) NSString *location;
@end


#pragma mark - client method
@interface OBSClient(createBucket)

/**
 创建桶

 @param request 创建桶的request对象
 @param completionHandler 创建桶的回调
 @return task对象
 */
- (OBSBFTask*)createBucket:(__kindof OBSBaseRequest<OBSCreateBucketProtocol>*)request
         completionHandler:(void (^)(OBSCreateBucketResponse  * response, NSError * error))completionHandler;
@end


#endif  /* OBSServiceBaseModel_h */
