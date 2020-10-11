#include<stdio.h>
#include<GL/glut.h>
#include<string.h>
#include<time.h>
#include<math.h>
#define PI 3.142
float yll=36,ylu=130,yln=80,yrh=320,ye=328,yre=325,yrf=348,yrnc=295,rlh=492,rrh=708,rla=495,rra=705,wty=45;
float sx=1,sy=1,sz=1,fsx=1,fsy=1,fsz=1,tx=0,ty=0,tz=0;
int tpos=640,ftx=0,fty=0,ftz=0,rxa=0,rya=0,flag=0,vflag=0,fflag=0,vtx=520,allover=0,i=0;

void tree()
{
    //Trunk
    glColor3f(0.325,0.208,0.039);
    glScalef(1.5,0.3,0.3);
    glTranslatef(0,-10,0);
    glutSolidSphere(10,18,20);
    glTranslatef(0,10,0);
    glScalef(1/1.5,1/0.3,1/0.3);
    glutSolidCube(12);

    //Tree
    glColor3f(0,1,0);
    for(int c=-5;c<=20;c+=5)
    {
        glTranslatef(c,25,0);
        glScalef(1,0.8,1);
        glutSolidSphere(20,20,20);
        glScalef(1,1/0.8,1);
        glTranslatef(-c,-25,0);
    }
}

void clouds()
{
    //Clouds
  
    glColor3f(0.8,0.8,1);
    glTranslatef(0,0,0);
    glScalef(1.6,1,1);
    glutSolidSphere(30,25,25);
    glScalef(1/1.6,1,1);
    glTranslatef(0,0,0);

    glTranslatef(0,0,40);
    glScalef(1.6,1,1);
    glutSolidSphere(30,25,25);
    glScalef(1/1.6,1,1);
    glTranslatef(0,0,-40);

    glTranslatef(0,0,-40);
    glScalef(1.6,1,1);
    glutSolidSphere(30,25,25);
    glScalef(1/1.6,1,1);
    glTranslatef(0,0,40);

    glTranslatef(40,0,0);
    glScalef(1.6,1,1);
    glutSolidSphere(30,25,25);
    glScalef(1/1.6,1,1);
    glTranslatef(-40,0,0);

 glTranslatef(20,0,0);
    glScalef(1.6,1,1);
    glutSolidSphere(30,25,25);
    glScalef(1/1.6,1,1);
    glTranslatef(-20,0,0);



    glTranslatef(-30,0,0);  
     glScalef(1.6,1,1);
    glutSolidSphere(30,25,25);
    glScalef(1/1.6,1,1);
    glTranslatef(30,0,0);
        glTranslatef(-30,0,0);
    glScalef(1.6,1,1);
    glutSolidSphere(30,25,25);
    glScalef(1/1.6,1,1);
    glTranslatef(30,0,0);

      }
   
   /*void drawHollowCircle(GLfloat x, GLfloat y, GLfloat radius){
	int i;
	int lineAmount = 100; //# of triangles used to draw circle
	
	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi = 2.0f * PI;
	
	glBegin(GL_LINE_LOOP);
		for(i = 0; i <= lineAmount;i++) { 
			glVertex2f(
			    x + (radius * cos(i *  twicePi / lineAmount)), 
			    y + (radius* sin(i * twicePi / lineAmount))
			);
		}
	glEnd();
       drawHollowCircle(x,y,radius);
}*/
void circle1(GLfloat x, GLfloat y, GLfloat radius) 
  { 
    float angle;   
    glBegin(GL_POLYGON); 
    for(int i=0;i<100;i++) 
	{ 
        angle = i*2*(M_PI/100); 
        glVertex2f(x+(cos(angle)*radius),y+(sin(angle)*radius)); 
    } 
    glEnd(); 
  }  


void background()
{
    //Floor
    glBegin(GL_QUADS);
    glColor3f(0.6,0.4,0.2);
    glVertex3i(-2400,0,0);
    glVertex3i(3600,0,0);
    glVertex3i(3600,0,500);
    glVertex3i(-2400,0,500);

    glColor3f(0.4,0.4,0.4);
    glVertex3i(-1200,120,0);
    glVertex3i(2480,120,0);
    glVertex3i(2480,160,0);
    glVertex3i(-1200,160,0);

    //Sky
    glColor3f(0.4,0.6,0.8);
    glVertex3i(-2400,0,500);
    glVertex3i(3600,0,500);
    glVertex3i(3600,1200,500);
    glVertex3i(-2400,1200,500);

    glEnd();

    for(int c=-400;c<=1500;c+=300)
    {
        //Trees on Right Side
        glTranslatef(c,170,0);
        tree();
        glTranslatef(-c,-170,0);
    }

    glTranslatef(200,560,300);
    clouds();
    glTranslatef(-200,-560,-300);
     glTranslatef(-350,560,300);
    clouds();
    glTranslatef(350,-560,-300);


    glTranslatef(0,560,10);
    clouds();
    glTranslatef(0,-560,-10);

    glTranslatef(1200,560,50);
    clouds();
    glTranslatef(-1200,-560,-50);

    glTranslatef(600,560,400);
    clouds();
    glTranslatef(-600,-560,-400);

    glTranslatef(550,560,50);
    clouds();
    glTranslatef(-550,-560,-50);

    glTranslatef(-1000,560,500);
    clouds();
    glTranslatef(1000,-560,-500);
     
   glTranslatef(1200,560,800);
    clouds();
    glTranslatef(-1200,-560,-800);



    glTranslatef(4000,560,1200);
    clouds();
    glTranslatef(-4000,-560,-1200);

    glTranslatef(3750,560,1200);
    clouds();
    glTranslatef(-3750,-560,-1200);

    glTranslatef(1100,480,300);
    clouds();
    glTranslatef(-1100,-480,-300);

    glTranslatef(-2800,560,800);
    clouds();
    glTranslatef(2800,-560,-800);
     
    glTranslatef(-3000,560,800);
    clouds();
    glTranslatef(3000,-560,-800);

     glTranslatef(2800,560,800);
    clouds();
    glTranslatef(-2800,-560,-800);
      glTranslatef(-2900,560,800);
    clouds();
    glTranslatef(2900,-560,-800);


     
}

void robot()
{
    glRotatef(rxa,1,0,0);
    glTranslatef(tx,ty,tz);
    glScalef(sx,sy,sz);

    //Robot Head
    glColor3f(0.7,0.7,0.7);
    glTranslatef(600,yrh,200);
    glScalef(1.8,1,0.2);
    glutSolidSphere(25,50,50);
    glScalef(1/1.8,1,1/0.2);
    glTranslatef(-600,-yrh,-200);

    //Left Ear
    glColor3f(0.2,0.2,0.7);
    glTranslatef(564,ye,200);
    glScalef(0.15,1,0.2);
    glutSolidCube(50);
    glScalef(1/0.15,1,1/0.2);
    glTranslatef(-564,-ye,-200);

    //Right Ear
    //glColor3f(0,0,1);
    glTranslatef(636,ye,200);
    glScalef(0.15,1,0.2);
    glutSolidCube(50);
    glScalef(1/0.15,1,1/0.2);
    glTranslatef(-636,-ye,-200);

    //Robot Eye
    //glColor3f(0,0,1);
    glTranslatef(600,yre,200);
    glScalef(1,0.10,0.15);
    glutSolidCube(72);
    glScalef(1,1/0.10,1/0.15);
    glTranslatef(-600,-yre,-200);

    //Robot Forehead
    //glColor3f(0,0,1);
    glTranslatef(600,yrf,200);
    glScalef(1.7,1,0.1);
    glutSolidCube(15);
    glScalef(1/1.7,1,1/0.1);
    glTranslatef(-600,-yrf,-200);

    //Robot Neck
    glColor3f(0.7,0.7,0.7);
    glTranslatef(600,yrnc,200);
    glScalef(3.5,1,0.1);
    glutSolidCube(15);
    glScalef(1/3.5,1,1/0.1);
    glTranslatef(-600,-yrnc,-200);

    //Robot Left Arm
    glColor3f(0.2,0.2,0.2);
    glTranslatef(rla,280,200);
    glScalef(1.2,0.4,0.2);
    glutSolidSphere(25,50,50);
    glScalef(1/1.2,1/0.4,1/0.2);
    glTranslatef(-rla,-280,-200);

    //Robot Right Arm
    glColor3f(0.2,0.2,0.2);
    glTranslatef(rra,280,200);
    glScalef(1.2,0.4,0.2);
    glutSolidSphere(25,50,50);
    glScalef(1/1.2,1/0.4,1/0.2);
    glTranslatef(-rra,-280,-200);

    //Robot Left Knee
    glColor3f(0.2,0.2,0.2);
    glTranslatef(545,yln,200);
    glScalef(1.3,0.5,0.2);
    glutSolidSphere(25,50,50);
    glScalef(1/1.3,1/0.5,1/0.2);
    glTranslatef(-545,-yln,-200);
    
   
    //Robot Right Knee
    glColor3f(0.2,0.2,0.2);
    glTranslatef(650,yln,200);
    glScalef(1.3,0.5,0.2);
    glutSolidSphere(25,50,50);
    glScalef(1/1.3,1/0.5,1/0.2);
    glTranslatef(-650,-yln,-200);

    glColor3f(1,0.639,0.102);
    glTranslatef(600,155,200);
    glScalef(1,0.45,0.2);
    glutSolidSphere(60,5,5);
    glScalef(1,1/0.45,1/0.2);
    glTranslatef(-600,-155,-200);

    //Robot Body
    glColor3f(0.2,0.2,0.7);
    glTranslatef(600,228,200);
    glScalef(1.3,1,0.6);
    glutSolidCube(120);
    glScalef(1/1.3,1,1/0.6);
    glTranslatef(-600,-228,-200);

    //Robot Left Leg Part 1
    //glColor3f(0,0,0.9);
    glTranslatef(550,ylu,200);
    glScalef(0.8,1.2,0.2);
    glutSolidCube(60);
    glScalef(1/0.8,1/1.2,1/0.2);
    glTranslatef(-550,-ylu,-200);

    //Robot Right Leg Part 1
    //glColor3f(0,0,0.9);
    glTranslatef(650,ylu,200);
    glScalef(0.8,1.2,0.2);
    glutSolidCube(60);
    glScalef(1/0.8,1/1.2,1/0.2);
    glTranslatef(-650,-ylu,-200);

    //Robot Left Leg Part 2
    //glColor3f(0,0,0.9);
    glTranslatef(550,yll,200);
    glScalef(1,1.2,0.2);
    glutSolidCube(60);
    glScalef(1,1/1.2,1/0.2);
    glTranslatef(-550,-yll,-200);
    
     //sach modifies
    /* glTranslatef(600,yll,200);
    glScalef(1,1.2,0.2);
    glutSolidCube(60);
    glScalef(1,1/1.2,1/0.2);
    glTranslatef(-600,-yll,-200);
    */   
      glColor3f(0.2,0.2,0.2);
    glTranslatef(598,yln,200);
    glScalef(1.3,0.5,0.2);
    glutSolidSphere(25,50,50);
    glScalef(1/1.3,1/0.5,1/0.2);
    glTranslatef(-598,-yln,-200);
    

    //Robot Right Leg Part 2
    //glColor3f(0,0,0.9);
    glTranslatef(650,yll,200);
    glScalef(1,1.2,0.2);
    glutSolidCube(60);
    glScalef(1,1/1.2,1/0.2);
    glTranslatef(-650,-yll,-200);

    //Robot Left Hand
    //glColor3f(0,0,0.9);
    glTranslatef(rlh,220,200);
    glScalef(0.8,1.8,0.2);
    glutSolidCube(60);
    glScalef(1/0.8,1/1.8,1/0.2);
    glTranslatef(-rlh,-220,-200);

    //Robot Right Hand
    //glColor3f(0,0,0.9);
    glTranslatef(rrh,220,200);
    glScalef(0.8,1.8,0.2);
    glutSolidCube(60);
    glScalef(1/0.8,1/1.8,1/0.2);
    glTranslatef(-rrh,-220,-200);

    glScalef(1/sx,1/sy,1/sz);
    glTranslatef(-tx,-ty,-tz);
    glRotatef(-rxa,1,0,0);
}

void trans()
{
    if (yll<130)
    {
        yll+=1;
        ylu+=1;
        yln+=1;
    }
    else if(yrh>240)
    {
        yrh-=1;
        yre-=1;
        yrf-=1;
        ye-=1;
        yrnc-=1;
    }
    else if(yll<220)
    {
        yll+=1;
    }
    else if(rlh<=560)
    {
        rlh+=1;
        rrh-=1;
        rla+=0.9;
        rra-=0.9;
    }
    else if(rxa<=90)
    {
        rxa+=1;
        tz-=2;
        ty+=1.2;
    }
    else
    {
        flag=1;
        rxa=0;
        sx=1.3;
        sy=0.5;
        sz=1;
    }
}

void vehicle()
{
    glTranslatef(ftx,fty,ftz);
    glScalef(fsx,fsy,fsz);

    if(vflag==1)
    {

        //Vehicle Hood
        glColor3f(1,0.639,0.102);
        glBegin(GL_QUADS);
        glVertex3i(vtx,35,200);
        glVertex3i(vtx+60,35,200);
        glVertex3i(vtx+60,90,200);
        glVertex3i(vtx,58,200);
        glEnd();

        //Front Wheel
        glColor3f(0.2,0.2,0.2);
        glTranslatef(540,wty,200);
        glScalef(1.7,1,0.2);
        glutSolidSphere(12.5,50,50);
        glScalef(1/1.7,1,1/0.2);
        glTranslatef(-540,-wty,-200);

        //Rear Wheel
        glColor3f(0.2,0.2,0.2);
        glTranslatef(655,wty,200);
        glScalef(1.7,1,0.2);
        glutSolidSphere(12.5,50,50);
        glScalef(1/1.7,1,1/0.2);
        glTranslatef(-655,-wty,-200);
    }

    glColor3f(0.2,0.2,0.7);
    glTranslatef(600,60,200);
    glScalef(sx,sy,sz);
        glRotatef(rya,0,1,0);
    glutSolidCube(120);
        glRotatef(-rya,0,1,0);
    glScalef(1/sx,1/sy,1/sz);
    glTranslatef(-600,-60,-200);


    glScalef(1/fsx,1/fsy,1/fsz);
    glTranslatef(-ftx,-fty,-ftz);
}

void calc()
{
    if(rya<=90)
    {
        rya+=1;
        sx+=0.002;
        sz-=0.01;
    }
    else if(fsx<=2.5)
    {
        fsx+=0.05;
        fsy+=0.05;
        fsz+=0.05;
        ftx-=20;
        fty-=10;
    }
    else
    {
        vflag=1;
    }
    if(vflag==1&&vtx>=465)
    {
        vtx-=1;
    }
    else if(vtx<465&&wty>=30)
    {
        wty-=0.5;
    }
    else if(wty<30)
    {
        allover=1;
    }
    if(allover==1)
    {
        if(i<=540)
        {
            ftx-=5;
            i++;
        }
        else if(i>540)
            fflag=1;
    }
}

void display()
{
    char pr[20]="OpenGL Project:";
    char name[20]="By Sachin Somanna";
    char title[15]="TRANSFORMERS";
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

    background();

    if(tpos>550)
    {
        tpos-=0.5;
    }
    glColor3f(0,0,0.502);
    glRasterPos2f(1000,tpos);
    for(int j=0;j<strlen(pr);j++)
    {
       glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, pr[j]);
    }
        glRasterPos2f(1150,tpos-24);
    for(int j=0;j<strlen(name);j++)
    {
       glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, name[j]);
    }
    glRasterPos2f(460,tpos-50);
    for(int j=0;j<strlen(title);j++)
    {
       glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, title[j]);
    }

    if(flag==0)
    {
        trans();
        robot();
    }
    else if(flag==1)
    {
        calc();
        vehicle();
    }

    //Draw Trees alongside the road
    for(int c=-400;c<=1500;c+=300)
    {
        //Trees on Left Side
        glTranslatef(c,110,0);
        tree();
        glTranslatef(-c,-110,0);
    }
    glFlush();
    glutSwapBuffers();
}

void changeSize(int w, int h)
{
	if(h == 0)
		h = 1;
	float ratio = 1.0* w / h;

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(0, 0, w, h);
	gluPerspective(78,ratio,1,500);
	glMatrixMode(GL_MODELVIEW);
}

void Timer(int value)
{
    if(fflag==0)
    {
        glutTimerFunc(20,Timer,0);
        glutPostRedisplay();
    }

}

void myinit()
{
    glClearColor(1.0,1.0,1.0,1.0);
    glOrtho(0,1200,0,640,0,500);

    glutTimerFunc(2000,Timer,0);
}

int main(int argc,char **argv)
{
   clock_t start, end;
     double cpu_time_used;

     start = clock();
      //robot();
      trans();
     end = clock();
     cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
     printf("%lf TIME IS TAKEN",cpu_time_used);
     
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB|GLUT_DEPTH);
    glutInitWindowPosition(0,0);
    glutInitWindowSize(1400,940);

    glutCreateWindow("OpenGL Project: Transformers");
    glutReshapeFunc(changeSize);
    glutDisplayFunc(display);

    myinit();
    trans();
    glutMainLoop();
}


