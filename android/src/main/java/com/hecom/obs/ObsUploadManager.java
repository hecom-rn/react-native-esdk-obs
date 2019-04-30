package com.hecom.obs;

import android.database.Cursor;
import android.net.Uri;
import android.provider.MediaStore;
import android.util.Log;

import com.facebook.react.bridge.Arguments;
import com.facebook.react.bridge.Promise;
import com.facebook.react.bridge.ReactContext;
import com.facebook.react.bridge.ReadableMap;
import com.facebook.react.bridge.WritableMap;
import com.facebook.react.modules.core.DeviceEventManagerModule;
import com.obs.services.ObsClient;
import com.obs.services.exception.ObsException;
import com.obs.services.model.ObjectMetadata;
import com.obs.services.model.ProgressListener;
import com.obs.services.model.ProgressStatus;
import com.obs.services.model.PutObjectRequest;
import com.obs.services.model.PutObjectResult;
import com.hecom.obs.utils.FileUtils;

import java.io.File;

public class ObsUploadManager {

    private ObsClient mObs;

    /**
     * ObsUploadManager contructor
     */
    public ObsUploadManager(ObsClient obs) {
        mObs = obs;
    }

    /**
     * upload
     */
    public void upload(final ReactContext context, String bucketName, String ossFile, String sourceFile,
                       ReadableMap options, final Promise promise) {
        // Content to file:// start
        Uri selectedVideoUri = Uri.parse(sourceFile);

        // 1. content uri -> file path
        // 2. inputstream -> temp file path
        Cursor cursor = null;
        try {
            String[] proj = {MediaStore.Images.Media.DATA};
            cursor = context.getCurrentActivity().getContentResolver().query(selectedVideoUri, proj, null, null, null);
            if (cursor == null) {
                sourceFile = selectedVideoUri.getPath();
            } else {
                int column_index = cursor.getColumnIndexOrThrow(MediaStore.Images.Media.DATA);
                cursor.moveToFirst();
                sourceFile = cursor.getString(column_index);
            }
        } catch (Exception e) {
            sourceFile = FileUtils.getFilePathFromURI(context.getCurrentActivity(), selectedVideoUri);
        } finally {
            if (cursor != null) {
                cursor.close();
            }
        }
        // init upload request
        PutObjectRequest put = new PutObjectRequest(bucketName, ossFile, new File(sourceFile));
        ObjectMetadata metadata = new ObjectMetadata();
        metadata.setContentType("application/octet-stream");
        put.setMetadata(metadata);

        // set callback
        put.setProgressListener(new ProgressListener() {
            @Override
            public void progressChanged(ProgressStatus progressStatus) {
                long currentSize = progressStatus.getTransferredBytes();
                long totalSize = progressStatus.getTotalBytes();
                Log.d("PutObject", "currentSize: " + currentSize + " totalSize: " + totalSize);
                String str_currentSize = Long.toString(currentSize);
                String str_totalSize = Long.toString(totalSize);
                WritableMap onProgressValueData = Arguments.createMap();
                onProgressValueData.putString("currentSize", str_currentSize);
                onProgressValueData.putString("totalSize", str_totalSize);
                context.getJSModule(DeviceEventManagerModule.RCTDeviceEventEmitter.class)
                        .emit("uploadProgress", onProgressValueData);
            }
        });
        put.setProgressInterval(1000L);

        try {
            PutObjectResult result = mObs.putObject(put);
            Log.d("PutObject", "UploadSuccess");
            Log.d("ETag", result.getEtag());
            Log.d("RequestId", result.getRequestId());
            promise.resolve("UploadSuccess");
        } catch (ObsException e) {
            PromiseExceptionManager.resolvePromiseException(e, promise);
        }
        Log.d("AliyunOSS", "OSS uploadObjectAsync ok!");
    }

    /**
     * asyncAppendObject
     */
    public void asyncAppendObject(final ReactContext context, String bucketName, String objectKey,
                                  String uploadFilePath, ReadableMap options, final Promise promise) {

    }

    /**
     * asyncResumableUpload
     */
    public void asyncResumableUpload(final ReactContext context, String bucketName, String objectKey,
                                     String uploadFilePath, ReadableMap options, final Promise promise) {

    }

    /**
     * initMultipartUpload
     */
    public void initMultipartUpload(String bucketName, String objectKey, final Promise promise) {
    }

    /**
     * multipartUpload
     */
    public void multipartUpload(final ReactContext context, String bucketName, String objectKey, String uploadId,
                                String filepath, ReadableMap options, final Promise promise) {

    }

    /**
     * abortMultipartUpload
     */
    public void abortMultipartUpload(String bucketName, String objectKey, String uploadId, final Promise promise) {
    }

    /**
     * listParts
     */
    public void listParts(String bucketName, String objectKey, String uploadId, final Promise promise) {
    }
}
