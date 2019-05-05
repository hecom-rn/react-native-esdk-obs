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

#ifndef OBSClient_h
#define OBSClient_h
#import "OBSLogging.h"

@class OBSBaseRequest;
@class OBSBFTask;
@class OBSBaseConfiguration;
@class OBSRequestConverter;


@interface OBSClient:NSObject
@property (nonatomic, strong, nonnull) OBSBaseConfiguration *configuration;


#pragma mark - init

/**
 client初始化

 @param configuration 配置参数
 @return client对象
 */
-(instancetype) initWithConfiguration: (__kindof OBSBaseConfiguration*) configuration;

#pragma mark - set logger
/* *Set log level, default level is info.
 log levels are:
 OBSDDLogLevelOff
 OBSDDLogLevelError
 OBSDDLogLevelWarning
 OBSDDLogLevelInfo
 OBSDDLogLevelDebug
 OBSDDLogLevelVerbose
*/

/**
 设置日志等级

 @param logLevel 日志种类
 OBSDDLogLevelOff
 OBSDDLogLevelError
 OBSDDLogLevelWarning
 OBSDDLogLevelInfo
 OBSDDLogLevelDebug
 OBSDDLogLevelVerbose
 */
-(void) setLogLevel:(OBSDDLogLevel) logLevel;

/**
  *Add custom logger, such as file logger
 */


/**
 添加日志logger

 @param logger 日志logger类型
 */
-(void) addLogger: (id <OBSDDLogger>) logger;


/**
  *Set Apple System Logger on, after turnning on this log could be seeing in the system's console app.
 */

/**
 开启窗口日志打印
 */
-(void) setASLogOn;

- (OBSBFTask*)invokeRequest:(OBSBaseRequest *) request;
-(BOOL)getOBSProtocol:(OBSBaseRequest *)request;
@end

#endif  /* OBSClient_h */
