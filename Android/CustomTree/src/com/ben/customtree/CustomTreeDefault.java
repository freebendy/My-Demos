package com.ben.customtree;

import android.app.Activity;
import android.os.Bundle;
import android.view.KeyEvent;
import android.view.View;
import android.view.View.OnClickListener;
import android.view.ViewGroup;
import android.widget.Button;
import android.widget.LinearLayout;

public class CustomTreeDefault extends Activity implements OnClickListener {

    private final int WC = ViewGroup.LayoutParams.WRAP_CONTENT;
    private LinearLayout mLayout;
    private GraphicView mGraphicView;

    /** Called when the activity is first created. */
    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        mLayout = new LinearLayout(this);
        mLayout.setOrientation(LinearLayout.HORIZONTAL);
        setContentView(mLayout);
        LinearLayout.LayoutParams param =
            new LinearLayout.LayoutParams(200, 300);
        param.leftMargin = 1;
        mGraphicView = new GraphicView(this);
        mLayout.addView(mGraphicView,param);

        Button btn = new Button(this);
        btn.setText("Exit");
        btn.setOnClickListener(this);
        param = new LinearLayout.LayoutParams(WC, WC);
        param.leftMargin = 10;
        mLayout.addView(btn, param);
        mGraphicView.build_model();
        mGraphicView.requestFocus();
    }

    @Override
    public boolean onKeyDown(int keyCode, KeyEvent msg) {
        if(keyCode == KeyEvent.KEYCODE_DPAD_DOWN) {
            mGraphicView.MoveDown();
        }
        if(keyCode == KeyEvent.KEYCODE_DPAD_UP) {
            mGraphicView.MoveUp();
        }
        if(keyCode == KeyEvent.KEYCODE_Z) {
            mGraphicView.zip_toggle();
        }
        return true;
    }

    public void onClick(View arg0) {
        finish();
    }
}