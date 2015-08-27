
#define GL_GLEXT_PROTOTYPES 1
#define GL3_PROTOTYPES 1
#include <GL\glew.h>
#include <GLFW/glfw3.h>
#define BUFFER_OFFSET(i) ((char *)NULL + (i))

#include <stdlib.h>
#include <stdio.h>

#pragma comment (lib,"opengl32.lib")
#pragma comment (lib,"glfw3.lib")
#pragma comment (lib,"glew32.lib")

static void error_callback(int error, const char* description)
{
	fputs(description, stderr);
}


short keymode = 1;
static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);

	if (key == GLFW_KEY_1 && action == GLFW_PRESS)
		keymode = 1;
	if (key == GLFW_KEY_2 && action == GLFW_PRESS)
		keymode = 2;
	if (key == GLFW_KEY_3 && action == GLFW_PRESS)
		keymode = 3;
	if (key == GLFW_KEY_4 && action == GLFW_PRESS)
		keymode = 4;
	if (key == GLFW_KEY_4 && action == GLFW_PRESS)
		keymode = 5;
	if (key == GLFW_KEY_4 && action == GLFW_PRESS)
		keymode = 6;
	if (key == GLFW_KEY_4 && action == GLFW_PRESS)
		keymode = 7;
	if (key == GLFW_KEY_4 && action == GLFW_PRESS)
		keymode = 8;
	if (key == GLFW_KEY_4 && action == GLFW_PRESS)
		keymode = 9;
}

int main(void)
{
	GLFWwindow* window;

	glfwSetErrorCallback(error_callback);

	if (!glfwInit())
		exit(EXIT_FAILURE);



	window = glfwCreateWindow(640, 480, "Simple example", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		exit(EXIT_FAILURE);
	}

	glfwMakeContextCurrent(window);

	glewInit();

	glfwSwapInterval(1);

	glfwSetKeyCallback(window, key_callback);


	GLfloat vert[] = { -0.6f, -0.4f, 0.f, 0.6f, -0.4f, 0.f, 0.f, 0.6f, 0.f };
	GLfloat norm[] = { 0, 0, 1, 0, 1, 1, 1, 0, 1 };
	GLfloat colo1[] = { 0.0f, 1.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f };
	GLfloat colo2[] = { 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f };
	GLfloat colo3[] = { 0.0f, 0.50f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.50f };

	GLubyte indices[] = { 0, 1, 2 };

	GLfloat collect[] = {
		-0.6f, -0.4f, 0.f, 1, 0, 0, 0.1f, 0.1f, 0.1f,
		0.6f, -0.4f, 0.f, 1, 1, 0, 0.1f, 0.1f, 0.1f,
		0.f, 0.6f, 0.f, 1, 0, 0, 0.1f, 0.1f, 0.1f
	};


	glEnableClientState(GL_NORMAL_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);
	glEnableClientState(GL_VERTEX_ARRAY);
	while (!glfwWindowShouldClose(window))
	{
		float ratio;
		int width, height;

		glfwGetFramebufferSize(window, &width, &height);
		ratio = width / (float)height;

		glViewport(0, 0, width, height);
		glClear(GL_COLOR_BUFFER_BIT);

		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		glOrtho(-ratio, ratio, -1.f, 1.f, 1.f, -1.f);
		glMatrixMode(GL_MODELVIEW);

		glLoadIdentity();
		glRotatef((float)glfwGetTime() * 5.f, 0.f, 0.f, 1.f);

		switch (keymode)
		{
		case 1:
				glBegin(GL_TRIANGLES);
				glColor3f(0.1f, 0.0f, 0.5f);
				glNormal3f(0,0,1);
				glVertex3f(-0.6f, -0.4f, 0.f);
				glColor3f(0.0f, 0.9f, 0.2f);
				glNormal3f(0,1,1);
				glVertex3f(0.6f, -0.4f, 0.f);
				glColor3f(0.7f, 0.1f, 0.0f);
				glNormal3f(1,0,1);
				glVertex3f(0.f, 0.6f, 0.f);
				glEnd();
			break;
		case 2:
			glColor3f(0.0f, 0.0f, 1.0f);
			//		glEnableClientState(GL_NORMAL_ARRAY);
			//		glEnableClientState(GL_COLOR_ARRAY);
			glEnableClientState(GL_VERTEX_ARRAY);
			//		glNormalPointer(GL_FLOAT, 0, norm);
			//		glColorPointer(3, GL_FLOAT, 0, colo);
			glVertexPointer(3, GL_FLOAT, 0, vert);
			glDrawArrays(GL_TRIANGLES, 0, 3);
			glDisableClientState(GL_VERTEX_ARRAY);  // disable vertex arrays
			//		glDisableClientState(GL_COLOR_ARRAY);
			//		glDisableClientState(GL_NORMAL_ARRAY);
			break;
		case 3:
			//// enable and specify pointers to vertex arrays
			glColor3f(1.0f, 0.0f, 0.0f);
			glEnableClientState(GL_NORMAL_ARRAY);
			glEnableClientState(GL_COLOR_ARRAY);
			glEnableClientState(GL_VERTEX_ARRAY);
			glNormalPointer(GL_FLOAT, 0, norm);
			glColorPointer(3, GL_FLOAT, 0, colo1);
			glVertexPointer(3, GL_FLOAT, 0, vert);
			glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_BYTE, indices);
			glDisableClientState(GL_VERTEX_ARRAY);  // disable vertex arrays
			glDisableClientState(GL_COLOR_ARRAY);
			glDisableClientState(GL_NORMAL_ARRAY);
			break;
		case 4:

			  glEnableClientState(GL_NORMAL_ARRAY);
			  glEnableClientState(GL_COLOR_ARRAY);
			  glEnableClientState(GL_VERTEX_ARRAY);
			  glNormalPointer(GL_FLOAT, 0, norm);
			  glColorPointer(3, GL_FLOAT, 0, colo2);
			  glVertexPointer(3, GL_FLOAT, 0, vert);			  
			  glDrawRangeElements(GL_TRIANGLES, 0, 3, 9, GL_UNSIGNED_BYTE, indices);
			  glDisableClientState(GL_VERTEX_ARRAY);  
			  glDisableClientState(GL_COLOR_ARRAY);
			  glDisableClientState(GL_NORMAL_ARRAY);

			break;
		case 5:			

			glNormalPointer(GL_FLOAT, 9 * sizeof(GLfloat), collect + 3);
			glColorPointer(3, GL_FLOAT, 9 * sizeof(GLfloat), collect + 6);
			glVertexPointer(3, GL_FLOAT, 9 * sizeof(GLfloat), collect);

			glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_BYTE, indices);

			glDisableClientState(GL_VERTEX_ARRAY);  // disable vertex arrays
			glDisableClientState(GL_COLOR_ARRAY);
			glDisableClientState(GL_NORMAL_ARRAY);
			break;
		case 6:
			break;
		}

		







		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwDestroyWindow(window);

	glfwTerminate();
	exit(EXIT_SUCCESS);
}