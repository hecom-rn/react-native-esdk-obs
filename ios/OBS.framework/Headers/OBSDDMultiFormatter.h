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

#import <Foundation/Foundation.h>

// Disable legacy macros
#ifndef OBSDD_LEGACY_MACROS
    #define OBSDD_LEGACY_MACROS 0
#endif

#import "OBSDDLog.h"

/**
  *This formatter can be used to chain different formatters together.
  *The log message will processed in the order of the formatters added.
 **/
@interface OBSDDMultiFormatter : NSObject <OBSDDLogFormatter>

/**
  * Array of chained formatters
 */
@property (readonly) NSArray<id<OBSDDLogFormatter>> *formatters;

/**
  * Add a new formatter
 */
- (void)addFormatter:(id<OBSDDLogFormatter>)formatter NS_SWIFT_NAME(add(_:));

/**
  * Remove a formatter
 */
- (void)removeFormatter:(id<OBSDDLogFormatter>)formatter NS_SWIFT_NAME(remove(_:));

/**
  * Remove all existing formatters
 */
- (void)removeAllFormatters NS_SWIFT_NAME(removeAll());

/**
  * Check if a certain formatter is used
 */
- (BOOL)isFormattingWithFormatter:(id<OBSDDLogFormatter>)formatter;

@end
