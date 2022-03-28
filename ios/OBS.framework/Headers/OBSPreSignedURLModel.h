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

#ifndef OBSPreSignedURLModel_h
#define OBSPreSignedURLModel_h

#import "OBSBaseModel.h"
#import "OBSBaseNetworking.h"
#import "OBSClient.h"
#import "OBSServiceBaseModel.h"
#import "OBSServiceCredentialProvider.h"

// 定义协议种类
static OBSProtocolType protocolPreSignedURL;

#pragma mark - client method
@interface OBSClient(preSignedURL)

/**
 获得V2临时鉴权URL

 @param request 所有继承OBSBaseRequest的request对象
 @param expire 有效时间
 @param completionHandler 回调
 @return OBSBFTask
 */
- (OBSBFTask*)createV2PreSignedURL:(__kindof OBSBaseRequest*)request expireAfter:(long long) expire completionHandler:(void (^)(NSString *urlString, NSString * httpVerb, NSDictionary *signedHeaders))completionHandler;
/**
 获得V4临时鉴权URL
 
 @param request 所有继承OBSBaseRequest的request对象
 @param expire 有效时间
 @param completionHandler 回调
 @return OBSBFTask
 */
- (OBSBFTask*)createV4PreSignedURL:(__kindof OBSBaseRequest*)request expireAfter:(long long) expire completionHandler:(void (^)(NSString *urlString, NSString *httpVerb, NSDictionary *signedHeaders))completionHandler;
@end
#endif  /* OBSPreSignedURLModel_h */
