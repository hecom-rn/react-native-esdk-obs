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

#ifndef OBSServiceBaseModel_h
#define OBSServiceBaseModel_h
#import "OBSBaseModel.h"
#import "OBSBaseNetworking.h"
#import "OBSServiceConstDefinition.h"


@class OBSBaseConfiguration;
@class OBSBaseNetworkingRequest;
@protocol OBSServiceCredentialProvider;

#pragma mark -  configuration
@interface OBSServiceConfiguration : OBSBaseConfiguration

/**
 对象存储区域
 */
@property (nonatomic, strong, nonnull) NSString  *region;

/**
 OBS操作凭证
 */
@property (atomic, strong, nonnull) id<OBSServiceCredentialProvider> credentialProvider;

/**
 是否使用虚拟主机
 */
@property (nonatomic, assign) BOOL useVirtualhost;

/**
 是否使用自定义域名
 */
@property (nonatomic, assign) BOOL useCustomDomain;

/**
 域名访问模式
 */
@property (nonatomic, assign) OBSDomainMode defaultDomainMode;

/**
 是否采用Date头域
 */
@property (nonatomic, assign) BOOL useDateHeader;

/**
 初始化服务配置 url初始化

 @param url url
 @param credentialProvider OBS操作凭证
 @return 服务配置对象
 */
-(instancetype) initWithURL: (NSURL*) url credentialProvider: (id<OBSServiceCredentialProvider>) credentialProvider;

/**
 初始化服务配置 url字符串

 @param urlString url字符串
 @param credentialProvider OBS操作凭证
 @return 服务配置对象
 */
-(instancetype) initWithURLString: (NSString*) urlString credentialProvider: (id<OBSServiceCredentialProvider>) credentialProvider;
@end


#pragma mark -  networking request

@interface OBSServiceNetworkingRequest : OBSBaseNetworkingRequest
@property (nonatomic, assign) BOOL authenticationRequired;
@property (nonatomic, assign) BOOL calcBodyHash;
@end

@interface OBSServiceNetworkingCommandRequest : OBSNetworkingCommandRequest
@property (nonatomic, assign) BOOL authenticationRequired;
@property (nonatomic, assign) BOOL calcBodyHash;
@end

@interface OBSServiceNetworkingUploadDataRequest : OBSNetworkingUploadDataRequest
@property (nonatomic, assign) BOOL authenticationRequired;
@property (nonatomic, assign) BOOL calcBodyHash;
@end

@interface OBSServiceNetworkingUploadFileRequest : OBSNetworkingUploadFileRequest
@property (nonatomic, assign) BOOL authenticationRequired;
@property (nonatomic, assign) BOOL calcBodyHash;
@end

@interface OBSServiceNetworkingDownloadFileRequest : OBSNetworkingDownloadFileRequest
@property (nonatomic, assign) BOOL authenticationRequired;
@property (nonatomic, assign) BOOL calcBodyHash;
@end

@interface OBSServiceNetworkingDownloadDataRequest : OBSNetworkingDownloadDataRequest
@property (nonatomic, assign) BOOL authenticationRequired;
@property (nonatomic, assign) BOOL calcBodyHash;
@end

#pragma mark - additional post processors
@interface OBSFlattenHeadersDictPostProcessor: NSObject<OBSNetworkingRequestPostProcessor>
@end

@interface OBSAddingContentMD5HeaderPostProcessor: NSObject<OBSNetworkingRequestPostProcessor>
@end

@interface OBSCustomMetaHeaderPreProcessor: NSObject<OBSNetworkingResponsePreProcessor>
@end

#pragma mark - Request
@interface OBSCORSRequest: OBSBaseRequest
@property (nonatomic, strong, nonnull) NSString *origin;
@property (nonatomic, strong, nonnull) NSArray<NSString*> *accessControlRequestHeadersList;
@end

#pragma mark - Response

/**
 OBS服务配置响应
 */
@interface OBSServiceResponse: OBSBaseResponse

/**
 xamzRequestID
 */
@property (nonatomic, strong, nullable) NSString *xRequestID;
@end

@interface OBSCORSResponse: OBSServiceResponse
@property (nonatomic, strong, nonnull) NSString *accessControlAllowOrigin;
@property (nonatomic, strong, nonnull) NSArray<NSString*> *accessControlAllowHeadersList;
@property (nonatomic, strong, nonnull) NSNumber *accessControlMaxAge;
@property (nonatomic, strong, nonnull) NSArray<NSString*> *accessControlAllowMethodsList;
@property (nonatomic, strong, nonnull) NSArray<NSString*> *accessControlExposeHeadersList;
@property (nonatomic, assign) BOOL accessControlAllowCredentials;
@end

    //config
#endif  /* OBSServiceBaseModel_h */
