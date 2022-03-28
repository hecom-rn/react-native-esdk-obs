//
//  OBSServiceUtils.h
//  OBS
//
//  Created by MaxZhang on 07/11/2017.
//  Copyright © 2017 obs. All rights reserved.
//

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
+(NSDictionary*)getOBSContetnTypeDict;
+(NSDictionary*)getOBSContentType;
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
