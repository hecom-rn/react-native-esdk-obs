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

#ifndef OBSGetBucketCORSModel_h
#define OBSGetBucketCORSModel_h

#import "OBSBaseModel.h"
#import "OBSBaseNetworking.h"
#import "OBSClient.h"
#import "OBSServiceBaseModel.h"
#import "OBSServiceCommonEntities.h"

#pragma mark - request

/**
 获取桶的CORS配置
 */
@protocol OBSGetBucketCORSProtocol
@required

/**
 桶名
 */
@property (nonatomic, strong, nonnull) NSString *bucketName;
@end


/**
 获取桶的CORS配置request
 */
@interface OBSGetBucketCORSRequest: OBSBaseRequest<OBSGetBucketCORSProtocol>

/**
 桶名
 */
@property (nonatomic, strong, nonnull) NSString *bucketName;

/**
 初始化获取桶的CORS配置request

 @param bucketName 桶名
 @return 获取桶CORS配置request
 */
-(instancetype)initWithBucketName:(NSString*) bucketName;
@end

#pragma mark - networking request
@interface OBSGetBucketCORSRequestNetworking : OBSServiceNetworkingCommandRequest
@end

    //response
#pragma mark - response

/**
 获取桶CORS配置response
 */
@interface OBSGetBucketCORSResponse: OBSServiceResponse

/**
 CORS配置列表
 */
@property (nonatomic, strong, nonnull) NSArray<OBSCORSRule*> *bucketCORSRuleList;
@end


#pragma mark - client method
@interface OBSClient(getBucketCORS)

/**
 获取桶CORS

 @param request 获取桶CORS request
 @param completionHandler 获取桶CORS回调
 @return OBSBFTask
 */
- (OBSBFTask*)getBucketCORS:(__kindof OBSBaseRequest<OBSGetBucketCORSProtocol>*)request
          completionHandler:(void (^)(OBSGetBucketCORSResponse * response, NSError * error))completionHandler;
@end
#endif /* OBSGetBucketCORSModel_h */
