#include <GL/gl.h>
#include <GL/glut.h>
#include <stdio.h>
int r, centerX, centerY;
void display(void)
{
/* clear all pixels */
glClear (GL_COLOR_BUFFER_BIT);
/* draw white polygon (rectangle) with corners at
* (0.25, 0.25, 0.0) and (0.75, 0.75, 0.0)
*/
//circle
int x, y, p, r;
r=450;
x=0;
y=r;
p=1-r;
centerX=0;
centerY=900;
while(x<y){
glColor3ub (255, 0, 0);
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
//lower line
glColor3ub (255, 255, 255);
glBegin(GL_POLYGON);
glVertex2d (-1400, 20);
glVertex2d (-1400, 40);
glVertex2d (1400, 40);
glVertex2d (1400, 20);
glEnd();

//left most pillars
//white
glColor3ub (255, 255, 255);
glBegin(GL_POLYGON);
glVertex2d (-1200, 40);
glVertex2d (-900, 40);
glVertex2d (-900, 700);
glVertex2d (-1200, 700);
glEnd();

//black
glColor3ub (0, 0, 0);
glBegin(GL_POLYGON);
glVertex2d (-1150, 40);
glVertex2d (-950, 40);
glVertex2d (-950, 650);
glVertex2d (-1150, 650);
glEnd();

//white
glColor3ub (255, 255, 255);
glBegin(GL_POLYGON);
glVertex2d (-800, 40);
glVertex2d (-500, 40);
glVertex2d (-500, 900);
glVertex2d (-800, 900);
glEnd();


//black
glColor3ub (0, 0, 0);
glBegin(GL_POLYGON);
glVertex2d (-750, 40);
glVertex2d (-550, 40);
glVertex2d (-550, 850);
glVertex2d (-750, 850);
glEnd();

//Right Most Pillars
//white
glColor3ub (255, 255, 255);
glBegin(GL_POLYGON);
glVertex2d (1200, 40);
glVertex2d (900, 40);
glVertex2d (900, 700);
glVertex2d (1200, 700);
glEnd();

//black
glColor3ub (0, 0, 0);
glBegin(GL_POLYGON);
glVertex2d (1150, 40);
glVertex2d (950, 40);
glVertex2d (950, 650);
glVertex2d (1150, 650);
glEnd();

//white
glColor3ub (255, 255, 255);
glBegin(GL_POLYGON);
glVertex2d (800, 40);
glVertex2d (500, 40);
glVertex2d (500, 900);
glVertex2d (800, 900);
glEnd();

//black
glColor3ub (0, 0, 0);
glBegin(GL_POLYGON);
glVertex2d (750, 40);
glVertex2d (550, 40);
glVertex2d (550, 850);
glVertex2d (750, 850);
glEnd();

//middle pillar
//left lower polygon
glColor3ub (255, 255, 255);
glBegin(GL_POLYGON);
glVertex2d (-400, 40);
glVertex2d (-350, 40);
glVertex2d (-350, 1000);
glVertex2d (-400, 1000);
glEnd();

//left upper polygon
glColor3ub (255, 255, 255);
glBegin(GL_POLYGON);
glVertex2d (-350, 1000);
glVertex2d (-400, 1000);
glVertex2d (-550, 1500);
glVertex2d (-500, 1500);
glEnd();

//right lower polygon
glColor3ub (255, 255, 255);
glBegin(GL_POLYGON);
glVertex2d (400, 40);
glVertex2d (350, 40);
glVertex2d (350, 1000);
glVertex2d (400, 1000);
glEnd();

//right upper polygon
glColor3ub (255, 255, 255);
glBegin(GL_POLYGON);
glVertex2d (350, 1000);
glVertex2d (400, 1000);
glVertex2d (550, 1500);
glVertex2d (500, 1500);
glEnd();

//mid line polygon
glColor3ub (255, 255, 255);
glBegin(GL_POLYGON);
glVertex2d (-25, 40);
glVertex2d (25, 40);
glVertex2d (25, 1500);
glVertex2d (-25, 1500);
glEnd();

//mid upper horizontal polygon
glColor3ub (255, 255, 255);
glBegin(GL_POLYGON);
glVertex2d (-550, 1500);
glVertex2d (550, 1500);
glVertex2d (550, 1550);
glVertex2d (-550, 1550);
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
gluOrtho2D(-1400, 1400, 0, 2000);
}
/*
* Declare initial window size, position, and display mode
* (single buffer and RGBA). Open window with "191-15-12179"
* in its title bar. Call initialization routines.
* Register callback function to display graphics.
* Enter main loop and process events.
*/
int main(int argc, char** argv)
{
 glutInit(&argc, argv);
 glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
 glutInitWindowSize (700, 500);
 glutInitWindowPosition (100, 100);
 glutCreateWindow ("191-15-12179");
 init ();
 glutDisplayFunc(display);
 glutMainLoop();
 return 0; /* ISO C requires main to return int. */
}
