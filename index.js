import { DeviceEventEmitter, NativeEventEmitter, NativeModules, Platform } from "react-native";
import { RTNObs } from './harmony';

const RNOBS = Platform.select({
    ios: NativeModules.RNOBS,
    android: NativeModules.RNOBS,
    harmony: {
        enableDevMode() {
            RTNObs.enableDevMode();
        },
    
        initWithPlainTextAccessKey(accessKey, secretKey, endPoint, configuration = conf) {
            RTNObs.initWithPlainTextAccessKey(accessKey, secretKey, endPoint, configuration);
        },
    
        initWithSecurityToken(securityToken, accessKey, secretKey, endPoint, configuration = conf) {
            RTNObs.initWithSecurityToken(securityToken, accessKey, secretKey, endPoint, configuration);
        },
    
        upload(bucketName, objectKey, filepath, options) {
            return RTNObs.upload(bucketName, objectKey, filepath, options);
        },
    }
})

let subscription;

//default configuration for OSS Client
const conf = {
    maxRetryCount: 3,
    timeoutIntervalForRequest: 30,
    timeoutIntervalForResource: 24 * 60 * 60
};

export default Obs = {

    //Enable dev mode
    enableDevMode() {
        RNOBS.enableDevMode();
    },

    /**
     * Initialize the OSS Client
     * Mode: PlainTextAKSK
     */
    initWithPlainTextAccessKey(accessKey, secretKey, endPoint, configuration = conf) {
        RNOBS.initWithPlainTextAccessKey(accessKey, secretKey, endPoint, configuration);
    },

    /**
     * Initialize the OSS Client
     * Mode: SecurityToken (STS)
     */
    initWithSecurityToken(securityToken, accessKey, secretKey, endPoint, configuration = conf) {
        RNOBS.initWithSecurityToken(securityToken, accessKey, secretKey, endPoint, configuration);
    },

    /**
     * Asynchronously uploading
     */
    upload(bucketName, objectKey, filepath, options) {
        return RNOBS.upload(bucketName, objectKey, filepath, options);
    },

    /**
     * event listener for native upload/download event
     * @param event one of 'uploadProgress' or 'downloadProgress'
     * @param callback a callback function accepts one params: event
     */
    addEventListener(event, callback) {
        const RNAliyunEmitter = Platform.OS === 'ios' ? new NativeEventEmitter(RNOBS) : DeviceEventEmitter;
        switch (event) {
            case 'uploadProgress':
                subscription = RNAliyunEmitter.addListener(
                    'uploadProgress',
                    e => callback(e)
                );
                break;
            case 'downloadProgress':
                subscription = RNAliyunEmitter.addListener(
                    'downloadProgress',
                    e => callback(e)
                );
                break;
            default:
                break;
        }
    },

    /**
     * remove event listener for native upload/download event
     * @param event one of 'uploadProgress' or 'downloadProgress'
     */
    removeEventListener(event) {
        switch (event) {
            case 'uploadProgress':
                subscription.remove();
                break;
            case 'downloadProgress':
                subscription.remove();
                break;
            default:
                break;
        }
    }
};