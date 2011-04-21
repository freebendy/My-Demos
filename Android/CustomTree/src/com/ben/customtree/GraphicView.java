package com.ben.customtree;

import java.util.ArrayList;
import java.util.HashMap;

import android.content.Context;
import android.graphics.Canvas;
import android.graphics.Color;
import android.graphics.Paint;
import android.view.View;

public class GraphicView extends View {

    private Paint mPaint = new Paint();

    private ObjectMap mRoot, mNextNode, mCurrentItem, pa;

    private MapList show_list, lv_0_coll, lv_1_coll, lv_2_coll;

    private int base, x, y, mTargetIndex, acc_index;

    private class MapList extends ArrayList<ObjectMap> {
        private static final long serialVersionUID = 1L;
    }

    private class ObjectMap extends HashMap<String, Object> {

        private static final long serialVersionUID = 1L;

        public void put_object(String aKey, Object aValue) {
            super.put(aKey, aValue);
        }

        public void put_string(String aKey, String aValue) {
            super.put(aKey, aValue);
        }

        public MapList get_children() {
            return (MapList) super.get("sons");
        }
    }

    GraphicView(Context context) {
        super(context);
        mTargetIndex = 0;
        base = 0;
        mRoot = getNewNode(null, "goal");
    }

    @Override
    protected void onDraw(Canvas canvas) {
        canvas.drawColor(Color.WHITE);
        y = base + 6;
        acc_index = 0;
        show_list = new MapList();
        this.drawNode_recursive(mRoot, canvas);
    }

    private void drawNode_recursive(ObjectMap curr_node, Canvas canvas) {
        String level = curr_node.get("level").toString();
        int k = Integer.valueOf(level);
        x = k * 10 + 2;
        MapList son_coll = curr_node.get_children();
        int sz = son_coll.size();
        String plus = "+"; // zip
        if (sz == 0) {
            plus = "-";
            show_list.add(curr_node);
            this.drawNode(x, y, curr_node, plus, canvas);
            if (pa != null)
                pa.put_object("last_pos", new Integer(y));
            curr_node.put_object("last_pos", new Integer(y + 6));
            return;
        } else {
            plus = curr_node.get("zip").toString();
            if (plus == "+") {
                show_list.add(curr_node);
                this.drawNode(x, y, curr_node, plus, canvas);
                pa = (ObjectMap) curr_node.get("parent");
                if (pa != null) {
                    pa.put_object("last_pos", new Integer(y));
                }
                curr_node.put_object("last_pos", new Integer(y + 6));
                return;
            }
            show_list.add(curr_node);
            this.drawNode(x, y, curr_node, plus, canvas);
            pa = (ObjectMap) curr_node.get("parent");
            if (pa != null) {
                pa.put("last_pos", new Integer(y));
            }
            curr_node.put_object("last_pos", new Integer(y + 6));
            for (int i = 0; i < sz; i++) {
                mNextNode = (ObjectMap) son_coll.get(i);
                y = y + 15;
                this.drawNode_recursive(mNextNode, canvas);
            }
        }
    }

    private void drawNode(int x, int y, ObjectMap curr_node, String plus,
            Canvas canvas) {
        String tx = curr_node.get("name").toString();
        mPaint.setAntiAlias(true);
        if (x != 2) {
            mPaint.setColor(Color.DKGRAY);
            canvas.drawLine(x - 5, y + 5, x, y + 5, mPaint);
            pa = (ObjectMap) curr_node.get("parent");
            Integer last_pos = (Integer) pa.get("last_pos");
            int last_y = last_pos;
            canvas.drawLine(x - 5, last_y + 4, x - 5, y + 5, mPaint);
        }
        mPaint.setColor(Color.BLACK);
        mPaint.setStrokeWidth(1);
        mPaint.setColor(Color.LTGRAY);
        canvas.drawRect(x, y, x + 10, y + 10, mPaint);
        mPaint.setColor(Color.BLUE);
        canvas.drawLine(x + 2, y + 5, x + 8, y + 5, mPaint);
        if (plus == "+") {
            canvas.drawLine(x + 5, y + 2, x + 5, y + 8, mPaint);
        }

        if (plus == "@") {
            canvas.drawRect(x + 2, y + 2, x + 8, y + 8, mPaint);
        }

        String level = curr_node.get("level").toString();
        int k = Integer.valueOf(level);
        switch (k) {
        case 0:
            mPaint.setColor(Color.BLACK);
            break;
        case 1:
            mPaint.setColor(Color.BLUE);
            break;
        case 2:
            mPaint.setColor(Color.BLACK);
            break;
        case 3:
            mPaint.setColor(Color.BLUE);
            break;
        }

        if (mTargetIndex == acc_index) {
            mPaint.setColor(Color.RED);
        }

        canvas.drawText(tx, x + 13, y + 8, mPaint);
        acc_index++;
    }

    public void build_model() {
        mRoot = getNewNode(null, "goal");
        lv_0_coll = mRoot.get_children();
        mCurrentItem = getNewNode(mRoot, "money");
        lv_0_coll.add(mCurrentItem);
        lv_1_coll = mCurrentItem.get_children();
        lv_1_coll.add(getNewNode(mCurrentItem, "salary"));
        lv_1_coll.add(getNewNode(mCurrentItem, "bonus"));
        lv_1_coll.add(getNewNode(mCurrentItem, "extra_bonus"));
        mCurrentItem.put_string("zip", "@");

        mCurrentItem = getNewNode(mRoot, "thing");
        lv_0_coll.add(mCurrentItem);
        lv_1_coll = mCurrentItem.get_children();
        mNextNode = getNewNode(mCurrentItem, "few");
        lv_1_coll.add(mNextNode);
        lv_2_coll = mNextNode.get_children();
        lv_2_coll.add(getNewNode(mNextNode, "little"));
        lv_2_coll.add(getNewNode(mNextNode, "fewer"));

        mNextNode.put("zip", "+");
        lv_1_coll.add(getNewNode(mCurrentItem, "middle"));
        lv_1_coll.add(getNewNode(mCurrentItem, "busy"));
        mCurrentItem.put_string("zip", "@");
        mCurrentItem = getNewNode(mRoot, "long");

        lv_0_coll.add(mCurrentItem);
        lv_1_coll = mCurrentItem.get_children();
        lv_1_coll.add(getNewNode(mCurrentItem, "short"));
        lv_1_coll.add(getNewNode(mCurrentItem, "middle"));
        lv_1_coll.add(getNewNode(mCurrentItem, "long"));
        mCurrentItem.put_string("zip", "@");
        mRoot.put_string("zip", "@");
    }

    private ObjectMap getNewNode(ObjectMap aParent, String aName) {
        String parentlevel = null;
        String level = null;
        if (aParent == null) {
            level = "0";
        } else {
            parentlevel = aParent.get("level").toString();
            level = String.valueOf(Integer.valueOf(parentlevel) + 1);
        }
        ObjectMap m_obj = new ObjectMap();
        m_obj.put_object("last_pos", new Integer(18));
        m_obj.put_string("level", level);
        m_obj.put_string("name", aName);
        m_obj.put_object("parent", aParent);
        m_obj.put_object("sons", new MapList());
        m_obj.put_string("zip", "+");
        return m_obj;
    }

    public void MoveUp() {
        mTargetIndex--;
        this.invalidate();
    }

    public void MoveDown() {
        mTargetIndex++;
        this.invalidate();
    }

    public void zip_toggle() {
        ObjectMap curr_node = show_list.get(mTargetIndex);
        String zz = curr_node.get("zip").toString();
        if (zz == "@") {
            curr_node.put_string("zip", "+");
            this.invalidate();
        }
        if (zz == "+") {
            curr_node.put_string("zip", "@");
            this.invalidate();
        }
    }
}
