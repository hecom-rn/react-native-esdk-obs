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

#ifndef OBSSetBucketQuotaModel_h
#define OBSSetBucketQuotaModel_h

#import "OBSBaseModel.h"
#import "OBSBaseNetworking.h"
#import "OBSClient.h"
#import "OBSServiceBaseModel.h"
#import "OBSServiceCommonEntities.h"


#pragma mark - entity


#pragma mark - request

/**
 设置桶配额
 */
@protocol OBSSetBucketQuotaProtocol
@required

/**
 桶名
 */
@property (nonatomic, strong, nonnull) NSString *bucketName;

/**
 桶配额
 */
@property (nonatomic, strong, nonnull) OBSQuota *quota;
@end



/**
 设置桶配额
 */
@interface OBSSetBucketQuotaRequest: OBSBaseRequest<OBSSetBucketQuotaProtocol>

/**
 桶名
 */
@property (nonatomic, strong, nonnull) NSString *bucketName;

/**
 桶配额
 */
@property (nonatomic, strong, nonnull) OBSQuota *quota;

/**
 初始化设置桶配额request

 @param bucketName 桶名
 @param quota 桶容量对象
 @return 设置桶配额request
 */
-(instancetype)initWithBucketName:(NSString*) bucketName quota:(OBSQuota*)quota;
@end

#pragma mark - networking request
@interface OBSSetBucketQuotaRequestNetworking : OBSServiceNetworkingCommandRequest
@end

    //response
#pragma mark - response

/**
 设置桶配额response
 */
@interface OBSSetBucketQuotaResponse: OBSServiceResponse
@end


#pragma mark - client method
@interface OBSClient(setBucketQuota)

/**
 设置桶配额

 @param request 设置桶配额request对象
 @param completionHandler 设置桶配额回调
 @return OBSBFTask
 */
- (OBSBFTask*)setBucketQuota:(__kindof OBSBaseRequest<OBSSetBucketQuotaProtocol>*)request
          completionHandler:(void (^)(OBSSetBucketQuotaResponse * response, NSError * error))completionHandler;
@end
#endif /* OBSSetBucketQuotaModel_h */
