#import "RNOBS.h"
#import <React/RCTLog.h>
#import <React/RCTConvert.h>

@implementation RNOBS

/**
 * Expose this native module to RN
 */
RCT_EXPORT_MODULE()

/**
 * Will be called when this module's first listener is added.
 */
- (void)startObserving {
    _hasListeners = YES;
    // Set up any upstream listeners or background tasks as necessary
}

/**
 * Will be called when this module's last listener is removed, or on dealloc.
 */
- (void)stopObserving {
    _hasListeners = NO;
    // Remove upstream listeners, stop unnecessary background tasks
}

/**
 * Supported two events: uploadProgress, downloadProgress
 * @return an array stored all supported events
 */
- (NSArray<NSString *> *)supportedEvents {
    return @[@"uploadProgress", @"downloadProgress"];
}

/**
 * Get local directory with read/write accessed
 * @return document directory
 */
- (NSString *)getDocumentDirectory {
    NSString * path = NSHomeDirectory();
    NSLog(@"NSHomeDirectory:%@",path);
    NSString * userName = NSUserName();
    NSString * rootPath = NSHomeDirectoryForUser(userName);
    NSLog(@"NSHomeDirectoryForUser:%@",rootPath);
    NSArray * paths = NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES);
    NSString * documentsDirectory = [paths objectAtIndex:0];
    return documentsDirectory;
}

/**
 * Get a temporary directory inside of application's sandbox
 * @return document directory
 */
- (NSString*)getTemporaryDirectory {
    NSString *TMP_DIRECTORY = @"react-native/";
    NSString *filepath = [NSTemporaryDirectory() stringByAppendingString:TMP_DIRECTORY];
    BOOL isDir;
    BOOL exists = [[NSFileManager defaultManager] fileExistsAtPath:filepath isDirectory:&isDir];
    if (!exists) {
        [[NSFileManager defaultManager] createDirectoryAtPath:filepath
                                  withIntermediateDirectories:YES attributes:nil error:nil];
    }
    return filepath;
}

@end
