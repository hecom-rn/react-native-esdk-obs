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

#ifndef OBSDeleteObjectModel_h
#define OBSDeleteObjectModel_h

#import "OBSBaseModel.h"
#import "OBSBaseNetworking.h"
#import "OBSClient.h"
#import "OBSServiceBaseModel.h"
#import "OBSServiceCommonEntities.h"

#pragma mark - request

/**
 删除对象
 */
@protocol OBSDeleteObjectProtocol
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
@end


/**
 删除对象request
 */
@interface OBSDeleteObjectRequest: OBSBaseRequest<OBSDeleteObjectProtocol>

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
 初始化删除对象request

 @param bucketName 桶名
 @param objectKey 对象KEY
 @return 删除对象request
 */
-(instancetype)initWithBucketName:(NSString*) bucketName objectKey:(NSString*) objectKey;
@end

#pragma mark - networking request
@interface OBSDeleteObjectRequestNetworking : OBSServiceNetworkingCommandRequest
@end

    //response
#pragma mark - response

/**
 删除对象response
 */
@interface OBSDeleteObjectResponse: OBSServiceResponse

/**
 删除标记
 */
@property (nonatomic, assign) BOOL deleteMarker;

/**
 多版本ID
 */
@property (nonatomic, strong, nonnull) NSString *versionID;
@end


#pragma mark - client method
@interface OBSClient(deleteObject)

/**
 删除对象

 @param request 删除对象request
 @param completionHandler 删除对象回调
 @return OBSBFTask
 */
- (OBSBFTask*)deleteObject:(__kindof OBSBaseRequest<OBSDeleteObjectProtocol>*)request
         completionHandler:(void (^)(OBSDeleteObjectResponse * response, NSError * error))completionHandler;
@end
#endif /* OBSDeleteObjectModel_h */
