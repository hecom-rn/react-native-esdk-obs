//
//  OBSXMLDictionary.h
//
//  Version 1.4.1
//
//  Created by Nick Lockwood on 15/11/2010.
//  Copyright 2010 Charcoal Design. All rights reserved.
//
//  Get the latest version of OBSXMLDictionary from here:
//
//  https://github.com/nicklockwood/XMLDictionary
//
//  This software is provided 'as-is', without any express or implied
//  warranty.  In no event will the authors be held liable for any damages
//  arising from the use of this software.
//
//  Permission is granted to anyone to use this software for any purpose,
//  including commercial applications, and to alter it and redistribute it
//  freely, subject to the following restrictions:
//
//  1. The origin of this software must not be misrepresented; you must not
//  claim that you wrote the original software. If you use this software
//  in a product, an acknowledgment in the product documentation would be
//  appreciated but is not required.
//
//  2. Altered source versions must be plainly marked as such, and must not be
//  misrepresented as being the original software.
//
//  3. This notice may not be removed or altered from any source distribution.
//

#import <Foundation/Foundation.h>
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wobjc-missing-property-synthesis"


NS_ASSUME_NONNULL_BEGIN

extern NSString *const OBSXMLDictionaryFrameworkVersionString;

typedef NS_ENUM(NSInteger, OBSXMLDictionaryAttributesMode)
{
    OBSXMLDictionaryAttributesModePrefixed = 0, //default
    OBSXMLDictionaryAttributesModeDictionary,
    OBSXMLDictionaryAttributesModeUnprefixed,
    OBSXMLDictionaryAttributesModeDiscard
};


typedef NS_ENUM(NSInteger, OBSXMLDictionaryNodeNameMode)
{
    OBSXMLDictionaryNodeNameModeRootOnly = 0, //default
    OBSXMLDictionaryNodeNameModeAlways,
    OBSXMLDictionaryNodeNameModeNever
};


static NSString *const OBSXMLDictionaryAttributesKey   = @"__attributes";
static NSString *const OBSXMLDictionaryCommentsKey     = @"__comments";
static NSString *const OBSXMLDictionaryTextKey         = @"__text";
static NSString *const OBSXMLDictionaryNodeNameKey     = @"__name";
static NSString *const OBSXMLDictionaryAttributePrefix = @"_";


@interface OBSXMLDictionaryParser : NSObject <NSCopying>

+ (OBSXMLDictionaryParser *)sharedInstance;

@property (nonatomic, assign) BOOL collapseTextNodes; // defaults to YES
@property (nonatomic, assign) BOOL stripEmptyNodes;   // defaults to YES
@property (nonatomic, assign) BOOL trimWhiteSpace;    // defaults to YES
@property (nonatomic, assign) BOOL alwaysUseArrays;   // defaults to NO
@property (nonatomic, assign) BOOL preserveComments;  // defaults to NO
@property (nonatomic, assign) BOOL wrapRootNode;      // defaults to NO

@property (nonatomic, assign) OBSXMLDictionaryAttributesMode attributesMode;
@property (nonatomic, assign) OBSXMLDictionaryNodeNameMode nodeNameMode;

- (nullable NSDictionary<NSString *, id> *)dictionaryWithParser:(NSXMLParser *)parser;
- (nullable NSDictionary<NSString *, id> *)dictionaryWithData:(NSData *)data;
- (nullable NSDictionary<NSString *, id> *)dictionaryWithString:(NSString *)string;
- (nullable NSDictionary<NSString *, id> *)dictionaryWithFile:(NSString *)path;

@end


@interface NSDictionary (OBSXMLDictionary)

+ (nullable NSDictionary<NSString *, id> *)dictionaryWithOBSXMLParser:(NSXMLParser *)parser;
+ (nullable NSDictionary<NSString *, id> *)dictionaryWithOBSXMLData:(NSData *)data;
+ (nullable NSDictionary<NSString *, id> *)dictionaryWithOBSXMLString:(NSString *)string;
+ (nullable NSDictionary<NSString *, id> *)dictionaryWithOBSXMLFile:(NSString *)path;

@property (nonatomic, readonly, copy, nullable) NSDictionary<NSString *, NSString *> *attributes;
@property (nonatomic, readonly, copy, nullable) NSDictionary<NSString *, id> *childNodes;
@property (nonatomic, readonly, copy, nullable) NSArray<NSString *> *comments;
@property (nonatomic, readonly, copy, nullable) NSString *nodeName;
@property (nonatomic, readonly, copy, nullable) NSString *innerText;
@property (nonatomic, readonly, copy) NSString *innerOBSXML;
@property (nonatomic, readonly, copy) NSString *OBSXMLString;

- (nullable NSArray *)arrayValueForKeyPath:(NSString *)keyPath;
- (nullable NSString *)stringValueForKeyPath:(NSString *)keyPath;
- (nullable NSDictionary<NSString *, id> *)dictionaryValueForKeyPath:(NSString *)keyPath;

@end


@interface NSString (OBSXMLDictionary)

@property (nonatomic, readonly, copy) NSString *OBSXMLEncodedString;

@end


NS_ASSUME_NONNULL_END


#pragma GCC diagnostic pop
