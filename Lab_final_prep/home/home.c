#include <GL/gl.h>
#include <GL/glut.h>
#include<stdio.h>
int x, y, r, p, centerX, centerY, r1, centerX1, centerY1;
centerX = 300;
centerY = 550;

centerX1 = 290;
centerY1 = 580;
void display(void)
{
/* clear all pixels */
glClear (GL_COLOR_BUFFER_BIT);
/* draw white polygon (rectangle) with corners at
* (0.25, 0.25, 0.0) and (0.75, 0.75, 0.0)
*/

//lower line
glColor3ub (200, 255, 12);
glBegin(GL_POLYGON);
glVertex2d (-500, 0);
glVertex2d (500, 0);
glVertex2d (500, -10);
glVertex2d (-500, -10);
glEnd();


glColor3ub (200, 255, 12);
glBegin(GL_LINES);
glVertex2d (-250, 0);
glVertex2d (-250, 350);
glVertex2d (-250, 350);
glVertex2d (250, 350);
glVertex2d (250, 350);
glVertex2d (250, 0);
glEnd();

glColor3ub (200, 255, 12);
glBegin(GL_POLYGON);
glVertex2d (-250, 350);
glVertex2d (250, 350);
glVertex2d (0, 450);
glEnd();

glColor3ub (200, 255, 12);
glBegin(GL_POLYGON);
glVertex2d (-90, 0);
glVertex2d (-90, 270);
glVertex2d (90, 270);
glVertex2d (90, 0);
glEnd();

glColor3ub (255, 200, 50);
glBegin(GL_POLYGON);
glVertex2d (-220, 200);
glVertex2d (-220, 270);
glVertex2d (-150, 270);
glVertex2d (-150, 200);
glEnd();

glColor3ub (255, 200, 50);
glBegin(GL_POLYGON);
glVertex2d (220, 200);
glVertex2d (220, 270);
glVertex2d (150, 270);
glVertex2d (150, 200);
glEnd();

r=90;
x=0;
y=r;
p=1-r;

while(x<y){
    glColor3ub (255, 255, 255);
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
        p=p+(2*x)+1-(2*y);
    }

}

r1=90;
x=0;
y=r1;
p=1-r1;

while(x<y){
    glColor3ub (0, 0, 0);
    glBegin(GL_POLYGON);
    glVertex2d (x+centerX1, -y+centerY1);
    glVertex2d (-x+centerX1, y+centerY1);
    glVertex2d (-x+centerX1, -y+centerY1);
    glVertex2d (y+centerX1, x+centerY1);
    glVertex2d (y+centerX1, -x+centerY1);
    glVertex2d (-y+centerX1, x+centerY1);
    glVertex2d (-y+centerX1, -x+centerY1);
    glVertex2d (x+centerX1, y+centerY1);
    glEnd();

    if(p<0){
        x=x+1;
        p=p+(2*x)+1;
    }
    else{
        x=x+1;
        y=y-1;
        p=p+(2*x)+1-(2*y);
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
gluOrtho2D(-500, 500, -100, 700);
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

