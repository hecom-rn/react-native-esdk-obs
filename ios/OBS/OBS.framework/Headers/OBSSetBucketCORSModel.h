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

#ifndef OBSSetBucketCORSModel_h
#define OBSSetBucketCORSModel_h

#import "OBSBaseModel.h"
#import "OBSBaseNetworking.h"
#import "OBSClient.h"
#import "OBSServiceBaseModel.h"
#import "OBSServiceCommonEntities.h"





#pragma mark - request

/**
 跨域资源共享设置
 */
@protocol OBSSetBucketCORSProtocol
@required

/**
 桶名
 */
@property (nonatomic, strong, nonnull) NSString *bucketName;

/**
 跨域资源共享设置规则列表
 */
@property (nonatomic, strong, nonnull) NSMutableArray<OBSCORSRule*> *bucketCORSRuleList;
@end


/**
 跨域资源共享设置请求
 */
@interface OBSSetBucketCORSRequest: OBSBaseRequest<OBSSetBucketCORSProtocol>

/**
 桶名
 */
@property (nonatomic, strong, nonnull) NSString *bucketName;

/**
 cors配置列表
 */
@property (nonatomic, strong, nonnull) NSMutableArray<OBSCORSRule*> *bucketCORSRuleList;

/**
 初始化跨域资源共享request

 @param bucketName 桶名
 @return 跨域资源共享request
 */
-(instancetype)initWithBucketName:(NSString*) bucketName;
@end

#pragma mark - networking request
@interface OBSSetBucketCORSRequestNetworking : OBSServiceNetworkingCommandRequest
@end

    //response
#pragma mark - response

/**
 设置桶CORS response
 */
@interface OBSSetBucketCORSResponse: OBSServiceResponse
@end


#pragma mark - client method
@interface OBSClient(setBucketCORS)

/**
 设置CORS

 @param request 设置桶CORS request
 @param completionHandler 设置CORS回调
 @return task对象
 */
- (OBSBFTask*)setBucketCORS:(__kindof OBSBaseRequest<OBSSetBucketCORSProtocol>*)request
                completionHandler:(void (^)(OBSSetBucketCORSResponse * response, NSError * error))completionHandler;
@end
#endif /* OBSSetBucketCORSModel_h */
