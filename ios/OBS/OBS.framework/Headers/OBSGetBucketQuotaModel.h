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

#ifndef OBSGetBucketQuotaModel_h
#define OBSGetBucketQuotaModel_h

#import "OBSBaseModel.h"
#import "OBSBaseNetworking.h"
#import "OBSClient.h"
#import "OBSServiceBaseModel.h"
#import "OBSServiceCommonEntities.h"


#pragma mark - entity


#pragma mark - request

/**
 获取桶配额
 */
@protocol OBSGetBucketQuotaProtocol
@required

/**
 桶名
 */
@property (nonatomic, strong, nonnull) NSString *bucketName;
@end


/**
 获取桶配额
 */
@interface OBSGetBucketQuotaRequest: OBSBaseRequest<OBSGetBucketQuotaProtocol>

/**
 桶名
 */
@property (nonatomic, strong, nonnull) NSString *bucketName;

/**
 初始化获取桶配额request

 @param bucketName 桶名
 @return 获取桶配额request
 */
-(instancetype)initWithBucketName:(NSString*) bucketName ;
@end

#pragma mark - networking request
@interface OBSGetBucketQuotaRequestNetworking : OBSServiceNetworkingCommandRequest
@end

    //response
#pragma mark - response

/**
 获取桶配额response
 */
@interface OBSGetBucketQuotaResponse: OBSServiceResponse

/**
 桶配额
 */
@property (nonatomic, strong, nonnull) OBSQuota *quota;
@end


#pragma mark - client method

@interface OBSClient(getBucketQuota)

/**
 获取桶配额

 @param request 获取桶配额request
 @param completionHandler 获取桶配额request
 @return OBSBFTask
 */
- (OBSBFTask*)getBucketQuota:(__kindof OBSBaseRequest<OBSGetBucketQuotaProtocol>*)request
           completionHandler:(void (^)(OBSGetBucketQuotaResponse * response, NSError * error))completionHandler;
@end

#endif /* OBSGetBucketQuotaModel_h */
