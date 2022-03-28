//
//  OBSBaseConstDefinition.h
//  OBS
//
//  Created by MaxZhang on 10/10/2017.
//  Copyright © 2017 obs. All rights reserved.
//

#ifndef OBSBaseDefinition_h
#define OBSBaseDefinition_h


static NSString *const  OBSSDKVersion                           =@"3.20.11.1";

static NSUInteger const  maxConcurrentRequestCountDefault       =3;

static NSString *const  OBSURLReservedCharacters                =@"-_.~!*'();:=@&=+$,/?#[]%";
static NSString *const  OBSURLAllowedSpecialCharacters          =@"-_.";

static NSString *const  OBSAbstractClassPrefix                  =@"OBSAbstract";
#pragma mark - Errors messages;
static NSString *const  OBSClientErrorDomain                    =@"com.obs.clientError";
static NSString *const  OBSServerErrorDomain                    =@"com.obs.serverError";
static NSString *const  OBSErrorMessageTOKEN                    =@"ErrorMessage";
static NSString *const  OBSClientErrorHTTPRequestIDKey          =@"RequestID";
static NSString *const  OBSClientErrorHTTPCodeKey               =@"HTTPErrorCode";
static NSString *const  OBSClientErrorHTTPBodyKey               =@"HTTPErrorBody";
static NSString *const  OBSClientErrorInvalidParameter          =@"InvalidParameter";

static char     *const  OBSProcessorsQueueName                  ="com.obs.sdk.processors";
static NSString *const  OBSMaxConcurrentCommandRequestCountKey  =@"maxConcurrentCommandRequestCount";
static NSString *const  OBSMaxConcurrentUploadRequestCountKey   =@"maxConcurrentUploadRequestCount";
static NSString *const  OBSMaxConcurrentDownloadRequestCountKey =@"maxConcurrentDownloadRequestCount";

static NSString *const  OBSUploadBackgroundIdentifierDefault    =@"com.obs.sdk.upload";
static NSString *const  OBSDownloadBackgroundIdentifierDefault  =@"com.obs.sdk.download";

    //networking request definition dict keys;
    //common fields;
static NSString *const  OBSRequestTypeKey                       =@"requestType";
static NSString *const  OBSRequestIDKey                         =@"requestID";
static NSString *const  OBSRequestHTTPMethodKey                 =@"requestMethod";
static NSString *const  OBSRequestResourceStringKey             =@"requestResourceString";
static NSString *const  OBSRequestResourceParametersKey         =@"requestResourceParameters";
static NSString *const  OBSRequestQueryParametersKey            =@"requestQueryParameters";
static NSString *const  OBSRequestHeaderParametersKey           =@"requestHeadersParameters";

static NSString *const  OBSRequestBodyParameterKey              =@"requestBodyParameters";
static NSString *const  OBSRequestAddonRequestPostProcessorsKey =@"addonRequestPostProcessorsParameters";
static NSString *const  OBSRequestAddonResponsePreProcessorsKey =@"addonResponsePreProcessorsParameters";
static NSString *const  OBSRequestAuthRequiredKey               =@"authenticationRequired";
    //upload data fields;
static NSString *const  OBSRequestUploadDataKey                 =@"uploadData";
static NSString *const  OBSRequestUploadProgressBlockKey        =@"uploadProgressBlock";
    //download data fields;
static NSString *const  OBSRequestOnReceiveDataBlockKey         =@"onReceiveDataBlock";
static NSString *const  OBSRequestDownloadProgressBlockKey      =@"downloadProgressBlock";
    //upload and download fields;
static NSString *const  OBSRequestUploadFilePathKey             =@"uploadFilePath";
static NSString *const  OBSRequestDownloadFilePathKey           =@"downloadFilePath";
static NSString *const  OBSRequestBackgroundKey                 =@"background";
    // headesr key;
static NSString *const  OBSHeadersUAKey                         =@"User-Agent";

static NSString *const  OBSHeadersHostKey                       =@"Host";
static NSString *const  OBSHeadersContentTypeKey                =@"Content-Type";
static NSString *const  OBSHeadersContentLengthKey              =@"Content-Length";
static NSString *const  OBSHeadersAuthorizationKey              =@"Authorization";
static NSString *const  OBSDefaultContentType                   =@"binary/octet-stream";
    //date format;
static NSString *const  OBSDateShortFormat                      =@"yyyyMMdd";
static NSString *const  OBSDateRFC1123Format                    =@"E, dd MMM yyyy HH:mm:ss z";
static NSString *const  OBSDateISO8601Format1                   =@"yyyy-MM-dd'T'HH:mm:ss'Z'";
static NSString *const  OBSDateISO8601Format2                   =@"yyyyMMdd'T'HHmmss'Z'" ;
static NSString *const  OBSDateISO8601Format3                   =@"yyyy-MM-dd'T'HH:mm:ss.SSS'Z'";
    //output keys and download temp file extention;
static NSString *const  OBSOutputCodeKey                        =@"statusCode";
static NSString *const  OBSOutputHeadersKey                     =@"headers";
static NSString *const  OBSOutputBodyKey                        =@"body";


static NSString *const OBSXMLDefaultNS                          =@" xmlns=\"http://s3.amazonaws.com/doc/2006-03-01/\"";
static NSString *const OBSXMLDefaultNS_OBS                          =@" xmlns=\"http://myhwclouds.com/doc/2015-06-30/\"";

static NSString *const OBSXMLDictionaryNodeOrderKey             =@"__order";

#pragma mark -Enum
/**
 *  OBS鉴权版本枚举
 */

typedef NS_ENUM(NSInteger, OBSContentType) {
    /**
     *  默认类型
     */
    OBSContentTypeNULL0,
    /**
     *  mp4
     */
    OBSContentTypeMP4,
    /**
     *  二进制流
     */
    OBSContentTypeBinary,
    /**
     *  JPEG
     */
    OBSContentTypeJPEG,
    /**
     *  PNG
     */
    OBSContentTypePNG,
    /**
     *  HTML
     */
    OBSContentTypeHTML,
    /**
     *  GIF
     */
    OBSContentTypeGIF,
    /**
     *  PDF
     */
    OBSContentTypePDF,
    /**
     *  MP3
     */
    OBSContentTypeMP3,
    /**
     *  WAV
     */
    OBSContentTypeWAV,
    /**
     *  MOV
     */
    OBSContentTypeMOV,
    /**
     *  m3u8
     */
    OBSContentTypeM3U8,
};

typedef NS_ENUM(NSInteger, OBSAuthVersion) {
    /**
     *  默认鉴权
     */
    OBSAuthVersionNULL0,
    /**
     *  V2鉴权
     */
    OBSAuthVersionV2,
    /**
     *  V4鉴权
     */
    OBSAuthVersionV4,
};

/**
 *  OBS协议种类
 */
typedef NS_ENUM(NSInteger, OBSProtocolType) {
   
    /**
     *  旧版本协议
     */
    OBSProtocolTypeOld,
    /**
     *  自研协议
     */
    OBSProtocolTypeOBS,
};

/**
 *  OBS错误码枚举
 */
typedef NS_ENUM(NSInteger, OBSErrorCode) {
    /**
     *  默认
     */
    OBSErrorCodeNoErrorCode0,
    /**
     *  服务器错误
     */
    OBSErrorCodeServerErrorStatus,
    /**
     *  客户端错误
     */
    OBSErrorCodeClientErrorStatus,
};

/**
 *  OBS客户端错误码枚举
 */
typedef NS_ENUM(NSInteger, OBSClientErrorCODE) {
    /**
     *  默认
     */
    OBSRequestNoErrorCode0,
    /**
     *  定义未找到
     */
    OBSClientErrorRequestDefinitionNotFoundCode,
    /**
     *   响应错误码
     */
    OBSClientErrorHTTPResponseCodeError,
    /**
     *  签名错误
     */
    OBSClientErrorCodeSignFailed,
//    OBSClientErrorCodeNetworkingFailWithResponseCode0,
//    OBSClientErrorCodeFileCantWrite,
//    OBSClientErrorCodeInvalidArgument,
//    OBSClientErrorCodeNilUploadid,
//    OBSClientErrorCodeTaskCancelled,
//    OBSClientErrorCodeNetworkError,
//    OBSClientErrorCodeCannotResumeUpload,
//    OBSClientErrorCodeExcpetionCatched,
//    OBSClientErrorCodeNotKnown
};

/**
 *  OBS请求代理类型
 */
typedef NS_ENUM(NSInteger, OBSHTTPProxyType) {
    /**
     *  默认
     */
    OBSHTTPRroxyTypeNull0,
    /**
     *  HTTP
     */
    OBSHTTPRroxyTypeHTTP,
    /**
     *  HTTPS
     */
    OBSHTTPRroxyTypeHTTPS,
    /**
     *  HTTP & HTTPS
     */
    OBSHTTPRroxyTypeHTTPAndHTTPS,
};

/**
 *  请求类型
 */
typedef NS_ENUM(NSInteger, OBSRequestType){
    /**
     *  默认
     */
    OBSRequestTypeNull0,
    /**
     *  命令
     */
    OBSRequestTypeCommandRequest,
    /**
     *  上传数据
     */
    OBSRequestTypeUploadDataRequest,
    /**
     *  上传文件
     */
    OBSRequestTypeUploadFileRequest,
    /**
     *  下载数据
     */
    OBSRequestTypeDownloadDataRequest,
    /**
     *  下载文件
     */
    OBSRequestTypeDownloadFileRequest,
};

/**
 *  请求体内容
 */
typedef NS_ENUM(NSInteger, OBSBodyType){
    /**
     *  默认
     */
    OBSBodyTypeNull0,
    /**
     *  JSON
     */
    OBSBodyTypeJSON,
    /**
     *  XML
     */
    OBSBodyTypeXML,
    /**
     *  字符串
     */
    OBSBodyTypeStringData,
};
/**
 *  请求方法类型枚举
 */
typedef NS_ENUM(NSInteger, OBSHTTPMethod){
    OBSHTTPMethodNull0,
    OBSHTTPMethodGET,
    OBSHTTPMethodHEAD,
    OBSHTTPMethodPUT,
    OBSHTTPMethodPOST,
    OBSHTTPMethodTRACE,
    OBSHTTPMethodOPTIONS,
    OBSHTTPMethodDELETE,
    OBSHTTPMethodLOCK,
    OBSHTTPMethodMKCOL,
    OBSHTTPMethodMOVE,
};


#pragma mark - ignore warn
#define SuppressPerformSelectorLeakWarning(code) \
        _Pragma("clang diagnostic push") \
        _Pragma("clang diagnostic ignored \"-Warc-performSelector-leaks\"") \
        code\
        _Pragma("clang diagnostic pop") \

#define SuppressMethodDefinitionNotFoundWarning(code) \
        _Pragma("clang diagnostic push") \
        _Pragma("clang diagnostic ignored \"-Wincomplete-implementation\"") \
        code\
        _Pragma("clang diagnostic pop") \

#define MakeDispatchOnceDictBEGIN \
        static NSDictionary *dict; \
        static dispatch_once_t onceToken; \
        dispatch_once(&onceToken, ^{

#define MakeDispatchOnceDictEND\
        });  \


#define MakeDispatchOnceArrayBEGIN \
        static NSArray *array; \
        static dispatch_once_t onceToken; \
        dispatch_once(&onceToken, ^{

#define MakeDispatchOnceArrayEND\
        });  \

#define MakeDispatchOnceTransformerBEGIN \
static NSValueTransformer *transformer; \
static dispatch_once_t onceToken; \
dispatch_once(&onceToken, ^{

#define MakeDispatchOnceTransformerEND \
});  \


#define metamacro_concat(A,B) A ## B
#define weakify(VAR) \
autoreleasepool {} \
__weak __typeof__(VAR) weak##VAR = VAR
    //    __weak __typeof__(VAR) metamacro_concat(VAR, _weak_) = (VAR)

#define strongify(VAR) \
autoreleasepool {} \
_Pragma("clang diagnostic push") \
_Pragma("clang diagnostic ignored \"-Wshadow\"") \
__strong __typeof__(VAR) VAR = metamacro_concat(VAR, _weak_)\
_Pragma("clang diagnostic pop") \

#pragma mark - Progress block
typedef void (^OBSNetworkingUploadProgressBlock) (int64_t bytesSent, int64_t totalBytesSent, int64_t totalBytesExpectedToSend);
typedef void (^OBSNetworkingDownloadProgressBlock) (int64_t bytesWritten, int64_t totalBytesWritten, int64_t totalBytesExpectedToWrite);
typedef void (^OBSNetworkingOnReceiveDataBlock)(NSData *data);
#endif /* OBSConstDefinition_h */
