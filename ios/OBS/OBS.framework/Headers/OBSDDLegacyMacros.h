// Software License Agreement (BSD License)
//
// Copyright (c) 2010-2016, Deusty, LLC
// All rights reserved.
//
// Redistribution and use of this software in source and binary forms,
// with or without modification, are permitted provided that the following conditions are met:
//
//  *Redistributions of source code must retain the above copyright notice,
//   this list of conditions and the following disclaimer.
//
//  *Neither the name of Deusty nor the names of its contributors may be used
//   to endorse or promote products derived from this software without specific
//   prior written permission of Deusty, LLC.

/**
  *Legacy macros used for 1.9.x backwards compatibility.
 *
  *Imported by default when importing a OBSDDLog.h directly and OBSDD_LEGACY_MACROS is not defined and set to 0.
 **/
#if OBSDD_LEGACY_MACROS

#warning CocoaLumberjack 1.9.x legacy macros enabled. \
Disable legacy macros by importing CocoaLumberjack.h or OBSDDLogMacros.h instead of OBSDDLog.h or add `#define OBSDD_LEGACY_MACROS 0` before importing OBSDDLog.h.

#ifndef OBSLOG_LEVEL_DEF
    #define OBSLOG_LEVEL_DEF obsddLogLevel
#endif

#define OBSLOG_FLAG_ERROR    OBSDDLogFlagError
#define OBSLOG_FLAG_WARN     OBSDDLogFlagWarning
#define OBSLOG_FLAG_INFO     OBSDDLogFlagInfo
#define OBSLOG_FLAG_DEBUG    OBSDDLogFlagDebug
#define OBSLOG_FLAG_VERBOSE  OBSDDLogFlagVerbose

#define OBSLOG_LEVEL_OFF     OBSDDLogLevelOff
#define OBSLOG_LEVEL_ERROR   OBSDDLogLevelError
#define OBSLOG_LEVEL_WARN    OBSDDLogLevelWarning
#define OBSLOG_LEVEL_INFO    OBSDDLogLevelInfo
#define OBSLOG_LEVEL_DEBUG   OBSDDLogLevelDebug
#define OBSLOG_LEVEL_VERBOSE OBSDDLogLevelVerbose
#define OBSLOG_LEVEL_ALL     OBSDDLogLevelAll

#define OBSLOG_ASYNC_ENABLED YES

#define OBSLOG_ASYNC_ERROR    ( NO && OBSLOG_ASYNC_ENABLED)
#define OBSLOG_ASYNC_WARN     (YES && OBSLOG_ASYNC_ENABLED)
#define OBSLOG_ASYNC_INFO     (YES && OBSLOG_ASYNC_ENABLED)
#define OBSLOG_ASYNC_DEBUG    (YES && OBSLOG_ASYNC_ENABLED)
#define OBSLOG_ASYNC_VERBOSE  (YES && OBSLOG_ASYNC_ENABLED)

#define OBSLOG_MACRO(isAsynchronous, lvl, flg, ctx, atag, fnct, frmt, ...) \
        [OBSDDLog log : isAsynchronous                                     \
             level : lvl                                                \
              flag : flg                                                \
           context : ctx                                                \
              file : __FILE__                                           \
          function : fnct                                               \
              line : __LINE__                                           \
               tag : atag                                               \
            format : (frmt), ## __VA_ARGS__]

#define OBSLOG_MAYBE(async, lvl, flg, ctx, fnct, frmt, ...)                       \
        do { if(lvl & flg) LOG_MACRO(async, lvl, flg, ctx, nil, fnct, frmt, ##__VA_ARGS__); } while(0)

#define OBSLOG_OBJC_MAYBE(async, lvl, flg, ctx, frmt, ...) \
        OBSLOG_MAYBE(async, lvl, flg, ctx, __PRETTY_FUNCTION__, frmt, ## __VA_ARGS__)

#define OBSDDLogError(frmt, ...)   OBSLOG_OBJC_MAYBE(OBSLOG_ASYNC_ERROR,   OBSLOG_LEVEL_DEF, OBSLOG_FLAG_ERROR,   0, frmt, ##__VA_ARGS__)
#define OBSDDLogWarn(frmt, ...)    OBSLOG_OBJC_MAYBE(OBSLOG_ASYNC_WARN,    OBSLOG_LEVEL_DEF, OBSLOG_FLAG_WARN,    0, frmt, ##__VA_ARGS__)
#define OBSDDLogInfo(frmt, ...)    OBSLOG_OBJC_MAYBE(OBSLOG_ASYNC_INFO,    OBSLOG_LEVEL_DEF, OBSLOG_FLAG_INFO,    0, frmt, ##__VA_ARGS__)
#define OBSDDLogDebug(frmt, ...)   OBSLOG_OBJC_MAYBE(OBSLOG_ASYNC_DEBUG,   OBSLOG_LEVEL_DEF, OBSLOG_FLAG_DEBUG,   0, frmt, ##__VA_ARGS__)
#define OBSDDLogVerbose(frmt, ...) OBSLOG_OBJC_MAYBE(OBSLOG_ASYNC_VERBOSE, OBSLOG_LEVEL_DEF, OBSLOG_FLAG_VERBOSE, 0, frmt, ##__VA_ARGS__)

#endif
