void drawtext(const char text2[],float x , float y)
{
    std::string text;
     //text = "-----------------------------------BLOCK CHAIN - THE TECHNOLOGY OF FUTURE----------------------------------------";
   // drawtext(text.data(),text.size(),-0.9,0.9); 
    text = text2;
    const char *text1 = text.data();
    int length = text.size();
    glRasterPos2f(-0.9,0.2);
    for (int i = 0; i < length; i++)
    {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,(int)text1[i]);
    }

}



/* void drawtext (const char *text , int length,float x , float y)
{
    glMatrixMode(GL_PROJECTION);
    double *matrix = new double[16];
    glGetDoublev(GL_PROJECTION_MATRIX,matrix);
    glLoadIdentity();
    glOrtho(0,800,0,600,-5,-5);
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glLoadIdentity();
    glRasterPos2f(x,y);
    glScalef(0.005,0.005,1);
    glutStrokeCharacter(GLUT_STROKE_ROMAN,(int)text[1]);
    for (int i = 0; i < length; i++)
    {
        
        glutStrokeCharacter(GLUT_STROKE_ROMAN,(int)text[i]);
    }
    glPopMatrix();
    glMatrixMode(GL_PROJECTION);
    glLoadMatrixd(matrix);

    
}  */


/* delete after  drawbox glBegin(GL_POLYGON); 
        glColor3f(0,0,1);
        glVertex2f(-8.5,-3.0);
        glVertex2f(-8.5,3.0);
        glVertex2f(-6.0,3.0);
        glVertex2f(-6.0,-3.0);
        
    
    glEnd();*/



   /*  delete after packet glBegin(GL_POLYGON);
        glColor3f( 1, 0, 0 );glVertex2f(x_pos,0.5);
        glColor3f( 1, 0, 0 );glVertex2f(x_pos,-0.5);
        glColor3f( 1, 0, 0 );glVertex2f(x_pos+0.5,-0.5);
        glColor3f( 1, 0, 0 );glVertex2f(x_pos+0.5,0.5);
        
     
    glEnd(); */

    R G B result
1.0 0.0 0.0 red, duh
0.0 1.0 0.0 green, duh
0.0 0.0 1.0 blue, duh
1.0 1.0 0.0 yellow
1.0 0.0 1.0 purple
0.0 1.0 1.0 cyan
1.0 1.0 1.0 white

1.0 0.5 0.0 orange
0.5 1.0 0.0 greenish yellow
…
0.5 1.0 0.5 light green
0.0 0.5 0.0 dark green
…