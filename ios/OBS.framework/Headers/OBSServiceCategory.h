//
//  OBSServiceCategory.h
//  OBS
//
//  Created by MaxZhang on 14/11/2017.
//  Copyright © 2017 obs. All rights reserved.
//

#ifndef OBSServiceCategory_h
#define OBSServiceCategory_h
#import "OBSServiceConstDefinition.h"

@class OBSMTLValueTransformer;

@interface OBSMTLValueTransformer(obsservice)
//+(NSValueTransformer*)obs_etagTransformer;
+(NSValueTransformer*)obs_copyEncryptionTransformer;
+(NSValueTransformer*)obs_metaDataDictTransformer;
+(NSValueTransformer*)v2_metaDataDictTransformer;
+(NSValueTransformer*)obs_arrayStringCommaTransformer;


+(NSValueTransformer*)obs_OBSTrueFalseDictTransformer;
+(NSValueTransformer*)obs_OBSStorageClassDictTransformer;
+(NSValueTransformer*)obs_OBSContentTypeTransformer;
+(NSValueTransformer*)obs_OBSACLDictTransformer;
+(NSValueTransformer*)obs_OBSBucketLifecycleStatusDictTransformer;
+(NSValueTransformer*)obs_OBSVersioningStatusDictTransformer;
+(NSValueTransformer*)obs_OBSACLPolicyDictTransformer;
+(NSValueTransformer*)obs_OBSReplicateStatusTransformer;

@end

@interface NSString (obsservice)
+ (nullable instancetype)obs_initWithOBSACLUserType:(OBSACLUserType) aclUserType;
@end


#endif  /* OBSServiceCategory_h */
