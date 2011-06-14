package com.ben.helloworld;

import java.util.HashMap;
import java.util.Map;

import android.app.Activity;
import android.os.Bundle;
import android.util.Log;

public class HelloWorld extends Activity {

    private static final String LOG_TAG = "HelloWorld";

    /** Called when the activity is first created. */
    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.main);

        Map<String, String> map = new HashMap<String, String>();
        map.put("1", "11");
        map.put("2", "22");
        Test test = new Test(map);
        Log.v(LOG_TAG, "1: " + (String) test.getObject().get("1"));
        map.put("1", "1111");
        Log.v(LOG_TAG, "2: " + (String) test.getObject().get("1"));
    }

    public static class Test {
        private Map<?, ?> mObj;
        public Test(Map<?, ?> aObject) {
            mObj = aObject;
        }

        Map<?, ?> getObject() {
            return mObj;
        }
    }
}