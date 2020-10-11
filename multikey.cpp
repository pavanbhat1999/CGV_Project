#include <GL/freeglut.h>
#include <sstream>
#include <string>
#include <vector>

using namespace std;
ostringstream oss;

string array;
vector< string > names( 1 );
void keyboard( unsigned char key, int x, int y )
{
    if( key == 13 )
    {
        // enter key
        string array=names[0].data();
        names.push_back(" ");
    }
    else if( key == 8 )
    {
        // backspace
        names.back().pop_back();
    }
    else
    {
        // regular text
        names.back().push_back( key );
    }
    
    if (key== 27)  // esc key
    exit(0);

    glutPostRedisplay();
}

void display()
{
    glClear( GL_COLOR_BUFFER_BIT );

    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    double w = glutGet( GLUT_WINDOW_WIDTH );
    double h = glutGet( GLUT_WINDOW_HEIGHT );
    glOrtho( 0, w, 0, h, -1, 1 );

    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity();
    


    for( size_t i = 0; i < names.size(); ++i )
    {
        
        
        ostringstream oss;
        oss << "Enter the transaction"<< i << ": " << names[i]<<array;

        void* font = GLUT_BITMAP_TIMES_ROMAN_24;
        const int fontHeight = glutBitmapHeight( font );
        glRasterPos2i( 10, h - ( fontHeight * ( i + 1 ) ) );
        glutBitmapString( font, (const unsigned char*)( oss.str().c_str() ) );
    }

    glutSwapBuffers();
}

int main( int argc, char **argv )
{
    glutInit( &argc, argv );
    glutInitDisplayMode( GLUT_RGBA | GLUT_DOUBLE );
    glutInitWindowSize( 640, 480 );
    glutCreateWindow( "GLUT" );
    glutDisplayFunc( display );
    glutKeyboardFunc( keyboard );
    glutMainLoop();
    return 0;
}