package com.sample.triangle;

import java.nio.ByteBuffer;
import java.nio.ByteOrder;
import java.nio.FloatBuffer;



import android.opengl.GLES20;
import android.widget.Toast;
import android.content.Context.*;

public class Shape 
{
	
	 static float shapeCoords[] = { // in counterclockwise order:
         0.0f,  0.6f, 0.0f,   // top
        -0.5f, -0.3f, 0.0f,   // bottom left
         0.5f, -0.3f, 0.0f    // bottom right
    };
	 
	 public final FloatBuffer mbuff_vertex; 
	 
	 private final String vertexShaderCode =
		        "attribute vec4 vPosition;" +
		        "void main() {" +
		        "  gl_Position = vPosition;" +
		        "}";

		    private final String fragmentShaderCode =
		        "precision mediump float;" +
		        "uniform vec4 vColor;" +
		        "void main() {" +
		        "  gl_FragColor = vColor;" +
		        "}";

		    private final FloatBuffer vertexBuffer=null;
		    private int mProgram=0;
		    private int mPositionHandle=0;
		    private int mColorHandle=0;
		    
		    float[] color={1,0,0,1};
	 
	public Shape() 
	{
		// use vertex byte buffer
		ByteBuffer bb = ByteBuffer.allocateDirect(shapeCoords.length*4);
		
		// use native byte order
		bb.order(ByteOrder.nativeOrder()); // little/big endian 
		
		mbuff_vertex = bb.asFloatBuffer();	// Make Space
		mbuff_vertex.put(shapeCoords);		// fill Coord
		mbuff_vertex.position(0);			// set first coord
		
		// Attach Shaders
		   // prepare shaders and OpenGL program
        int vertexShader = GLRenderer.LoadShader(GLES20.GL_VERTEX_SHADER,vertexShaderCode);
        int fragmentShader = GLRenderer.LoadShader(GLES20.GL_FRAGMENT_SHADER,fragmentShaderCode);

        mProgram = GLES20.glCreateProgram();             // create empty OpenGL Program
        GLES20.glAttachShader(mProgram, vertexShader);   // add the vertex shader to program
        GLES20.glAttachShader(mProgram, fragmentShader); // add the fragment shader to program
        GLES20.glLinkProgram(mProgram);                  // create OpenGL program executables

	}

	public void DrawShape()
	{
		String s;
		try
		{
			GLES20.glUseProgram(mProgram);
			mPositionHandle = GLES20.glGetAttribLocation(mProgram, "vPosition");
			
			GLES20.glEnableVertexAttribArray(mPositionHandle);

			GLES20.glVertexAttribPointer(mPositionHandle, 3, GLES20.GL_FLOAT, false, 3*4, mbuff_vertex);
			
			mColorHandle = GLES20.glGetUniformLocation(mProgram, "vColor");			
			
			// Set color for drawing the triangle
	        GLES20.glUniform4fv(mColorHandle, 1, color, 0);

	        // Draw the triangle
	        GLES20.glDrawArrays(GLES20.GL_TRIANGLES, 0, (shapeCoords.length/3));

	        // Disable vertex array
	        GLES20.glDisableVertexAttribArray(mPositionHandle);
	        
		}catch(Exception e)
		{
			s=e.toString();
		}
	}
	
}
