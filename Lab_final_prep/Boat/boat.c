#include <GL/gl.h>
#include <GL/glut.h>
float x=0;
int y=0;
void display(void)
{
/* clear all pixels */
glClear (GL_COLOR_BUFFER_BIT);
/* draw white polygon (rectangle) with corners at
* (0.25, 0.25, 0.0) and (0.75, 0.75, 0.0)
*/

//water
glColor3ub (10, 150, 200);
glBegin(GL_POLYGON);
glVertex2d (-500,0);
glVertex2d (500,0);
glVertex2d (500,-300);
glVertex2d (-500,-300);
glEnd();

//boat
glColor3ub (128, 90, 70);
glBegin(GL_POLYGON);
glVertex2d (-490+x,40+y);
glVertex2d (-260+x,40+y);
glVertex2d (-320+x,-60+y);
glVertex2d (-440+x,-60+y);
glEnd();

glColor3ub (255, 150, 19);
glBegin(GL_POLYGON);
glVertex2d (-450+x,40+y);
glVertex2d (-310+x,40+y);
glVertex2d (-310+x,100+y);
glVertex2d (-380+x,120+y);
glVertex2d (-450+x,100+y);
glEnd();

if(x<500){
    x+=0.02;
}
else{
    x=0;
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
gluOrtho2D(-500, 500, -300, 500);
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
glutInitWindowSize (1000, 500);
glutInitWindowPosition (100, 100);
glutCreateWindow ("191-15-12179");
init ();
glutDisplayFunc(display);
glutMainLoop();
return 0; /* ISO C requires main to return int. */
}
