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

#ifndef OBS_h
#define OBS_h
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
    //! Project version number for OBS.
FOUNDATION_EXPORT double OBSVersionNumber;

    //! Project version string for OBS.
FOUNDATION_EXPORT unsigned char OBSVersionString[];
NS_ASSUME_NONNULL_END

#import "OBSBaseNetworking.h"
#import "OBSClient.h"
#import "OBSServiceBaseModel.h"
#import "OBSUtils.h"
#import "OBSBolts.h"
#import "OBSServiceCredentialProvider.h"
#import "OBSMantle.h"
#import "OBSLogging.h"

#import "OBSServiceCommonEntities.h"


#pragma mark service models
#pragma mark presign
#import "OBSPreSignedURLModel.h"

#pragma mark bucket
#import "OBSListBucketsModel.h"
#import "OBSCreateBucketModel.h"


#import "OBSGetBucketMetaDataModel.h"
#import "OBSGetBucketLocationModel.h"
#import "OBSGetBucketStorageInfoModel.h"

#import "OBSSetBucketQuotaModel.h"
#import "OBSGetBucketQuotaModel.h"

#import "OBSSetBucketACLModel.h"
#import "OBSGetBucketACLModel.h"

#import "OBSSetBucketCORSModel.h"
#import "OBSGetBucketCORSModel.h"
#import "OBSDeleteBucketCORSModel.h"

#import "OBSSetBucketStoragePolicyModel.h"
#import "OBSGetBucketStoragePolicyModel.h"

#import "OBSSetBucketLoggingModel.h"
#import "OBSGetBucketLoggingModel.h"

#import "OBSSetBucketPolicyModel.h"
#import "OBSGetBucketPolicyModel.h"
#import "OBSDeleteBucketPolicyModel.h"

#import "OBSSetBucketLifecycleModel.h"
#import "OBSGetBucketLifecycleModel.h"
#import "OBSDeleteBucketLifecycleModel.h"

#import "OBSSetBucketWebsiteModel.h"
#import "OBSGetBucketWebsiteModel.h"
#import "OBSDeleteBucketWebsiteModel.h"

#import "OBSSetBucketVersioningModel.h"
#import "OBSGetBucketVersioningModel.h"

#import "OBSSetBucketNotificationModel.h"
#import "OBSGetBucketNotificationModel.h"

#import "OBSOptionsBucketModel.h"

#import "OBSListMultipartUploadsModel.h"

#import "OBSSetBucketTaggingModel.h"
#import "OBSGetBucketTaggingModel.h"
#import "OBSDeleteBucketTaggingModel.h"

#import "OBSDeleteBucketModel.h"
#import "OBSReplicateBucketModel.h"
#import "OBSGetReplicateBucketModel.h"
#import "OBSDeleteReplicateBucketModel.h"
#import "OBSAppendObjectModel.h"

#pragma mark object
#import "OBSPutObjectModel.h"
#import "OBSGetObjectModel.h"
#import "OBSCopyObjectModel.h"

#import "OBSSetObjectACLModel.h"
#import "OBSGetObjectACLModel.h"

#import "OBSListObjectsModel.h"
#import "OBSListObjectsVersionsModel.h"

#import "OBSGetObjectMetaDataModel.h"
#import "OBSOptionsObjectModel.h"
#import "OBSRestoreObjectModel.h"

#import "OBSInitiateMultipartUploadModel.h"
#import "OBSUploadPartModel.h"
#import "OBSCopyPartModel.h"
#import "OBSListPartsModel.h"
#import "OBSCompleteMultipartUploadModel.h"
#import "OBSAbortMultipartUploadModel.h"

#import "OBSDeleteObjectModel.h"
#import "OBSDeleteObjectsModel.h"

#pragma mark additional 
#import "OBSDownloadFileModel.h"
#import "OBSUploadFileModel.h"

#import "OBSUploadFileModel.h"
#import "OBSGetBucketLocationModel.h"
#import "OBSGetBucketStorageInfoModel.h"
#import "OBSSetBucketQuotaModel.h"
#import "OBSGetBucketStorageInfoModel.h"
#import "OBSServiceUtils.h"
#import "OBSListPartsModel.h"
#import "OBSAbortMultipartUploadModel.h"
#import "OBSCompleteMultipartUploadModel.h"
#import "OBSDownloadFileModel.h"
#import "OBSDeleteObjectModel.h"
#import "OBSDeleteObjectsModel.h"
#endif  /* OBS_h */
