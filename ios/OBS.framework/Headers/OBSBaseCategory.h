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

#ifndef OBSBaseCategory_h
#define OBSBaseCategory_h
#import "OBSBaseConstDefinition.h"
#import "OBSMTLJSONAdapter.h"
#import "OBSMTLValueTransformer.h"
@class OBSBaseNetworkingRequest;
@class OBSBFTaskCompletionSource;



@interface NSString (OBS)
    //data to NSString with utf8 encoding
+ (nullable instancetype)obs_initWithDataUTF8:(NSData *)data;
    //OBSHTTPMethod enum to string
+ (nullable instancetype)obs_initWithOBSHTTPMethod:(OBSHTTPMethod) HTTPMethod;
    //url string remove tailing slash
- (nullable NSString*)obs_removeTailSlash;
    //url string append query string
//- (nullable NSString*)obs_stringByAppendingQueryStringForURL:(NSDictionary *)queryDict;
    //trim spaces
- (nullable NSString*)obs_trim;

-(nullable NSString*)stringWithRepeatTimes:(NSInteger) times;

    //bool with string
//-(BOOL) obs_boolWithString;
    //OBSHTTPMethod string to enum
//- (OBSHTTPMethod)obs_OBSHTTPMethodWithString;
    //OBSBodyType string to enum
//-(OBSBodyType)obs_OBSBodyTypeWithString;
    //URL encoding
-(nullable NSString*)obs_stringWithURLEncodingAllowedSet;
//-(nullable NSString*)obs_stringWithURLEncodingAll;
//-(nullable NSString*)obs_stringWithURLEncodingAllowedAlphanumeric;
    //string substitue
-(nullable NSString*)obs_stringSubstituteWithDict:(NSDictionary*) dict;
    //xml encoding
//-(nullable NSString*)obs_XMLEncodeString;
@end

@interface NSDictionary(OBS)
//-(NSString*)obs_convertDictionaryToXMLWithStartNode:(NSString*)startNode;
-(NSString*)obs_XMLString;
- (NSString *)obs_innerXML:(NSInteger) ident;
- (nullable NSDictionary *)obs_childNodes;
- (nullable NSDictionary<NSString *, NSString *> *)obs_attributes;
@end

@interface NSMutableArray(OBS)
-(id)pop;
-(void)push:(id)obj;
@end

@interface NSURLSessionTask(OBS)
-(OBSBaseNetworkingRequest*)obsNetworkingRequest;
-(void)setObsNetworkingRequest:(OBSBaseNetworkingRequest*) networkingRequest;
@end

@interface OBSMTLJSONAdapter(OBS)
+ (NSDictionary *)valueTransformersForModelClass:(Class)modelClass;
@end

@interface OBSMTLValueTransformer(OBS)
//+(NSValueTransformer*)obs_mtl_nsnumberIntegerTransformer;
+(NSValueTransformer*)obs_mtl_nsnumberLongLongTransformer;
+(NSValueTransformer*)obs_mtl_nsnumberUIntegerTransformer;
+(NSValueTransformer*)obs_mtl_nsdateRFC1123Transformer;
+(NSValueTransformer*)obs_mtl_nsdateIOS8601Format3Transformer;
//+(NSValueTransformer*)obs_mtl_filterNullStringTransformer;
@end
#endif /* OBSBaseCategory_h */
