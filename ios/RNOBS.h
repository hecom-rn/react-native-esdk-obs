#import <React/RCTBridgeModule.h>
#import <React/RCTEventEmitter.h>
#import <OBS/OBS.h>

@interface RNOBS : RCTEventEmitter <RCTBridgeModule>

@property OBSClient *client;
@property OBSServiceConfiguration *clientConfiguration;

@property bool hasListeners;

- (NSString *)getDocumentDirectory;
- (NSString *)getTemporaryDirectory;

+ (NSString*)generateTemporaryDirectoryFrom:(NSString*)sourcePath withData:(NSData*)data;

@end
