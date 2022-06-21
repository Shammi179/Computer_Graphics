#include <GL/gl.h>
#include <GL/glut.h>
#include<stdio.h>

int r, centerX, centerY;
void display(void)
{
/* clear all pixels */
glClear (GL_COLOR_BUFFER_BIT);
/* draw white polygon (rectangle) with corners at
* (0.25, 0.25, 0.0) and (0.75, 0.75, 0.0)
*/
glColor3ub (0, 106, 78);
glBegin(GL_POLYGON);
glVertex2d (-500,0 );
glVertex2d (500,0 );
glVertex2d (500,500 );
glVertex2d (-500,500 );
glEnd();

glColor3ub (139, 0, 0);
glBegin(GL_POLYGON);
glVertex2d (-500,-500 );
glVertex2d (-540,-500 );
glVertex2d (-540,520 );
glVertex2d (-500,520 );
glEnd();

int x, y, p, r;
r=200;
x=0;
y=r;
p=1-r;
centerX=0;
centerY=250;
while(x<y){
glColor3ub (244, 42, 65);
glBegin(GL_POLYGON);
glVertex2d (x+centerX, -y+centerY);
glVertex2d (-x+centerX, y+centerY);
glVertex2d (-x+centerX, -y+centerY);
glVertex2d (y+centerX, x+centerY);
glVertex2d (y+centerX, -x+centerY);
glVertex2d (-y+centerX, x+centerY);
glVertex2d (-y+centerX, -x+centerY);
glVertex2d (x+centerX, y+centerY);
glEnd();
if(p<0){
 x=x+1;
 p=p+(2*x)+1;
}
else{
 x=x+1;
 y=y-1;
 p= p+(2*x)+1-(2*y);
}
}
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
gluOrtho2D(-1000, 1000, -1000, 1000);
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

