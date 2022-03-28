//
//  EXTKeyPathCoding.h
//  extobjc
//
//  Created by Justin Spahr-Summers on 19.06.12.
//  Copyright (C) 2012 Justin Spahr-Summers.
//  Released under the MIT license.
//

#import <Foundation/Foundation.h>
#import "OBSmetamacros.h"

/**
  *\@keypath allows compile-time verification of key paths. Given a real object
  *receiver and key path:
 *
  *@code

NSString *UTF8StringPath = @keypath(str.lowercaseString.UTF8String);
// => @"lowercaseString.UTF8String"

NSString *versionPath = @keypath(NSObject, version);
// => @"version"

NSString *lowercaseStringPath = @keypath(NSString.new, lowercaseString);
// => @"lowercaseString"

  *@endcode
 *
  *... the macro returns an \c NSString containing all but the first path
  *component or argument (e.g., @"lowercaseString.UTF8String", @"version").
 *
  *In addition to simply creating a key path, this macro ensures that the key
  *path is valid at compile-time (causing a syntax error if not), and supports
  *refactoring, such that changing the name of the property will also update any
  *uses of \@keypath.
 */
#define obs_keypath(...) \
    obs_metamacro_if_eq(1, obs_metamacro_argcount(__VA_ARGS__))(obs_keypath1(__VA_ARGS__))(obs_keypath2(__VA_ARGS__))

#define obs_keypath1(PATH) \
    (((void)(NO && ((void)PATH, NO)), strchr(# PATH, '.') + 1))

#define obs_keypath2(OBJ, PATH) \
    (((void)(NO && ((void)OBJ.PATH, NO)), # PATH))

/**
  *\@collectionKeypath allows compile-time verification of key paths across collections NSArray/NSSet etc. Given a real object
  *receiver, collection object receiver and related keypaths:
 *
  *@code
 
 NSString *employeesFirstNamePath = @collectionKeypath(department.employees, Employee.new, firstName)
 // => @"employees.firstName"
 
 NSString *employeesFirstNamePath = @collectionKeypath(Department.new, employees, Employee.new, firstName)
 // => @"employees.firstName"

  *@endcode
 *
 */
#define obs_collectionKeypath(...) \
    obs_metamacro_if_eq(3, obs_metamacro_argcount(__VA_ARGS__))(obs_collectionKeypath3(__VA_ARGS__))(obs_collectionKeypath4(__VA_ARGS__))

#define obs_collectionKeypath3(PATH, COLLECTION_OBJECT, COLLECTION_PATH) ([[NSString stringWithFormat:@"%s.%s",obs_keypath(PATH), obs_keypath(COLLECTION_OBJECT, COLLECTION_PATH)] UTF8String])

#define obs_collectionKeypath4(OBJ, PATH, COLLECTION_OBJECT, COLLECTION_PATH) ([[NSString stringWithFormat:@"%s.%s",obs_keypath(OBJ, PATH), obs_keypath(COLLECTION_OBJECT, COLLECTION_PATH)] UTF8String])

