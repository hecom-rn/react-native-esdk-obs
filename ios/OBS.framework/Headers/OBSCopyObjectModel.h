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

#ifndef OBSCopyObjectModel_h
#define OBSCopyObjectModel_h

#import "OBSBaseNetworking.h"
#import "OBSClient.h"
#import "OBSServiceBaseModel.h"
#import "OBSServiceConstDefinition.h"


@class OBSEncryptionTypeCustomer;
@class OBSAbstractEncryption;
    //request

#pragma mark - request

/**
 复制对象
 */
@protocol OBSCopyObjectProtocol<NSObject>
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
 被复制对版本ID
 */
@property (nonatomic, strong, nonnull) NSString *srcObjectVersionID;

/**
 复制后的桶名
 */
@property (nonatomic, strong, nonnull) NSString *dstBucketName;

/**
 复制后的对象名
 */
@property (nonatomic, strong, nonnull) NSString *dstObjectKey;

/**
 复制后对象访问策略
 */
@property (nonatomic, assign) OBSACLPolicy dstObjectACLPolicy;

/**
 复制后对象元数据
 */
@property (nonatomic, assign) OBSMetaDirective dstObjectMetaDirective;

/**
 如果etag匹配则复制
 */
@property (nonatomic, strong, nonnull) NSString *cpSrcIfETagMatch;

/**
 如果etag不匹配则复制
 */
@property (nonatomic, strong, nonnull) NSString *cpSrcIfETagNoneMatch;

/**
 只有当源对象在此参数指定的时间之后修改过才进行复制对象操作
 */
@property (nonatomic, strong, nonnull) NSDate *cpSrcIfModifiedSince;

/**
 只有当源对象不在此参数指定的时间之后修改过才进行复制对象操作
 */
@property (nonatomic, strong, nonnull) NSDate *cpSrcIfUnmodifiedSince;

/**
 复制后对象存储类型
 */
@property (nonatomic, assign) OBSStorageClass dstObjectStorageClass;

/**
 复制后对象网站重定向
 */
@property (nonatomic, strong, nonnull) NSString *dstObjectWebsiteRedirectLocation;

/**
 复制后对象加密方式
 */
@property (nonatomic, strong, nonnull) __kindof OBSAbstractEncryption *dstObjectEncryption;

/**
 被复制对象加密方式
 */
@property (nonatomic, strong, nonnull) __kindof OBSAbstractEncryption *srcObjectEncryption;

/**
 自定义元数据
 */
@property (nonatomic, strong, nullable) NSDictionary *metaDataDict;
@end


/**
 复制对象request
 */
@interface OBSCopyObjectRequest: OBSBaseRequest<OBSCopyObjectProtocol>

/**
 被复制桶名
 */
@property (nonatomic, strong, nonnull) NSString *srcBucketName;

/**
 被复制的对象key
 */
@property (nonatomic, strong, nonnull) NSString *srcObjectKey;

/**
 被复制对象多版本ID
 */
@property (nonatomic, strong, nonnull) NSString *srcObjectVersionID;

/**
 复制后的桶名
 */
@property (nonatomic, strong, nonnull) NSString *dstBucketName;

/**
 复制后的对象key
 */
@property (nonatomic, strong, nonnull) NSString *dstObjectKey;


/**
 复制后对象的ACL
 */
@property (nonatomic, assign) OBSACLPolicy dstObjectACLPolicy;

/**
 复制后对象的元数据
 */
@property (nonatomic, assign) OBSMetaDirective dstObjectMetaDirective;


/**
 只有当源对象的Etag与此参数指定的值相等时才进行复制对象操作
 */
@property (nonatomic, strong, nonnull) NSString *cpSrcIfETagMatch;

/**
 只有当源对象的Etag与此参数指定的值不相等时才进行复制对象操作
 */
@property (nonatomic, strong, nonnull) NSString *cpSrcIfETagNoneMatch;


/**
 只有当源对象在此参数指定的时间之后修改过才进行复制对象操作
 */
@property (nonatomic, strong, nonnull) NSDate *cpSrcIfModifiedSince;

/**
 只有当源对象在此参数指定的时间之后没有修改过才进行复制对象操作
 */
@property (nonatomic, strong, nonnull) NSDate *cpSrcIfUnmodifiedSince;

/**
 对象存储类型
 */
@property (nonatomic, assign) OBSStorageClass dstObjectStorageClass;

/**
 对象重定向
 */
@property (nonatomic, strong, nonnull) NSString *dstObjectWebsiteRedirectLocation;

/**
 复制后的对象加密方式
 */
@property (nonatomic, strong, nonnull) __kindof OBSAbstractEncryption *dstObjectEncryption;

/**
 被复制对象加密方式
 */
@property (nonatomic, strong, nonnull) __kindof OBSAbstractEncryption *srcObjectEncryption;

/**
 自定义元数据
 */
@property (nonatomic, strong, nullable) NSDictionary *metaDataDict;

/**
 自定义MIME类型
 */
@property (nonatomic, strong, nonnull) NSString *customContentType;

/**
 初始化复制对象request

 @param srcBucketName 被复制桶名
 @param srcObjectKey 被复制对象的key
 @param dstBucketName 复制后的桶名
 @param dstObjectKey 复制后对象的key
 @return 复制对象request
 */
-(instancetype)initWithSrcBucketName:(NSString*) srcBucketName
                        srcObjectKey:(NSString*) srcObjectKey
                       dstBucketName:(NSString*) dstBucketName
                        dstObjectKey:(NSString*) dstObjectKey;
@end

#pragma mark - networking request
@interface OBSNetworkingCopyObjectRequest : OBSServiceNetworkingCommandRequest
@end

    //response
#pragma mark - response

/**
 复制对象response
 */
@interface OBSCopyObjectResponse: OBSServiceResponse

/**
 复制后对象etag值
 */
@property (nonatomic, strong, nonnull) NSString *etag;

/**
 对象最后修改时间
 */
@property (nonatomic, strong, nonnull) NSDate *lastModified;

/**
 如果桶多版本开启，则返回被复制对象的版本号
 */
@property (nonatomic, strong, nonnull) NSString *srcObjectVersionID;

/**
 如果桶多版本开启，则返回新对象的版本号
 */
@property (nonatomic, strong, nonnull) NSString *dstObjectVersionID;


/**
 新对象加密方式
 */
@property (nonatomic, strong, nonnull) __kindof OBSAbstractEncryption *encryption;

@end

    //client method
#pragma mark - client method
@interface OBSClient(copyObject)

/**
 复制对象

 @param request 复制对象request
 @param completionHandler 复制对象回调
 @return OBSBFTask
 */
- (OBSBFTask*)copyObject:(__kindof OBSBaseRequest<OBSCopyObjectProtocol>*)request
      completionHandler:(void (^)(OBSCopyObjectResponse  * response, NSError * error))completionHandler;
@end
#endif /* OBSCopyObjectModel_h */
