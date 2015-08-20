/**
 * 
 */
package com.sample.triangle;

import android.app.Activity;
import android.opengl.*;
import android.os.Bundle;

/**
 * @author Mandar
 *
 */
public class SimpleTraingle extends Activity {

	private GLSurfaceView m_Surface;
	
	public SimpleTraingle() 
	{
		
	}

	@Override
	protected void onCreate(Bundle savedInstanceState) 
	{	
		super.onCreate(savedInstanceState);
		
		m_Surface = new Surface(this);
		setContentView(m_Surface);
	}


	@Override
	protected void onPause() 
	{	
		super.onPause();
		m_Surface.onPause();
	}


	@Override
	protected void onResume() 
	{		
		super.onResume();
		m_Surface.onResume();
	}

}

