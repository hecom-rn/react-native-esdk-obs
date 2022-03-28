//
//  OBSPutObjectRequest.h
//  OBS
//
//  Created by MaxZhang on 07/11/2017.
//  Copyright © 2017 obs. All rights reserved.
//

#ifndef OBSPutObjectRequest_h
#define OBSPutObjectRequest_h

#import "OBSBaseNetworking.h"
#import "OBSClient.h"
#import "OBSServiceBaseModel.h"
#import "OBSServiceConstDefinition.h"

    //request
@class OBSAbstractEncryption;
#pragma mark - request

/**
 上传对象
 */
@protocol OBSPutObjectProtocol<NSObject>
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
 MD5值
 */
@property (nonatomic, strong, nonnull) NSString *contentMD5;

/**
 对象访问策略
 */
@property (nonatomic, assign) OBSACLPolicy objectACLPolicy;

/**
 对象存储类型
 */
@property (nonatomic, assign) OBSStorageClass storageClass;

/**
 元数据字典
 */
@property (nonatomic, strong, nullable) NSDictionary *metaDataDict;

/**
 重定向地址
 */
@property (nonatomic, strong, nonnull) NSString *websiteRedirectLocation;

/**
 加密方式
 */
@property (nonatomic, strong, nonnull) __kindof OBSAbstractEncryption *encryption;

/**
 上传进度
 */
@property (nonatomic, copy, nonnull) OBSNetworkingUploadProgressBlock uploadProgressBlock;
/**
 MIME类型
 */
@property (nonatomic, assign) OBSContentType contentType;
@end


/**
 上传对象request父类
 */
@interface OBSAbstractPutObjectRequest : OBSBaseRequest<OBSPutObjectProtocol>

/**
 桶名
 */
@property (nonatomic, strong, nonnull) NSString *bucketName;

/**
 对象描述标识
 */
@property (nonatomic, strong, nonnull) NSString *objectKey;

/**
 对象的MD5
 */
@property (nonatomic, strong, nonnull) NSString *contentMD5;

/**
 对象的ACL
 */
@property (nonatomic, assign) OBSACLPolicy objectACLPolicy;

/**
 对象存储类型
 */
@property (nonatomic, assign) OBSStorageClass storageClass;

/**
 对象元数据字典
 */
@property (nonatomic, strong, nullable) NSDictionary *metaDataDict;

/**
 对象重定向地址
 */
@property (nonatomic, strong, nonnull) NSString *websiteRedirectLocation;

/**
 创建对象时，使用此头域授权domain下所有用户有读对象和获取对象元数据的权限
 */
@property (nonatomic, strong, nonnull) NSString *granteRead;

/**
创建对象时，使用此头域授权domain下所有用户有读对象和获取对象元数据的权限
*/
@property (nonatomic, strong, nonnull) NSString *granteReadAcp;

/**
 创建对象时，使用此头域授权domain下所有用户有获取对象ACL的权限
 */
@property (nonatomic, strong, nonnull) NSString *granteWriteAcp;

/**
 创建对象时，使用此头域授权domain下所有用户有读对象、获取对象元数据、获取对象ACL、写对象ACL的权限
 */
@property (nonatomic, strong, nonnull) NSString *granteFullControl;

/**
 此参数的值是一个URL，用于指定当此次请求操作成功响应后的重定向的地址
 如果此参数值有效且操作成功，响应码为303，location头域由此参数以及桶名、对象名、对象的ETag组成
 如果此参数值无效，忽略此参数的作用，响应码为204，location头域为对象地址
 */
@property (nonatomic, strong, nonnull) NSString *actionRedirect;

/**
 表示上传对象的过期时间，单位是天
 */
@property (nonatomic, strong, nonnull) NSNumber *expires;

/**
 MIME类型
 */
@property (nonatomic, assign) OBSContentType contentType;

/**
 自定义MIME类型
 */
@property (nonatomic, strong, nonnull) NSString *customContentType;

/**
 最终映射MIME类型
 */
@property (nonatomic, strong, nonnull) NSString *finalContentType;

/**
 加密方式
 */
@property (nonatomic, strong, nonnull) __kindof OBSAbstractEncryption *encryption;

/**
 上传对象时的回调
 */
@property (nonatomic, copy, nonnull) OBSNetworkingUploadProgressBlock uploadProgressBlock;
@end


/**
 流式上传对象request
 */
@interface OBSPutObjectWithDataRequest: OBSAbstractPutObjectRequest

/**
 上传的数据
 */
@property (nonatomic, strong, nonnull) NSData *uploadData;

/**
 初始化流式上传对象request

 @param bucketName 桶名
 @param objectKey 对象名
 @param data 需要上传的对象数据
 @return 流式上传对象request
 */
-(instancetype)initWithBucketName:(NSString*) bucketName objectKey: (NSString*) objectKey uploadData:(NSData*) data;

/**
 初始上传网络流对象request

 @param bucketName 桶名
 @param objectKey 对象名
 @param dataURL 需要上传的网络流地址
 @return 上传网络流对象request
 */
-(instancetype)initWithBucketName:(NSString*) bucketName objectKey: (NSString*) objectKey uploadDataURL:(NSURL*) dataURL;
@end

/**
 通过文件上传对象request
 */
@interface OBSPutObjectWithFileRequest: OBSAbstractPutObjectRequest

/**
 文件路径
 */
@property (nonatomic, strong, nonnull) NSString *uploadFilePath;
@property (nonatomic, assign) BOOL background;

/**
 初始化通过文件上传对象request

 @param bucketName 桶名
 @param objectKey 对象描述标识
 @param uploadFilePath 文件路径
 @return 通过文件上传对象request
 */
-(instancetype)initWithBucketName:(NSString*) bucketName objectKey: (NSString*) objectKey uploadFilePath:(NSString*) uploadFilePath;
@end

#pragma mark - networking request
@interface OBSNetworkingPutObjectWithDataRequest : OBSServiceNetworkingUploadDataRequest
@end
@interface OBSNetworkingPutObjectWithFileRequest : OBSServiceNetworkingUploadFileRequest
@end

    //response
#pragma mark - response

/**
 上传对象响应
 */
@interface OBSPutObjectResponse: OBSServiceResponse

/**
 对象etag值
 */
@property (nonatomic, strong, nonnull) NSString *etag;

/**
 如果桶开启了多版本状态 则返回版本号
 */
@property (nonatomic, strong, nonnull) NSString *versionID;

/**
 对象存储类型
 */
@property (nonatomic, assign) OBSStorageClass storageClass;

/**
 对象加密方式
 */
@property (nonatomic, strong, nonnull) __kindof OBSAbstractEncryption *encryption;
@end

    //client method
#pragma mark - client method
@interface OBSClient(putObject)

/**
 上传对象

 @param request 上传对象request
 @param completionHandler 上传对象回调
 @return OBSBFTask
 */
- (OBSBFTask*)putObject:(__kindof OBSBaseRequest<OBSPutObjectProtocol>*)request
              completionHandler:(void (^)(OBSPutObjectResponse  * response, NSError * error))completionHandler;
@end
#endif  /* OBSPutObjectRequest_h */
