//
//  NSError+OBSMTLModelException.h
//  Mantle
//
//  Created by Robert Böhnke on 7/6/13.
//  Copyright (c) 2013 GitHub. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSError (OBSMTLModelException)

/// Creates a new error for an exception that occurred during updating an
/// OBSMTLModel.
///
/// exception - The exception that was thrown while updating the model.
///             This argument must not be nil.
///
/// Returns an error that takes its localized description and failure reason
/// from the exception.
+ (instancetype)obs_mtl_modelErrorWithException:(NSException *)exception;

@end
