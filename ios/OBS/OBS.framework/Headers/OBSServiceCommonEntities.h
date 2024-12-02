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

#ifndef OBSServiceRequestCommonEntity_h
#define OBSServiceRequestCommonEntity_h
#import "OBSBaseModel.h"
#import "OBSServiceConstDefinition.h"
#pragma mark encryption
@interface OBSAbstractEncryption: OBSBaseEntity
@end

/**
 KMS加密方式
 */
@interface OBSEncryptionTypeKMS: OBSAbstractEncryption

/**
 加密方式
 */
@property (nonatomic, strong, nonnull) NSString *serverSideEncryption;

/**
 主秘钥
 */
@property (nonatomic, strong, nullable) NSString *serverSideEncryptionAwsKmsKeyID;

/**
 初始化KMS加密方式

 @param keyID 主密钥
 @return KMS加密方式
 */
-(instancetype)initWithKeyID:(NSString*) keyID;
@end

/**
 SSE-C加密方式
 */
@interface OBSEncryptionTypeCustomer: OBSAbstractEncryption

/**
 加密方式
 */
@property (nonatomic, strong, nonnull) NSString *serverSideEncryptionCustomerAlgorithm;

/**
 秘钥
 */
@property (nonatomic, strong, nonnull) NSString *serverSideEncryptionCustomerKey;

/**
 秘钥的MD5
 */
@property (nonatomic, strong, nonnull) NSString *serverSideEncryptionCustomerMD5;

/**
 初始化SSE加密方式

 @param algorithm 加密算法
 @param key 秘钥
 @param keyMD5 秘钥的MD5
 @return SSE加密方式
 */
-(instancetype)initWithAlgorithm:(NSString*) algorithm key:(NSString*) key keyMD5:(NSString*) keyMD5;
@end



#pragma mark ACL

/**
 桶的访问权限控制
 */
@interface OBSUser: OBSBaseEntity

/**
 桶拥有者ID
 */
@property (nonatomic, strong, nonnull) NSString *ID;

/**
 显示名字
 */
@property (nonatomic, strong, nullable) NSString *displayName;
-(instancetype)initWithID:(NSString*) ID;
@end

@interface OBSAbstractACLGrantee :OBSBaseEntity
@end

/**
 被授权用户
 */
@interface OBSGrantee : OBSAbstractACLGrantee

/**
 被授权用户ID
 */
@property (nonatomic, strong, nonnull) NSString *ID;

@end
@interface OBSACLGranteeUser : OBSAbstractACLGrantee

/**
 被授权用户ID
 */
@property (nonatomic, strong, nonnull) NSString *ID;

/**
 显示名字
 */
@property (nonatomic, strong, nullable) NSString *displayName;
-(instancetype)initWithID:(NSString*) ID;
@end

@interface OBSACLGranteeAuthenciatedUsers: OBSAbstractACLGrantee
@end

@interface OBSACLGranteeAllUsers: OBSAbstractACLGrantee
@end


//桶日志设置
@interface OBSACLGranteeLogDelivery: OBSAbstractACLGrantee
@end


/**
 授权用户及权限
 */
@interface OBSACLGrant: OBSBaseEntity

/**
 授权用户对象
 */
@property (nonatomic, strong, nonnull) __kindof OBSAbstractACLGrantee *grantee;



/**
 授予的权限
 
 OBSACLRead 读权限,
 OBSACLWrite 写权限,
 OBSACLRead_ACP 读ACP权限,
 OBSACLWrite_ACP 写ACP权限,
 OBSACLFull_Control 所有权限,
 OBSACLRead_Object 读桶中的对象,
 OBSACLFull_Control_Object 拥有对象的所有权限,
 
 */
@property (nonatomic, assign) OBSACL permission;

/**
 初始化授权对象

 @param grantee 授权用户对象
 @param permission 权限对象
 @return 授权对象
 */
-(instancetype)initWithGrantee:(__kindof OBSAbstractACLGrantee*) grantee permission:(OBSACL) permission;
@end


/**
 用户访问权限控制
 */
@interface OBSAccessControlPolicy: OBSBaseEntity

/**
 用户对象
 */
@property (nonatomic, strong, nonnull) OBSUser *owner;

/**
 访问控制列表
 */
@property (nonatomic, strong, nonnull) NSMutableArray<OBSACLGrant*> *accessControlList;

/**
 初始化用户访问控制权限

 @param owner 拥有者对象
 @return 用户访问控制权限对象
 */
-(instancetype)initWithOwner:(OBSUser*) owner;
@end


#pragma mark - CORS

/**
 跨域资源共享规则
 */
@interface OBSCORSRule: OBSBaseEntity<OBSMTLDictionaryItemOrderProtocol>

/**
 一条Rule的标识
 */
@property (nonatomic, strong, nonnull) NSString *ID;

/**
 CORS规则允许的请求方法
 */
@property (nonatomic, strong, nonnull) NSArray<NSString*> *allowedMethodList;

/**
 CORS规则允许的域名字符串
 */
@property (nonatomic, strong, nonnull) NSArray<NSString*> *allowedOriginList;

/**
 CORS请求中允许携带的头域
 */
@property (nonatomic, strong, nonnull) NSArray<NSString*> *allowedHeaderList;

/**
 可以缓存的CORS响应时间
 */
@property (nonatomic, strong, nonnull) NSNumber *maxAgeSeconds;

/**
 CORS响应中带的附加头域
 */
@property (nonatomic, strong, nonnull) NSArray<NSString*> *exposeHeaderList;
@end

#pragma mark - storage policy
// 存储策略
@interface OBSStoragePolicy : OBSBaseEntity
@property (nonatomic, assign) OBSStorageClass defaultStorageClass;
/**
 存储策略初始化
 
 @param storageClass 存储种类
 OBSStorageClassNULL0,
 OBSStorageClassStandard(标准存储),
 OBSStorageClassStandardIA(低频访问存储),
 OBSStorageClassGlacier(归档存储)
 @return 存储策略对象
 */
-(instancetype)initWithStorageClass:(OBSStorageClass) storageClass;
@end

#pragma mark bucket location configuration
@interface OBSBucketConfiguration: OBSBaseEntity
@property (nonatomic, strong, nonnull) NSString *locationConstraint;
-(instancetype)initWithLocationConstraint:(NSString*) location;
@end

#pragma mark bucket replication rule
@interface OBSReplicateBucketRule: OBSBaseEntity
@property (nonatomic, strong, nonnull) NSString *replicateBucketRule;
@property (nonatomic, strong, nonnull) NSString *ID;
@property (nonatomic, strong, nonnull) NSString *prefix;
@property (nonatomic, assign) OBSReplicateStatus status;
@property (nonatomic, strong, nonnull) NSString *destination;

-(instancetype)initWithID:(NSString*) ID prefix:(NSString*) prefix status:(OBSReplicateStatus) status destination:(NSString*) destination;

@end



#pragma mark bucket quota
// 桶存储容量
@interface OBSQuota: OBSBaseEntity

/**
 存储容量
 */
@property (nonatomic, strong, nonnull) NSNumber *storageQuota;

/**
 初始化桶存储容量对象

 @param storageQuotaNumber 容量大小
 @return 桶存储容量对象
 */
-(instancetype)initWithQuotaNumber:(NSNumber*)storageQuotaNumber;
@end
#pragma mark bucket logging
@interface OBSLoggingEnabled: OBSBaseEntity<OBSMTLDictionaryItemOrderProtocol>
@property (nonatomic, strong, nonnull) NSString *targetBucket;
@property (nonatomic, strong, nonnull) NSString *targetPrefix;
/**
 产生logging日志桶Owner创建委托OBS上传logging日志的委托名
 */
@property (nonatomic, strong, nonnull) NSString *agency;
@property (nonatomic, strong, nonnull) NSMutableArray<OBSACLGrant*> *targetGrantsList;
-(instancetype)initWithTargetBucket:(NSString*)targetBucket targetPrefix:(NSString*) targetPrefix;
@end

#pragma mark bucket policy

/**
 被授权人
 */
@interface OBSPolicyPrincipal: OBSBaseEntity

/**
 账户类型
 */
@property (nonatomic, strong, nonnull) NSString *accountType;

/**
 Principal授权格式
 
 */
@property (nonatomic, strong, nonnull) NSArray<NSString*> *accountARNList;
@end


/**
 condition具体配置
 */
@interface OBSPolicyConditionItem: OBSBaseEntity

/**
 从左边开始匹配
 */
@property (nonatomic, strong, nonnull) NSString *leftExpression;

/**
 从右边开始匹配的字符串数组
 */
@property (nonatomic, strong, nonnull) NSArray<NSString*> *rightExpressionList;
@end


/**
 statement生效条件
 */
@interface OBSPolicyCondition: OBSBaseEntity

/**
 字符串匹配
 */
@property (nonatomic, strong, nonnull) OBSPolicyConditionItem *stringEquals;

/**
 字符串不匹配
 */
@property (nonatomic, strong, nonnull) OBSPolicyConditionItem *stringNotEquals;

/**
 忽略大小写的字符串匹配
 */
@property (nonatomic, strong, nonnull) OBSPolicyConditionItem *stringEqualsIgnoreCase;

/**
 不忽略大小写的字符串匹配
 */
@property (nonatomic, strong, nonnull) OBSPolicyConditionItem *stringEqualsNotIgnoreCase;

/**
 宽松的区分大小写的匹配
 */
@property (nonatomic, strong, nonnull) OBSPolicyConditionItem *stringLike;

/**
 非宽松区别大小写的匹配
 */
@property (nonatomic, strong, nonnull) OBSPolicyConditionItem *stringNotLike;

/**
 相等
 */
@property (nonatomic, strong, nonnull) OBSPolicyConditionItem *numericEquals;

/**
 不相等
 */
@property (nonatomic, strong, nonnull) OBSPolicyConditionItem *numericNotEquals;

/**
 小于
 */
@property (nonatomic, strong, nonnull) OBSPolicyConditionItem *numericLessThan;

/**
 小于等于
 */
@property (nonatomic, strong, nonnull) OBSPolicyConditionItem *numericLessThanEquals;

/**
 大于
 */
@property (nonatomic, strong, nonnull) OBSPolicyConditionItem *numericGreaterThan;

/**
 大于等于
 */
@property (nonatomic, strong, nonnull) OBSPolicyConditionItem *numericGreaterThanEquals;



/**
 日期时间相等
 */
@property (nonatomic, strong, nonnull) OBSPolicyConditionItem *dateEquals;

/**
 日期时间不相等
 */
@property (nonatomic, strong, nonnull) OBSPolicyConditionItem *dateNotEquals;

/**
 日期时间小于
 */
@property (nonatomic, strong, nonnull) OBSPolicyConditionItem *dateLessThan;

/**
 日期时间小于等于
 */
@property (nonatomic, strong, nonnull) OBSPolicyConditionItem *dateLessThanEquals;

/**
 日期时间大于
 */
@property (nonatomic, strong, nonnull) OBSPolicyConditionItem *dateGreaterThan;

/**
 日期时间大于等于
 */
@property (nonatomic, strong, nonnull) OBSPolicyConditionItem *dateGreaterThanEquals;


/**
 严格布尔值相等
 */
@property (nonatomic, strong, nonnull) OBSPolicyConditionItem *booL;

@property (nonatomic, strong, nonnull) OBSPolicyConditionItem *binaryEquals;


/**
 指定的IP或IP范围
 */
@property (nonatomic, strong, nonnull) OBSPolicyConditionItem *IpAddress;

/**
 不包含指定的IP或IP范围
 */
@property (nonatomic, strong, nonnull) OBSPolicyConditionItem *notIpaddress;

@property (nonatomic, strong, nonnull) OBSPolicyConditionItem *arnEquals;
@property (nonatomic, strong, nonnull) OBSPolicyConditionItem *arnNotEquals;
@property (nonatomic, strong, nonnull) OBSPolicyConditionItem *arnLike;
@property (nonatomic, strong, nonnull) OBSPolicyConditionItem *arnNotLike;


@property (nonatomic, strong, nonnull) OBSPolicyConditionItem *stringEqualsIfExists;
@property (nonatomic, strong, nonnull) OBSPolicyConditionItem *stringNotEqualsIfExists;
@property (nonatomic, strong, nonnull) OBSPolicyConditionItem *stringEqualsIgnoreCaseIfExists;
@property (nonatomic, strong, nonnull) OBSPolicyConditionItem *stringEqualsNotIgnoreCaseIfExists;
@property (nonatomic, strong, nonnull) OBSPolicyConditionItem *stringLikeIfExists;
@property (nonatomic, strong, nonnull) OBSPolicyConditionItem *stringNotLikeIfExists;

@property (nonatomic, strong, nonnull) OBSPolicyConditionItem *numericEqualsIfExists;
@property (nonatomic, strong, nonnull) OBSPolicyConditionItem *numericNotEqualsIfExists;
@property (nonatomic, strong, nonnull) OBSPolicyConditionItem *numericLessThanIfExists;
@property (nonatomic, strong, nonnull) OBSPolicyConditionItem *numericLessThanEqualsIfExists;
@property (nonatomic, strong, nonnull) OBSPolicyConditionItem *numericGreaterThanIfExists;
@property (nonatomic, strong, nonnull) OBSPolicyConditionItem *numericGreaterThanEqualsIfExists;

@property (nonatomic, strong, nonnull) OBSPolicyConditionItem *dateEqualsIfExists;
@property (nonatomic, strong, nonnull) OBSPolicyConditionItem *dateNotEqualsIfExists;
@property (nonatomic, strong, nonnull) OBSPolicyConditionItem *dateLessThanIfExists;
@property (nonatomic, strong, nonnull) OBSPolicyConditionItem *dateLessThanEqualsIfExists;
@property (nonatomic, strong, nonnull) OBSPolicyConditionItem *dateGreaterThanIfExists;
@property (nonatomic, strong, nonnull) OBSPolicyConditionItem *dateGreaterThanEqualsIfExists;

@property (nonatomic, strong, nonnull) OBSPolicyConditionItem *booLIfExists;

@property (nonatomic, strong, nonnull) OBSPolicyConditionItem *binaryEqualsIfExists;

@property (nonatomic, strong, nonnull) OBSPolicyConditionItem *IpAddressIfExists;
@property (nonatomic, strong, nonnull) OBSPolicyConditionItem *notIpaddressIfExists;

@property (nonatomic, strong, nonnull) OBSPolicyConditionItem *arnEqualsIfExists;
@property (nonatomic, strong, nonnull) OBSPolicyConditionItem *arnNotEqualsIfExists;
@property (nonatomic, strong, nonnull) OBSPolicyConditionItem *arnLikeIfExists;
@property (nonatomic, strong, nonnull) OBSPolicyConditionItem *arnNotLikeIfExists;

@property (nonatomic, strong, nonnull) OBSPolicyConditionItem *nulL;

@end

/**
 策略声明
 */
@interface OBSPolicyStatement: OBSBaseEntity

/**
 statement ID 描述statement的字符串
 */
@property (nonatomic, strong, nonnull) NSString *sid;

/**
 本条statement的权限
 
 OBSPolicyEffectAllow,
 OBSPolicyEffectDeny,
 */
@property (nonatomic, assign) OBSPolicyEffect effect;

/**
 被授权人
 */
@property (nonatomic, strong, nonnull) OBSPolicyPrincipal *principal;

/**
 不被授权人
 */
@property (nonatomic, strong, nonnull) OBSPolicyPrincipal *notPrincipal;

/**
 本条statement生效条件
 */
@property (nonatomic, strong, nonnull) OBSPolicyCondition *condition;

/**
 本条statement作用的操作
 */
@property (nonatomic, strong, nonnull) NSMutableArray<NSString*> *actionList;

/**
 不被匹配的作用的操作
 */
@property (nonatomic, strong, nonnull) NSMutableArray<NSString*> *notActionList;

/**
 起作用的一组资源
 */
@property (nonatomic, strong, nonnull) NSMutableArray<NSString*> *resourceList;

/**
 不起作用的一组资源
 */
@property (nonatomic, strong, nonnull) NSMutableArray<NSString*> *notResourceList;

/**
 初始化策略声明

 @param sid statement ID
 @param effect 权限类型
 @return 策略声明对象
 */
-(instancetype)initWithSid:(NSString*) sid effect:(OBSPolicyEffect) effect;
@end

#pragma mark bucket lifecycle

/**
 生命周期配置中表示迁移时间和迁移后对象存储级别的元素(仅针对对象的最新版本)
 */
@interface OBSLifecycleTransition : OBSBaseEntity

/**
 对象创建时间后第几天时规则生效
 */
@property (nonatomic, strong, nonnull) NSNumber *days;

/**
 对象将被修改成的存储级别
 */
@property (nonatomic, assign) OBSStorageClass storageClass;

/**
 初始化生命周期迁移时间及对象存储级别

 @param days 第几天生效
 @param storageClass 修改成的存储级别
 @return 迁移时间及对象存储级别对象
 */
-(instancetype)initWithDays:(NSNumber*) days storageClass:(OBSStorageClass) storageClass;
@end

/**
 历史版本迁移时间和迁移后对象存储级别的元素
 */
@interface OBSLifecycleNoncurrentVersionTransition : OBSBaseEntity

/**
 第几天生效
 */
@property (nonatomic, strong, nonnull) NSNumber *noncurrentDays;

/**
 修改成的存储级别
 */
@property (nonatomic, assign) OBSStorageClass storageClass;

/**
 初始化历史版本迁移时间和迁移后对象存储级别的元素

 @param days 第几天生效
 @param storageClass 修改成的存储级别
 @return 历史版本迁移时间和迁移后对象存储级别对象
 */
-(instancetype)initWithDays:(NSNumber*) days storageClass:(OBSStorageClass) storageClass;
@end

/**
 生命周期配置中表示过期时间的Container
 */
@interface OBSLifecycleExpiration: OBSBaseEntity

/**
 过期时间
 */
@property (nonatomic, strong, nonnull) NSNumber *days;

/**
 初始化过期时间对象

 @param days 过期时间
 @return 过期时间对象
 */
-(instancetype)initWithDays:(NSNumber*) days;
@end

/**
 历史版本过期时间的Container
 */
@interface OBSLifecycleNoncurrentVersionExpiration: OBSBaseEntity

/**
 历史版本过期时间
 */
@property (nonatomic, strong, nonnull) NSNumber *noncurrentDays;

/**
 初始化历史版本过期时间的Container

 @param days 过期时间
 @return 历史版本过期时间的Container对象
 */
-(instancetype)initWithDays:(NSNumber*) days;
@end

/**
 生命周期配置
 */
@interface OBSLifecycleRule : OBSBaseEntity

/**
 ID
 */
@property (nonatomic, strong, nonnull) NSString *ID;

/**
 对象名前缀
 */
@property (nonatomic, strong, nonnull) NSString *prefix;

/**
 标识当前Rule是否启用
 */
@property (nonatomic, assign) OBSLifecycleStatus status;

/**
 生命周期配置中表示迁移时间和迁移后对象存储级别的元素(仅针对对象的最新版本)
 */
@property (nonatomic, strong, nonnull) NSMutableArray<OBSLifecycleTransition*> *transitionList;

/**
 生命周期配置中表示对象的历史版本迁移时间和迁移后对象存储级别的元素
 */
@property (nonatomic, strong, nonnull) NSMutableArray<OBSLifecycleNoncurrentVersionTransition*> *noncurrentVersionTransitionList;

/**
 生命周期配置中表示过期时间的Container (仅针对对象的最新版本)
 */
@property (nonatomic, strong, nonnull) OBSLifecycleExpiration *expiration;

/**
 生命周期配置中表示历史版本过期时间的Container。您可以将该动作设置在已启用多版本(或暂停)的桶，来让系统删除对象的满足特定生命周期的历史版本(仅针对历史版本)
 */
@property (nonatomic, strong, nonnull) OBSLifecycleNoncurrentVersionExpiration *noncurrentVersionExpiration;

/**
 初始化生命周期配置

 @param ID ID
 @param prefix 对象名前缀
 @param status 标识当前Rule的启用状态
 @return 生命周期配置对象
 */
-(instancetype)initWithID:(NSString*) ID prefix:(NSString*) prefix status:(OBSLifecycleStatus) status;
@end

#pragma mark bucket website

@interface OBSAbstractWebsiteConf: OBSBaseEntity
@end


/**
 配置所有请求重定向
 */
@interface OBSWebsiteConfRedirectAll : OBSAbstractWebsiteConf

/**
 重定向站点名
 */
@property (nonatomic, strong, nonnull) NSString *hostName;

/**
 请求种类
 */
@property (nonatomic, strong, nonnull) NSString *protocol;

/**
 初始化配置所有请求重定向

 @param hostName 重定向站点名
 @return 所有请求的重定向设置
 */
-(instancetype)initWithHostName:(NSString*)hostName;
@end

/**
 默认主页面
 */
@interface OBSWebsiteConfCustomIndexDocument: OBSBaseEntity

/**
 网页名
 */
@property (nonatomic, strong, nonnull) NSString *suffix;

/**
 初始化默认加载页面

 @param suffix 网页名
 @return 默认主页面
 */
-(instancetype)initWithSuffix:(NSString*)suffix;
@end


/**
 默认错误页面
 */
@interface OBSWebsiteConfCustomErrorDocument: OBSBaseEntity

/**
 网页名
 */
@property (nonatomic, strong, nonnull) NSString *key;

/**
 初始化错误加载页面

 @param key 网页名
 @return 错误加载页面
 */
-(instancetype)initWithKey:(NSString*)key;
@end


/**
 网站托管自定义规则设置
 */
@interface OBSWebsiteConfCustomRedirect: OBSBaseEntity

/**
 请求种类
 */
@property (nonatomic, strong, nonnull) NSString *protocol;

/**
 重定向站点
 */
@property (nonatomic, strong, nonnull) NSString *hostName;

/**
 重定向目录
 */
@property (nonatomic, strong, nonnull) NSString *replaceKeyPrefixWith;

/**
 重定向对象
 */
@property (nonatomic, strong, nonnull) NSString *replaceKeyWith;

/**
 重定向状态码
 */
@property (nonatomic, strong, nonnull) NSString *httpRedirectCode;
@end


/**
 重定向规则匹配的条件元素
 */
@interface OBSWebsiteConfCustomCondition: OBSBaseEntity

/**
 前缀名
 */
@property (nonatomic, strong, nonnull) NSString *keyPrefixEquals;

/**
 错误码
 */
@property (nonatomic, strong, nonnull) NSString *httpErrorCodeReturnedEquals;

/**
 初始化重定向规则匹配的元素

 @param keyPrefix 前缀名
 @return 重定向规则匹配的元素
 */
-(instancetype)initWithKeyPrefix:(NSString*) keyPrefix;

/**
 初始化重定向规则匹配的元素

 @param httpErrorCodeReturned 错误码
 @return 重定向规则匹配的元素
 */
-(instancetype)initWithKeyErrorCode:(NSString*) httpErrorCodeReturned;
@end


/**
 路由规则
 */
@interface OBSWebsiteConfCustomRoutingRule: OBSBaseEntity

/**
 重定向规则匹配的条件
 */
@property (nonatomic, strong, nonnull) OBSWebsiteConfCustomCondition *condition;

/**
 重定向配置
 */
@property (nonatomic, strong, nonnull) OBSWebsiteConfCustomRedirect *redirect;

/**
 初始化路由规则

 @param condition 重定向规则匹配的条件
 @param redirect 重定向配置
 @return 路由规则
 */
-(instancetype)initWithCondition:(OBSWebsiteConfCustomCondition*) condition redirect:(OBSWebsiteConfCustomRedirect*) redirect;
@end

/**
 自定义网站配置
 */
@interface OBSWebsiteConfCustom: OBSAbstractWebsiteConf

/**
 默认访问页面
 */
@property (nonatomic, strong, nonnull) NSMutableArray<OBSWebsiteConfCustomIndexDocument*> *indexDocumentList;

/**
 错误跳转页面
 */
@property (nonatomic, strong, nonnull) NSMutableArray<OBSWebsiteConfCustomErrorDocument*> *errorDocumentList;

/**
 路由规则表
 */
@property (nonatomic, strong, nonnull) NSMutableArray<OBSWebsiteConfCustomRoutingRule*> *routingRulesList;
@end


#pragma mark bucket versioning
// 桶多版本配置
@interface OBSBucketVersioningConfiguration : OBSBaseEntity

/**
 桶多版本状态
 */
@property (nonatomic, assign) OBSVersioningStatus status;
@end

#pragma mark bucket nofitication

/**
 定义过滤规则键值对的元素
 */
@interface OBSNotificationFilterRule : OBSBaseEntity<OBSMTLDictionaryItemOrderProtocol>

/**
 指定规则按对象名前缀或后缀进行过滤
 */
@property (nonatomic, strong, nonnull) NSString *name;

/**
 指定的对象名关键字
 */
@property (nonatomic, strong, nonnull) NSString *value;

/**
 初始化定义过滤规则键值对的元素

 @param name 指定规则按对象名前缀或后缀进行过滤
 @param value 指定的对象名关键字
 @return 过滤规则键值对的元素
 */
-(instancetype)initWithName:(NSString*) name value:(NSString*)value;
@end

/**
 通知设置
 */
@interface OBSNotificationFilter : OBSBaseEntity

/**
 通知设置的具体规则
 */
@property (nonatomic, strong, nonnull) NSMutableArray<OBSNotificationFilterRule*> *filterRuleList;
@end


/**
 配置事件通知元素的主题
 */
@interface OBSNotificationTopicConfiguration : OBSBaseEntity<OBSMTLDictionaryItemOrderProtocol>

/**
 每项事件通知配置的唯一标识
 */
@property (nonatomic, strong, nonnull) NSString *ID;

/**
 保存过滤对象名的一组规则
 */
@property (nonatomic, strong, nonnull) OBSNotificationFilter *filter;

/**
 事件通知主题的URN
 */
@property (nonatomic, strong, nonnull) NSString *topic;

/**
 事件列表
 */
@property (nonatomic, strong, nonnull) NSMutableArray<NSString*> *eventList;
@end
#pragma mark bucket tagging
@interface OBSBucketTag : OBSBaseEntity
@property (nonatomic, strong, nonnull) NSString *key;
@property (nonatomic, strong, nonnull) NSString *value;
-(instancetype)initWithKey:(NSString*) key value:(NSString*)value;
@end

#pragma mark part
@interface OBSPart: OBSBaseEntity
@property (nonatomic, strong, nonnull) NSNumber *partNumber;
@property (nonatomic, strong, nullable) NSDate *lastModified;
@property (nonatomic, strong, nonnull) NSString *etag;
@property (nonatomic, strong, nullable) NSNumber *size;
-(instancetype)initWithPartNumber:(NSNumber*) partNumber etag:(NSString*)etag;
@end
#endif  /* OBSServiceRequestCommonEntity_h */
