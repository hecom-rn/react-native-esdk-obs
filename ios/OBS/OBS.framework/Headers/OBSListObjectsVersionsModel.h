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

#ifndef OBSListObjectsVersionsModel_h
#define OBSListObjectsVersionsModel_h

#import "OBSBaseModel.h"
#import "OBSBaseNetworking.h"
#import "OBSClient.h"
#import "OBSServiceBaseModel.h"
#import "OBSServiceCommonEntities.h"

#pragma mark - entities
@interface OBSObjectVersion: OBSBaseEntity
@property (nonatomic, strong, nonnull) NSString *key;
@property (nonatomic, strong, nonnull) NSString *versionID;
@property (nonatomic, assign) BOOL isLatest;
@property (nonatomic, strong, nonnull) NSDate *lastModified;
@property (nonatomic, strong, nonnull) NSString *etag;
@property (nonatomic, strong, nonnull) NSNumber *size;
@property (nonatomic, strong, nonnull) OBSUser *owner;
@property (nonatomic, assign) OBSStorageClass storageClass;
@end

@interface OBSDeleteMarker: OBSBaseEntity
@property (nonatomic, strong, nonnull) NSString *key;
@property (nonatomic, strong, nonnull) NSString *versionID;
@property (nonatomic, assign) BOOL isLatest;
@property (nonatomic, strong, nonnull) NSDate *lastModified;
@property (nonatomic, strong, nonnull) OBSUser *owner;
@end

#pragma mark - request

/**
 列举多版本对象
 */
@protocol OBSListObjectsVersionsProtocol
@required

/**
 桶名
 */
@property (nonatomic, strong, nonnull) NSString *bucketName;

/**
 列举以指定的字符串prefix开头的对象
 */
@property (nonatomic, strong, nonnull) NSString *prefix;

/**
 列举对象时的起始位置
 */
@property (nonatomic, strong, nonnull) NSString *keyMarker;

/**
 列举时最多返回的对象个数
 */
@property (nonatomic, strong, nonnull) NSNumber *maxKeys;

/**
 用来分组桶内对象的字符串
 */
@property (nonatomic, strong, nonnull) NSString *delimiter;

/**
 列举对象时的起始位置
 */
@property (nonatomic, strong, nonnull) NSString *versionIDMarker;

/**
 
 */
@property (nonatomic, strong, nonnull) NSString *origin;

/**
 允许访问的请求种类
 */
@property (nonatomic, strong, nonnull) NSArray<NSString*> *accessControlRequestHeadersList;
@end


/**
 列举多版本对象
 */
@interface OBSListObjectsVersionsRequest: OBSCORSRequest<OBSListObjectsVersionsProtocol>

/**
 桶名
 */
@property (nonatomic, strong, nonnull) NSString *bucketName;

/**
 列举以指定的字符串prefix开头的对象
 */
@property (nonatomic, strong, nonnull) NSString *prefix;

/**
 列举标识符以后的对象
 */
@property (nonatomic, strong, nonnull) NSString *keyMarker;

/**
 指定返回的最大对象
 */
@property (nonatomic, strong, nonnull) NSNumber *maxKeys;

/**
 分组桶内的字符串
 */
@property (nonatomic, strong, nonnull) NSString *delimiter;

/**
 与响应中的keyarker配合使用，返回的对象列表将是按照字典顺序排序后在该标识符以后的所有对象。如果versiondIDMaker不是keyMarker的一个版本号，则该参数 无效
 */
@property (nonatomic, strong, nonnull) NSString *versionIDMarker;

/**
 初始化获取多版本对象request

 @param bucketName 桶名
 @return 获取多版本对象request
 */
-(instancetype)initWithBucketName:(NSString*) bucketName;
@end

#pragma mark - networking request
@interface OBSListObjectsVersionsRequestNetworking : OBSServiceNetworkingCommandRequest
@end

    //response
#pragma mark - response

/**
 列举多版本对象response
 */
@interface OBSListObjectsVersionsResponse: OBSCORSResponse

/**
 桶名
 */
@property (nonatomic, strong, nonnull) NSString *bucketName;

/**
 对象名的前缀，表示本次请求只列举对象名能匹配该前缀的所有对象
 */
@property (nonatomic, strong, nonnull) NSString *prefix;

/**
 列举对象时的起始位置
 */
@property (nonatomic, strong, nonnull) NSString *keyMarker;

/**
 列举对象时的起始位置
 */
@property (nonatomic, strong, nonnull) NSString *versionIDMarker;

/**
 如果本次没有返回全部结果，响应请求中将包含该元素，用于标明接下来请求的KeyMarker值
 */
@property (nonatomic, strong, nonnull) NSString *nextKeyMarker;

/**
 如果本次没有返回全部结果，响应请求中将包含该元素，用于标明接下来请求的KeyMarker值
 */
@property (nonatomic, strong, nonnull) NSString *nextVersionIDMarker;

/**
 列举时最多返回的对象个数
 */
@property (nonatomic, strong, nonnull) NSNumber *maxKeys;

/**
 请求中携带的delimiter参数
 */
@property (nonatomic, strong, nonnull) NSString *delimiter;

/**
 表明是否本次返回的ListVersionsResult结 果列表被截断。“true”表示本次没有返 回全部结果;“false”表示本次已经返 回了全部结果
 */
@property (nonatomic, assign) BOOL isTruncated;

/**
 保存列举桶中对象列表(含多版本)请求结果的容器
 */
@property (nonatomic, strong, nonnull) NSArray<OBSObjectVersion*> *versionList;

/**
 删除标记的数组
 */
@property (nonatomic, strong, nonnull) NSArray<OBSDeleteMarker*> *deleteMarkerList;

/**
 对象名的前缀数组，表示本次请求只列举对象名能匹配该前缀的所有对象
 */
@property (nonatomic, strong, nonnull) NSArray<NSString*> * commonPrefixesList;

@end


#pragma mark - client method
@interface OBSClient(listObjectsVerions)

/**
 列举多版本对象

 @param request 列举多版本对象request
 @param completionHandler 列举多版本对象回调
 @return OBSBFTask
 */
- (OBSBFTask*)listObjectsVersions:(__kindof OBSBaseRequest<OBSListObjectsVersionsProtocol>*)request
        completionHandler:(void (^)(OBSListObjectsVersionsResponse * response, NSError * error))completionHandler;
@end
#endif  /* OBSListObjectsVersionsModel_h */
