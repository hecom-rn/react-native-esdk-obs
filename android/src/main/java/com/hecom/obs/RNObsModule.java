
package com.hecom.obs;

import com.facebook.react.bridge.Promise;
import com.facebook.react.bridge.ReactApplicationContext;
import com.facebook.react.bridge.ReactContextBaseJavaModule;
import com.facebook.react.bridge.ReactMethod;
import com.facebook.react.bridge.ReadableMap;
import com.obs.services.LogConfigurator;
import com.obs.services.ObsClient;

public class RNObsModule extends ReactContextBaseJavaModule {

    private ObsClient mObs;
    private ObsUploadManager mUploadManager;
    private ObsAuthManager mAuth;

    /**
     * RNObsModule constructor
     */
    public RNObsModule(ReactApplicationContext reactContext) {
        super(reactContext);
        mAuth = new ObsAuthManager(reactContext.getApplicationContext(), new ObsAuthManager.AuthListener() {
            @Override
            public void onAuthFinished(ObsClient obs) {
                init(obs);
            }
        });
    }

    @Override
    public String getName() {
        return "RNOBS";
    }

    /**
     * enable dev log
     */
    @ReactMethod
    public void enableDevMode() {
        LogConfigurator.enableLog();
    }

    /**
     * init oss ReactMethod
     */
    private void init(ObsClient oss) {
        mObs = oss;
        mUploadManager = new ObsUploadManager(mObs);
    }

    /**
     * initWithPlainTextAccessKey ReactMethod
     */
    @ReactMethod
    public void initWithPlainTextAccessKey(String accessKeyId, String accessKeySecret, String endPoint,
                                           ReadableMap configuration) {
        mAuth.initWithPlainTextAccessKey(accessKeyId, accessKeySecret, endPoint, configuration);
    }

    /**
     * initWithSecurityToken ReactMethod
     */
    @ReactMethod
    public void initWithSecurityToken(String securityToken, String accessKeyId, String accessKeySecret,
                                      String endPoint, ReadableMap configuration) {
        mAuth.initWithSecurityToken(securityToken, accessKeyId, accessKeySecret, endPoint, configuration);
    }

    /**
     * async Upload ReactMethod
     */
    @ReactMethod
    public void upload(String bucketName, String ossFile, String sourceFile, ReadableMap options,
                       final Promise promise) {
        mUploadManager.upload(getReactApplicationContext(), bucketName, ossFile, sourceFile, options, promise);
    }
}