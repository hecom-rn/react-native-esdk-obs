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

#ifndef OBSListPartsModel_h
#define OBSListPartsModel_h

#import "OBSBaseModel.h"
#import "OBSBaseNetworking.h"
#import "OBSClient.h"
#import "OBSServiceBaseModel.h"
#import "OBSServiceCommonEntities.h"

#pragma mark - entities


#pragma mark - request

/**
 列举段
 */
@protocol OBSListPartsProtocol
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
 多段上传ID
 */
@property (nonatomic, strong, nonnull) NSString *uploadID;

/**
 最大列举数目
 */
@property (nonatomic, strong, nonnull) NSNumber *maxParts;

/**
 段号
 */
@property (nonatomic, strong, nonnull) NSNumber *partNumberMarker;
@end

/**
 列举段request
 */
@interface OBSListPartsRequest: OBSBaseRequest<OBSListPartsProtocol>

/**
 桶名
 */
@property (nonatomic, strong, nonnull) NSString *bucketName;

/**
 对象KEY
 */
@property (nonatomic, strong, nonnull) NSString *objectKey;

/**
 多段上传任务ID
 */
@property (nonatomic, strong, nonnull) NSString *uploadID;

/**
 最大段
 */
@property (nonatomic, strong, nonnull) NSNumber *maxParts;

/**
 段号
 */
@property (nonatomic, strong, nonnull) NSNumber *partNumberMarker;

/**
 初始化列举段request

 @param bucketName 桶名
 @param objectKey 对象KEY
 @param uploadID 多段上传任务ID
 @return 列举段request
 */
-(instancetype)initWithBucketName:(NSString*) bucketName
                        objectKey:(NSString*) objectKey
                         uploadID:(NSString*) uploadID;
@end

#pragma mark - networking request
@interface OBSListPartsRequestNetworking : OBSServiceNetworkingCommandRequest
@end

    //response
#pragma mark - response

/**
 列举段response
 */
@interface OBSListPartsResponse: OBSCORSResponse

/**
 桶名
 */
@property (nonatomic, strong, nonnull) NSString *bucketName;

/**
 对象名
 */
@property (nonatomic, strong, nonnull) NSString *objectKey;

/**
 上传任务ID
 */
@property (nonatomic, strong, nonnull) NSString *uploadID;

/**
 upload任务的创建者
 */
@property (nonatomic, strong, nonnull) OBSUser *initiator;

/**
 和initiator相同
 */
@property (nonatomic, strong, nonnull) OBSUser *owner;

/**
 存储类型
 */
@property (nonatomic, assign) OBSStorageClass storageClass;

/**
 本次List结果的partNumber起始位置
 */
@property (nonatomic, strong, nonnull) NSNumber *partNumberMarker;

/**
 如果本次没有返回全部结果，响应请求中将包含nextPartNumberMarker元素，用于标明接下来请求的 partNumberMarker值
 */
@property (nonatomic, strong, nonnull) NSNumber *nextPartNumberMarker;

/**
 返回请求中最大的part数目
 */
@property (nonatomic, strong, nonnull) NSNumber *maxParts;

/**
 标明是否本次返回的listPart结果列表被截断。“true”表示 本次没有返回全部结果;“false”表示本次已经返回了全部结果
 */
@property (nonatomic, assign) BOOL isTruncated;

/**
 已经上传段的数组
 */
@property (nonatomic, strong, nonnull) NSArray<OBSPart*> *partsList;

@end


#pragma mark - client method
@interface OBSClient(listParts)

/**
 列举段

 @param request 列举段request
 @param completionHandler 列举段回调
 @return OBSBFTask
 */
- (OBSBFTask*)listParts:(__kindof OBSBaseRequest<OBSListPartsProtocol>*)request
        completionHandler:(void (^)(OBSListPartsResponse * response, NSError * error))completionHandler;
@end
#endif /* OBSListPartsModel_h */
