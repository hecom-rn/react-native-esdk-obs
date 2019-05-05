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

#ifndef OBSRestoreObjectModel_h
#define OBSRestoreObjectModel_h
#import "OBSBaseModel.h"
#import "OBSBaseNetworking.h"
#import "OBSClient.h"
#import "OBSServiceBaseModel.h"
#import "OBSServiceCommonEntities.h"


#pragma mark - request

/**
 取回归档存储对象
 */
@protocol OBSRestoreObjectProtocol
@required

/**
 桶名
 */
@property (nonatomic, strong, nonnull) NSString *bucketName;

/**
 对象名
 */
@property (nonatomic, strong, nonnull) NSString *objectKey;

/**
 多版本ID
 */
@property (nonatomic, strong, nonnull) NSString *versionID;

/**
 有效时间
 */
@property (nonatomic, strong, nonnull) NSNumber *storeDays;

/**
 取回方式
 */
@property (nonatomic, assign) OBSRestoreTier restoreTier;


/**
 对象
 */

@property (nonatomic, strong, nonnull) NSString *restore;

@end

/**
 取回归档存储对象request
 */
@interface OBSRestoreObjectRequest: OBSBaseRequest<OBSRestoreObjectProtocol>

/**
 桶名
 */
@property (nonatomic, strong, nonnull) NSString *bucketName;

/**
 对象KEY
 */
@property (nonatomic, strong, nonnull) NSString *objectKey;

/**
 多版本ID
 */
@property (nonatomic, strong, nonnull) NSString *versionID;

/**
 取回对象的保存时间
 */
@property (nonatomic, strong, nonnull) NSNumber *storeDays;

/**
 取回方式
 
 Expedited表示快速取回对象，取回耗时1~5min，
 Standard表示标准取回对象，取回耗时3~5h
 */
@property (nonatomic, assign) OBSRestoreTier restoreTier;
@property (nonatomic, strong, nonnull) NSString *restore;


/**
 初始化取回归档存储对象request

 @param bucketName 桶名
 @param objectKey 对象KEY
 @param storeDays 保存时间
 @return 取回归档存储对象request
 */
-(instancetype)initWithBucketName:(NSString*) bucketName
                        objectKey:(NSString*) objectKey
                        storeDays:(NSNumber*) storeDays;
@end

#pragma mark - networking request
@interface OBSRestoreObjectRequestNetworking : OBSServiceNetworkingCommandRequest
@end

    //response
#pragma mark - response

/**
 取回归档存储对象response
 */
@interface OBSRestoreObjectResponse: OBSServiceResponse
@end


#pragma mark - client method
@interface OBSClient(restoreObject)

/**
 取回归档存储对象

 @param request 取回归档存储对象request
 @param completionHandler 取回归档存储对象回调
 @return OBSBFTask
 */
- (OBSBFTask*)restoreObject:(__kindof OBSBaseRequest<OBSRestoreObjectProtocol>*)request
         completionHandler:(void (^)(OBSRestoreObjectResponse  * response, NSError * error))completionHandler;
@end

#endif /* OBSRestoreObjectModel_h */
