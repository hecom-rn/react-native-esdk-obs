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

#ifndef OBSSetBucketTaggingModel_h
#define OBSSetBucketTaggingModel_h

#import "OBSBaseModel.h"
#import "OBSBaseNetworking.h"
#import "OBSClient.h"
#import "OBSServiceBaseModel.h"
#import "OBSServiceCommonEntities.h"
#import "OBSServiceConstDefinition.h"


#pragma mark - request

/**
 设置桶标签
 */
@protocol OBSSetBucketTaggingProtocol
@required

/**
 桶名
 */
@property (nonatomic, strong, nonnull) NSString *bucketName;
@end


/**
 设置桶标签request
 */
@interface OBSSetBucketTaggingRequest: OBSBaseRequest<OBSSetBucketTaggingProtocol>

/**
 桶名
 */
@property (nonatomic, strong, nonnull) NSString *bucketName;

/**
 标签表
 */
@property (nonatomic, strong, nonnull) NSMutableArray<OBSBucketTag*> *tagList;

/**
 初始化设置桶标签request

 @param bucketName 桶名
 @return 设置桶标签request
 */
-(instancetype)initWithBucketName:(NSString*) bucketName;
@end


#pragma mark - networking request
@interface OBSSetBucketTaggingRequestNetworking : OBSServiceNetworkingCommandRequest
@end


    //response
#pragma mark - response

/**
 设置桶标签response
 */
@interface OBSSetBucketTaggingResponse: OBSServiceResponse
@end


#pragma mark - client method
@interface OBSClient(setBucketTagging)

/**
 设置桶标签

 @param request 设置桶标签request
 @param completionHandler 设置桶标签回调
 @return OBSBFTask
 */
- (OBSBFTask*)setBucketTagging:(__kindof OBSBaseRequest<OBSSetBucketTaggingProtocol>*)request
             completionHandler:(void (^)(OBSSetBucketTaggingResponse  * response, NSError * error))completionHandler;
@end
#endif /* OBSSetBucketTaggingModel_h */
