#include <iostream>
#include <stdio.h>
#include <GL\glew.h>
#include <GL\freeglut.h>

#include <fstream>
#include <conio.h>
#define EOL '\n'
#define CAR_RETURN '\r'



int main(int argc, char *argv[])
{

	char cmd;
	float v1, v2, v3, v4;
	FILE * pFile;

	fopen_s(&pFile,"t.obj", "r");

	if (pFile == NULL)
		return 0;

	unsigned int line_count = 0;
	unsigned int face_count = 0;
	char ch;
	fseek(pFile, 0, SEEK_SET);
	while ((ch = fgetc(pFile)) != EOF)
	{
		if (ch == 'v')
			++line_count;
		if (ch == 'f')
			++face_count;
	}
	float* vert = new float[((line_count + 1) * 3)];
	long vid = 0;
	int* face = new int[((face_count + 1) * 3)];
	long fid = 0;

	fseek(pFile, 0, SEEK_SET);
	while (!feof(pFile))
	{
		fscanf(pFile, "%c %f %f %f %f", &cmd, &v1, &v2, &v3, &v4);
		//printf("%c %f %f %f %f\n", cmd, v1, v2, v3, v4);
		switch (cmd)
		{
		case 'v':
			vert[vid] = v1; vid++;
			vert[vid] = v2; vid++;
			vert[vid] = v3; vid++;
			break;
		case 'f':
			face[fid] = (int)v1; fid++;
			face[fid] = (int)v2; fid++;
			face[fid] = (int)v3; fid++;
			break;
		default:
			break;
		}
		
	}
	cmd=0;
	fclose(pFile);

	glutInit(&argc,argv);
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize (250, 250);
	glutInitWindowPosition (100, 100);

	glutCreateWindow ("winlock");
	glClearColor (0.0, 0.0, 0.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);

	GLuint idvtx=0;

	glewInit();
	glGenBuffers(1,&idvtx);
	glBindBuffer(GL_ARRAY_BUFFER,idvtx);
	glBufferData(GL_ARRAY_BUFFER,vid,&vert[0],GL_STATIC_DRAW);

	glVertexPointer(2, GL_FLOAT, sizeof(float)*3,vert);
	glEnableClientState(GL_VERTEX_ARRAY);

	delete [] vert;

	glDrawArrays(GL_TRIANGLES, 0, vid);

	glDisableClientState(GL_COLOR_ARRAY);
	glDisableClientState(GL_VERTEX_ARRAY);

	while (getch())
	{

	}
	return 0;
}