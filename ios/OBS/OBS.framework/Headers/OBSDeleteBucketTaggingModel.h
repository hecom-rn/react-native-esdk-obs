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

#ifndef OBSDeleteBucketTaggingModel_h
#define OBSDeleteBucketTaggingModel_h

#import "OBSBaseModel.h"
#import "OBSBaseNetworking.h"
#import "OBSClient.h"
#import "OBSServiceBaseModel.h"
#import "OBSServiceCommonEntities.h"
#import "OBSServiceConstDefinition.h"


#pragma mark - request

/**
 删除桶标签
 */
@protocol OBSDeleteBucketTaggingProtocol
@required

/**
 桶名
 */
@property (nonatomic, strong, nonnull) NSString *bucketName;
@end


/**
 删除桶标签request
 */
@interface OBSDeleteBucketTaggingRequest: OBSBaseRequest<OBSDeleteBucketTaggingProtocol>

/**
 桶名
 */
@property (nonatomic, strong, nonnull) NSString *bucketName;

/**
 初始化删除桶标签request

 @param bucketName 桶名
 @return 删除桶标签request
 */
-(instancetype)initWithBucketName:(NSString*) bucketName;
@end

#pragma mark - networking request
@interface OBSDeleteBucketTaggingRequestNetworking : OBSServiceNetworkingCommandRequest
@end

    //response
#pragma mark - response

/**
 删除桶标签response
 */
@interface OBSDeleteBucketTaggingResponse: OBSServiceResponse
@end


#pragma mark - client method
@interface OBSClient(deleteBucketTagging)

/**
 删除桶标签

 @param request 删除桶标签request
 @param completionHandler 删除桶标签回调
 @return OBSBFTask
 */
- (OBSBFTask*)deleteBucketTagging:(__kindof OBSBaseRequest<OBSDeleteBucketTaggingProtocol>*)request
                completionHandler:(void (^)(OBSDeleteBucketTaggingResponse  * response, NSError * error))completionHandler;
@end
#endif /* OBSDeleteBucketTaggingModel_h */
