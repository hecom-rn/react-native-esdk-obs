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

#ifndef OBSBaseModel_h
#define OBSBaseModel_h

#import "OBSBaseCategory.h"
#import "OBSBaseConstDefinition.h"
#import "OBSMantle.h"
#import "OBSXMLDictionary.h"

@class OBSRequestConverter;
@protocol OBSNetworkingRequestPostProcessor;

//#pragma mark - OBSSafeMutableDictionary
//@interface OBSSafeMutableDictionary<KeyType, ObjectType>:NSMutableDictionary
//- (id) objectForKey:(id)aKey;
//- (void)setObject:(ObjectType)anObject forKey:(KeyType <NSCopying>) aKey;
//- (void)removeObjectForKey:(KeyType)aKey;
//@end
//#pragma mark - OBSOrderedMutableDictionary
//@interface OBSOrderedMutableDictionary<KeyType, ObjectType>:NSMutableDictionary
//- (id) objectForKey:(id)aKey;
//- (void)setObject:(ObjectType)anObject forKey:(KeyType <NSCopying>) aKey;
//- (void)removeObjectForKey:(KeyType)aKey;
//- (NSEnumerator*)keyEnumerator;
//- (NSUInteger)count;
//@end

#pragma mark - OBSWeakMutableArray
@interface OBSWeakMutableArray<ObjectType>:NSMutableArray
-(instancetype)initWithCapacity:(NSUInteger)numItems;
-(NSUInteger)count;
-(void)addObject:(id)anObject;
-(void)removeObject:(id)anObject;
-(void)removeObjectAtIndex:(NSUInteger)index;
-(id)objectAtIndex:(NSUInteger)index;
@end

@protocol OBSGetBodyTypeProtocol<NSObject>
+(OBSBodyType)GetBodyType;
@end

#pragma mark configuration
@interface OBSHTTPProxyConfiguration : NSObject
@property (nonatomic, assign) OBSHTTPProxyType proxyType;
@property (nonatomic, strong, nonnull) NSString  *proxyHost;
@property (nonatomic, strong, nonnull) NSNumber  *proxyPort;
@property (nonatomic, strong, nonnull) NSString  *username;
@property (nonatomic, strong, nonnull) NSString  *password;

/**
 端口代理初始化

 @param proxyType 请求类型(OBSHTTPRroxyTypeNull0 OBSHTTPRroxyTypeHTTP OBSHTTPRroxyTypeHTTPS OBSHTTPRroxyTypeHTTPAndHTTPS)
 @param host host
 @param port port
 @return 代理对象
 */
-(instancetype)initWithType:(OBSHTTPProxyType) proxyType proxyHost:(NSString*) host proxyPort:(NSUInteger) port;
-(NSDictionary*) getProxyDict;
@end

@interface OBSBaseConfiguration : NSObject
@property (nonatomic, strong, readonly, nonnull) NSURL *url;
@property (nonatomic, strong) NSString *lastUploadPath;
@property (nonatomic, strong) NSData *uploadAllData;
@property (nonatomic, assign) BOOL trustUnsafeCert;
@property (nonatomic, assign) uint32_t maxConcurrentCommandRequestCount;
@property (nonatomic, assign) uint32_t maxConcurrentUploadRequestCount;
@property (nonatomic, assign) uint32_t maxConcurrentDownloadRequestCount;

@property (nonatomic, strong) NSURLSessionConfiguration * commandSessionConfiguration;
@property (nonatomic, strong) NSURLSessionConfiguration * uploadSessionConfiguration;
@property (nonatomic, strong) NSURLSessionConfiguration * downloadSessionConfiguration;
@property (nonatomic, strong) NSURLSessionConfiguration * backgroundUploadSessionConfiguration;
@property (nonatomic, strong) NSURLSessionConfiguration * backgroundDownloadSessionConfiguration;

@property (nonatomic, strong) OBSHTTPProxyConfiguration * proxyConfig;
@property (nonatomic, strong) NSMutableArray<id<OBSNetworkingRequestPostProcessor>> * customProcessors;
@property (nonatomic, assign) BOOL enableURLEncoding;
-(instancetype) initWithURL:(NSURL*) url;
-(NSArray*)getDefaultPostProcessors;
@end

#pragma mark MTLJSONAdaptor and XML Parser

@protocol OBSMTLDictionaryItemOrderProtocol <NSObject>
@required
+(NSArray*)DictionaryOrderList;
@end

@interface OBSMTLJSONAdapterCustomized: OBSMTLJSONAdapter

-(void)setModelClass:(Class)clazz;
-(Class)modelClass;

-(void)setJSONKeyPathsByPropertyKey:(NSDictionary*)dict;
-(NSDictionary*)JSONKeyPathsByPropertyKey;

-(void)setValueTransformersByPropertyKey:(NSDictionary*)dict;
-(NSDictionary*)valueTransformersByPropertyKey;

-(void)setJSONAdaptersByModelClass:(NSMapTable*)dict;
-(NSMapTable*)JSONAdaptersByModelClass;

- (OBSMTLJSONAdapter *)JSONAdapterForModelClass:(Class)modelClass error:(NSError **)error;
@end

@interface OBSXMLDictionaryParserWithFormat: OBSXMLDictionaryParser
+ (NSString *)OBSXMLStringForNode:(id)node withNodeName:(NSString *)nodeName ident:(NSInteger) ident;
- (void)endText;
-(void)setRoot:(NSMutableDictionary<NSString *, id>*) root;
-(NSMutableDictionary<NSString *, id>*)root;
-(void)setStack:(NSMutableArray*) stack;
-(NSMutableArray*)stack;
@end

#pragma mark - Base Model


@protocol OBSRequestConvert
@required
-(OBSBaseNetworkingRequest*)convertToNetworkingRequest:(OBSBaseConfiguration*) configuration error:(NSError**) error;
@end

@interface OBSAbstractModel : OBSMTLModel<OBSMTLJSONSerializing>
@end

@interface OBSBaseEntity: OBSAbstractModel
@end

@interface OBSResponseHeaderEntity: OBSBaseEntity
@end

@interface OBSResponseURLEntity: OBSBaseEntity
@end

@interface OBSResponseBodyEntity: OBSBaseEntity
@end

#pragma mark - Base Requests


/**
 OBS网络请求基类
 */
@interface OBSBaseRequest: OBSAbstractModel<OBSRequestConvert>

/**
 请求ID
 */
@property (nonatomic, strong, nonnull) NSString *requestID;

/**
 是否取消
 */
@property (readonly, nonatomic, assign) BOOL isCancelled;

/**
 请求类型
 */
@property (nonatomic, assign) OBSProtocolType protocolType;


/**
 取消请求
 */
-(void)cancel;

/**
 判断是否是一个合法的请求

 @param error 抛出的错误
 @return 返回是否为合法请求
 */
-(BOOL)validateRequest:(NSError**)error;
@end

#pragma mark - Base Response

/**
 OBS网络响应基类
 */
@interface OBSBaseResponse: OBSAbstractModel<OBSGetBodyTypeProtocol>

/**
 响应状态码
 */
@property (nonatomic, strong, nonnull)  NSString *statusCode;

/**
 响应头部
 */
@property (nonatomic, strong, nullable) NSDictionary *headers;

/**
 请求ID
 */
@property (nonatomic, strong, nullable) NSString *requestID;
@end


#endif  /* OBSBaseModel_h */
