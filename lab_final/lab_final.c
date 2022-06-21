#include <GL/gl.h>
#include <GL/glut.h>
#include <stdio.h>

void display(void)
{
/* clear all pixels */
glClear (GL_COLOR_BUFFER_BIT);
/* draw white polygon (rectangle) with corners at
* (0.25, 0.25, 0.0) and (0.75, 0.75, 0.0)
*/
glColor3f (1, 1, 1);

glBegin(GL_POLYGON);
glVertex2d(10, 100);
glVertex2d(310, 100);
glVertex2d(310, 200);
glVertex2d(10, 200);

glEnd();
glBegin(GL_POLYGON);
glVertex2d(110, 10);
glVertex2d(210, 10);
glVertex2d(210, 310);
glVertex2d(110, 310);
glEnd();

glColor3f (1, 0, 0);
glBegin(GL_POLYGON);
glVertex2d(310, 10);
glVertex2d(450, 10);
glVertex2d(310, 150);
glEnd();

glColor3f (0, 1, 0);
glBegin(GL_POLYGON);
glVertex2d(500, 150);
glVertex2d(450, 10);
glVertex2d(550, 10);
glVertex2d(600, 150);
glVertex2d(550, 290);
glVertex2d(450, 290);
glEnd();

glColor3f (0, 0, 1);
glBegin(GL_POLYGON);
glVertex2d(600, 150);
glVertex2d(740, 150);
glVertex2d(600, 300);
glEnd();

glFlush ();
}
void init (void)
{
/* select clearing (background) color */
glClearColor (0.0, 0.0, 0.0, 0.0);
/* initialize viewing values */
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(0,1000,0,500);
}

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


