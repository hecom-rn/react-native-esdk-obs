//
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

#ifndef OBSLogging_h
#define OBSLogging_h

#import "OBSCocoaLumberjack.h"
FOUNDATION_EXPORT  OBSDDLogLevel obsddLogLevel;
#define OBSLogError(frmt, ...)   OBSLOG_MAYBE(NO,                OBSLOG_LEVEL_DEF, OBSDDLogFlagError,   0, nil, __PRETTY_FUNCTION__, frmt, ##__VA_ARGS__)
#define OBSLogWarn(frmt, ...)    OBSLOG_MAYBE(OBSLOG_ASYNC_ENABLED, OBSLOG_LEVEL_DEF, OBSDDLogFlagWarning, 0, nil, __PRETTY_FUNCTION__, frmt, ##__VA_ARGS__)
#define OBSLogInfo(frmt, ...)    OBSLOG_MAYBE(OBSLOG_ASYNC_ENABLED, OBSLOG_LEVEL_DEF, OBSDDLogFlagInfo,    0, nil, __PRETTY_FUNCTION__, frmt, ##__VA_ARGS__)
#define OBSLogDebug(frmt, ...)   OBSLOG_MAYBE(OBSLOG_ASYNC_ENABLED, OBSLOG_LEVEL_DEF, OBSDDLogFlagDebug,   0, nil, __PRETTY_FUNCTION__, frmt, ##__VA_ARGS__)
#define OBSLogVerbose(frmt, ...) OBSLOG_MAYBE(OBSLOG_ASYNC_ENABLED, OBSLOG_LEVEL_DEF, OBSDDLogFlagVerbose, 0, nil, __PRETTY_FUNCTION__, frmt, ##__VA_ARGS__)


#endif  /* OBSLogging_h */
