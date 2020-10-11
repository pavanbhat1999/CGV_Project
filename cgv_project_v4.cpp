#include <GL/glut.h>
#include <GL/freeglut.h>
#include <cstring>
#include <string>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
using namespace std;
#include <openssl/sha.h>
#define upbox 2

int flag=0;
float tr=0.0,t=0.0,t2=0.0,t3=0.0,t4=0.0,t1=0.0,t5=0.0;
float tr1=0.0;
float tr2=0.0;
float tr3=0.0;
float tr4=0.0;
float tr5=0.0;

void anim();
void animate();


void mymenu(int id)
{
switch(id)
{
case 1: glutIdleFunc(animate);
break;
case 2:flag=1;
glutIdleFunc(anim);
break;
case 3: flag=2;
glutIdleFunc(anim);
break;
case 4: flag=3;
glutIdleFunc(anim);
break;
case 5:exit(0);
}
}
void anim()
{
if(t<53)
t+=0.2;
else if(t>=53 && t1<53)
t1+=0.2;
//S T O R E
else if(t2<53)
t2+=0.2;
else if(t2>=53 && t3<53)
t3+=0.2;
//L I S T
else if(t4<53)
t4+=0.2;
else if(t4>=53 && t5<53)
t5+=0.2;
glutPostRedisplay();
}
void animate()
{
//drawtext("(GENISYS BLOCK)",-8.3,8.0,0);
}

float angle =0.0;
float x_pos = -9.0;
int state =1;
int count=0;
bool isAnimating = true;
bool first  = true;
bool second = false;
bool third  = false;
bool block1 = true;
bool block2 = true;
bool block3 = true;
bool p      = false;
bool mine =false;


void *fonts[] = { GLUT_BITMAP_9_BY_15,
				  GLUT_BITMAP_TIMES_ROMAN_10,
				  GLUT_BITMAP_TIMES_ROMAN_24,
				  GLUT_BITMAP_HELVETICA_18,
                  GLUT_BITMAP_HELVETICA_12 };

void display();
void reshape(int , int );
void keyboard( unsigned char key, int x, int y );
void drawtext(const char text_from_main[],float x , float y,int);
void drawline(float x,float y,float x1,float y1);



void draw_block(float x, float y,float z)
{
    glOrtho(-5,5,-5,5,-5,5);
    //glNewList(upbox,GL_COMPILE_AND_EXECUTE);
    glBegin(GL_POLYGON);
        glColor3f(0.6,0.5,0.4);

        glVertex3f(x+2,y+2.0,z-5);
        glVertex3f(x+2,y-23.0,z-5);
        glVertex3f(x+12,y-23.0,z-5);                                // back
        glVertex3f(x+12,y+2.0,z-5);
    glEnd();
    glBegin(GL_POLYGON);
        glColor3f(0.4,0.5,0.3);

        glVertex3f(x,y-25.0,z);                                      // bootom
        glVertex3f(x+10,y-25.0,z);
        glVertex3f(x+12,y-23.0,z-5);
        glVertex3f(x+2,y-23.0,z-5);
    glEnd();
    glBegin(GL_POLYGON);
        glColor3f(0.4,0.5,0.3);

        glVertex3f(x+2,y+2.0,z-5);             //same top
        glVertex3f(x+2,y-23.0,z-5);           // background         //left
        glVertex3f(x,y-25.0,z);          // same front
        glVertex3f(x,y,z);            //same  front
    glEnd();
    glBegin(GL_POLYGON);
        glColor3f(0.7,0.8,0.6);      
        glVertex3f(x,y,z);                      //same front top left
        glVertex3f(x+10,y,z);                   // same front top right              // top
        glVertex3f(x+12,y+2.0,0.0);           // top left
        glVertex3f(x+2,y+2.0,z-5);          // same right side top left
    glEnd();
    glBegin(GL_POLYGON);
        glColor3f(0.7,0.7,0.6);

        glVertex3f(x+10,y,z);     //same left bottom front
        glVertex3f(x+10,y-25.0,z);   // same left bottom front // right side
        glVertex3f(x+12,y-23.0,z-5);   // bottom
        glVertex3f(x+12,y+2.0,z-5);     // top
    glEnd();

    glBegin(GL_POLYGON);
        glColor3f(0.3,0.5,0.4);

        glVertex3f(x,y-25.0,z); //bottom right  // front
        glVertex3f(x+10,y-25,z); // bottom left
        glVertex3f(x+10,y,z);   // top left
        glVertex3f(x,y,z);    // top right   // x y z
    glEnd();
    glLoadIdentity();

}
void draw_computer(float x,float y)
{
      glBegin(GL_POLYGON);
            glColor3f(0.7,0.65,0.83); //stand
            glVertex3f(x+0.7,y-2.4,-2);
            glVertex3f(x+0.7,y-3,-2);
            glVertex3f(x+1.4,y-3,-2);
            glVertex3f(x+1.4,y-2.4,-2);
       glEnd();
        glBegin(GL_POLYGON);
            glColor3f(0.2,0.3,.4); //stand
            glVertex2f(x+0.5,y-3.0);
            glVertex2f(x+1.6,y-3.0);
            glVertex2f(x+1.6,y-3.2);
            glVertex2f(x+0.5,y-3.2);
        glEnd();
        glBegin(GL_QUAD_STRIP);
            glColor3f(0.2,0.3,0.4);
            glVertex2f(x-0.2,y-2.6);
            glVertex2f(x+2.2,y-2.6);
            glVertex2f(x+2.2,y+0.1);
            glVertex2f(x-0.2,y+0.1);
            glVertex2f(x-0.2,y+0.1);
            glVertex2f(x-0.2,y-2.6);
            glVertex2f(x+2.2,y+0.1);
            glVertex2f(x+2.2,y-2.6);
        glEnd();
       glBegin(GL_POLYGON); //monitor
            glColor3f(0.6,0.73,0.83);
            glVertex2f(x ,     y-2.4);
            glVertex2f(x+2.0 , y-2.4);
            glVertex2f(x+2.0 ,  y   );
            glVertex2f(x ,      y   );      /////// xand y is passed
        glEnd();
        glBegin(GL_POLYGON);
            glColor3f(0.3,0.5,0.6);
            glVertex2f(x-0.2,y-4.2);
            glVertex2f(x+2.4,y-4.2); //keyboard
            glVertex2f(x+2.2,y-3.4);
            glVertex2f(x,y-3.4);
        glEnd();  
}


string sha256(const string str)
{
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, str.c_str(), str.size());
    SHA256_Final(hash, &sha256);
    stringstream ss;
    for(int i = 0; i < SHA256_DIGEST_LENGTH; i++)
    {
        ss << hex << setw(2) << setfill('0') << (int)hash[i];
    }
    return ss.str();
}

void keyboard( unsigned char key, int x, int y )
{
//   All keyboard inputs
    if ('m'==key)
    {
        mine = !mine;
    }
    if ('p'==key)
    {
        p=!p;
    }
    if ('c'==key)
    {
        count++;
        switch (count)
        {
        case 1:
            
            second = true;
            first = false;
            third = false;
            break;
        case 2:
            third = true;
            first =false;
            second = false;
        
        default:
            break;
        }
    }
    if ('b'==key)
    {
        count--;
        switch (count)
        {
        case 1:
            
            second = true;
            first = false;
            third = false;
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

        block3 = !block3;
    }
    
}
void draw_pkt_value(const char text_from_main[],float x , float y,int font)
{
    std::string text;
     //text = "-----------------------------------BLOCK CHAIN - THE TECHNOLOGY OF FUTURE----------------------------------------";
   // drawtext(text.data(),text.size(),-0.9,0.9);
   if(mine)
   {
   int nounce=0;
    while(nounce<100)
    {
        std::string text1 =sha256(text_from_main+nounce) ;
        const char *real_text1 = text1.data();
        if (real_text1[0]=='0')
        {
            text =sha256(text_from_main+nounce);
            break;
        }
        drawtext("Mining Successfull",-0.6,5.0,2);
        nounce++;
    }
    }
    if(!mine)
    text =sha256(text_from_main);
    //text = text_from_main;
    const char *real_text = text.data();
    int length = text.size();
    glRasterPos2f(x,y);
    for (int i = 0; i < length; i++)
    {
        glColor3f(0.5,0.0,0.1);
        glutBitmapCharacter(fonts[font],(int)real_text[i]);
    }
}

void drawtext(const char text_from_main[],float x , float y,int font)
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
        glColor3f(0.5,0.0,0.1);
        glutBitmapCharacter(fonts[font],(int)real_text[i]);
    }

}


void drawbox(float x_up,float y_left, float x_down , float y_right)
{
    
    glBegin(GL_POLYGON); 
        glColor3f(0.1,0.0,1.0);
        glVertex2f(x_up,y_left);
        glVertex2f(x_up,y_right);
        glVertex2f(x_down,y_right);
        glVertex2f(x_down,y_left);
        
    
    glEnd();
}
void drawline(float x,float y,float x1,float y1)
{

    glBegin(GL_LINES);
            glColor3f(0,0,0);
            glVertex2f(x,y);
            glVertex2f(x1,y1);
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
    glViewport(0,0,GLsizei(w),GLsizei(h));
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-10,10,-10,10,-10,10);
    //gluPerspective(60,1,2.0,50.0);
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
                    x_pos+=0.05;
                    
                }
                else
                    state = -1;
                break;
        
        case -1 :
                    if (x_pos>-8)
                    {
                        x_pos-=0.05;
                        
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
    
   
    angle+=0.8;
    if (angle > 360.0)
    {
        angle = angle - 360.0;
    }
    
    
}
void init()
{
    glClearColor(0.0,1.0,1.0,1.0);
    glEnable(GL_DEPTH_TEST);
}

void display()
{
    
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    if (first)
    {
            drawbox(-1.0,-4.0,3.0,4.0);
            //draw_block(-4.0,-1.0,5.0);
            //drawtext(" ",-9.0,-9.0,2);
            drawtext("BLOCK",0.5,6.0,2);
            drawtext("Index :",-0.6,3.0,2);
            drawtext("Transaction (data) :",-0.6,2.0,2);
            drawtext("Timestamp :",-0.6,1.0,2);
            drawtext("Previous hash :",-0.6,0.0,2);
            drawtext("POW (nounce) :",-0.6,-1.0,2);
            drawtext("----------------------------------------BLOCK CHAIN - THE NEXT BIG THING----------------------------------------",-9.0,9.0,3);
            
            
    }
    
    if (second)
    {
        if (block1)
        {
            //drawbox(-8.5,-3.0,-6.0,3.0);
            draw_block(-8.5*5,3.0*5,5.0);
            drawtext("BLOCK 1",-8.0,-4.0,3);
            glColor3f(0.0,0.0,1.0);
            drawtext("(GENISYS BLOCK)",-8.3,-4.5,0);
        }
        if (block2)
        {
            //drawbox(-1.0,-3.0,1.5,3.0);
            draw_block(-1.0*5,3.0*5,5.0);
            drawtext("BLOCK 2",-0.5,-4.0,3);
        }
        if (block3)
        {
            //drawbox(8.5,-3.0,6.0,3.0);
            draw_block(5.5*5,3.0*5,5.0);
            drawtext("BLOCK 3",7.0,-4.0,3);
        }

        /*drawbox_green(-1.0,-6.0,1.5,-9.0);
        drawtext("LEDGER",-0.5,-9.5,3);
        if (block1)
        drawline(-7.5,-3.0,-1.0,-6.0);
        if (block2)
        drawline(0.0,-3.0,0.0,-6.0);
        if (block3)
        drawline(7.5,-3.0,1.5,-6.0);*/
        
        drawpkt();
        glColor3f(0.5,0.0,0.1);
        if(block1)
        {   
            int index=1;
            const char* data="My name is root";
            float time_stamp=0.1;
            const char* pre_hash="";  //genysys block
            bool nounce=0;            // nounce
            if (!p)
            {
                if(!block3&&!block2)
                drawtext(data,-8.3,-2.0,2);
            }
            if (p&&!block3&&!block2)
            {
              draw_pkt_value(data,-8.0,-2.0,2);  
            }
            
        }
        
        if (!p)
        {
            drawtext("P1",x_pos+0.5,-1.0,4);
        }
        if(p)
        {
            draw_pkt_value("P+K",x_pos+0.5,-1.0,4);
        }
        drawtext("----------------------------------------BLOCK CHAIN - THE NEXT BIG THING----------------------------------------",-9.0,9.0,3);
        drawtext("Press 'm' for mining ",-9.0,-7.0,4);
    }
   if (third)
   {
       // draw_computer(-9.4,-5.0);
       // draw_computer(0,0);
       // draw_computer(-9,9);
        
    glLoadIdentity();
    glTranslatef(x_pos,x_pos,0.0);
    draw_computer(0.0,0.0);
    glLoadIdentity();
    glTranslatef(0.0,0.0,-35.0);
    
    draw_block(-45,40,5);
    glRotatef(90,1.0,0.0,0.0);
    draw_block(-25,40,5);
    glLoadIdentity();
    glColor3f(0.5,0,0.1);
    drawtext("D A T A",5,-1.2,2);
    drawtext("sample 3",0.0,0.0,2);
        
              




      /*  glBegin(GL_POLYGON);
            glColor3f(0.7,0.65,0.83); //stand
            glVertex3f(-43.50*0.2,26.0*0.2,-10.0*0.2);
            glVertex3f(-43.50*0.2,23.0*0.2,-10.0*0.2);
            glVertex3f(-40.0*0.2,23.0*0.2,-10.0*0.2);
            glVertex3f(-40.0*0.2,26.0*0.2,-10.0*0.2);
       glEnd();
        glBegin(GL_POLYGON);
            glColor3f(0.2,0.3,.4); //stand
            glVertex2f(-44.5*0.2,23.0*0.2);
            glVertex2f(-39.0*0.2,23.0*0.2);
            glVertex2f(-39.0*0.2,22.0*0.2);
            glVertex2f(-44.5*0.2,22.0*0.2);
        glEnd();
        glBegin(GL_QUAD_STRIP);
            glColor3f(0.2,0.3,0.4);
            glVertex2f(-48.0*0.2,25.0*0.2);
            glVertex2f(-36.0*0.2,25.0*0.2);
            glVertex2f(-36.0*0.2,38.5*0.2);
            glVertex2f(-48.0*0.2,38.5*0.2);
            glVertex2f(-48.0*0.2,38.5*0.2);
            glVertex2f(-48.0*0.2,25.0*0.2);
            glVertex2f(-36.0*0.2,38.5*0.2);
            glVertex2f(-36.0*0.2,25.0*0.2);
        glEnd();
       glBegin(GL_POLYGON); //monitor
            glColor3f(0.6,0.73,0.83);
            glVertex2f(-9.4,5.2);
            glVertex2f(-7.4,5.2);
            glVertex2f(-7.4,7.6);
            glVertex2f(-9.4,7.6);
        glEnd();
        glBegin(GL_POLYGON);
            glColor3f(0.3,0.5,0.6);
            glVertex2f(-48.0*0.2,17.0*0.2);
            glVertex2f(-35.0*0.2,17.0*0.2); //keyboard
            glVertex2f(-36.0*0.2,21.0*0.2);
            glVertex2f(-47.0*0.2,21.0*0.2);
        glEnd();*/
       
       
   } 
    //glFlush();
    drawtext("press   'b'   to go back",-9.0,-7.5,4);
        drawtext("----------------------------------------BLOCK CHAIN - THE NEXT BIG THING----------------------------------------",-9.0,9.0,3);
        drawtext("press   'c'   to continue to next page",-9.0,-8.0,4);
        drawtext("press   'p'   to  know packet info",-9.0,-8.5,4);
    glutSwapBuffers(); // Required to copy color buffer onto the screen.
   
    
}

//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

int main(int argc,char **argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowPosition(100,1000);
    glutInitWindowSize(1500,1000);
    glutCreateWindow("window");

    glutDisplayFunc(display);
glutCreateMenu(mymenu);
glutAddMenuEntry("START",1);
glutAddMenuEntry("START 1:RETRIVE",2);
glutAddMenuEntry("START 2:STORE",3);
glutAddMenuEntry("START 3:LIST",4);
glutAddMenuEntry("EXIT",5);
glutAttachMenu(GLUT_RIGHT_BUTTON);
glBlendFunc(GL_SRC_ALPHA,GL_DST_ALPHA);

    glutReshapeFunc(reshape);
    //glutTimerFunc(0,timer1,0);
    glutKeyboardFunc(keyboard) ;
    glutTimerFunc(0,timer,0);
    init();
    glutMainLoop();

}