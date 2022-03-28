/*
  * Copyright (c) 2014, Facebook, Inc.
  * All rights reserved.
 *
  * This source code is licensed under the BSD-style license found in the
  * LICENSE file in the root directory of this source tree. An additional grant
  * of patent rights can be found in the PATENTS file in the same directory.
 *
 */

#import "OBSBFCancellationToken.h"
#import "OBSBFCancellationTokenRegistration.h"
#import "OBSBFCancellationTokenSource.h"
#import "OBSBFExecutor.h"
#import "OBSBFGeneric.h"
#import "OBSBFTask.h"
#import "OBSBFTaskCompletionSource.h"

#if __has_include("OBSBFAppLink.h") && TARGET_OS_IPHONE && !TARGET_OS_WATCH && !TARGET_OS_TV
#import "OBSBFAppLink.h"
#import "OBSBFAppLinkNavigation.h"
#import "OBSBFAppLinkResolving.h"
#import "OBSBFAppLinkReturnToRefererController.h"
#import "OBSBFAppLinkReturnToRefererView.h"
#import "OBSBFAppLinkTarget.h"
#import "OBSBFMeasurementEvent.h"
#import "OBSBFURL.h"
#import "OBSBFWebViewAppLinkResolver.h"
#endif


NS_ASSUME_NONNULL_BEGIN

/**
 A string containing the version of the Bolts Framework used by the current application.
 */
FOUNDATION_EXPORT NSString *const OBSBoltsFrameworkVersionString;

NS_ASSUME_NONNULL_END
