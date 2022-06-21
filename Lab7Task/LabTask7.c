#include <GL/gl.h>
#include <GL/glut.h>
#include <stdio.h>
float y=300;
void display(void)
{
/* clear all pixels */
glClear (GL_COLOR_BUFFER_BIT);
/* draw white polygon (rectangle) with corners at
* (0.25, 0.25, 0.0) and (0.75, 0.75, 0.0)
*/

glColor3ub (200, 45, 12);
glBegin(GL_POLYGON);
glVertex2d (-30, y);
glVertex2d (30, y);
glVertex2d (30, y-30);
glVertex2d (-30, y-30);
glEnd();
if(y>-300){
    y-=0.05;
}
else{
    y=300;
}

/* don't wait!
* start processing buffered OpenGL routines
*/
glFlush ();
glutPostRedisplay();
}
void init (void)
{
/* select clearing (background) color */
glClearColor (1.0, 1.0, 1.0, 1.0);
/* initialize viewing values */
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
//glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
gluOrtho2D(-300, 300, -300, 300);
}
/*
* Declare initial window size, position, and display mode
* (single buffer and RGBA). Open window with "hello"
* in its title bar. Call initialization routines.
* Register callback function to display graphics.
* Enter main loop and process events.
*/
int main(int argc, char** argv)
{
 glutInit(&argc, argv);
 glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
 glutInitWindowSize (500, 500);
 glutInitWindowPosition (100, 100);
 glutCreateWindow ("191-15-12179");
 init ();
 glutDisplayFunc(display);
 glutMainLoop();
 return 0; /* ISO C requires main to return int. */
}


