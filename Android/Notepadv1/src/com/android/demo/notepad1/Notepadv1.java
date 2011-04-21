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

package com.android.demo.notepad1;

import android.app.ListActivity;
import android.database.Cursor;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuInflater;
import android.view.MenuItem;
import android.widget.SimpleCursorAdapter;

public class Notepadv1 extends ListActivity {
    private int mNoteNumber = 1;
    private NotesDbAdapter mDbAdapter;

    /** Called when the activity is first created. */
    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.notepad_list);
        mDbAdapter = new NotesDbAdapter(this);
        mDbAdapter.open();
        initList();
    }

    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        // TODO Auto-generated method stub
//        return super.onCreateOptionsMenu(menu);
        MenuInflater inflater = getMenuInflater();
        inflater.inflate(R.menu.list_options_menu, menu);
        return true;

    }

    @Override
    public boolean onOptionsItemSelected(MenuItem item) {
        // TODO Auto-generated method stub
        switch (item.getItemId()) {
        case R.id.menu_add_note:
            addNote();
            return true;
        }
        return super.onOptionsItemSelected(item);
    }
    
    public void addNote() {
        String noteName = "Note" + mNoteNumber++;
        mDbAdapter.createNote(noteName, "");
        initList();
    }
    
    private void initList() {
        Cursor cursor = mDbAdapter.fetchAllNotes();
        startManagingCursor(cursor);
        
        String[] from = new String[] { NotesDbAdapter.KEY_TITLE };
        int[] to = new int[] { R.id.textView1 };
        
        SimpleCursorAdapter listAdapter =
            new SimpleCursorAdapter(this,R.layout.notes_rows,cursor,from,to );
        
        setListAdapter(listAdapter);
    }
}
