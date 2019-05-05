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

#ifndef OBSGetBucketTaggingModel_h
#define OBSGetBucketTaggingModel_h
#import "OBSBaseModel.h"
#import "OBSBaseNetworking.h"
#import "OBSClient.h"
#import "OBSServiceBaseModel.h"
#import "OBSServiceCommonEntities.h"
#import "OBSServiceConstDefinition.h"


#pragma mark - request

/**
 获取桶标签
 */
@protocol OBSGetBucketTaggingProtocol
@required

/**
 桶名
 */
@property (nonatomic, strong, nonnull) NSString *bucketName;
@end


/**
 获取桶标签request
 */
@interface OBSGetBucketTaggingRequest: OBSBaseRequest<OBSGetBucketTaggingProtocol>

/**
 桶名
 */
@property (nonatomic, strong, nonnull) NSString *bucketName;

/**
 初始化获取桶标签request

 @param bucketName 桶名
 @return 获取桶标签request
 */
-(instancetype)initWithBucketName:(NSString*) bucketName;
@end

#pragma mark - networking request
@interface OBSGetBucketTaggingRequestNetworking : OBSServiceNetworkingCommandRequest
@end

    //response
#pragma mark - response

/**
 获取桶标签response
 */
@interface OBSGetBucketTaggingResponse: OBSServiceResponse

/**
 标签列表
 */
@property (nonatomic, strong, nonnull)  NSArray<OBSBucketTag*> *tagList;
@end


#pragma mark - client method
@interface OBSClient(getBucketTagging)

/**
 获取桶标签

 @param request 获取桶标签request
 @param completionHandler 获取桶标签回调
 @return OBSBFTask
 */
- (OBSBFTask*)getBucketTagging:(__kindof OBSBaseRequest<OBSGetBucketTaggingProtocol>*)request
             completionHandler:(void (^)(OBSGetBucketTaggingResponse  * response, NSError * error))completionHandler;
@end



#endif /* OBSGetBucketTaggingModel_h */
