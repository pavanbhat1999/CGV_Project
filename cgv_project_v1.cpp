
#include<GL/glut.h>
#include<GL/freeglut.h>
#include <cstring>
#include<string>
#include<windows.h>
#include<GL/gl.h>

void display();
void reshape(int , int );
void timer(int);
void keyboard( unsigned char key, int x, int y );

float x_pos = -9.0;
int state =1;
int count=0;
bool isAnimating = true;
bool first = true;
bool second =false;
bool third = false;
bool block1 = true;
bool block2 = true;
bool block3 = true;


void keyboard( unsigned char key, int x, int y )
{
//   All keyboard inputs
    if ('c'==key)
    {
        count++;
        switch (count)
        {
        case 1:
            second = true;
            first = false;
            second = true;
            break;
        case 2:
            third = true;
            first =false;
            second = false;

        default:
            break;
        }
    }
    if( ' ' == key )
    {
        isAnimating = !isAnimating;
    }
    if ('1'==key)
    {

        block1 = !block1;
    }
    if ('2'==key)
    {
        block2 = !block2;
    }
    if ('3'==key)
    {
glutPostRedisplay();
        block3 = !block3;
    }

}

void drawtext(const char text_from_main[],float x , float y)
{
    std::string text;
     //text = "-----------------------------------BLOCK CHAIN - THE TECHNOLOGY OF FUTURE----------------------------------------";
   // drawtext(text.data(),text.size(),-0.9,0.9);
    text = text_from_main;
    const char *real_text = text.data();
    int length = text.size();
    glRasterPos2f(x,y);
    for (int i = 0; i < length; i++)
    {
        glColor3f(1.0,0.0,0.0);
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,(int)real_text[i]);
    }

}


void drawbox(float x_up,float y_left, float x_down , float y_right)
{

    glBegin(GL_POLYGON);
        glColor3f(0,0,1);
        glVertex2f(x_up,y_left);
        glVertex2f(x_up,y_right);
        glVertex2f(x_down,y_right);
        glVertex2f(x_down,y_left);


    glEnd();
}

void drawbox_green(float x_up,float y_left, float x_down , float y_right)
{

    glBegin(GL_POLYGON);
        glColor3f(1.0,0.0,0.5);
        //glColor3f(0.5f,0.5f,1.0f);
        glVertex2f(x_up,y_left);
        glVertex2f(x_up,y_right);
        glVertex2f(x_down,y_right);
        glVertex2f(x_down,y_left);


    glEnd();
}

void drawpkt()
{
    glBegin(GL_POLYGON);
     glColor3f( 1, 0, 0 );glVertex2f(x_pos,0.5);
        glColor3f( 1, 0, 0 );glVertex2f(x_pos,-0.5);
        glColor3f( 1, 0, 0 );glVertex2f(x_pos+0.5,-0.5);
        glColor3f( 1, 0, 0 );glVertex2f(x_pos+0.5,0.5);

    glEnd();
}

void reshape(int w ,int h)
{
    glViewport(0,0,w,h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-10,10,-10,10);
    glMatrixMode(GL_MODELVIEW);


}

void timer1(int  )
{
    glutPostRedisplay();
    glutTimerFunc(1000/60,timer1,0 );
 if (isAnimating)
 {
    switch (state)
        {
        case 1:



                if (x_pos<8)
                {
                    x_pos+=0.03;

                }
                else
                    state = -1;
                break;

        case -1 :
                    if (x_pos>-8)
                    {
                        x_pos-=0.03;

                        // state = 0;  stop right
                    }
                    else
                        state=1;
                        //state = 0;  stop left

                    break;
        case 0 : break;
        }
  }
}

void timer(int  )
{
    glutPostRedisplay();
    glutTimerFunc(1000/60,timer,0 );


    switch (state)
    {
    case 1:


            if (x_pos<10)
            {
                x_pos+=0.05;

            }
            else
                state = -1;
            break;

    case -1 :
                if (x_pos>-10)
                {
                    x_pos-=0.05;

                }
                else
                    state=1;

                break;
    }
}
void init()
{
    glClearColor(0.0,1.0,1.0,1.0);
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    if (first)
    {
            drawtext("press c to continue", -9.0,-9.0);
    }

    if (second)
    {
    if (block1)
    {
        drawbox(-8.5,-3.0,-6.0,3.0);
        drawtext("BLOCK 1",-8.0,-2.0);
    }
    if (block2)
    {
        drawbox(-1.0,-3.0,1.5,3.0);
        drawtext("BLOCK 2",-0.5,-4.0);
    }
    if (block3)
    {
        drawbox(8.5,-3.0,6.0,3.0);
        drawtext("BLOCK 3",7.0,-4.0);
    }
    drawbox_green(-1.0,-6.0,1.5,-9.0);
    drawtext("LEDGER",-0.5,-9.5);
    glBegin(GL_LINES);
    glColor3f(0,0,0);
    glVertex2f(-7.5,-3.0);
    glVertex2f(-1.0,-6.0);
glEnd();
    drawpkt();
    if (block1)
    drawtext("BLOCK 1",-8.0,-2.0);
    drawtext("P1",x_pos+0.5,-1.0);
    drawtext("----------------------------------------BLOCK CHAIN - THE NEXT BIG THING----------------------------------------",-9.0,9.0);
    drawtext("press c to continue",-9.0,-9.0);
    }
   if (third)
   {
       drawtext("sample 3",0.0,0.0);
   }
    //glFlush();

    glutSwapBuffers(); // Required to copy color buffer onto the screen.


}

//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

int main(int argc,char **argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowPosition(1000,1000);
    glutInitWindowSize(5000,5000);
    glutCreateWindow("window");

    glutDisplayFunc(display);

    glutReshapeFunc(reshape);
    glutTimerFunc(0,timer1,0);
    glutKeyboardFunc(keyboard) ;
    //glutTimerFunc(0,timer,0);
    init();
    glutMainLoop();

}
