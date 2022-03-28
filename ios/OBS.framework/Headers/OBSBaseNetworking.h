// Copyright 2019 Huawei Technologies Co.,Ltd.
// Licensed under the Apache License, Version 2.0 (the "License"); you may not use
// this file except in compliance with the License.  You may obtain a copy of the
// License at
//
// http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software distributed
// under the License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
// CONDITIONS OF ANY KIND, either express or implied.  See the License for the
// specific language governing permissions and limitations under the License.

#ifndef OBSBaseNetworking_h
#define OBSBaseNetworking_h
#import "OBSBaseConstDefinition.h"
#import "OBSBaseModel.h"
@class OBSBFTaskCompletionSource;
@class OBSBFTask;
@class OBSBaseRequest;
@class OBSEndpoint;
@class OBSBaseNetworkingRequest;
@class OBSBaseConfiguration;
@class OBSAbstractCredentailProvider;
@protocol NSURLSessionDelegate;
@protocol NSURLSessionDataDelegate;
@protocol OBSServiceCredentialProvider;

#pragma mark - Networking classes

@protocol OBSNetworkingRequestPostProcessor<NSObject>
@required
+(void)processRequest:(OBSBaseNetworkingRequest*) request configuration:(__kindof OBSBaseConfiguration *const) configuration error:(NSError**)  error;
@end

@protocol OBSNetworkingResponsePreProcessor<NSObject>
@required
+(void)processResponse:(NSMutableDictionary*) responseDict configuration:(__kindof OBSBaseConfiguration *const) configuration error:(NSError**)  error;
@end

@interface OBSRequestURLStringPostProcessor: NSObject<OBSNetworkingRequestPostProcessor>
@end

@interface OBSResouceParameterPostProcessor: NSObject<OBSNetworkingRequestPostProcessor>
@end

@interface OBSHeaderUAPostProcessor: NSObject <OBSNetworkingRequestPostProcessor>
@end

@interface OBSHeaderContentLengthPostProcessor: NSObject <OBSNetworkingRequestPostProcessor>
@end

@interface OBSHeaderContentTypePostProcessor: NSObject <OBSNetworkingRequestPostProcessor>
@end

@interface OBSHeaderHostPostProcessor: NSObject <OBSNetworkingRequestPostProcessor>
@end

@interface OBSURLEncodingPostProcessor: NSObject <OBSNetworkingRequestPostProcessor>
@end

@protocol OBSNetworkingRequestJSONDataProtocol<NSObject>
@required
+(NSDictionary*) AdditionalJSONData;
+(NSDictionary*) getAdditionalJSONDataIncludeParents;
@end

#pragma mark - Networking Manager
@interface OBSNetworkingManager :NSObject<NSURLSessionDelegate, NSURLSessionTaskDelegate,NSURLSessionDataDelegate,NSURLSessionDownloadDelegate>
@property (nonatomic, readonly, nonnull) OBSBaseConfiguration *configuration;
-(instancetype) initWithConfiguration:(OBSBaseConfiguration*) configuration;
-(OBSBFTask*) sendRequest: (OBSBaseNetworkingRequest*) request;
-(void)releaseSessions;
@end

#pragma mark - networking base requests

@protocol OBSNetworkingGetResponseClazz
@optional
-(Class)getResponseClazz;
@end

@interface OBSBaseNetworkingRequest : OBSAbstractModel<OBSNetworkingGetResponseClazz>
    //config
@property (nonatomic, assign) OBSRequestType requestType;
@property (nonatomic, copy, nonnull) NSString *requestID;
@property (nonatomic, assign) OBSHTTPMethod  requestMethod;
@property (nonatomic, strong, nullable) NSString *requestBaseURLString;
@property (nonatomic, strong, nullable) NSString *requestResourceString;
@property (nonatomic, strong, nullable) NSString *requestOriginalResourceString;
@property (nonatomic, strong, nullable) NSMutableDictionary *requestResourceParameters;
@property (nonatomic, strong, nullable) NSMutableDictionary *requestQueryParameters;
@property (nonatomic, strong, nullable) NSMutableDictionary *requestHeadersParameters;
@property (nonatomic, strong, nullable) NSMutableArray *addonRequestPostProcessorsParameters;
@property (nonatomic, strong, nullable) NSMutableArray *addonResponsePreProcessorsParameters;

    //processing attribute
@property (nonatomic, strong, nullable) NSData *requestBodyData;
@property (nonatomic, strong, nullable) NSMutableData *responseData;
@property (nonatomic, strong) NSMutableArray<Class<OBSNetworkingRequestPostProcessor>> *postProcessors;
@property (nonatomic, strong) NSMutableArray<Class<OBSNetworkingResponsePreProcessor>> *preProcessors;
@property (nonatomic, strong, nullable) OBSWeakMutableArray<NSURLSessionTask*>  *sessionTaskList;
@property (nonatomic, strong) OBSBFTaskCompletionSource *completionSource;
@property (nonatomic, weak, nullable) OBSBaseRequest *obsRequest;
@property (readonly, nonatomic, assign) BOOL isCancelled;
-(void)cancel;
@end

@interface OBSNetworkingCommandRequest : OBSBaseNetworkingRequest<OBSNetworkingRequestJSONDataProtocol, OBSGetBodyTypeProtocol>
@property (nonatomic, strong, nullable) NSMutableDictionary *requestBodyParameters;
@end

@interface OBSNetworkingUploadDataRequest : OBSBaseNetworkingRequest<OBSNetworkingRequestJSONDataProtocol>
@property (nonatomic, strong, nonnull) NSData *uploadData;
@property (nonatomic, copy, nullable) OBSNetworkingUploadProgressBlock uploadProgressBlock;
@end

@interface OBSNetworkingUploadFileRequest : OBSBaseNetworkingRequest<OBSNetworkingRequestJSONDataProtocol>
@property (nonatomic, strong, nonnull) NSString *uploadFilePath;
@property (nonatomic, assign) BOOL background;
@property (nonatomic, copy, nullable) OBSNetworkingUploadProgressBlock uploadProgressBlock;
@end

@interface OBSNetworkingDownloadDataRequest : OBSBaseNetworkingRequest<OBSNetworkingRequestJSONDataProtocol>
@property (nonatomic, copy, nonnull) OBSNetworkingOnReceiveDataBlock onReceiveDataBlock;
@property (nonatomic, copy) OBSNetworkingDownloadProgressBlock  downloadProgressBlock;
@property (nonatomic, assign) int64_t bytes_totalGot;

@end

@interface OBSNetworkingDownloadFileRequest : OBSBaseNetworkingRequest<OBSNetworkingRequestJSONDataProtocol>
@property (nonatomic, assign) BOOL background;
@property (nonatomic, strong, nonnull) NSString * downloadFilePath;
@property (nonatomic, copy) OBSNetworkingDownloadProgressBlock  downloadProgressBlock;
@end





#endif  /* OBSBaseNetworking_h */
