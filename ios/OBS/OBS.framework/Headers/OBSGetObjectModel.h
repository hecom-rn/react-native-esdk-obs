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

#ifndef OBSGetObjectModel_h
#define OBSGetObjectModel_h

#import "OBSBaseModel.h"
#import "OBSBaseNetworking.h"
#import "OBSClient.h"
#import "OBSServiceBaseModel.h"
#import "OBSServiceConstDefinition.h"
@class OBSEncryptionTypeCustomer;
@class OBSAbstractEncryption;

#pragma mark - request

/**
 下载对象
 */
@protocol OBSGetObjectProtocol<NSObject>
@required

/**
 桶名
 */
@property (nonatomic, strong, nonnull) NSString *bucketName;

/**
 对象
 */
@property (nonatomic, strong, nonnull) NSString *objectKey;
@end


/**
 获取对象父类
 */
@interface OBSAbstractGetObjectRequest: OBSCORSRequest<OBSGetObjectProtocol>

/**
 桶名
 */
@property (nonatomic, strong, nonnull) NSString *bucketName;

/**
 对象key
 */
@property (nonatomic, strong, nonnull) NSString *objectKey;

    //resource parameters

/**
 版本号
 */
@property (nonatomic, strong, nonnull) NSString *versionID;

/**
重写contentType头
 */
@property (nonatomic, strong, nonnull) NSString *responseContentType;

/**
 重写响应中的contentLanguage头
 */
@property (nonatomic, strong, nonnull) NSString *responseContentLanguage;

/**
 重写响应中的expires头
 */
@property (nonatomic, strong, nonnull) NSString *responseExpires;

/**
 重写响应中的cacheControl头
 */
@property (nonatomic, strong, nonnull) NSString *responseCacheControl;

/**
 重写响应中的contentDisposition 头
 */
@property (nonatomic, strong, nonnull) NSString *responseContentDisposition;

/**
 重写响应中的contentEncoding头
 */
@property (nonatomic, strong, nonnull) NSString *responseContentEncoding;

//header parameters

/**
 获取在range范围内的对象内容
 */
@property (nonatomic, strong, nonnull) NSString *range;

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
 如果对象的eTag和请求中指定eTag不相同，则返回对象内容
 */
@property (nonatomic, strong, nonnull) NSString *ifETagNoneMatch;
    //image process
@property (nonatomic, strong, nonnull) NSString *imageProcess;

/**
 加密方式
 */
@property (nonatomic, strong, nonnull) __kindof OBSAbstractEncryption *encryption;


/**
 下载block
 */
@property (nonatomic, copy, nonnull) OBSNetworkingDownloadProgressBlock downloadProgressBlock;
@end


/**
 流式下载对象request
 */
@interface OBSGetObjectToDataRequest: OBSAbstractGetObjectRequest

/**
 流式下载对象回调
 */
@property (nonatomic, copy, nonnull) OBSNetworkingOnReceiveDataBlock onReceiveDataBlock;

/**
 初始化流式下载对象request

 @param bucketName 桶名
 @param objectKey 对象的key
 @return 流式下载对象request
 */

-(instancetype)initWithBucketName:(NSString*) bucketName objectKey: (NSString*) objectKey;
@end


/**
 文件方式下载对象request
 */
@interface OBSGetObjectToFileRequest: OBSAbstractGetObjectRequest

/**
 文件存储路径
 */
@property (nonatomic, strong, nonnull) NSString *downloadFilePath;

/**
 是否后台下载
 */
@property (nonatomic, assign) BOOL background;

/**
 初始化文件方式下载对象request

 @param bucketName 桶名
 @param objectKey 对象key
 @param downloadFilePath 文件存储路径
 @return 文件方式下载对象request
 */
-(instancetype)initWithBucketName:(NSString*) bucketName objectKey: (NSString*) objectKey downloadFilePath:(NSString*) downloadFilePath;
@end

#pragma mark - networking request
@interface OBSGetObjectToDataRequestNetworking : OBSServiceNetworkingDownloadDataRequest
@end
@interface OBSGetObjectToFileRequestNetworking : OBSServiceNetworkingDownloadFileRequest
@end

    //response
#pragma mark - response

/**
 下载对象response
 */
@interface OBSGetObjectResponse:OBSCORSResponse

/**
 对象etag值
 */
@property (nonatomic, strong, nonnull) NSString *etag;

/**
 如果对象配置了过期时间，则会返回过期时间
 */
@property (nonatomic, strong, nonnull) NSString *expiration;

/**
 对象最后修改时间
 */
@property (nonatomic, strong, nonnull) NSDate *lastModified;

/**
 当桶设置了website配置，就可以设置对象元数据的这个属性，website接入点返回重定向响应，将请求重定向到该属性指定的桶内的另一个对象或外部的URL。
 */
@property (nonatomic, strong, nonnull) NSString *websiteRedirectLocation;

/**
 标识对象是否是删除标记
 */
@property (nonatomic, assign) BOOL deleteMarker;

/**
 对象的版本号。如果该对象无版本号，则响应中不会出现
 */
@property (nonatomic, strong, nonnull) NSString *versionID;

/**
 加密方式
 */
@property (nonatomic, strong, nonnull) __kindof OBSAbstractEncryption *encryption;

/**
 对象存储类型
 */
@property (nonatomic, assign) OBSStorageClass storageClass;

/**
 对象自定义元数据
 */
@property (nonatomic, strong, nullable) NSDictionary *metaDataDict;

/**
 对象数据
 */
@property (nonatomic, strong, nonnull) NSData *objectData;
@end

    //client method
#pragma mark - client method
@interface OBSClient(getObject)

/**
 获取对象

 @param request 下载对象request
 @param completionHandler 下载对象的回调
 @return OBSBFTask
 */
- (OBSBFTask*)getObject:(__kindof OBSBaseRequest<OBSGetObjectProtocol>*)request
              completionHandler:(void (^)(OBSGetObjectResponse  * response, NSError * error))completionHandler;
@end
#endif  /* OBSGetObjectModel_h */
