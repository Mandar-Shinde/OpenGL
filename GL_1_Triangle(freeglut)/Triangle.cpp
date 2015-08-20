
/* Author : Mandar Shinde  */
/* OpenGL Sample using Freeglut Library */

#include <stdio.h>
#include <GL\freeglut.h>

#pragma comment(lib,"freeglut.lib")

void init()
{
	glClearColor(1.0f,1.0f,1.0f,1.0f);		// Clear and set Background Color
}

void Display()
{
	glClear(GL_COLOR_BUFFER_BIT);			// Clear Color Buffers
	
	//Right
	glColor3f(1.0f,0.0f,0.0f);				// Set Color for Triangle 
	glBegin(GL_TRIANGLES);					// Draw Triangle
		glVertex3f(-0.5,-0.0f,1.0f);
		glVertex3f(0.0,0.5f,1.0f);
		glVertex3f(0.5,-0.0f,1.0f);
	glEnd();		

	glutSwapBuffers();						// Swap Front Buffer From Double Buffres
}


int main(int argc,char** argv)
{
	glutInit(&argc,argv);									// Initialize Freeglut Library
	glutInitDisplayMode(GLUT_DEPTH|GLUT_DOUBLE|GLUT_RGB);	// Enable Modes
	glutCreateWindow(" Freeglut OpenGL Triangles");			// Creating Window
	glutDisplayFunc(Display);								// Setting Draw Function
	init();													// Setting before Drawing Geometry
	glutMainLoop();											// Start Drawing
}