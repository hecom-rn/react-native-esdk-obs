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

#ifndef OBSListObjectsModel_h
#define OBSListObjectsModel_h
#import "OBSBaseModel.h"
#import "OBSBaseNetworking.h"
#import "OBSClient.h"
#import "OBSServiceBaseModel.h"
#import "OBSServiceCommonEntities.h"

#pragma mark - entities
@interface OBSContent :  OBSBaseEntity
@property (nonatomic, strong, nonnull) NSString *key;
@property (nonatomic, strong, nonnull) NSDate *lastModified;
@property (nonatomic, strong, nonnull) NSString *etag;
@property (nonatomic, strong, nonnull) NSNumber *size;
@property (nonatomic, strong, nonnull) OBSUser *owner;
@property (nonatomic, assign) OBSStorageClass storageClass;
@end



@interface OBSCommonPrefix : OBSBaseEntity
@property (nonatomic,strong) NSString *prefix;
@end



#pragma mark - request

/**
 列举桶对象
 */
@protocol OBSListObjectsProtocol
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
 列举桶内对象列表时，指定一个标识符，返回的对象列表将是按照字典顺序排序后，这个标识符以后的所有对象
 */
@property (nonatomic, strong, nonnull) NSString *marker;

/**
 最大返回对象数目
 */
@property (nonatomic, strong, nonnull) NSNumber *maxKeys;

/**
 用来分组桶内对象的字符串。所有名字包含指定的前缀且第一次出现的object作为一组元素commonPrefixes
 */
@property (nonatomic, strong, nonnull) NSString *delimiter;

/**
 
 */
@property (nonatomic, strong, nonnull) NSString *origin;

/**
 允许访问的请求类型
 */
@property (nonatomic, strong, nonnull) NSArray<NSString*> *accessControlRequestHeadersList;
@end


/**
 列举桶对象request
 */
@interface OBSListObjectsRequest: OBSCORSRequest<OBSListObjectsProtocol>

/**
 桶名
 */
@property (nonatomic, strong, nonnull) NSString *bucketName;


/**
 列举以指定的字符串prefix开头的对象
 */
@property (nonatomic, strong, nonnull) NSString *prefix;

/**
 列举桶内对象列表时，指定一个标识符，返回的对象列表将是按照字典顺序排序后，这个标识符以后的所有对象
 */
@property (nonatomic, strong, nonnull) NSString *marker;

/**
 指定返回的最大对象数范围[1,1000],超出按照1000处理
 */
@property (nonatomic, strong, nonnull) NSNumber *maxKeys;

/**
 用来分组桶内对象的字符串。所有名字包含指定的前缀 且第一次出现的object作为一组元素commonPrefixes
 */
@property (nonatomic, strong, nonnull) NSString *delimiter;

/**
 与响应中的keyMarker配合使用，返回的对象列表将是按照字典顺序排序后在该标识符以后的所有对象。如果versionIDMarker不是keyMarker的一个版本号，则该参数无效。
 */
@property (nonatomic, strong, nonnull) NSString *versionID;


/**
 初始化列举桶内对象request

 @param bucketName 桶名
 @return 列举桶内对象request
 */
-(instancetype)initWithBucketName:(NSString*) bucketName;
@end

#pragma mark - networking request
@interface OBSListObjectsRequestNetworking : OBSServiceNetworkingCommandRequest
@end

    //response
#pragma mark - response

/**
  列举桶对象response
 */
@interface OBSListObjectsResponse: OBSCORSResponse

/**
 桶区域位置
 */
@property (nonatomic, strong, nonnull) NSString *region;

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
@property (nonatomic, strong, nonnull) NSString *marker;

/**
 如果本次没有返回全部结果，响应请求 中将包含此字段，用于标明本次请求列 举到的最后一个对象。后续请求可以指 定Marker等于该值来列举剩余的对象
 */
@property (nonatomic, strong, nonnull) NSString *nextMarker;

/**
 列举时最多返回的对象个数
 */
@property (nonatomic, strong, nonnull) NSNumber *maxKeys;

/**
 请求中携带的delimiter参数
 */
@property (nonatomic, strong, nonnull) NSString *delimiter;

/**
 表明是否本次返回的listBucketResult结果列表被截断。“YES”表示本次没有返回全部结果;“NO”表示本次已经返回了全部结果
 */
@property (nonatomic, assign) BOOL isTruncated;

/**
 桶中对象列表
 */
@property (nonatomic, strong, nonnull) NSArray<OBSContent*> *contentsList;

/**
 公共头
 */
@property (nonatomic, strong, nonnull) NSArray<OBSCommonPrefix*> *commonPrefixesList;

@end


#pragma mark - client method
@interface OBSClient(listObjects)
- (OBSBFTask*)listObjects:(__kindof OBSBaseRequest<OBSListObjectsProtocol>*)request
                 completionHandler:(void (^)(OBSListObjectsResponse * response, NSError * error))completionHandler;
@end

#endif  /* OBSListObjectsModel_h */
