#include <iostream>
#include <stdio.h>
//#include <GL\freeglut.h>
#include <fstream>
#define EOL '\n'
#define CAR_RETURN '\r'

void readt()
{
	char str[80];

	char cmd;
	float v1, v2, v3, v4;
	FILE * pFile;

	pFile = fopen("t.obj", "r");

	if (pFile == NULL)
		return;

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
		fscanf(pFile, "%s %f %f %f %f", &cmd, &v1, &v2, &v3, &v4);
		printf("%c %f %f %f %f\n", cmd, v1, v2, v3, v4);
		switch (cmd)
		{
		case 'v':
			vert[vid] = v1; vid++;
			vert[vid] = v2; vid++;
			vert[vid] = v3; vid++;
			break;
		case 'f':
			face[fid] = v1; fid++;
			face[fid] = v2; fid++;
			face[fid] = v3; fid++;
			break;
		default:
			break;
		}
		
	}
	fclose(pFile);
}

int main()
{
	readt();
	return 0;
}