package com.hecom.obs.utils;

import com.facebook.react.bridge.ReadableMap;
import com.obs.services.ObsConfiguration;

public class ConfigUtils {

    /**
     * Auth initAuthConfig
     * @param configuration
     * @return
     */
    public static ObsConfiguration initAuthConfig(ReadableMap configuration) {
        ObsConfiguration conf = new ObsConfiguration();
       conf.setConnectionTimeout(configuration.getInt("timeoutIntervalForRequest") * 1000);
       conf.setSocketTimeout(configuration.getInt("timeoutIntervalForRequest") * 1000);
       conf.setMaxErrorRetry(configuration.getInt("maxRetryCount"));
       conf.setCname(configuration.getBoolean("cname"));
       return conf;
   }
}
