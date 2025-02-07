#import "RNOBS+AUTH.h"

@implementation RNOBS (AUTH)

/**
 * initWithPlainTextAccessKey
 */
RCT_EXPORT_METHOD(initWithPlainTextAccessKey:(NSString *)accessKey
                  secretKey:(NSString *)secretKey
                  endPoint:(NSString *)endPoint
                  configuration:(NSDictionary *)configuration) {
    OBSStaticCredentialProvider *credential = [[OBSStaticCredentialProvider alloc] initWithAccessKey:accessKey secretKey:secretKey];
    [self initConfiguration:configuration
                   endPoint:endPoint
          creditialProvider:credential];
    self.client = [[OBSClient alloc] initWithConfiguration:self.clientConfiguration];
}

/**
 * initWithSecurityToken
 */
RCT_EXPORT_METHOD(initWithSecurityToken:(NSString *)securityToken
                  accessKey:(NSString *)accessKey
                  secretKey:(NSString *)secretKey
                  endPoint:(NSString *)endPoint
                  configuration:(NSDictionary *)configuration) {
    OBSStaticCredentialProvider *credential = [[OBSStaticCredentialProvider alloc] initWithAccessKey:accessKey secretKey:secretKey];
    credential.securityToken = securityToken;
    credential.isGetProtocol = NO;
    credential.protocolType = OBSProtocolTypeOBS;
    [self initConfiguration:configuration
                   endPoint:endPoint
          creditialProvider:credential];
    self.client = [[OBSClient alloc] initWithConfiguration:self.clientConfiguration];
}

/**
 * Setup initial configuration for initializing OSS Client
 * @param configuration a configuration object (NSDictionary *) passed from react-native side
 */
- (void)initConfiguration:(NSDictionary *)configuration
                 endPoint:(NSString *)endPoint
        creditialProvider:(id<OBSServiceCredentialProvider>)credentialProvider {
    self.clientConfiguration = [[OBSServiceConfiguration alloc] initWithURLString:endPoint credentialProvider:credentialProvider];
    //    _clientConfiguration.maxRetryCount = [RCTConvert int:configuration[@"maxRetryCount"]]; // default 3
    //    _clientConfiguration.timeoutIntervalForRequest = [RCTConvert double:configuration[@"timeoutIntervalForRequest"]]; //default 30
    //    _clientConfiguration.timeoutIntervalForResource = [RCTConvert double:configuration[@"timeoutIntervalForResource"]]; //default 24 * 60 * 60
    self.clientConfiguration.defaultDomainMode = configuration[@"cname"] ? OBSDomainModeCustom : OBSDomainModeNULL0;
}

@end
