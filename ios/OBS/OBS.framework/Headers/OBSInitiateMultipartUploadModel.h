//
//  OBSInitiateMultipartUploadModel.h
//  OBS
//
//  Created by MaxZhang on 01/12/2017.
//  Copyright © 2017 obs. All rights reserved.
//

#ifndef OBSInitiateMultipartUploadModel_h
#define OBSInitiateMultipartUploadModel_h

#import "OBSBaseNetworking.h"
#import "OBSClient.h"
#import "OBSServiceBaseModel.h"
#import "OBSServiceConstDefinition.h"

@class OBSAbstractEncryption;
    //request
#pragma mark - request

/**
 初始化多段上传任务
 */
@protocol OBSInitiateMultipartUploadProtocol<NSObject>
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
 对象访问策略
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
 对象重定向
 */
@property (nonatomic, strong, nonnull) NSString *websiteRedirectLocation;

/**
 加密方式
 */
@property (nonatomic, strong, nonnull) __kindof OBSAbstractEncryption *encryption;
/**
 MIME类型
 */
@property (nonatomic, assign) OBSContentType contentType;

@end



/**
 初始化多段上传任务request
 */
@interface OBSInitiateMultipartUploadRequest : OBSBaseRequest<OBSInitiateMultipartUploadProtocol>

/**
 桶名
 */
@property (nonatomic, strong, nonnull) NSString *bucketName;

/**
 对象KEY
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
 重定向网址
 */
@property (nonatomic, strong, nonnull) NSString *websiteRedirectLocation;

/**
 加密方式
 */
@property (nonatomic, strong, nullable) __kindof OBSAbstractEncryption *encryption;

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
 初始化多段上传任务request

 @param bucketName 桶名
 @param objectKey 对象KEY
 @return 初始化多段上传任务request
 */
-(instancetype)initWithBucketName:(NSString*) bucketName objectKey: (NSString*) objectKey;
@end

#pragma mark - networking request
@interface OBSNetworkingInitiateMultipartUploadRequest : OBSServiceNetworkingCommandRequest
@end

    //response
#pragma mark - response

/**
 初始化多段上传任务response
 */
@interface OBSInitiateMultipartUploadResponse: OBSServiceResponse

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
 存储类型
 */
@property (nonatomic, assign) OBSStorageClass storageClass;

/**
 加密方式
 */
@property (nonatomic, strong, nonnull) __kindof OBSAbstractEncryption *encryption;
@end

    //client method
#pragma mark - client method
@interface OBSClient(initiateMultipartUpload)

/**
 初始化多段上传任务

 @param request 初始化多段上传任务request
 @param completionHandler 初始化多段上传任务回调
 @return OBSBFTask
 */
- (OBSBFTask*)initiateMultipartUpload:(__kindof OBSBaseRequest<OBSInitiateMultipartUploadProtocol>*)request
      completionHandler:(void (^)(OBSInitiateMultipartUploadResponse  * response, NSError * error))completionHandler;
@end
#endif /* OBSInitiateMultipartUploadModel_h */
