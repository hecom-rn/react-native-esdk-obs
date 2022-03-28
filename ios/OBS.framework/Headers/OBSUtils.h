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

#ifndef OBSUtils_h
#define OBSUtils_h
@class OBSBaseRequest;
@class OBSBaseNetworkingRequest;
@class OBSBaseConfiguration;
@class OBSServiceNetworkingRequest;

@interface OBSUtils : NSObject
//+ (NSDictionary*)convertXMLStringToDict:(NSString*) xmlString error:(NSError**) error;
+ (NSDictionary*)convertXMLDataToDict:(NSData*) xmlData error:(NSError**) error;
+ (NSString*)convertDictToXMLString:(NSDictionary*) dict error:(NSError**) error;

+(__kindof OBSBaseNetworkingRequest*)convertOBSRequestToNetworkingRequestWithMTL:(OBSBaseRequest*) obsRequest
                                                                   configuration:(OBSBaseConfiguration*) configruation
                                                                     targetClazz:(Class) targetClazz
                                                                           error:(NSError**) error;

+(NSMutableDictionary*)getDataDict:(OBSBaseRequest*) obsRequest
                     configuration:(OBSBaseConfiguration*) configuration
                       targetClazz:(Class) targetClazz
                             error:(NSError**) error;

+(OBSBaseNetworkingRequest*)getNetworkingRequestFromDict:(Class) networkingClazz
                                                dataDict:(NSDictionary*) dataDict
                                           configuration:(OBSBaseConfiguration*) configuration
                                                   error:(NSError**) error;

+(NSString*)generateQueryString:(NSDictionary*) queryParameters;
+(NSString*)V4PresignGenerateQueryString:(NSDictionary*) queryParameters;

+ (NSDateFormatter *)getDateFormatterRFC1123;
+ (NSDateFormatter *)getDateFormatterISO8601Format3;
+ (NSString *)getDateStringWithFormatString:(NSDate*) date format:(NSString*) dateFormat;

// 新增CDN自定义域名处理函数
+ (NSString *)v2CDNCustomDomain:(OBSServiceNetworkingRequest*) request;
+ (void)v4CDNCustomDomain:(OBSServiceNetworkingRequest*) request;
@end

#endif  /* OBSUtils_h */
