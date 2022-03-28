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

#import <Foundation/Foundation.h>
#import <os/lock.h>
#import <CommonCrypto/CommonCrypto.h>
#import "OBSBaseNetworking.h"
#import "OBSBaseModel.h"




@interface OBSProtocol : NSObject

@property(nonatomic,strong)NSLock *nslock0;
@property(nonatomic,strong)NSLock *nslock1;
@property(nonatomic,strong)NSLock *nslock2;
@property(nonatomic,strong)NSLock *nslock3;
@property(nonatomic,strong)NSLock *nslock4;
@property(nonatomic,strong)NSLock *nslock5;
@property(nonatomic,strong)NSLock *nslock6;
@property(nonatomic,strong)NSLock *nslock7;
@property(nonatomic,strong)NSLock *nslock8;
@property(nonatomic,strong)NSLock *nslock9;

// 单例
+(OBSProtocol *)sharedOBSProtocol;

//列举桶
-(BOOL)getObsProtocolListBucket:(int)times endPoint:(NSURL*)endPoint baseRequest:(OBSBaseRequest *) baseRequest;
//创建桶
-(BOOL)getObsProtocolCreatBucket:(int)times bucketName:(NSString*)bucketName endPoint:(NSURL*)endPoint baseRequest:(OBSBaseRequest *) baseRequest;
//其他接口
-(BOOL)getObsProtocolOthers:(int)times bucketName:(NSString*)bucketName endPoint:(NSURL*)endPoint baseRequest:(OBSBaseRequest *) baseRequest;


@end
