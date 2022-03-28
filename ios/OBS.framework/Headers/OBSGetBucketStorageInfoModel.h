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

#ifndef OBSGetBucketStorageInfoModel_h
#define OBSGetBucketStorageInfoModel_h
#import "OBSBaseNetworking.h"
#import "OBSClient.h"
#import "OBSServiceBaseModel.h"
#import "OBSServiceConstDefinition.h"
#import "OBSServiceCommonEntities.h"

@class OBSEncryptionTypeCustomer;


/**
 获取桶存量信息
 */
@protocol OBSGetBucketStorageInfoProtocol <NSObject>
@end

#pragma mark - entity

@interface OBSBucketStorageInfo: OBSBaseEntity

/**
 存量大小
 */
@property (nonatomic, strong, nonnull) NSNumber *size;

/**
 对象个数
 */
@property (nonatomic, strong, nonnull) NSNumber *objectNumber;
@end

#pragma mark - request

/**
 获取桶存量信息
 */
@interface OBSGetBucketStorageInfoRequest : OBSBaseRequest<OBSGetBucketStorageInfoProtocol>

/**
 桶名
 */
@property (nonatomic, strong, nonnull) NSString *bucketName;

/**
 获取桶存量信息request初始化

 @param bucketName 桶名
 @return 获取桶存量信息request
 */
-(instancetype)initWithBucketName:(NSString*) bucketName;
@end

#pragma mark - networking request
@interface OBSNetworkingGetBucketStorageInfoRequest : OBSServiceNetworkingCommandRequest
@end

    //response
#pragma mark - response

/**
 获取桶存量信息response
 */
@interface OBSGetBucketStorageInfoResponse: OBSServiceResponse

/**
 桶存量信息
 */
@property (nonatomic, strong, nonnull) OBSBucketStorageInfo *storageInfo;
@end

    //client method
#pragma mark - client method
@interface OBSClient(getBucketStorageInfo)

/**
 获取桶存量信息

 @param request 获取桶存量信息request
 @param completionHandler 获取桶存量信息回调
 @return OBSBFTask
 */
- (OBSBFTask*)getBucketStorageInfo:(__kindof OBSBaseRequest<OBSGetBucketStorageInfoProtocol>*)request
              completionHandler:(void (^)(OBSGetBucketStorageInfoResponse  * response, NSError * error))completionHandler;
@end



#endif /* OBSGetBucketStorageInfoModel_h */
