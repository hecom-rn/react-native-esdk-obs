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

#ifndef OBSGetReplicateBucketModel_h
#define OBSGetReplicateBucketModel_h
#import "OBSBaseModel.h"
#import "OBSBaseNetworking.h"
#import "OBSClient.h"
#import "OBSServiceBaseModel.h"
#import "OBSServiceConstDefinition.h"
#import "OBSServiceCommonEntities.h"
#import "OBSServiceCredentialProvider.h"

    //request
#pragma mark - request entity


#pragma mark - request




/**
 获取桶的跨域复制
 */
@protocol OBSGetReplicateBucketProtocol
@required

/**
 桶名
 */
@property (nonatomic, strong, nonnull) NSString *bucketName;
@end


/**
 获取桶跨域复制request
 */
@interface OBSGetReplicateBucketRequest: OBSBaseRequest<OBSGetReplicateBucketProtocol>


/**
 桶名
 */
@property (nonatomic, strong, nonnull) NSString *bucketName;




/**
 初始化跨域复制桶的request

 @param bucketName 桶名

 @return 跨域复制桶的request
 */

-(instancetype)initWithBucketName:(NSString*) bucketName;

@end

#pragma mark - networking request
@interface OBSGetReplicateBucketRequestNetworking : OBSServiceNetworkingCommandRequest
@end

    //response
#pragma mark - response

/**
 获取桶的跨域复制response
 */
@interface OBSGetReplicateBucketResponse: OBSServiceResponse

@property (nonatomic, strong, nonnull) NSMutableArray<OBSReplicateBucketRule*> *replicateConfiguration;

@end


#pragma mark - client method
@interface OBSClient(getReplicateBucket)

/**
 获取桶的跨域复制

 @param request 获取桶的跨域复制request对象
 @param completionHandler 获取桶的跨域复制的回调
 @return task对象
 */
- (OBSBFTask*)getReplicateBucket:(__kindof OBSBaseRequest<OBSGetReplicateBucketProtocol>*)request
         completionHandler:(void (^)(OBSGetReplicateBucketResponse  * response, NSError * error))completionHandler;
@end


#endif  /* OBSServiceBaseModel_h */
