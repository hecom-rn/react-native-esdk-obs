package com.hecom.obs;

import android.util.Log;

import com.facebook.react.bridge.Promise;
import com.obs.services.exception.ObsException;

public class PromiseExceptionManager {

    /**
     * resolvePromiseException
     * @param exception
     * @param promise
     */
    public static void resolvePromiseException(ObsException exception,  final Promise promise) {
        if (exception != null) {
            exception.printStackTrace();
            Log.e("ErrorCode", exception.getErrorCode());
            Log.e("RequestId", exception.getErrorRequestId());
            Log.e("HostId", exception.getErrorHostId());
            Log.e("RawMessage", exception.getErrorMessage());
            promise.reject(exception);
        }
    }
}