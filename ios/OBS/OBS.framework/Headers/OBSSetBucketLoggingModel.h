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

#ifndef OBSSetBucketLoggingModel_h
#define OBSSetBucketLoggingModel_h

#import "OBSBaseModel.h"
#import "OBSBaseNetworking.h"
#import "OBSClient.h"
#import "OBSServiceBaseModel.h"
#import "OBSServiceCommonEntities.h"


#pragma mark - entity


#pragma mark - request
/**
 设置桶日志
 */
@protocol OBSSetBucketLoggingProtocol
@required

/**
 桶名
 */
@property (nonatomic, strong, nonnull) NSString *bucketName;
@end



/**
 设置桶日志request
 */
@interface OBSSetBucketLoggingRequest: OBSBaseRequest<OBSSetBucketLoggingProtocol>

/**
 桶名
 */
@property (nonatomic, strong, nonnull) NSString *bucketName;



/**
 日志配置数组
 */
@property (nonatomic, strong, nonnull) NSMutableArray<OBSLoggingEnabled*> *loggingEnabledList;

/**
 初始化设置桶日志request

 @param bucketName 桶名
 @return 设置桶日志request
 */
-(instancetype)initWithBucketName:(NSString*) bucketName;
@end

#pragma mark - networking request


@interface OBSSetBucketLoggingRequestNetworking : OBSServiceNetworkingCommandRequest
@end

    //response
#pragma mark - response

/**
 设置桶日志response
 */
@interface OBSSetBucketLoggingResponse: OBSServiceResponse
@end


#pragma mark - client method
@interface OBSClient(setBucketLogging)

/**
 设置桶日志

 @param request 设置桶日志request
 @param completionHandler 设置桶日志回调
 @return OBSBFTask
 */
- (OBSBFTask*)setBucketLogging:(__kindof OBSBaseRequest<OBSSetBucketLoggingProtocol>*)request
           completionHandler:(void (^)(OBSSetBucketLoggingResponse * response, NSError * error))completionHandler;
@end
#endif /* OBSSetBucketLoggingModel_h */
