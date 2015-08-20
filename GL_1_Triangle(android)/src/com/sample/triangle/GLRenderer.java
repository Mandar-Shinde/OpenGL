package com.sample.triangle;


import javax.microedition.khronos.egl.*;
import javax.microedition.khronos.opengles.*;



import android.opengl.GLES20;
import android.opengl.GLSurfaceView;

public class GLRenderer implements GLSurfaceView.Renderer 
{
	private Shape m_Shape;
	
	public GLRenderer() {	}

	// keep lite as possible
	@Override
	public void onDrawFrame(GL10 gl) 
	{
		// Clear background
		GLES20.glClear(GLES20.GL_COLOR_BUFFER_BIT);
		
		// Drawing
		m_Shape.DrawShape();
		
	}

	
	// dont load always
	@Override
	public void onSurfaceChanged(GL10 gl, int width, int height) {
		GLES20.glViewport(0, 0, width, height);
		
	}

	@Override
	public void onSurfaceCreated(GL10 gl, EGLConfig config) {
		
		// Set the background frame color
        GLES20.glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

        m_Shape = new Shape();
	}
	
	public static int LoadShader(int type,String shaderCode)
	{
		int shader = GLES20.glCreateShader(type);
		GLES20.glShaderSource(shader, shaderCode);
		GLES20.glCompileShader(shader);
		
		return shader;			
	}


}
