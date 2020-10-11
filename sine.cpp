#include <iostream>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <GL/freeglut.h>
#include <cmath>
#include <GL/glut.h>
#include <GL/freeglut.h>
#include<math.h>
#include <cstring>
#include <string>
#include <iostream>
#include <iomanip>
#include <sstream>
#include<time.h>
using namespace std;
#include <openssl/sha.h>

using namespace std;

void init()
{
 glOrtho(-10, 10, -10, 10, -10, 10);
}

void func1()
{
 glClearColor(.45, .29, .76, 0);
 glClear(GL_COLOR_BUFFER_BIT);
 double y=4;
 glLoadIdentity();
 glOrtho(-50, 50, -50, 50, -50, 50);
 glTranslatef(0,-3,0);
 glColor3f(0.19, 0.27, 0.39);
 glPointSize(2);
 glBegin(GL_POINTS);
 for (double x = -10; x <= 10; x += 0.01) {
  glVertex2f(x, sin(y));
  glVertex2f(x,cos(y));
  y = y+0.01;
 }
 glEnd();
 glLoadIdentity();
 glOrtho(-10, 10, -10, 10, -10, 10);
 glColor3f(0.19, 0.27, 0.39);
 glPointSize(2);
 glBegin(GL_POINTS);
 for (double x = -10; x <= 10; x += 0.01) {
  glVertex2f(x, sin(y));
  glVertex2f(x,cos(y));
  y = y+0.01;
 }
 glEnd();
 glFlush();
}

int main(int argc, char **argv)
{
 glutInit(&argc, argv);
 glutInitWindowPosition(50, 50);
 glutInitWindowSize(500, 500);
 glutCreateWindow("Sine Wave");
 init();
 glutDisplayFunc(func1);
 glutMainLoop();

 return 0;
}