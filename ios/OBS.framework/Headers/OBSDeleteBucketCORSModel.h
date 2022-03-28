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

#ifndef OBSDeleteBucketCORSModel_h
#define OBSDeleteBucketCORSModel_h
#import "OBSBaseModel.h"
#import "OBSBaseNetworking.h"
#import "OBSClient.h"
#import "OBSServiceBaseModel.h"
#import "OBSServiceCommonEntities.h"

#pragma mark - request

/**
 删除桶CORS
 */
@protocol OBSDeleteBucketCORSProtocol
@required

/**
 桶名
 */
@property (nonatomic, strong, nonnull) NSString *bucketName;
@end

/**
 删除桶CORS request
 */
@interface OBSDeleteBucketCORSRequest: OBSBaseRequest<OBSDeleteBucketCORSProtocol>

/**
 桶名
 */
@property (nonatomic, strong, nonnull) NSString *bucketName;

/**
 初始化删除桶CORS request

 @param bucketName 桶名
 @return 删除桶CORS request
 */
-(instancetype)initWithBucketName:(NSString*) bucketName;
@end

#pragma mark - networking request
@interface OBSDeleteBucketCORSRequestNetworking : OBSServiceNetworkingCommandRequest
@end

    //response
#pragma mark - response

/**
 删除桶CORS response
 */
@interface OBSDeleteBucketCORSResponse: OBSServiceResponse
@end


#pragma mark - client method
@interface OBSClient(deleteBucketCORS)

/**
 删除桶CORS

 @param request 删除桶CORS request
 @param completionHandler 删除桶CORS回调
 @return OBSBFTask
 */
- (OBSBFTask*)deleteBucketCORS:(__kindof OBSBaseRequest<OBSDeleteBucketCORSProtocol>*)request
          completionHandler:(void (^)(OBSDeleteBucketCORSResponse * response, NSError * error))completionHandler;
@end

#endif /* OBSDeleteBucketCORSModel_h */
