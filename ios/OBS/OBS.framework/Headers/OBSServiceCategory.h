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

#ifndef OBSServiceCategory_h
#define OBSServiceCategory_h
#import "OBSServiceConstDefinition.h"

@class OBSMTLValueTransformer;

@interface OBSMTLValueTransformer(obsservice)
//+(NSValueTransformer*)obs_etagTransformer;
+(NSValueTransformer*)obs_copyEncryptionTransformer;
+(NSValueTransformer*)obs_metaDataDictTransformer;
+(NSValueTransformer*)obs_arrayStringCommaTransformer;


+(NSValueTransformer*)obs_OBSTrueFalseDictTransformer;
+(NSValueTransformer*)obs_OBSStorageClassDictTransformer;
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
