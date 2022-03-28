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

#ifndef OBSListBucketsModel_h
#define OBSListBucketsModel_h
#import "OBSBaseModel.h"
#import "OBSBaseNetworking.h"
#import "OBSClient.h"
#import "OBSServiceBaseModel.h"
#import "OBSServiceCommonEntities.h"
#import "OBSServiceCredentialProvider.h"




#pragma mark - ListBuckets

    //request
#pragma mark - request
@protocol OBSListBucketsProtocol<NSObject>
@end

// 桶列表类
@interface OBSListBucketsRequest: OBSBaseRequest<OBSListBucketsProtocol>
/**
 是否返回桶的区域信息
 */
@property (nonatomic, assign) NSString *isQueryLocation;

@end

    //networking request
#pragma mark - networking request
@interface OBSListBucketsRequestNetworking : OBSServiceNetworkingCommandRequest
@end

@interface OBSListBucketsAdditionalProcessor : NSObject<OBSNetworkingRequestPostProcessor>
@end

    //response
#pragma mark - response
@interface OBSBucket:OBSBaseEntity
@property (nonatomic, strong, nonnull) NSString *name;
@property (nonatomic, strong,nonnull) NSString *location;
@property (nonatomic, strong, nonnull) NSDate *creationDate;
@end

@interface OBSListBucketsResponse: OBSServiceResponse

/**
 用户信息，包含用户DomainId和用户名
 */
@property (nonatomic, strong, nonnull) OBSUser *owner;

/**
 返回桶列表数组
 */
@property (nonatomic, strong, nonnull) NSArray<OBSBucket*>  *bucketsList;
@end

#pragma mark - client method
@interface OBSClient(listBuckets)

/**
 列举桶 

 @param request 列举桶列表request
 @param completionHandler 列举桶列表回调
 @return OBSBFTask对象
 */
- (OBSBFTask*)listBuckets:(__kindof OBSBaseRequest<OBSListBucketsProtocol>*)request
        completionHandler:(void (^)(OBSListBucketsResponse  * , NSError  *  error))completionHandler;
@end
#endif  /* OBSListBucketsModel_h */
