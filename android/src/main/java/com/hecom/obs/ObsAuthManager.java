package com.hecom.obs;

import android.content.Context;
import android.util.Log;

import com.facebook.react.bridge.ReadableMap;
import com.obs.services.ObsClient;
import com.obs.services.ObsConfiguration;
import com.hecom.obs.utils.ConfigUtils;

public class ObsAuthManager {
    private ObsClient mObs;
    private Context mContext;
    private AuthListener mAuthListener;

    /**
     * ObsAuthManager constructor
     * @param context
     * @param listener
     */
    public ObsAuthManager(Context context, AuthListener listener) {
        mContext = context;
        mAuthListener = listener;
    }

    /**
     * inteface AuthListener
     */
    public interface AuthListener {
        void onAuthFinished(ObsClient oss);
    }

    /**
     * initWithPlainTextAccessKey
     * @param accessKeyId
     * @param accessKeySecret
     * @param endPoint
     * @param configuration
     */
    public void initWithPlainTextAccessKey(String accessKeyId,
                                           String accessKeySecret,
                                           String endPoint,
                                           ReadableMap configuration) {
        // init conf
        ObsConfiguration conf = ConfigUtils.initAuthConfig(configuration);

        mObs = new ObsClient(accessKeyId, accessKeySecret, endPoint, conf);
        Log.d("AliyunOSS", "OSS initWithKey ok!");
        mAuthListener.onAuthFinished(mObs);
    }

    /**
     * initWithPlainTextAccessKey
     * @param securityToken
     * @param accessKeyId
     * @param accessKeySecret
     * @param endPoint
     * @param configuration
     */
    public void initWithSecurityToken(String securityToken,
                                      String accessKeyId,
                                      String accessKeySecret,
                                      String endPoint,
                                      ReadableMap configuration) {
        // init conf
        ObsConfiguration conf = ConfigUtils.initAuthConfig(configuration);
        conf.setEndPoint(endPoint);
        mObs = new ObsClient(accessKeyId, accessKeySecret, securityToken, conf);
        Log.d("AliyunOSS", "OSS initWithKey ok!");
        mAuthListener.onAuthFinished(mObs);
    }
}
