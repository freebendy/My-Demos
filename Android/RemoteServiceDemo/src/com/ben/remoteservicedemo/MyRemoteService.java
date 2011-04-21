package com.ben.remoteservicedemo;

import android.app.Service;
import android.content.Intent;
import android.os.IBinder;
import android.os.RemoteException;
import android.os.Process;
import android.util.Log;

public class MyRemoteService extends Service {

    private static String LOG_TAG = "remoteservicedemo.MyRemoteService";

    private int mStatus = 1;

    @Override
    public void onCreate() {
        Log.v(LOG_TAG, "onCreate");
        super.onCreate();
    }


    @Override
    public void onStart(Intent intent, int startId) {
        Log.v(LOG_TAG, "onStart");
        super.onStart(intent, startId);
    }

    @Override
    public IBinder onBind(Intent aIntent) {
        Log.v(LOG_TAG, "onBind - pid: " + Process.myPid() + ",thread name: " + Thread.currentThread().getName());
        return mMyServiceStub;
    }

    @Override
    public void onDestroy() {
        Log.v(LOG_TAG, "onDestroy");
        super.onDestroy();
    }

    private IMyService.Stub mMyServiceStub = new IMyService.Stub() {
        public int getStatus() throws RemoteException {
            Log.v(LOG_TAG, "getStatus - pid: " + Process.myPid() + ",thread name: " + Thread.currentThread().getName());
            return mStatus++;
        }
    };

}
