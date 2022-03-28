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

#ifndef OBSServiceDefine_h
#define OBSServiceDefine_h
#import "OBSBaseConstDefinition.h"


#define OBSCORSHTTPGET         @"GET"
#define OBSCORSHTTPPUT         @"PUT"
#define OBSCORSHTTPHEAD        @"HEAD"
#define OBSCORSHTTPPOST        @"POST"
#define OBSCORSHTTPDELETE      @"DELETE"


    // canonical headedrs key
static NSString *const  OBSCanonicalPrefix                      =@"x-amz-";
static NSString *const  OBSCanonicalMetaPrefix                  =@"x-obs-meta-";
static NSString *const  OBSV2MetaPrefix                         =@"x-amz-meta-";
static NSString *const  OBSCanonicalDateKey                     =@"x-amz-date";
static NSString *const  OBSCanonicalContentSha256Key            =@"x-amz-content-sha256";
static NSString *const  OBSCanonicalRequestIDKey                =@"x-amz-request-id";
static NSString *const  OBSSTSTokenHeaderKey                    =@"x-amz-security-token";
static NSString *const  OBSServiceName                          =@"s3";

static NSString *const  OBSCanonicalPrefix_OBS                  =@"x-obs-";
static NSString *const  OBSCanonicalMetaPrefix_OBS              =@"x-obs-meta-";
static NSString *const  OBSCanonicalDateKey_OBS                 =@"x-obs-date";
static NSString *const  OBSCanonicalContentSha256Key_OBS        =@"x-obs-content-sha256";
static NSString *const  OBSCanonicalRequestIDKey_OBS            =@"x-obs-request-id";
static NSString *const  OBSSTSTokenHeaderKey_OBS                =@"x-obs-security-token";
static NSString *const  OBSServiceName_OBS                      =@"s3";

static NSString *const  OBSEncryptionKMSKey                     =@"aws:kms";
static NSString *const  OBSMetaDataDictKey                      =@"metaDataDict";

static NSString *const  OBSDefaultRegion                        =@"china";
static NSString *const  OBSSigV4Marker                          =@"AWS4";
static NSString *const  OBSSigV4Algorithm                       =@"AWS4-HMAC-SHA256";
static NSString *const  OBSSigV4Terminator                      =@"aws4_request";

static NSString *const  OBSHeaderContentMD5Key                  =@"Content-MD5";

static NSString *const  OBSSubResourceACLKey                    =@"acl";
static NSString *const  OBSSubResourceLifecycleKey              =@"lifecycle";
static NSString *const  OBSSubResourceLocationKey               =@"location";
static NSString *const  OBSSubResourceLoggingKey                =@"logging";
static NSString *const  OBSSubResourceNotificationKey           =@"notification";
static NSString *const  OBSSubResourcePartNumberKey             =@"partNumber";
static NSString *const  OBSSubResourcePolicyKey                 =@"policy";
static NSString *const  OBSSubResourceUploadIDKey               =@"uploadId";
static NSString *const  OBSSubResourceUploadsKey                =@"uploads";
static NSString *const  OBSSubResourceAppendKey                 =@"append";
static NSString *const  OBSSubResourcePositionKey               =@"position";
static NSString *const  OBSSubResourceVersionIDKey              =@"versionId";
static NSString *const  OBSSubResourceImageProcessKey           =@"x-image-process";
static NSString *const  OBSSubResourceVersioningKey             =@"versioning";
static NSString *const  OBSSubResourceVersionsKey               =@"versions";
static NSString *const  OBSSubResourceWebsiteKey                =@"website";
static NSString *const  OBSSubResourceQuotaKey                  =@"quota";
static NSString *const  OBSSubResourceStoragePolicyKey          =@"storagePolicy";
static NSString *const  OBSSubResourceStoragePolicyKey_OBS      =@"storageClass";
static NSString *const  OBSSubResourceReplicateBucketKey        =@"replication";
static NSString *const  OBSSubResourceStorageInfoKey            =@"storageinfo";
static NSString *const  OBSSubResourceCORSKey                   =@"cors";
static NSString *const  OBSSubResourceDeleteKey                 =@"delete";
static NSString *const  OBSSubResourceRestoreKey                =@"restore";
static NSString *const  OBSSubResourceResponseContentTypeKey    =@"response-content-type";
static NSString *const  OBSSubResourceResponseContentLanguageKey=@"response-content-language";
static NSString *const  OBSSubResourceResponseExpiresKey        =@"response-expires";
static NSString *const  OBSSubResourceResponseCacheControlKey   =@"response-cache-control";
static NSString *const  OBSSubResourceResponseContentDispositionKey=@"response-content-disposition";
static NSString *const  OBSSubResourceResponseContentEncodingKey=@"response-content-encoding";
static NSString *const  OBSSubResourceTaggingKey                =@"tagging";



static NSString *const  OBSUserAttributeKey                     =@"xsi:type";
static NSString *const  OBSUserURIKey                           =@"URI";

static NSString *const  OBSUserAuthenticatedUsersURI            =@"http://acs.amazonaws.com/groups/global/AuthenticatedUsers";
static NSString *const  OBSUserAllUsersURI                      =@"http://acs.amazonaws.com/groups/global/AllUsers";
static NSString *const  OBSUserLogDeliveryURI                   =@"http://acs.amazonaws.com/groups/s3/LogDelivery";


#pragma mark -Enum

#pragma mark -Enum


/**
 *  OBSACLPolicy枚举
 *
 *  OBS 预定义的权限控制策略
 *
 */
typedef NS_ENUM(NSInteger, OBSACLPolicy){
    /**
     *  默认权限
     */
    OBSACLPolicyNULL0,
    /**
     *  桶或对象的所有者拥有完全控制的权限，其他任何人都没有访问权限(自研/旧版本)
     */
    OBSACLPolicyPrivate,
    /**
     *  桶或对象的所有者拥有完全控制的权限，其他所有用户包括匿名用户拥有读的权限(自研/旧版本)
     */
    OBSACLPolicyPublicRead,
    /**
     *  桶或对象的所有者拥有完全控制的权限，其他所有用户包括匿名用户拥有读和写的权限(自研/旧版本)
     */
    OBSACLPolicyPublicReadWrite,
    /**
     *  桶或对象的所有者拥有完全控制的权限，其他OBS授权用户拥有读权限
     */
    OBSACLPolicyAuthenticatedRead,
    /**
     *  对象的所有者拥有完全控制的权限，桶的所有者拥有只读的权限
     */
    OBSACLPolicyBucketOwnerRead,
    /**
     *  对象的所有者拥有完全控制的权限，桶的所有者拥有完全控制的权限
     */
    OBSACLPolicyBucketOwnerFullControl,
    /**
     *  日志投递用户组拥有对桶的写权限以及读ACP的权限
     */
    OBSACLPolicyLogDeliveryWrite,
    /**
     *  设在桶上，所有人可以获取该桶内对象列表、桶内多段任务、桶的元数据，可以获取该桶内对象的内容和元数据。不能应用在对象上。（自研协议）
     */
    OBSACLPolicyPublicReadDelivered,
    /**
     *  设在桶上，所有人可以获取该桶内对象列表、桶内多段任务、桶的元数据、上传对象删除对象、初始化段任务、上传段、合并段、拷贝段、取消多段上传任务，可以获取该桶内对象的内容和元数据。
不能应用在对象上。（自研协议）
     */
    OBSACLPolicyPublicReadWriteDelivered,

};


/**
 *  OBSACL枚举
 *
 *  支持的桶或对象权限
 *
 */
typedef NS_ENUM(NSInteger, OBSACL){
    /**
     *  默认
     */
    OBSACLNULL0,
    /**
     *  若有桶的读权限，则可以获取该桶内对象列表和桶的元数据。若有对象的读权限，则可以获取该对象内容和元数据
     */
    OBSACLRead,
    /**
     *  若有桶的写权限，则可以上传、覆盖和删除该桶内任何对象。此权限在对象上不适用
     */
    OBSACLWrite,
    /**
     *  若有读ACP的权限，则可以获取对应的桶或对象的权限控制列 表(ACL)。桶或对象的所有者永远拥有读对应桶或对象ACP的权限
     */
    OBSACLRead_ACP,
    /**
     *  若有写ACP的权限，则可以更新对应桶或对象的权限控制列表 (ACL)。桶或对象的所有者永远拥有写对应桶或对象的ACP的权限。 拥有了写ACP的权限，由于可以更改权限控制策略，实际上意味着拥有了完全访问的权限
     */
    OBSACLWrite_ACP,
    /**
     *  若有桶的完全控制权限意味着拥有READ、WRITE、 READ_ACP WRITE_ACP的权限。若有对象的完全控制权限意味着拥有READ、READ_ACP和 WRITE_ACP的权限。READ_ONLY的用户不受此限制
     */
    OBSACLFull_Control,
    /**
     *  对象的读权限，则可以获取该对象内容和元数据
     */
    OBSACLRead_Object,
    /**
     *  对象的完全控制权限意味着拥有READ、READ_ACP和 WRITE_ACP的权限。READ_ONLY的用户不受此限制
     */
    OBSACLFull_Control_Object,
};

/**
 *  OBSACLUserType
 *
 *  用户类型
 *
 */
typedef NS_ENUM(NSInteger, OBSACLUserType){
    /**
     *   默认组
     */
    OBSACLUserTypeNULL0,
    /**
     *   授予OBS用户
     */
    OBSACLUserTypeCanonicalUser,
    /**
     *   授予注册用户组
     */
    OBSACLUserTypeAuthenticatedUsers,
    /**
     *   授予匿名用户
     */
    OBSACLUserTypeAllUsers,
    /**
     *   日志投递用户组
     */
    OBSACLUserTypeLogDelivery,
};


/**
 *   OBSStorageClass
 *
 *  桶的存储类型
 *
 */
typedef NS_ENUM(NSInteger, OBSStorageClass){
    /**
     *   默认存储类型
     */
    OBSStorageClassNULL0,
    /**
     *   标准存储
     */
    OBSStorageClassStandard,
    /**
     *   低频访问存储
     */
    OBSStorageClassStandardIA,
    /**
     *   归档存储
     */
    OBSStorageClassGlacier,
   
};

typedef NS_ENUM(NSInteger, OBSReplicateStatus){
    /**
     *   默认
     */
    OBSReplicateStatusNULL0,
    /**
     *   enable状态
     */
    OBSReplicateStatusEnable,
    /**
     *   disable状态
     */
    OBSReplicateStatusDisable,
    
    
};

/**
 *   OBSVersioningStatus
 *
 *   多版本状态
 *
 */
typedef NS_ENUM(NSInteger, OBSVersioningStatus){
    /**
     *   默认配置
     */
    OBSVersioningStatusNULL0,
    /**
     *   开启
     */
    OBSVersioningStatusEnabled,
    /**
     *   关闭
     */
    OBSVersioningStatusSuspended,
};


/**
 *   OBSLifecycleStatus
 *
 *  桶生命周期状态
 *
 */
typedef NS_ENUM(NSInteger, OBSLifecycleStatus){
    /**
     *   默认配置
     */
    OBSLifecycleStatusNULL0,
    /**
     *   开启
     */
    OBSLifecycleStatusEnabled,
    /**
     *   关闭
     */
    OBSLifecycleStatusSuspended,
};

/**
 *   OBSPolicyEffect
 *
 *   策略的响应状态
 *
 */
typedef NS_ENUM(NSInteger, OBSPolicyEffect){
    /**
     *   默认
     */
    OBSPolicyEffectNULL0,
    /**
     *   允许
     */
    OBSPolicyEffectAllow,
    /**
     *   拒绝
     */
    OBSPolicyEffectDeny,
};

/**
 *   OBSMetaDirective
 *
 *  此参数用来指定新对象的元数据是从源对象中复制，还是用请求中的元数据替换
 *
 */
typedef NS_ENUM(NSInteger, OBSMetaDirective){
    /**
     *   默认
     */
    OBSMetaDirectiveNULL0,
    /**
     *   复制
     */
    OBSMetaDirectiveCopy,
    /**
     *   替换
     */
    OBSMetaDirectiveReplace,
};

/**
 *   OBSRestoreTier
 *
 *   归档取回方式
 *
 */
typedef NS_ENUM(NSInteger, OBSRestoreTier){
    /**
     *   默认
     */
    OBSRestoreTierNULL0,
    /**
     *   表示标准取回对象，取回耗时3~5 h
     */
    OBSRestoreTierStandard,
    /**
     *   表示快速取回对 象，取回耗时1~5 min，
     */
    OBSRestoreTierExpedited,
    /**
     *   OBSRestoreTierBulk
     */
    OBSRestoreTierBulk,
};

/**
 *   OBSDomainMode
 *
 *   域名访问方式
 *
 */
typedef NS_ENUM(NSInteger, OBSDomainMode){
    /**
     *   默认域名访问方式
     */
    OBSDomainModeNULL0,
    /**
     *   自定义域名访问
     */
    OBSDomainModeCustom,
    
};

#define OBSPolicyActionAbortMultipartUpload              @"s3:AbortMultipartUpload"
#define OBSPolicyActionDeleteObject                      @"s3:DeleteObject"
#define OBSPolicyActionDeleteObjectTagging               @"s3:DeleteObjectTagging"
#define OBSPolicyActionDeleteObjectVersion               @"s3:DeleteObjectVersion"
#define OBSPolicyActionDeleteObjectVersionTagging        @"s3:DeleteObjectVersionTagging"
#define OBSPolicyActionGetObject                         @"s3:GetObject"
#define OBSPolicyActionGetObjectAcl                      @"s3:GetObjectAcl"
#define OBSPolicyActionGetObjectTagging                  @"s3:GetObjectTagging"
#define OBSPolicyActionGetObjectTorrent                  @"s3:GetObjectTorrent"
#define OBSPolicyActionGetObjectVersion                  @"s3:GetObjectVersion"
#define OBSPolicyActionGetObjectVersionAcl               @"s3:GetObjectVersionAcl"
#define OBSPolicyActionGetObjectVersionTagging           @"s3:GetObjectVersionTagging"
#define OBSPolicyActionGetObjectVersionTorrent           @"s3:GetObjectVersionTorrent"
#define OBSPolicyActionListMultipartUploadParts          @"s3:ListMultipartUploadParts"
#define OBSPolicyActionPutObject                         @"s3:PutObject"
#define OBSPolicyActionPutObjectAcl                      @"s3:PutObjectAcl"
#define OBSPolicyActionPutObjectTagging                  @"s3:PutObjectTagging"
#define OBSPolicyActionPutObjectVersionAcl               @"s3:PutObjectVersionAcl"
#define OBSPolicyActionPutObjectVersionTagging           @"s3:PutObjectVersionTagging"
#define OBSPolicyActionRestoreObject                     @"s3:RestoreObject"
#define OBSPolicyActionCreateBucket                      @"s3:CreateBucket"
#define OBSPolicyActionDeleteBucket                      @"s3:DeleteBucket"
#define OBSPolicyActionListBucket                        @"s3:ListBucket"
#define OBSPolicyActionListBucketVersions                @"s3:ListBucketVersions"
#define OBSPolicyActionListAllMyBuckets                  @"s3:ListAllMyBuckets"
#define OBSPolicyActionListBucketMultipartUploads        @"s3:ListBucketMultipartUploads"
#define OBSPolicyActionDeleteBucketPolicy                @"s3:DeleteBucketPolicy"
#define OBSPolicyActionDeleteBucketWebsite               @"s3:DeleteBucketWebsite"
#define OBSPolicyActionDeleteReplicationConfiguration    @"s3:DeleteReplicationConfiguration"
#define OBSPolicyActionGetAccelerateConfiguration        @"s3:GetAccelerateConfiguration"
#define OBSPolicyActionGetAnalyticsConfiguration         @"s3:GetAnalyticsConfiguration"
#define OBSPolicyActionGetBucketAcl                      @"s3:GetBucketAcl"
#define OBSPolicyActionGetBucketCORS                     @"s3:GetBucketCORS"
#define OBSPolicyActionGetBucketLocation                 @"s3:GetBucketLocation"
#define OBSPolicyActionGetBucketLogging                  @"s3:GetBucketLogging"
#define OBSPolicyActionGetBucketNotification             @"s3:GetBucketNotification"
#define OBSPolicyActionGetBucketPolicy                   @"s3:GetBucketPolicy"
#define OBSPolicyActionGetBucketRequestPayment           @"s3:GetBucketRequestPayment"
#define OBSPolicyActionGetBucketTagging                  @"s3:GetBucketTagging"
#define OBSPolicyActionGetBucketVersioning               @"s3:GetBucketVersioning"
#define OBSPolicyActionGetBucketWebsite                  @"s3:GetBucketWebsite"
#define OBSPolicyActionGetEncryptionConfiguration        @"s3:GetEncryptionConfiguration"
#define OBSPolicyActionGetInventoryConfiguration         @"s3:GetInventoryConfiguration"
#define OBSPolicyActionGetLifecycleConfiguration         @"s3:GetLifecycleConfiguration"
#define OBSPolicyActionGetMetricsConfiguration           @"s3:GetMetricsConfiguration"
#define OBSPolicyActionGetReplicationConfiguration       @"s3:GetReplicationConfiguration"
#define OBSPolicyActionPutAccelerateConfiguration        @"s3:PutAccelerateConfiguration"
#define OBSPolicyActionPutAnalyticsConfiguration         @"s3:PutAnalyticsConfiguration"
#define OBSPolicyActionPutBucketAcl                      @"s3:PutBucketAcl"
#define OBSPolicyActionPutBucketCORS                     @"s3:PutBucketCORS"
#define OBSPolicyActionPutBucketLogging                  @"s3:PutBucketLogging"
#define OBSPolicyActionPutBucketNotification             @"s3:PutBucketNotification"
#define OBSPolicyActionPutBucketPolicy                   @"s3:PutBucketPolicy"
#define OBSPolicyActionPutBucketRequestPayment           @"s3:PutBucketRequestPayment"
#define OBSPolicyActionPutBucketTagging                  @"s3:PutBucketTagging"
#define OBSPolicyActionPutBucketVersioning               @"s3:PutBucketVersioning"
#define OBSPolicyActionPutBucketWebsite                  @"s3:PutBucketWebsite"
#define OBSPolicyActionPutEncryptionConfiguration        @"s3:PutEncryptionConfiguration"
#define OBSPolicyActionPutInventoryConfiguration         @"s3:PutInventoryConfiguration"
#define OBSPolicyActionPutLifecycleConfiguration         @"s3:PutLifecycleConfiguration"
#define OBSPolicyActionPutMetricsConfiguration           @"s3:PutMetricsConfiguration"
#define OBSPolicyActionPutReplicationConfiguration       @"s3:PutReplicationConfiguration"

// 3.0版本
#define OBSPolicyActionCreateBucket_OBS                          @"CreateBucket"
#define OBSPolicyActionDeleteBucket_OBS                          @"DeleteBucket"
#define OBSPolicyActionListBucket_OBS                            @"ListBucket"
#define OBSPolicyActionHeadBucket_OBS                            @"HeadBucket"
#define OBSPolicyActionListBucketVersions_OBS                    @"ListBucketVersions"
#define OBSPolicyActionListBucketMultipartUploads_OBS             @"ListBucketMultipartUploads"
#define OBSPolicyActionGetBucketAcl_OBS                          @"GetBucketAcl"
#define OBSPolicyActionPutBucketAcl_OBS                          @"PutBucketAcl"
#define OBSPolicyActionGetBucketCORS_OBS                         @"GetBucketCORS"
#define OBSPolicyActionPutBucketCORS_OBS                         @"PutBucketCORS"
#define OBSPolicyActionGetBucketVersioning_OBS                   @"GetBucketVersioning"
#define OBSPolicyActionPutBucketVersioning_OBS                   @"PutBucketVersioning"
#define OBSPolicyActionGetBucketLocation_OBS                     @"GetBucketLocation"
#define OBSPolicyActionGetBucketPolicy_OBS                       @"GetBucketPolicy"
#define OBSPolicyActionDeleteBucketPolicy_OBS                    @"DeleteBucketPolicy"
#define OBSPolicyActionPutBucketPolicy_OBS                       @"PutBucketPolicy"
#define OBSPolicyActionGetBucketLogging_OBS                      @"GetBucketLogging"
#define OBSPolicyActionPutBucketLogging_OBS                      @"PutBucketLogging"
#define OBSPolicyActionGetBucketWebsite_OBS                      @"GetBucketWebsite"
#define OBSPolicyActionPutBucketWebsite_OBS                      @"PutBucketWebsite"
#define OBSPolicyActionDeleteBucketWebsite_OBS                   @"DeleteBucketWebsite"
#define OBSPolicyActionGetLifecycleConfiguration_OBS             @"GetLifecycleConfiguration"
#define OBSPolicyActionPutLifecycleConfiguration_OBS             @"PutLifecycleConfiguration"
#define OBSPolicyActionGetBucketNotification_OBS                 @"GetBucketNotification"
#define OBSPolicyActionPutBucketNotification_OBS                 @"PutBucketNotification"
#define OBSPolicyActionGetReplicationConfiguration_OBS             @"GetReplicationConfiguration"
#define OBSPolicyActionGetObject_OBS                             @"GetObject"
#define OBSPolicyActionGetObjectVersion_OBS                      @"GetObjectVersion"
#define OBSPolicyActionPutObject_OBS                             @"PutObject"
#define OBSPolicyActionGetObjectAcl_OBS                          @"GetObjectAcl"
#define OBSPolicyActionGetObjectVersionAcl_OBS                   @"GetObjectVersionAcl"
#define OBSPolicyActionPutObjectAcl_OBS                          @"PutObjectAcl"
#define OBSPolicyActionPutObjectVersionAcl_OBS                   @"PutObjectVersionAcl"
#define OBSPolicyActionDeleteObject_OBS                          @"DeleteObject"
#define OBSPolicyActionDeleteObjectVersion_OBS                   @"DeleteObjectVersion"
#define OBSPolicyActionListMultipartUploadParts_OBS              @"ListMultipartUploadParts"
#define OBSPolicyActionAbortMultipartUpload_OBS                  @"AbortMultipartUpload"
#define OBSPolicyActionRestoreObject_OBS                         @"RestoreObject"
#define OBSPolicyActionDeleteObject_OBS                          @"DeleteObject"
#define OBSPolicyActionReplicateObject_OBS                       @"ReplicateObject"
#define OBSPolicyActionReplicateDelete_OBS                       @"ReplicateDelete"



#endif  /* OBSServiceDefinition_h */
