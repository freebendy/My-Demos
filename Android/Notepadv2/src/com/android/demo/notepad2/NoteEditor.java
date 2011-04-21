/**
 * 
 */
package com.android.demo.notepad2;

import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;

public class NoteEditor extends Activity {

    private EditText mTitle;
    
    private EditText mBody;
    
    private Long mRowId;
    
    /** Called when the activity is first created. */
    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.note_edit);
        
        mTitle = (EditText) findViewById(R.id.title);
        
        mBody = (EditText) findViewById(R.id.body);
        
        Bundle extras = getIntent().getExtras();
        
        mRowId = null;
        if (extras != null) {
            String title = extras.getString(NotesDbAdapter.KEY_TITLE);
            String body = extras.getString(NotesDbAdapter.KEY_BODY);
            mRowId = extras.getLong(NotesDbAdapter.KEY_ROWID);
            
            if (title != null) {
                mTitle.setText(title);
            }
            
            if (mBody != null) {
                mBody.setText(body);
            }
        }
        
        Button confirmButton = (Button) findViewById(R.id.confirm);
        confirmButton.setOnClickListener( new View.OnClickListener() {
            
            public void onClick(View v) {
                Bundle bundle = new Bundle();
                bundle.putString(NotesDbAdapter.KEY_TITLE, mTitle.getText().toString());
                bundle.putString(NotesDbAdapter.KEY_BODY, mBody.getText().toString());
                if ( mRowId != null ) {
                    bundle.putLong(NotesDbAdapter.KEY_ROWID, mRowId);
                }
                
                Intent intent = new Intent();
                intent.putExtras(bundle);
                setResult(RESULT_OK,intent);
                finish();
            }
        });
    }
}
