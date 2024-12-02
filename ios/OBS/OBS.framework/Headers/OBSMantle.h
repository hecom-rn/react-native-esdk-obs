//
//  Mantle.h
//  Mantle
//
//  Created by Justin Spahr-Summers on 2012-09-04.
//  Copyright (c) 2012 GitHub. All rights reserved.
//

#import <Foundation/Foundation.h>

//! Project version number for Mantle.
NS_ASSUME_NONNULL_BEGIN
FOUNDATION_EXPORT double OBSMantleVersionNumber;

//! Project version string for Mantle.
FOUNDATION_EXPORT const unsigned char OBSMantleVersionString[];
NS_ASSUME_NONNULL_END

#import "OBSMTLJSONAdapter.h"
#import "OBSMTLModel.h"
#import "OBSMTLModel+NSCoding.h"
#import "OBSMTLValueTransformer.h"
#import "OBSMTLTransformerErrorHandling.h"
#import "NSArray+OBSMTLManipulationAdditions.h"
#import "NSDictionary+OBSMTLManipulationAdditions.h"
#import "NSDictionary+OBSMTLMappingAdditions.h"
#import "NSObject+OBSMTLComparisonAdditions.h"
#import "NSValueTransformer+OBSMTLInversionAdditions.h"
#import "NSValueTransformer+OBSMTLPredefinedTransformerAdditions.h"
