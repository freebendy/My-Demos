package com.ben.remoteservicedemo;

import android.app.Activity;
import android.content.ComponentName;
import android.content.Context;
import android.content.Intent;
import android.content.ServiceConnection;
import android.os.Bundle;
import android.os.IBinder;
import android.os.Process;
import android.os.RemoteException;
import android.util.Log;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.Button;
import android.widget.Toast;

public class MainActivity extends Activity {

    private static String LOG_TAG = "remoteservicedemo.MainActivity";

    private IMyService mMyService = null;

    private ServiceConnection mServiceConnection = null;

    private Button mBindButton = null;
    private Button mInvokeButton = null;
    private Button mReleaseButton = null;

    /** Called when the activity is first created. */
    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.main);

        mBindButton = (Button) findViewById(R.id.ButtonBind);
        mInvokeButton = (Button) findViewById(R.id.ButtonInvoke);
        mReleaseButton = (Button) findViewById(R.id.ButtonRelease);

        mBindButton.setOnClickListener(new OnClickListener() {
            public void onClick(View v) {
                if (mServiceConnection == null) {
                    mServiceConnection = new ServiceConnection() {
                        public void onServiceConnected(ComponentName name, IBinder service) {
                            Log.v(LOG_TAG, "onServiceConnected - name: " + name);
                            mMyService = IMyService.Stub.asInterface((IBinder)service);
                        }

                        public void onServiceDisconnected(ComponentName name) {
                            Log.v(LOG_TAG, "onServiceDisconnected - name: " + name);
                            mMyService = null;
                        }
                    };

                    Intent intent = new Intent();
                    intent.setClass(MainActivity.this, MyRemoteService.class);
                    bindService(intent, mServiceConnection, Context.BIND_AUTO_CREATE);
                    setButtonsState(true);
                }
            }
        });

        mReleaseButton.setOnClickListener(new OnClickListener() {
            public void onClick(View v) {
                if (mServiceConnection != null) {
                    unbindService(mServiceConnection);
                    mServiceConnection = null;
                    setButtonsState(false);
                }
            }
        });

        mInvokeButton.setOnClickListener(new OnClickListener() {
            public void onClick(View v) {
                if (mServiceConnection == null) {
                    Toast.makeText(MainActivity.this,
                            "Service not bound, must bind the service first.",
                            Toast.LENGTH_SHORT).show();
                } else {
                    try {
                        Log.v(LOG_TAG, "pid: " + Process.myPid() + ",thread name: " + Thread.currentThread().getName());
                        int counter = mMyService.getStatus();
                        Toast.makeText(MainActivity.this, "counter: " + counter,
                                Toast.LENGTH_LONG).show();
                    } catch (RemoteException re) {
                        Log.e(getClass().getSimpleName(), "RemoteException");
                    }
                }
            }
        });

        setButtonsState(false);
    }

    void setButtonsState(boolean isBind) {
        Log.v(LOG_TAG, "setButtonsState - isBind: " + isBind);
        mBindButton.setEnabled(!isBind);
        mInvokeButton.setEnabled(isBind);
        mReleaseButton.setEnabled(isBind);
    }
}