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

#ifndef OBSDownloadFileModel_h
#define OBSDownloadFileModel_h

#import "OBSBaseModel.h"
#import "OBSBaseNetworking.h"
#import "OBSClient.h"
#import "OBSServiceBaseModel.h"
#import "OBSServiceConstDefinition.h"
@class OBSAbstractEncryption;

#pragma mark - request

/**
 断点续传下载
 */
@protocol OBSDownloadFileProtocol<NSObject>
@required

/**
 桶名
 */
@property (nonatomic, strong, nonnull) NSString *bucketName;

/**
 对象名
 */
@property (nonatomic, strong, nonnull) NSString *objectKey;
    //resource parameters

/**
 多版本ID
 */
@property (nonatomic, strong, nonnull) NSString *versionID;
    //header parameters

/**
 如果对象在请求中指定的时间之后有修改，则返回对象内容
 */
@property (nonatomic, strong, nonnull) NSDate *ifModifiedSince;

/**
 如果对象在请求中指定的时间之后没有修改，则返回对象内容
 */
@property (nonatomic, strong, nonnull) NSDate *ifUnmodifiedSince;

/**
 如果对象的eTag和请求中指定的eTag相同，则返回对象内容
 */
@property (nonatomic, strong, nonnull) NSString *ifETagMatch;

/**
 如果对象的eTag和请求中指定的eTag不相同，则返回对象内容
 */
@property (nonatomic, strong, nonnull) NSString *ifETagNoneMatch;

/**
 加密方式
 */
@property (nonatomic, strong, nonnull) __kindof OBSAbstractEncryption *encryption;

/**
 下载文件路径
 */
@property (nonatomic, strong, nonnull) NSString *downloadFilePath;

/**
 下载进度
 */
@property (atomic, copy, nonnull) OBSNetworkingDownloadProgressBlock downloadProgressBlock;

/**
 是否开启断点续传
 */
@property (nonatomic, assign) BOOL enableCheckpoint;

/**
 是否开启MD5校验
 */
@property (nonatomic, assign) BOOL enableMD5Check;

/**
 是否打开强制覆盖
 */
@property (nonatomic, assign) BOOL enableForceOverwrite;

/**
 设置断点续传模式下，记录下载进度的文件
 */
@property (nonatomic, strong, nonnull) NSString *checkpointFilePath;

/**
 分段大小
 */
@property (nonatomic, strong, nonnull) NSNumber *partSize;
@end


/**
 断点续传下载request
 */
@interface OBSDownloadFileRequest: OBSBaseRequest<OBSDownloadFileProtocol>

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
 如果对象在请求中指定的时间之后有修改，则返回对象内容
 */
@property (nonatomic, strong, nonnull) NSDate *ifModifiedSince;

/**
 如果对象在请求中指定的时间之后没有修改，则返回对象内容
 */
@property (nonatomic, strong, nonnull) NSDate *ifUnmodifiedSince;

/**
 如果对象的eTag和请求中指定的eTag相同，则返回对象内容
 */
@property (nonatomic, strong, nonnull) NSString *ifETagMatch;

/**
 如果对象的eTag和请求中指定的eTag不相同，则返回对象内容
 */
@property (nonatomic, strong, nonnull) NSString *ifETagNoneMatch;

/**
 加密方式
 */
@property (nonatomic, strong, nonnull) __kindof OBSAbstractEncryption *encryption;

/**
 保存文件路径
 */
@property (nonatomic, strong, nonnull) NSString *downloadFilePath;

/**
 下载文件回调
 */
@property (atomic, copy, nonnull) OBSNetworkingDownloadProgressBlock downloadProgressBlock;

/**
 是否支持断点传续
 */
@property (nonatomic, assign) BOOL enableCheckpoint;

/**
 是否打开MD5校验
 */
@property (nonatomic, assign) BOOL enableMD5Check;

/**
 是否开启强制覆盖
 */
@property (nonatomic, assign) BOOL enableForceOverwrite;

/**
 设置断点续传模式下，记录下载进度的文件
 */
@property (nonatomic, strong, nonnull) NSString *checkpointFilePath;

/**
 分段大小
 */
@property (nonatomic, strong, nonnull) NSNumber *partSize;

/**
 初始化断点续传下载request

 @param bucketName 桶名
 @param objectKey 对象key
 @param downloadFilePath 存储路径
 @return 断点续传下载request
 */
-(instancetype)initWithBucketName:(NSString*) bucketName objectKey:(NSString*) objectKey downloadFilePath:(NSString*) downloadFilePath;
@end

    //response
#pragma mark - response

/**
 断点续传下载response
 */
@interface OBSDownloadFileResponse: OBSServiceResponse

/**
 对象etag
 */
@property (nonatomic, strong, nonnull) NSString *etag;

/**
 过期时间
 */
@property (nonatomic, strong, nonnull) NSString *expiration;

/**
 网址重定向
 */
@property (nonatomic, strong, nonnull) NSString *websiteRedirectLocation;

/**
 最后修改时间
 */
@property (nonatomic, strong, nonnull) NSDate *lastModified;

/**
 删除标记
 */
@property (nonatomic, assign) BOOL deleteMarker;

/**
 如果桶开启了多版本，则返回多版本ID
 */
@property (nonatomic, strong, nonnull) NSString *versionID;

/**
 加密方式
 */
@property (nonatomic, strong, nonnull) __kindof OBSAbstractEncryption *encryption;

/**
 存储类型
 */
@property (nonatomic, assign) OBSStorageClass storageClass;

/**
 对象元数据字典
 */
@property (nonatomic, strong, nullable) NSDictionary *metaDataDict;
@end

    //client method
#pragma mark - client method
@interface OBSClient(downloadFile)

/**
 下载文件

 @param request 断点续传下载request
 @param completionHandler 断点续传下载回调
 @return OBSBFTask
 */
- (OBSBFTask*)downloadFile:(__kindof OBSBaseRequest<OBSDownloadFileProtocol>*)request
      completionHandler:(void (^)(OBSDownloadFileResponse  * response, NSError * error))completionHandler;
@end
#endif /* OBSDownloadFileModel_h */
