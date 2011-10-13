package com.ben.demos.sensordemo;

import java.util.List;

import android.app.Activity;
import android.hardware.Sensor;
import android.hardware.SensorEvent;
import android.hardware.SensorEventListener;
import android.hardware.SensorManager;
import android.os.Bundle;
import android.util.Log;
import android.widget.TextView;

public class SensorDemoActivity extends Activity {
    private static final String LOG_TAG = "SensorDemoActivity";
    
    // temperature
    TextView mTextViewTemp;// t

    // magnetic field
    TextView mTextViewMagX;// x

    TextView mTextViewMagY;// y

    TextView mTextViewMagZ;// z

    // acc
    TextView mTextViewAccX;// x

    TextView mTextViewAccY;// y

    TextView mTextViewAccZ;// z

    // ori
    TextView mTextViewOriX;// x

    TextView mTextViewOriY;// y

    TextView mTextViewOriZ;// z

    // Light
    TextView mTextViewLight;// z

    SensorManager mSensorManager;//
    
    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.main);
        mTextViewTemp = (TextView) findViewById(R.id.TextViewTemp);
        
        mTextViewMagX = (TextView) findViewById(R.id.TextViewMagX);
        mTextViewMagY = (TextView) findViewById(R.id.TextViewMagY);
        mTextViewMagZ = (TextView) findViewById(R.id.TextViewMagZ);
        
        mTextViewAccX = (TextView) findViewById(R.id.TextViewAccX);
        mTextViewAccY = (TextView) findViewById(R.id.TextViewAccY);
        mTextViewAccZ = (TextView) findViewById(R.id.TextViewAccZ);
        
        mTextViewOriX = (TextView) findViewById(R.id.TextViewOriX);
        mTextViewOriY = (TextView) findViewById(R.id.TextViewOriY);
        mTextViewOriZ = (TextView) findViewById(R.id.TextViewOriZ);
        
        mTextViewLight = (TextView) findViewById(R.id.TextViewLight);
        
        mSensorManager = (SensorManager) getSystemService(SENSOR_SERVICE);
    }

    private SensorEventListener mySensorListener = new SensorEventListener() {
        @Override
        public void onAccuracyChanged(Sensor sensor, int accuracy) {
        }

        @Override
        public void onSensorChanged(SensorEvent event) {
            int type = event.sensor.getType();
//            Log.v(LOG_TAG, "onSensorChanged -type = " + type);
            switch (type) {
            case Sensor.TYPE_TEMPERATURE:
                mTextViewTemp.setText("Current Temprature：" + String.format("%.2f",event.values[0]));
                break;
            case Sensor.TYPE_MAGNETIC_FIELD:
                mTextViewMagX.setText("Current Magnetic x：" + String.format("%.2f",event.values[0]));
                mTextViewMagY.setText("Current Magnetic y：" + String.format("%.2f",event.values[1]));
                mTextViewMagZ.setText("Current Magnetic z：" + String.format("%.2f",event.values[2]));
                break;
            case Sensor.TYPE_ACCELEROMETER:
                mTextViewAccX.setText("Current Accelero x：" + String.format("%.2f",event.values[0]));
                mTextViewAccY.setText("Current Accelero y：" + String.format("%.2f",event.values[1]));
                mTextViewAccZ.setText("Current Accelero z：" + String.format("%.2f",event.values[2]));
                break;
            case Sensor.TYPE_ORIENTATION:
                mTextViewOriX.setText("Current Oraenttation x："
                        + String.format("%.1f",event.values[0]));
                mTextViewOriY.setText("Current Oraenttation y："
                        + String.format("%.1f",event.values[1]));
                mTextViewOriZ.setText("Current Oraenttation z："
                        + String.format("%.1f",event.values[2]));
                break;
            case Sensor.TYPE_LIGHT:
                mTextViewLight.setText("Current Light:"
                        + String.format("%.2f",event.values[0]));
                break;
            default:
                Log.v(LOG_TAG, "onSensorChanged -- unhandled type = " + type);
                break;
            }
        }
    };
    
    @Override
    protected void onResume() {
//        mSensorManager.registerListener(mySensorListener,
//                mSensorManager.getDefaultSensor(Sensor.TYPE_TEMPERATURE),
//                SensorManager.SENSOR_DELAY_NORMAL);
//        
        mSensorManager.registerListener(mySensorListener,
                mSensorManager.getDefaultSensor(Sensor.TYPE_MAGNETIC_FIELD),
                SensorManager.SENSOR_DELAY_NORMAL);
        
        mSensorManager.registerListener(mySensorListener,
                mSensorManager.getDefaultSensor(Sensor.TYPE_ACCELEROMETER),
                SensorManager.SENSOR_DELAY_NORMAL);
        
        mSensorManager.registerListener(mySensorListener,
                mSensorManager.getDefaultSensor(Sensor.TYPE_ORIENTATION),
                SensorManager.SENSOR_DELAY_NORMAL);
        
//        mSensorManager.registerListener(mySensorListener,
//                mSensorManager.getDefaultSensor(Sensor.TYPE_LIGHT),
//                SensorManager.SENSOR_DELAY_NORMAL);
        super.onResume();
    }

    @Override
    protected void onPause() {
        mSensorManager.unregisterListener(mySensorListener);
        super.onPause();
    }
}