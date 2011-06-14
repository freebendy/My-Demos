package com.tieto.SlidingTime;

import android.content.Context;
import android.graphics.Canvas;
import android.util.AttributeSet;
import android.util.Log;
import android.view.Gravity;
import android.view.ViewGroup;
import android.widget.TextView;

public class SlidingTime extends ViewGroup {

    private static final String TAG = "SlidingTime";
    private static boolean DEBUG = true;

    private static int mDefaultItemsCount = 20;
    private static int mDefaultItemWidth = 90;
    private static int mDefaultItemHeight = 90;
    private static int mDefaultBarHeight = 60;

    private SlidingBar mBar;
    private SlidingItem[] mItems;    
    private int mCoordOffset;        

    public SlidingTime(Context context) {
        super(context);
        init(context);
    }

    public SlidingTime(Context context, AttributeSet attrs) {
        super(context, attrs);
        init(context);
    }

    public SlidingTime(Context context, AttributeSet attrs, int defStyle) {
        super(context, attrs, defStyle);
        init(context);
    }

    private void init(Context context) {
        setBackgroundColor(0x676767FF);
        mBar = new SlidingBar(this);
        mItems = new SlidingItem[mDefaultItemsCount];
        mItems[0] = new SlidingItem(getContext());
        mItems[0].setItemData("11:00", "Wen", "Bye");
        mItems[1] = new SlidingItem(getContext());
        mItems[1].setItemData("11:30", "Huang", "Hello");
        mItems[2] = new SlidingItem(getContext());
        mItems[2].setItemData("11:50", "Liu", "Good");
        addView(mItems[0]);
        addView(mItems[1]);
        addView(mItems[2]);
    }

    @Override
    protected void onLayout(boolean changed, int l, int t, int r, int b) {
            Log.i(TAG, "SlidingTime - onLayout(changed=" + changed + ", l=" + l + ", t=" + t + ", r=" + r + ", b=" + b + ")");
        mBar.layout(l, t+200, r, t+200+mDefaultBarHeight);
        int pos = 0;
        for (int i=0; i < mItems.length; i++) {
            if ( mItems[i] != null ) {
                mItems[i].layout(l + pos, t, l + mDefaultItemWidth + pos, t + mDefaultItemHeight);
                pos += 100;
            }
        }
    }

    /*
     *
     */
    private class SlidingItem extends ViewGroup {
        private static final String TAG = "SlidingTime.SlidingItem";

        private TextView mTime;
        private TextView mName;
        private TextView mSubject;

        private boolean mDirectionUp;    
        private int mType;

        public SlidingItem(Context context) {
            super(context);
            init();
        }

        public SlidingItem(Context context, AttributeSet attrs) {
            super(context, attrs);
            init();
        }

        public SlidingItem(Context context, AttributeSet attrs, int defStyle) {
            super(context, attrs, defStyle);
            init();
        }

        public void setItemData(String time, String name, String subject) {
            mTime.setText(time);
            mName.setText(name);
            mSubject.setText(subject);
        }

        private void init() {
            setBackgroundColor(0x80808080);
            mTime = new TextView(getContext());
            mTime.setBackgroundColor(0xEFEFEFFF);
            mTime.setText("12:00");
            mTime.setGravity(Gravity.RIGHT);
            mName = new TextView(getContext());
            mName.setBackgroundColor(0xEFEFEFFF);
            mName.setText("Wen Jing");
            mName.setGravity(Gravity.RIGHT);
            mSubject = new TextView(getContext());
            mSubject.setBackgroundColor(0xEFEFEFFF);
            mSubject.setText("Hello World");
            SlidingItem.this.addView(mTime);
            SlidingItem.this.addView(mName);
            SlidingItem.this.addView(mSubject);
        }

        @Override
        protected void onMeasure(int widthMeasureSpec, int heightMeasureSpec) {
            super.onMeasure(widthMeasureSpec, heightMeasureSpec);
            //setMeasuredDimension(mDefaultItemWidth, mDefaultItemHeight);
        }

        @Override
        protected void onLayout(boolean changed, int l, int t, int r, int b) {
                Log.v(TAG, "SlidingItem - onLayout(changed=" + changed + ", l=" + l + ", t=" + t + ", r=" + r + ", b=" + b + ")");
            mTime.layout(l+20, t, r, t+20);
            mName.layout(l+20, t+20, r, t+40);
            mSubject.layout(l, t+40, r, b);
        }
    }

    private class SlidingBar {
        private static final String TAG = "SlidingTime.SlidingBar";

        private TextView mTime;

        SlidingBar(ViewGroup parent) {
            mTime = new TextView(parent.getContext());
            mTime.setText("abc is good");
            mTime.setBackgroundColor(0xEFEFEFFF);
            parent.addView(mTime);
        }

        public void layout(int l, int t, int r, int b) {
            if (DEBUG) {
                Log.d(TAG, "onLayout(l=" + l + ", t=" + t + ", r=" + r + ", b=" + b + ")");
            }
            mTime.layout(l, t, r, b);
        }
    }


}
