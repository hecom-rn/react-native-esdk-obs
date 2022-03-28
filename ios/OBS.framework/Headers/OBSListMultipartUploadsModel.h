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

#ifndef OBSListMultipartUploadsModel_h
#define OBSListMultipartUploadsModel_h
#import "OBSBaseModel.h"
#import "OBSBaseNetworking.h"
#import "OBSClient.h"
#import "OBSServiceBaseModel.h"
#import "OBSServiceCommonEntities.h"

#pragma mark - entities
@interface OBSUpload: OBSBaseEntity
@property (nonatomic, strong, nonnull) NSString *objectKey;
@property (nonatomic, strong, nonnull) NSString *uploadID;
@property (nonatomic, strong, nonnull) OBSUser *initiator;
@property (nonatomic, strong, nonnull) OBSUser *owner;
@property (nonatomic, assign) OBSStorageClass storageClass;
@property (nonatomic, strong, nonnull) NSDate *initiatedTime;
@end


#pragma mark - request

/**
 列举多段上传任务
 */
@protocol OBSListMultipartUploadsProtocol
@required

/**
 桶名
 */
@property (nonatomic, strong, nonnull) NSString *bucketName;

/**
 分组标识
 */
@property (nonatomic, strong, nonnull) NSString *delimiter;

/**
 响应对象名以prefix开始的任务信息
 */
@property (nonatomic, strong, nonnull) NSString *prefix;

/**
 列举最大的上传任务数目
 */
@property (nonatomic, strong, nonnull) NSNumber *maxUploads;

/**
 列举指定的keyMarker之后的多段任务
 */
@property (nonatomic, strong, nonnull) NSString *keyMarker;

/**
 只有和keyMarker一起使用才有意义，列举时返回指定的keyMarker的uploadIDMarker之后的多段任务
 */
@property (nonatomic, strong, nonnull) NSString *uploadIDMarker;
@end


/**
 列举多段上传任务request
 */
@interface OBSListMultipartUploadsRequest: OBSBaseRequest<OBSListMultipartUploadsProtocol>

/**
 桶名
 */
@property (nonatomic, strong, nonnull) NSString *bucketName;

/**
 分组标识
 */
@property (nonatomic, strong, nonnull) NSString *delimiter;

/**
 响应对象名以prefix开始的任务信息
 */
@property (nonatomic, strong, nonnull) NSString *prefix;

/**
 列举的多段任务的最大条目
 */
@property (nonatomic, strong, nonnull) NSNumber *maxUploads;

/**
 列举指定的keyMarker之后的多段任务
 */
@property (nonatomic, strong, nonnull) NSString *keyMarker;

/**
 只有和keyMarker一起使用才有意义，列举时返回指定的keyMarker的uploadIDMarker之后的多段任务
 */
@property (nonatomic, strong, nonnull) NSString *uploadIDMarker;

/**
 初始化列举多段上传任务request

 @param bucketName 桶名
 @return 列举多段上传任务
 */
-(instancetype)initWithBucketName:(NSString*) bucketName;
@end

#pragma mark - networking request
@interface OBSListMultipartUploadsRequestNetworking : OBSServiceNetworkingCommandRequest
@end

    //response
#pragma mark - response

/**
 列举多段上传任务response
 */
@interface OBSListMultipartUploadsResponse: OBSBaseResponse

/**
 桶名
 */
@property (nonatomic, strong, nonnull) NSString *bucketName;

/**
 列举时的起始对象位置
 */
@property (nonatomic, strong, nonnull) NSString *keyMarker;

/**
 列举时的起始uploadID位置
 */
@property (nonatomic, strong, nonnull) NSString *uploadIDMarker;

/**
 如果本次没有返回全部结果，响应请求中将包含nextKeyMarker字段，用于标明接下来请求的keyMarker值
 */
@property (nonatomic, strong, nonnull) NSString *nextKeyMarker;

/**
 如果本次没有返回全部结果，响应请求中将 包含nextUploadIDMarker字段，用于标明接下来请求的uploadMarker值
 */
@property (nonatomic, strong, nonnull) NSString *nextUploadIDMarker;

/**
 返回的最大多段上传任务数目
 */
@property (nonatomic, strong, nonnull) NSNumber *maxUploads;

/**
 表明是否本次返回的multipartUpload结果列表被截断。“YES”表示本次没有返回全部结果;“NO”表示本次已经返回了全部结果
 */
@property (nonatomic, assign) BOOL isTruncated;

/**
 多段上传任务列表
 */
@property (nonatomic, strong, nonnull) NSArray<OBSUpload*> *uploadsList;

/**
 请求中带的prefix
 */
@property (nonatomic, strong, nonnull) NSString *prefix;

/**
 请求中带的delimiter
 */
@property (nonatomic, strong, nonnull) NSString *delimiter;

/**
 请求中带delimiter参数时，返回消息带commonPrefixes分组信息
 */
@property (nonatomic, strong, nonnull) NSArray<NSString*> *commonPrefixesList;

@end


#pragma mark - client method
@interface OBSClient(listMultipartUploads)

/**
 列举多段上传任务

 @param request 列举多段上传任务request
 @param completionHandler 列举多段上传任务回调
 @return OBSBFTask
 */
- (OBSBFTask*)listMultipartUploads:(__kindof OBSBaseRequest<OBSListMultipartUploadsProtocol>*)request
        completionHandler:(void (^)(OBSListMultipartUploadsResponse * response, NSError * error))completionHandler;
@end

#endif /* OBSListMultipartUploadsModel_h */
