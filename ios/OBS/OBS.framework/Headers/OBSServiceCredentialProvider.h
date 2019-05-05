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

#ifndef OBSCredentialProvider_h
#define OBSCredentialProvider_h
#import "OBSBaseNetworking.h"
#import "OBSServiceConstDefinition.h"

@protocol OBSServiceCredentialProvider <OBSNetworkingRequestPostProcessor>

@required
@property (nonatomic, strong, nonnull) NSString  *accessKey;
@property (nonatomic, strong, nonnull) NSString  *secretKey;

@optional
@property (nonatomic, strong, nonnull) NSString  *stsToken;
@property (nonatomic, strong, nonnull) NSDate  *expiration;
@property (nonatomic, assign) OBSProtocolType protocolType;

- (void)refresh;
@end


@interface OBSStaticCredentialProvider :  NSObject <OBSServiceCredentialProvider>

@property (nonatomic, strong, nonnull) NSString  *accessKey;
@property (nonatomic, strong, nonnull) NSString  *secretKey;
@property (nonatomic, assign) OBSAuthVersion authVersion;
@property (nonatomic, assign) OBSProtocolType protocolType;
@property (nonatomic, strong, nonnull) NSString *securityToken;
@property (nonatomic,assign) BOOL isGetProtocol;

/**
 使用AccessKey初始化凭证 默认采用V2鉴权
 
 @param accessKey 云服务控制台提供的accessKey
 @param secretKey 云服务控制台提供的secreKey
 @return 初始化完成的对象
 */
- (instancetype)initWithAccessKey:(NSString *)accessKey secretKey:(NSString *)secretKey;

/**
 使用AccessKey初始化凭证
 
 @param accessKey 云服务控制台提供的accessKey
 @param secretKey 云服务控制台提供的secreKey
 @param authVersion 鉴权版本(OBSAuthVersionV2 OBSAuthVersionV4)
 @return 初始化完成的对象
 */
- (instancetype)initWithAccessKey:(NSString *)accessKey secretKey:(NSString *)secretKey authVersion:(OBSAuthVersion) authVersion;
@end

@interface OBSSTSCredentialProvider : NSObject <OBSServiceCredentialProvider>
@property (nonatomic, strong, nonnull) NSString  *accessKey;
@property (nonatomic, strong, nonnull) NSString  *secretKey;
@property (nonatomic, assign) OBSAuthVersion authVersion;
@property (nonatomic, strong, nonnull) NSString  *stsToken;


/**
 临时访问凭证初始化 默认采用V4鉴权

 @param accessKey 临时访问密钥中的accessKey
 @param secretKey 临时访问密钥中的secreKey
 @param stsToken 安全令牌
 @return 初始化完成的对象
 */
- (instancetype)initWithAccessKey:(NSString *)accessKey secretKey:(NSString *)secretKey stsToken:(NSString *)stsToken;


/**
 临时访问凭证初始化

 @param accessKey 临时访问密钥中的accessKey
 @param secretKey 临时访问密钥中的secreKey
 @param stsToken 安全令牌
 @param authVersion 鉴权版本(OBSAuthVersionV2 OBSAuthVersionV4)
 @return 初始化完成的对象
 */
- (instancetype)initWithAccessKey:(NSString *)accessKey
                        secretKey:(NSString *)secretKey
                         stsToken:(NSString *)stsToken
                      authVersion:(OBSAuthVersion) authVersion;
@end

NSArray *GetCanonicalHeadersKey(NSDictionary *headers, NSArray *additionalKeys,BOOL isOBSProtocol);

NSString *GetCanonicalHeaderString(NSDictionary *headers ,NSArray *keyArray);

NSString *V4GetSignedHeaderString(NSDictionary *headers,  NSArray *keyArray);

#endif  /* OBSCredentialProvider_h */
