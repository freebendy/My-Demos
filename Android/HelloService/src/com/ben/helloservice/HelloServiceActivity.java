package com.ben.helloservice;

import com.ben.helloservice.R;

import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;

public class HelloServiceActivity extends Activity {
    /** Called when the activity is first created. */
    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.main);

        Button startButton = (Button) findViewById(R.id.button1);
        startButton.setOnClickListener( new View.OnClickListener() {

            public void onClick(View aV) {
                // TODO Auto-generated method stub
                Intent intent = new Intent(HelloServiceActivity.this, HelloService.class);
                startService(intent);
            }
        });
    }
}