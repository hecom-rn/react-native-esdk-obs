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

#ifndef OBSDeleteObjectssModel_h
#define OBSDeleteObjectssModel_h

#import "OBSBaseModel.h"
#import "OBSBaseNetworking.h"
#import "OBSClient.h"
#import "OBSServiceBaseModel.h"
#import "OBSServiceCommonEntities.h"

#pragma mark - entity
@interface OBSObjectToDelete : OBSBaseEntity
@property (nonatomic, strong, nonnull) NSString *key;
@property (nonatomic, strong, nonnull) NSString *versionID;
-(instancetype)initWithObjectKey:(NSString*) key;
-(instancetype)initWithObjectKey:(NSString*) key versionID:(NSString*)versionID;
@end

@interface OBSObjectDeleted : OBSBaseEntity
@property (nonatomic, strong, nonnull) NSString *key;
@property (nonatomic, strong, nonnull) NSString *versionID;
@property (nonatomic, assign) BOOL deleteMarker;
@property (nonatomic, strong, nonnull) NSString *deleteMarkerVersionID;
@end

@interface OBSObjectDeleteError : OBSBaseEntity
@property (nonatomic, strong, nonnull) NSString *key;
@property (nonatomic, strong, nonnull) NSString *code;
@property (nonatomic, strong, nonnull) NSString *message;
@end

#pragma mark - request

/**
 批量删除对象
 */
@protocol OBSDeleteObjectsProtocol
@required

/**
 桶名
 */
@property (nonatomic, strong, nonnull) NSString *bucketName;

/**
 quiet模式:只返回删除失败的对象结果
 */
@property (nonatomic, assign)  BOOL quiet;

/**
 删除对象列表
 */
@property (nonatomic, strong, nonnull) NSMutableArray<OBSObjectToDelete*> *objectList;
@end


/**
 批量删除对象request
 */
@interface OBSDeleteObjectsRequest: OBSBaseRequest<OBSDeleteObjectsProtocol>

/**
 桶名
 */
@property (nonatomic, strong, nonnull) NSString *bucketName;

/**
 quiet模式:只返回删除失败的对象结果
 */
@property (nonatomic, assign)  BOOL quiet;

/**
 被批量删除对象列表
 */
@property (nonatomic, strong, nonnull) NSMutableArray<OBSObjectToDelete*> *objectList;

/**
 初始化批量删除对象request

 @param bucketName 桶名
 @return 批量删除对象request
 */
-(instancetype)initWithBucketName:(NSString*) bucketName;
@end

#pragma mark - networking request
@interface OBSDeleteObjectsRequestNetworking : OBSServiceNetworkingCommandRequest
@end

    //response
#pragma mark - response
/**
 批量删除对象response
 */
@interface OBSDeleteObjectsResponse: OBSServiceResponse

/**
 成功删除对象列表
 */
@property (nonatomic, strong, nonnull) NSMutableArray<OBSObjectDeleted*> *deletedList;

/**
 删除失败对象列表
 */
@property (nonatomic, strong, nonnull) NSMutableArray<OBSObjectDeleteError*> *errorList;
@end


#pragma mark - client method
@interface OBSClient(deleteObjects)

/**
 批量删除对象

 @param request 批量删除对象request
 @param completionHandler 批量删除对象回调
 @return OBSBFTask
 */
- (OBSBFTask*)deleteObjects:(__kindof OBSBaseRequest<OBSDeleteObjectsProtocol>*)request
         completionHandler:(void (^)(OBSDeleteObjectsResponse * response, NSError * error))completionHandler;
@end
#endif /* OBSDeleteObjectssModel_h */
