
#include <string.h>
#include <GL/glut.h>
#include <iostream>
#include <fstream>
#include<GL/freeglut.h>

GLfloat UpwardsScrollVelocity = -10.0;
float view=20.0;

char quote[6][80];
int numberOfQuotes=0,i;

//*********************************************
//*  glutIdleFunc(timeTick);                  *
//*********************************************

void timeTick(void)
{
    if (UpwardsScrollVelocity< -600)
        view-=0.011;
    if(view < 0) {view=20; UpwardsScrollVelocity = -10.0;}
    //  exit(0);
    UpwardsScrollVelocity -= 0.5;
  glutPostRedisplay();

}


//*********************************************
//* printToConsoleWindow()                *
//*********************************************

void printToConsoleWindow()
{
    int l,lenghOfQuote, i;

    for(  l=0;l<numberOfQuotes;l++)
    {
        lenghOfQuote = (int)strlen(quote[l]);

        for (i = 0; i < lenghOfQuote; i++)
        {
          //cout<<quote[l][i];
        }
          //out<<endl;
    }

}

//*********************************************
//* RenderToDisplay()                       *
//*********************************************

void RenderToDisplay()
{
    int l,lenghOfQuote, i;

    glTranslatef(0.0, -10, 25);
    glRotatef(-20, 1.0, 0.0, 0.0);
    glScalef(0.1, 0.1, 1);


glScalef(0.5,0.5,1);
glutStrokeString(GLUT_STROKE_ROMAN, (unsigned char*)"The game over!");
   
        lenghOfQuote = (int)strlen(quote[1]);
        glPushMatrix();
        glTranslatef(-(lenghOfQuote*37), -(1*200), 0.0);
        for (i = 0; i < lenghOfQuote; i++)
        {
            glColor3f((UpwardsScrollVelocity/10)+300+(1*10),(UpwardsScrollVelocity/10)+300+(1*10),0.0);
            glutStrokeCharacter(GLUT_STROKE_ROMAN, quote[1][i]);
        }
        glPopMatrix();
   

}
//*********************************************
//* glutDisplayFunc(myDisplayFunction);       *
//*********************************************

void myDisplayFunction(void)
{
  glClear(GL_COLOR_BUFFER_BIT);
  glLoadIdentity();
  gluLookAt(0.0, 30.0, 100.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
  RenderToDisplay();
  glutSwapBuffers();
}
//*********************************************
//* glutReshapeFunc(reshape);               *
//*********************************************

void reshape(int w, int h)
{
  glViewport(0, 0, w, h);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(60, 1.0, 1.0, 3200);
  glMatrixMode(GL_MODELVIEW);
}

//*********************************************
//* int main()                                *
//*********************************************


int main(int argc, char **argv)
{
    
    strcpy(quote[1],"B");
    
    numberOfQuotes=5;
glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 400);
    glutCreateWindow("StarWars scroller");
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glLineWidth(3);

    glutDisplayFunc(myDisplayFunction);
    glutReshapeFunc(reshape);
    glutIdleFunc(timeTick);
    glutMainLoop();

    return 0;
}