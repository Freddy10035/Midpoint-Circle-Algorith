#include <stdio.h>
#include <iostream>
#include <glut.h>
using namespace std;
int p, q, r;
void myInit(void)
{
	glClearColor(0.0, 1.0, 0.0, 0.0);
	glColor3f(0.0f, 0.0f, 0.0f);
	glPointSize(5.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 640.0, 0.0, 480.0);
}
void plotVertex(int x, int y)
{
	glBegin(GL_POINTS);
	glVertex2i(x + p, y + q);
	glEnd();
}
void myDisplay(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0, 0.0, 1.0);
	glPointSize(4.0);
	int x = 0;
	int y = r;
	float decs = 5 / 4 - r;
	plotVertex(x, y);
	while (y > x)
	{
		if (decs < 0) {
			x++;
			decs += 2 * x + 1;
		}
		else {
			y--;
			x++;
			decs += 2 * (x - y) + 1;
		}
		plotVertex(x, y);
		plotVertex(x, -y);
		plotVertex(-x, y);
		plotVertex(-x, -y);
		plotVertex(y, x);
		plotVertex(-y, x);
		plotVertex(y, -x);
		plotVertex(-y, -x);
	}
	glFlush();
}

void main(int argc, char** argv)
{
	cout << " Midpoint Circle Drawing Algorithm in C++ using OpenGL\n\n";
	cout << "Enter x co-ordinate : "; cin >> p;
	cout << "Enter y co-ordinate : "; cin >> q;
	cout << "Enter the radius : "; cin >> r;
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(640, 480);
	glutInitWindowPosition(100, 150);
	glutCreateWindow("Midpoint Circle Drawing Alogrithm");
	glutDisplayFunc(myDisplay);
	myInit();
	glutMainLoop();
}