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
  *Welcome to CocoaLumberjack!
 *
  *The project page has a wealth of documentation if you have any questions.
  *https://github.com/CocoaLumberjack/CocoaLumberjack
 *
  *If you're new to the project you may wish to read "Getting Started" at:
  *Documentation/GettingStarted.md
 *
  *Otherwise, here is a quick refresher.
  *There are three steps to using the macros:
 *
  *Step 1:
  *Import the header in your implementation or prefix file:
 *
  *#import <CocoaLumberjack/CocoaLumberjack.h>
 *
  *Step 2:
  *Define your logging level in your implementation file:
 *
  // Log levels: off, error, warn, info, verbose
  *static const OBSDDLogLevel obsddLogLevel = OBSDDLogLevelVerbose;
 *
  *Step 2 [3rd party frameworks]:
 *
  *Define your OBSLOG_LEVEL_DEF to a different variable/function than obsddLogLevel:
 *
  // #undef OBSLOG_LEVEL_DEF // Undefine first only if needed
  *#define OBSLOG_LEVEL_DEF myLibLogLevel
 *
  *Define your logging level in your implementation file:
 *
  // Log levels: off, error, warn, info, verbose
  *static const OBSDDLogLevel myLibLogLevel = OBSDDLogLevelVerbose;
 *
  *Step 3:
  *Replace your NSLog statements with OBSDDLog statements according to the severity of the message.
 *
  *NSLog(@"Fatal error, no dohickey found!"); -> OBSDDLogError(@"Fatal error, no dohickey found!");
 *
  *OBSDDLog works exactly the same as NSLog.
  *This means you can pass it multiple variables just like NSLog.
 **/

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN


NS_ASSUME_NONNULL_END

FOUNDATION_EXPORT NSString *const OBSCocoaLumberjackFrameworkVersionString;
// Disable legacy macros
#ifndef OBSDD_LEGACY_MACROS
    #define OBSDD_LEGACY_MACROS 0
#endif

// Core
#import "OBSDDLog.h"

// Main macros
#import "OBSDDLogMacros.h"
#import "OBSDDAssertMacros.h"

// Capture ASL
#import "OBSDDASLLogCapture.h"

// Loggers
#import "OBSDDTTYLogger.h"
#import "OBSDDASLLogger.h"
#import "OBSDDFileLogger.h"
#import "OBSDDOSLogger.h"

// CLI
#if __has_include("OBSCLIColor.h") && TARGET_OS_OSX
#import "OBSCLIColor.h"
#endif
