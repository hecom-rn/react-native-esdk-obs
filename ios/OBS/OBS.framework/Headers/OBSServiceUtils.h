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

#ifndef OBSServiceUtils_h
#define OBSServiceUtils_h
#import "CommonCrypto/CommonHMAC.h"
#import "OBSUtils.h"
@interface OBSUtils(obsservice)
+ (NSString *)calBase64md5FromData:(NSData*) data;
+ (NSData *)sha256Hash:(NSData *)data;
+ (NSData *)sha256HashString:(NSString*)string;
+ (NSString *)hexEncode:(NSString*)string;
+ (NSData*)hmacWithData:(NSData*) data withKeyData:(NSData*) key algorithm:(CCHmacAlgorithm)algorithm;
+ (NSData*)hmacWithString:(NSString*) string withKeyString:(NSString*) key algorithm:(CCHmacAlgorithm)algorithm;
+ (NSData*)hmacWithString:(NSString*) string withKeyData:(NSData*) key algorithm:(CCHmacAlgorithm)algorithm;
+ (NSData*)sha256HmacWithData:(NSData*) data withKeyData:(NSData*) key;
+ (NSData*)sha256HmacWithString:(NSString*) string withKeyString:(NSString*) key;
+ (NSData*)sha256HmacWithString:(NSString*) string withKeyData:(NSData*) key;
+ (NSDate*)dateFromString:(NSString*)string format:(NSString*) dateFormat;

+(NSDictionary*)getOBSTrueFalseDict;
+(NSDictionary*)getOBSACLPolicyDict;
+(NSDictionary*)getOBSACLDict;
+(NSDictionary*)getOBSStorageClassDict;
+(NSDictionary*)getOBSVersioningStatusDict;
+(NSDictionary*)getOBSBucketLifecycleStatusDict;
+(NSDictionary*)getOBSPolicyEffectDict;
+(NSDictionary*)getOBSMetaDataDirectiveDict;
+(NSDictionary*)getOBSRestoreTierDict;
+(NSDictionary*)getOBSReplicateStatusDict;


+(NSArray*)getOBSCORSAllowedMethodArray;

+(NSArray*)convertDictToArray:(NSDictionary *)dict orderAray:(NSArray*)orderArray;

+(__kindof OBSBaseNetworkingRequest*)convertOBSClientRequestToNetworkingRequestWithMTL:(OBSBaseRequest*) obsRequest
                                                                         configuration:(OBSBaseConfiguration*) configruation
                                                                           targetClazz:(Class) targetClazz error:(NSError**) error;
@end

#endif  /* OBSServiceUtils_h */
