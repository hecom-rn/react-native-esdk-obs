#import "RNOBS+AUTH.h"

@implementation RNOBS (AUTH)



/**
 initWithPlainTextAccessKey
 
 */
RCT_EXPORT_METHOD(initWithPlainTextAccessKey:(NSString *)accessKey secretKey:(NSString *)secretKey endPoint:(NSString *)endPoint configuration:(NSDictionary *)configuration){
    
    id<OSSCredentialProvider> credential = [[OSSPlainTextAKSKPairCredentialProvider alloc] initWithPlainTextAccessKey:accessKey secretKey:secretKey];
    
    [self initConfiguration: configuration];
    
    self.client = [[OSSClient alloc] initWithEndpoint:endPoint credentialProvider:credential clientConfiguration:self.clientConfiguration];
}

/**
 initWithSecurityToken
 
 */
RCT_EXPORT_METHOD(initWithSecurityToken:(NSString *)securityToken accessKey:(NSString *)accessKey secretKey:(NSString *)secretKey endPoint:(NSString *)endPoint configuration:(NSDictionary *)configuration){
    
    id<OSSCredentialProvider> credential = [[OSSStsTokenCredentialProvider alloc] initWithAccessKeyId:accessKey secretKeyId:secretKey securityToken:securityToken];
    
    [self initConfiguration: configuration];
    
    
    self.client = [[OSSClient alloc] initWithEndpoint:endPoint credentialProvider:credential clientConfiguration:self.clientConfiguration];
}


@end
