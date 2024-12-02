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

// Disable legacy macros
#ifndef OBSDD_LEGACY_MACROS
    #define OBSDD_LEGACY_MACROS 0
#endif

#import "OBSDDLog.h"

/**
  *The constant/variable/method responsible for controlling the current log level.
 **/
#ifndef OBSLOG_LEVEL_DEF
    #define OBSLOG_LEVEL_DEF obsddLogLevel
#endif

/**
  *Whether async should be used by log messages, excluding error messages that are always sent sync.
 **/
#ifndef OBSLOG_ASYNC_ENABLED
    #define OBSLOG_ASYNC_ENABLED YES
#endif

/**
  *These are the two macros that all other macros below compile into.
  *These big multiline macros makes all the other macros easier to read.
 **/
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

#define OBSLOG_MACRO_TO_OBSDDLOG(obsddlog, isAsynchronous, lvl, flg, ctx, atag, fnct, frmt, ...) \
        [obsddlog log : isAsynchronous                                     \
             level : lvl                                                \
              flag : flg                                                \
           context : ctx                                                \
              file : __FILE__                                           \
          function : fnct                                               \
              line : __LINE__                                           \
               tag : atag                                               \
            format : (frmt), ## __VA_ARGS__]

/**
  *Define version of the macro that only execute if the log level is above the threshold.
  *The compiled versions essentially look like this:
 *
  *if (logFlagForThisLogMsg & obsddLogLevel) { execute log message }
 *
  *When LOG_LEVEL_DEF is defined as obsddLogLevel.
 *
  *As shown further below, Lumberjack actually uses a bitmask as opposed to primitive log levels.
  *This allows for a great amount of flexibility and some pretty advanced fine grained logging techniques.
 *
  *Note that when compiler optimizations are enabled (as they are for your release builds),
  *the log messages above your logging threshold will automatically be compiled out.
 *
  *(If the compiler sees LOG_LEVEL_DEF/obsddLogLevel declared as a constant, the compiler simply checks to see
  * if the 'if' statement would execute, and if not it strips it from the binary.)
 *
  *We also define shorthand versions for asynchronous and synchronous logging.
 **/
#define OBSLOG_MAYBE(async, lvl, flg, ctx, tag, fnct, frmt, ...) \
        do { if(lvl & flg) OBSLOG_MACRO(async, lvl, flg, ctx, tag, fnct, frmt, ##__VA_ARGS__); } while(0)

#define OBSLOG_MAYBE_TO_OBSDDLOG(obsddlog, async, lvl, flg, ctx, tag, fnct, frmt, ...) \
        do { if(lvl & flg) OBSLOG_MACRO_TO_OBSDDLOG(obsddlog, async, lvl, flg, ctx, tag, fnct, frmt, ##__VA_ARGS__); } while(0)

/**
  *Ready to use log macros with no context or tag.
 **/
#define OBSDDLogError(frmt, ...)   OBSLOG_MAYBE(NO,                OBSDDLogLevelError, OBSDDLogFlagError,   0, nil, __PRETTY_FUNCTION__, frmt, ##__VA_ARGS__)
#define OBSDDLogWarn(frmt, ...)    OBSLOG_MAYBE(OBSLOG_ASYNC_ENABLED, OBSDDLogLevelWarn, OBSDDLogFlagWarning, 0, nil, __PRETTY_FUNCTION__, frmt, ##__VA_ARGS__)
#define OBSDDLogInfo(frmt, ...)    OBSLOG_MAYBE(OBSLOG_ASYNC_ENABLED, OBSDDLogLevelInfo, OBSDDLogFlagInfo,    0, nil, __PRETTY_FUNCTION__, frmt, ##__VA_ARGS__)
#define OBSDDLogDebug(frmt, ...)   OBSLOG_MAYBE(OBSLOG_ASYNC_ENABLED, OBSDDLogLevelDebug, OBSDDLogFlagDebug,   0, nil, __PRETTY_FUNCTION__, frmt, ##__VA_ARGS__)
#define OBSDDLogVerbose(frmt, ...) OBSLOG_MAYBE(OBSLOG_ASYNC_ENABLED, OBSDDLogLevelVerbose, OBSDDLogFlagVerbose, 0, nil, __PRETTY_FUNCTION__, frmt, ##__VA_ARGS__)

    // default macro
/*
#define DDLogError(frmt, ...)   LOG_MAYBE(NO,                LOG_LEVEL_DEF, DDLogFlagError,   0, nil, __PRETTY_FUNCTION__, frmt, ##__VA_ARGS__)
#define DDLogWarn(frmt, ...)    LOG_MAYBE(LOG_ASYNC_ENABLED, LOG_LEVEL_DEF, DDLogFlagWarning, 0, nil, __PRETTY_FUNCTION__, frmt, ##__VA_ARGS__)
#define DDLogInfo(frmt, ...)    LOG_MAYBE(LOG_ASYNC_ENABLED, LOG_LEVEL_DEF, DDLogFlagInfo,    0, nil, __PRETTY_FUNCTION__, frmt, ##__VA_ARGS__)
#define DDLogDebug(frmt, ...)   LOG_MAYBE(LOG_ASYNC_ENABLED, LOG_LEVEL_DEF, DDLogFlagDebug,   0, nil, __PRETTY_FUNCTION__, frmt, ##__VA_ARGS__)
#define DDLogVerbose(frmt, ...) LOG_MAYBE(LOG_ASYNC_ENABLED, LOG_LEVEL_DEF, DDLogFlagVerbose, 0, nil, __PRETTY_FUNCTION__, frmt, ##__VA_ARGS__)
 */

#define OBSDDLogErrorToOBSDDLog(obsddlog, frmt, ...)   OBSLOG_MAYBE_TO_OBSDDOBSLOG(obsddlog, NO,                OBSLOG_LEVEL_DEF, OBSDDLogFlagError,   0, nil, __PRETTY_FUNCTION__, frmt, ##__VA_ARGS__)
#define OBSDDLogWarnToOBSDDLog(obsddlog, frmt, ...)    OBSLOG_MAYBE_TO_OBSDDOBSLOG(obsddlog, OBSLOG_ASYNC_ENABLED, OBSLOG_LEVEL_DEF, OBSDDLogFlagWarning, 0, nil, __PRETTY_FUNCTION__, frmt, ##__VA_ARGS__)
#define OBSDDLogInfoToOBSDDLog(obsddlog, frmt, ...)    OBSLOG_MAYBE_TO_OBSDDOBSLOG(obsddlog, OBSLOG_ASYNC_ENABLED, OBSLOG_LEVEL_DEF, OBSDDLogFlagInfo,    0, nil, __PRETTY_FUNCTION__, frmt, ##__VA_ARGS__)
#define OBSDDLogDebugToOBSDDLog(obsddlog, frmt, ...)   OBSLOG_MAYBE_TO_OBSDDOBSLOG(obsddlog, OBSLOG_ASYNC_ENABLED, OBSLOG_LEVEL_DEF, OBSDDLogFlagDebug,   0, nil, __PRETTY_FUNCTION__, frmt, ##__VA_ARGS__)
#define OBSDDLogVerboseToOBSDDLog(obsddlog, frmt, ...) OBSLOG_MAYBE_TO_OBSDDOBSLOG(obsddlog, OBSLOG_ASYNC_ENABLED, OBSLOG_LEVEL_DEF, OBSDDLogFlagVerbose, 0, nil, __PRETTY_FUNCTION__, frmt, ##__VA_ARGS__)
