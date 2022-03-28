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

#ifndef OBSCopyPartModel_h
#define OBSCopyPartModel_h

#import "OBSBaseNetworking.h"
#import "OBSClient.h"
#import "OBSServiceBaseModel.h"
#import "OBSServiceConstDefinition.h"


@class OBSEncryptionTypeCustomer;
@class OBSAbstractEncryption;
    //request

#pragma mark - request

/**
 拷贝段
 */
@protocol OBSCopyPartProtocol<NSObject>
@required

/**
 被复制桶名
 */
@property (nonatomic, strong, nonnull) NSString *srcBucketName;

/**
 被复制对象名
 */
@property (nonatomic, strong, nonnull) NSString *srcObjectKey;

/**
 被复制多版本ID
 */
@property (nonatomic, strong, nonnull) NSString *srcObjectVersionID;

/**
 被复制范围
 */
@property (nonatomic, strong, nonnull) NSString *range;


/**
 上传段的桶名
 */
@property (nonatomic, strong, nonnull) NSString *uploadBucketName;

/**
 上传段对象名
 */
@property (nonatomic, strong, nonnull) NSString *uploadObjectKey;

/**
 上传段段号
 */
@property (nonatomic, strong, nonnull) NSNumber *uploadPartNumber;

/**
 多段上传任务ID
 */
@property (nonatomic, strong, nonnull) NSString *uploadID;

/**
 被复制对象加密方式
 */
@property (nonatomic, strong, nonnull) __kindof OBSAbstractEncryption *srcObjectEncryption;

/**
 复制后对象加密方式
 */
@property (nonatomic, strong, nonnull) __kindof OBSAbstractEncryption *uploadEncryption;
@end


/**
 拷贝段
 */
@interface OBSCopyPartRequest: OBSBaseRequest<OBSCopyPartProtocol>

/**
 被拷贝桶名
 */
@property (nonatomic, strong, nonnull) NSString *srcBucketName;

/**
 被拷贝的对象KEY
 */
@property (nonatomic, strong, nonnull) NSString *srcObjectKey;

/**
 被拷贝的对象多版本ID
 */
@property (nonatomic, strong, nonnull) NSString *srcObjectVersionID;

/**
 被拷贝的字节范围
 */
@property (nonatomic, strong, nonnull) NSString *range;


/**
 拷贝后桶名
 */
@property (nonatomic, strong, nonnull) NSString *uploadBucketName;

/**
 拷贝后对象KEY
 */
@property (nonatomic, strong, nonnull) NSString *uploadObjectKey;

/**
 被拷贝的段号
 */
@property (nonatomic, strong, nonnull) NSNumber *uploadPartNumber;

/**
 多段上传任务ID
 */
@property (nonatomic, strong, nonnull) NSString *uploadID;

/**
 被拷贝加密方式
 */
@property (nonatomic, strong, nonnull) __kindof OBSAbstractEncryption *srcObjectEncryption;

/**
 拷贝后加密方式
 */
@property (nonatomic, strong, nonnull) __kindof OBSAbstractEncryption *uploadEncryption;

/**
 初始化拷贝段request

 @param srcBucketName 原始桶名
 @param srcObjectKey 原始对象KEY
 @param uploadBucketName 拷贝后桶名
 @param uploadObjectKey 拷贝后对象KEY
 @param uploadPartNumber 拷贝段段号
 @param uploadID 多段上传任务ID
 @return 拷贝段request
 */
-(instancetype)initWithSrcBucketName:(NSString*) srcBucketName
                        srcObjectKey:(NSString*) srcObjectKey
                    uploadBucketName:(NSString*) uploadBucketName
                     uploadObjectKey:(NSString*) uploadObjectKey
                    uploadPartNumber:(NSNumber*) uploadPartNumber
                            uploadID:(NSString*) uploadID;
@end

#pragma mark - networking request
@interface OBSNetworkingCopyPartRequest : OBSServiceNetworkingCommandRequest
@end

    //response
#pragma mark - response

/**
 拷贝段response
 */
@interface OBSCopyPartResponse: OBSServiceResponse

/**
 新段的etag
 */
@property (nonatomic, strong, nonnull) NSString *etag;

/**
 最后修改时间
 */
@property (nonatomic, strong, nonnull) NSDate *lastModified;

/**
 被拷贝对象的多版本ID
 */
@property (nonatomic, strong, nonnull) NSString *srcObjectVersionID;

/**
 加密方式
 */
@property (nonatomic, strong, nonnull) __kindof OBSAbstractEncryption *encryption;

@end

    //client method
#pragma mark - client method
@interface OBSClient(copyPart)

/**
 拷贝段

 @param request 拷贝段request
 @param completionHandler 拷贝段回调
 @return OBSBFTask
 */
- (OBSBFTask*)copyPart:(__kindof OBSBaseRequest<OBSCopyPartProtocol>*)request
       completionHandler:(void (^)(OBSCopyPartResponse  * response, NSError * error))completionHandler;
@end
#endif /* OBSCopyPartModel_h */
