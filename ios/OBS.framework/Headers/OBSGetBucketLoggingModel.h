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

#ifndef OBSGetBucketLoggingModel_h
#define OBSGetBucketLoggingModel_h

#import "OBSBaseModel.h"
#import "OBSBaseNetworking.h"
#import "OBSClient.h"
#import "OBSServiceBaseModel.h"
#import "OBSServiceCommonEntities.h"


#pragma mark - entity


#pragma mark - request

/**
 获取桶日志
 */
@protocol OBSGetBucketLoggingProtocol
@required

/**
 桶名
 */
@property (nonatomic, strong, nonnull) NSString *bucketName;
@end


/**
 获取桶日志request
 */
@interface OBSGetBucketLoggingRequest: OBSBaseRequest<OBSGetBucketLoggingProtocol>

/**
 桶名
 */
@property (nonatomic, strong, nonnull) NSString *bucketName;


/**
 初始化获取桶日志request

 @param bucketName 桶名
 @return 获取桶日志request
 */
-(instancetype)initWithBucketName:(NSString*) bucketName;
@end

#pragma mark - networking request
@interface OBSGetBucketLoggingRequestNetworking : OBSServiceNetworkingCommandRequest
@end

    //response
#pragma mark - response

/**
 获取桶日志response
 */
@interface OBSGetBucketLoggingResponse: OBSServiceResponse

/**
 桶日志配置列表
 */
@property (nonatomic, strong, nonnull) NSMutableArray<OBSLoggingEnabled*> *loggingEnabledList;
@end


#pragma mark - client method
@interface OBSClient(getBucketLogging)

/**
 获取桶日志

 @param request 获取桶日志request
 @param completionHandler 获取桶日志回调
 @return OBSBFTask
 */
- (OBSBFTask*)getBucketLogging:(__kindof OBSBaseRequest<OBSGetBucketLoggingProtocol>*)request
             completionHandler:(void (^)(OBSGetBucketLoggingResponse * response, NSError * error))completionHandler;
@end
#endif /* OBSGetBucketLoggingModel_h */
