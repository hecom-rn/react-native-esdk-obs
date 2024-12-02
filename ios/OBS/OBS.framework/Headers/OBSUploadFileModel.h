//
//  OBSUploadFileModel.h
//  OBS
//
//  Created by MaxZhang on 11/12/2017.
//  Copyright © 2017 obs. All rights reserved.
//

#ifndef OBSUploadFileModel_h
#define OBSUploadFileModel_h
#import "OBSBaseModel.h"
#import "OBSBaseNetworking.h"
#import "OBSClient.h"
#import "OBSServiceBaseModel.h"
#import "OBSServiceConstDefinition.h"
@class OBSAbstractEncryption;

#pragma mark - request

/**
 断点续传
 */
@protocol OBSUploadFileProtocol<NSObject>
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
 访问策略
 */
@property (nonatomic, assign) OBSACLPolicy objectACLPolicy;

/**
 存储类型
 */
@property (nonatomic, assign) OBSStorageClass storageClass;

/**
 元数据
 */
@property (nonatomic, strong, nullable) NSDictionary *metaDataDict;

/**
 重定向站点
 */
@property (nonatomic, strong, nonnull) NSString *websiteRedirectLocation;

/**
 加密方式
 */
@property (nonatomic, strong, nonnull) __kindof OBSAbstractEncryption *encryption;

/**
 上传文件地址
 */
@property (nonatomic, strong, nonnull) NSString *uploadFilePath;

/**
 上传进度
 */
@property (atomic, copy, nonnull) OBSNetworkingUploadProgressBlock uploadProgressBlock;

/**
 开启断点续传
 */
@property (nonatomic, assign) BOOL enableCheckpoint;

/**
 开启MD5校验
 */
@property (nonatomic, assign) BOOL enableMD5Check;

/**
 开启分段MD5校验
 */
@property (nonatomic, assign) BOOL enablePartMD5Check;

/**
 设置断点续传模式下，记录上传进度的文件
 */
@property (nonatomic, strong, nonnull) NSString *checkpointFilePath;

/**
 分段大小
 */
@property (nonatomic, strong, nonnull) NSNumber *partSize;

/**
 MIME类型
 */
@property (nonatomic, assign) OBSContentType contentType;

@end


/**
 断点续传request
 */
@interface OBSUploadFileRequest: OBSBaseRequest<OBSUploadFileProtocol>

/**
 上传数据
 */
@property (nonatomic, strong) NSData *uploadAllData; 

@property (nonatomic, strong) NSFileHandle *fileHandle;
/**
 上传路径，避免多次重新读取数据映射造成内存问题
 */
@property (nonatomic, strong) NSString *lastUploadFilePath;  

/**
 桶名
 */
@property (nonatomic, strong, nonnull) NSString *bucketName;

/**
 对象key
 */
@property (nonatomic, strong, nonnull) NSString *objectKey;

/**
 对象ACL
 */
@property (nonatomic, assign) OBSACLPolicy objectACLPolicy;

/**
 存储模式
 */
@property (nonatomic, assign) OBSStorageClass storageClass;

/**
 元数据
 */
@property (nonatomic, strong, nullable) NSDictionary *metaDataDict;

/**
 网址重定向
 */
@property (nonatomic, strong, nonnull) NSString *websiteRedirectLocation;

/**
 加密方式
 */
@property (nonatomic, strong, nonnull) __kindof OBSAbstractEncryption *encryption;

/**
 上传文件路径
 */
@property (nonatomic, strong, nonnull) NSString *uploadFilePath;

/**
 上传回调
 */
@property (atomic, copy, nonnull) OBSNetworkingUploadProgressBlock uploadProgressBlock;

/**
 是否支持断点续传
 */
@property (nonatomic, assign) BOOL enableCheckpoint;

/**
 文件MD5校验
 */
@property (nonatomic, assign) BOOL enableMD5Check;

/**
 设置断点续传模式下，记录上传进度的文件
 */
@property (nonatomic, strong, nonnull) NSString *checkpointFilePath;

/**
 分段大小
 */
@property (nonatomic, strong, nonnull) NSNumber *partSize;

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
 初始化断点续传request

 @param bucketName 桶名
 @param objectKey 对象key
 @param uploadFilePath 上传文件路径
 @return 断点续传request
 */
-(instancetype)initWithBucketName:(NSString*) bucketName objectKey:(NSString*) objectKey uploadFilePath:(NSString*) uploadFilePath;
@end

    //response
#pragma mark - response

/**
 断点续传response
 */
@interface OBSUploadFileResponse: OBSServiceResponse

/**
 上传对象etag
 */
@property (nonatomic, strong, nonnull) NSString *etag;

/**
 加密方式
 */
@property (nonatomic, strong, nonnull) __kindof OBSAbstractEncryption *encryption;
@end

    //client method
#pragma mark - client method
@interface OBSClient(uploadFile)

/**
 上传文件

 @param request 断点续传request
 @param completionHandler 断点续传回调
 @return OBSBFTask
 */
- (OBSBFTask*)uploadFile:(__kindof OBSBaseRequest<OBSUploadFileProtocol>*)request
         completionHandler:(void (^)(OBSUploadFileResponse  * response, NSError * error))completionHandler;
@end

#endif /* OBSUploadFileModel_h */
