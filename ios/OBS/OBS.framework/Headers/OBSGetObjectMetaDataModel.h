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

#ifndef OBSGetObjectMetaDataModel_h
#define OBSGetObjectMetaDataModel_h
#import "OBSBaseNetworking.h"
#import "OBSClient.h"
#import "OBSServiceBaseModel.h"
#import "OBSServiceConstDefinition.h"

@class OBSAbstractEncryption;


/**
 获取对象属性
 */
@protocol OBSGetObjectMetaDataProtocol <NSObject>

/**
 桶名
 */
@property (nonatomic, strong, nonnull) NSString *bucketName;

/**
 对象名
 */
@property (nonatomic, strong, nonnull) NSString *objectKey;
@end

#pragma mark - request

/**
 获取对象属性request
 */
@interface OBSGetObjectMetaDataRequest : OBSCORSRequest<OBSGetObjectMetaDataProtocol>

/**
 桶名
 */
@property (nonatomic, strong, nonnull) NSString *bucketName;

/**
 对象key
 */
@property (nonatomic, strong, nonnull) NSString *objectKey;

/**
 多版本ID
 */
@property (nonatomic, strong, nonnull) NSString *versionID;

/**
 加密方式
 */
@property (nonatomic, strong, nonnull) __kindof OBSAbstractEncryption *encryption;

/**
 初始化获取对象属性request

 @param bucketName 桶名
 @param objectKey 对象KEY
 @return 获取对象元数据request
 */
-(instancetype)initWithBucketName:(NSString*) bucketName objectKey: (NSString*) objectKey;
@end

#pragma mark - networking request
@interface OBSNetworkingGetObjectMetaDataRequest : OBSServiceNetworkingCommandRequest
@end

    //response
#pragma mark - response

/**
 获取对象属性response
 */
@interface OBSGetObjectMetaDataResponse: OBSCORSResponse

/**
 对象etag
 */
@property (nonatomic, strong, nonnull) NSString *etag;

/**
 对象大小
 */
@property (nonatomic, strong, nonnull) NSNumber *size;

/**
 对象过期时间
 */
@property (nonatomic, strong, nonnull) NSString *expiration;

/**
 重定向网址
 */
@property (nonatomic, strong, nonnull) NSString *websiteRedirectLocation;

/**
 版本号
 */
@property (nonatomic, strong, nonnull) NSString *versionID;

/**
 最后修改时间
 */
@property (nonatomic, strong, nonnull) NSDate *lastModified;

/**
 加密方式
 */
@property (nonatomic, strong, nonnull) __kindof OBSAbstractEncryption *encryption;

/**
 存储类型
 */
@property (nonatomic, assign) OBSStorageClass storageClass;

/**

 对象为归档存储类型，并且处于正在取回或已经取回时，表示对象的取回状态
 */
@property (nonatomic, strong, nonnull) NSString *restore;

/**
 对象元数据字典
 */
@property (nonatomic, strong, nullable) NSDictionary *metaDataDict;
@end

    //client method
#pragma mark - client method
@interface OBSClient(getObjectMetaData)

/**
 获取对象属性

 @param request 获取对象属性request
 @param completionHandler 获取对象属性回调
 @return OBSBFTask
 */
- (OBSBFTask*)getObjectMetaData:(__kindof OBSBaseRequest<OBSGetObjectMetaDataProtocol>*)request
              completionHandler:(void (^)(OBSGetObjectMetaDataResponse  * response, NSError * error))completionHandler;
@end
#endif  /* OBSGetObjectMetaDataModel_h */
