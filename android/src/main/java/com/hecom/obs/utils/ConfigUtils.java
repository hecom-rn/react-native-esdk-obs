package com.hecom.obs.utils;

import com.facebook.react.bridge.ReadableMap;
import com.obs.services.ObsConfiguration;

public class ConfigUtils {

    /**
     * Auth initAuthConfig
     */
    public static ObsConfiguration initAuthConfig(ReadableMap configuration) {
        ObsConfiguration conf = new ObsConfiguration();
        if (configuration != null) {
            if (configuration.hasKey("maxRetryCount")) {
                conf.setMaxErrorRetry(configuration.getInt("maxRetryCount"));
            }
            if (configuration.hasKey("timeoutIntervalForRequest")) {
                conf.setConnectionTimeout(configuration.getInt("timeoutIntervalForRequest") * 1000);
                conf.setSocketTimeout(configuration.getInt("timeoutIntervalForRequest") * 1000);
            }
            if (configuration.hasKey("cname")) {
                conf.setCname(configuration.getBoolean("cname"));
            }
        }
        return conf;
    }
}
