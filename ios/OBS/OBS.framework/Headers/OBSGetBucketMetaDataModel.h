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

#ifndef OBSGetBucketMetaDataModel_h
#define OBSGetBucketMetaDataModel_h
#import "OBSBaseNetworking.h"
#import "OBSClient.h"
#import "OBSServiceBaseModel.h"
#import "OBSServiceConstDefinition.h"

@class OBSEncryptionTypeCustomer;

/**
 获取桶元数据
 */
@protocol OBSGetBucketMetaDataProtocol <NSObject>
@end

#pragma mark - request

/**
 获取桶元数据request
 */
@interface OBSGetBucketMetaDataRequest : OBSCORSRequest<OBSGetBucketMetaDataProtocol>

/**
 桶名
 */
@property (nonatomic, strong, nonnull) NSString *bucketName;

/**
 初始化获取桶元数据request

 @param bucketName 桶名
 @return 获取桶元数据request
 */
-(instancetype)initWithBucketName:(NSString*) bucketName;
@end

#pragma mark - networking request
@interface OBSNetworkingGetBucketMetaDataRequest : OBSServiceNetworkingCommandRequest
@end

    //response
#pragma mark - response

/**
 获取桶元数据response
 */
@interface OBSGetBucketMetaDataResponse: OBSCORSResponse

/**
 桶区域位置
 */
@property (nonatomic, strong, nonnull) NSString *region;

/**
 桶存储类型
 */
@property (nonatomic, assign)  OBSStorageClass defaultStorageClass;
@end

    //client method
#pragma mark - client method
@interface OBSClient(getBucketMetaData)

/**
 获取桶元数据

 @param request 获取桶元数据request
 @param completionHandler 获取桶元数据回调
 @return OBSBFTask
 */
- (OBSBFTask*)getBucketMetaData:(__kindof OBSBaseRequest<OBSGetBucketMetaDataProtocol>*)request
              completionHandler:(void (^)(OBSGetBucketMetaDataResponse  * response, NSError * error))completionHandler;
@end

#endif /* OBSGetBucketMetaDataModel_h */
