#include <GL/gl.h>
#include <GL/glut.h>
void display(void)
{
/* clear all pixels */
glClear (GL_COLOR_BUFFER_BIT);
/* draw white polygon (rectangle) with corners at
* (0.25, 0.25, 0.0) and (0.75, 0.75, 0.0)
*/
glColor3ub (255, 18, 100);
glBegin(GL_LINES);
glVertex2d (-500, 0);
glVertex2d (500, 0);
glEnd();

glColor3ub (200, 255, 12);
glBegin(GL_LINES);
glVertex2d (0, 500);
glVertex2d (0, -500);
glEnd();
//upper
glColor3ub (200, 255, 12);
glBegin(GL_POLYGON);
glVertex2d (20, 40);
glVertex2d (60, 60);
glVertex2d (20, 80);
glVertex2d (0, 120);
glVertex2d (-20, 80);
glVertex2d (-60, 60);
glVertex2d (-20, 40);
glVertex2d (0, 0);
glEnd();

//lower
glColor3ub (200, 255, 12);
glBegin(GL_POLYGON);
glVertex2d (20, -40);
glVertex2d (60, -60);
glVertex2d (20, -80);
glVertex2d (0, -120);
glVertex2d (-20, -80);
glVertex2d (-60, -60);
glVertex2d (-20, -40);
glVertex2d (0, 0);
glEnd();

//right
glColor3ub (255, 18, 100);
glBegin(GL_POLYGON);
glVertex2d (40, 20);
glVertex2d (60, 60);
glVertex2d (80, 20);
glVertex2d (120, 0);
glVertex2d (80, -20);
glVertex2d (60, -60);
glVertex2d (40, -20);
glVertex2d (0, 0);
glEnd();

//left
glColor3ub (255, 18, 100);
glBegin(GL_POLYGON);
glVertex2d (-40, 20);
glVertex2d (-60, 60);
glVertex2d (-80, 20);
glVertex2d (-120, 0);
glVertex2d (-80, -20);
glVertex2d (-60, -60);
glVertex2d (-40, -20);
glVertex2d (0, 0);
glEnd();

/* don't wait!
* start processing buffered OpenGL routines
*/
glFlush ();
}
void init (void)
{
/* select clearing (background) color */
glClearColor (0.0, 0.0, 0.0, 0.0);
/* initialize viewing values */
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
//glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
gluOrtho2D(-500, 500, -500, 500);
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
