/*
 * Copyright (C) 2008 Google Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

package com.android.demo.notepad3;

import android.app.Activity;
import android.content.Intent;
import android.database.Cursor;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.util.Log;

public class NoteEdit extends Activity {
    
    private static final String LOG_TAG = "notepad3.NoteEdit";

    private EditText mTitleText;
    private EditText mBodyText;
    private Long mRowId;
    private NotesDbAdapter mDBAdapter;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        
        Log.v(LOG_TAG, "onCreate");
        
        mDBAdapter = new NotesDbAdapter(this);
        mDBAdapter.open();
        
        setContentView(R.layout.note_edit);
        setTitle(R.string.edit_note);
        
        mTitleText = (EditText) findViewById(R.id.title);
        mBodyText = (EditText) findViewById(R.id.body);

        Button confirmButton = (Button) findViewById(R.id.confirm);

        mRowId = savedInstanceState == null ? null :
            savedInstanceState.getLong(NotesDbAdapter.KEY_ROWID);

        if (mRowId == null) {
            Bundle extras = getIntent().getExtras();
            mRowId = extras != null ? extras.getLong(NotesDbAdapter.KEY_ROWID)
                    : null;
        }
        
        initFields();

        confirmButton.setOnClickListener(new View.OnClickListener() {

            public void onClick(View view) {
                setResult(RESULT_OK);
                finish();
            }

        });
    }
    
    @Override
    protected void onStart() {
        super.onStart();
        Log.v(LOG_TAG, "onStart");
    }
    
    @Override
    protected void onResume() {
        super.onResume();
        Log.v(LOG_TAG, "onResume");
        initFields();
    }
    
    @Override
    protected void onPause() {
        super.onPause();
        Log.v(LOG_TAG, "onPause");
        saveState();
    }
    
    @Override
    protected void onStop() {
        super.onStop();
        Log.v(LOG_TAG, "onStop");
    }
    
    @Override
    protected void onDestroy() {
        super.onDestroy();
        Log.v(LOG_TAG, "onDestroy");
    }
    
    @Override
    protected void onSaveInstanceState (Bundle outState) {
        super.onSaveInstanceState(outState);
        Log.v(LOG_TAG, "onSaveInstanceState");
        saveState();
        if (mRowId != null) {
            outState.putLong(NotesDbAdapter.KEY_ROWID, mRowId);
        }
    }
    
    private void saveState() {
        Log.v(LOG_TAG, "saveState");
        String title = mTitleText.getText().toString();
        String body =mBodyText.getText().toString();
        
        if (mRowId == null) {
            long id = mDBAdapter.createNote(title, body);
            if (id > 0) {
                mRowId = id;
            }
        } else {
            mDBAdapter.updateNote(mRowId, title, body);
        }
    }
    
    private void initFields() {
        Log.v(LOG_TAG, "initFields");
        if ( mRowId != null ) {
            Cursor cursor = mDBAdapter.fetchNote(mRowId);
            startManagingCursor(cursor);
            if (cursor != null) {
                mTitleText.setText(cursor.getString(
                        cursor.getColumnIndex(NotesDbAdapter.KEY_TITLE)));
                mBodyText.setText(cursor.getString(
                        cursor.getColumnIndex(NotesDbAdapter.KEY_BODY)));
            }
        }
    }
}
