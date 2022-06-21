#include <GL/gl.h>
#include <GL/glut.h>
int x,y,r,p,cx1,cy1,cx2,cy2;
float m;
r=50;
cx1= -640;
cy1= 52;
cx2= -440;
cy2= 52;
void display(void)
{
/* clear all pixels */
glClear (GL_COLOR_BUFFER_BIT);
/* draw white polygon (rectangle) with corners at
* (0.25, 0.25, 0.0) and (0.75, 0.75, 0.0)
*/

glColor3ub (255, 200, 0);
glBegin(GL_LINES);
glVertex2d (-700, 0);
glVertex2d (700, 0);
glEnd();

x=0;
y=r;
p=1-r;

while(x<y){
    glColor3ub (255, 200, 0);
    glBegin(GL_POINTS);
    glVertex2d (x+cx1+m,y+cy1);
    glVertex2d (x+cx1+m,-y+cy1);
    glVertex2d (-x+cx1+m,y+cy1);
    glVertex2d (-x+cx1+m,-y+cy1);
    glVertex2d (y+cx1+m,x+cy1);
    glVertex2d (y+cx1+m,-x+cy1);
    glVertex2d (-y+cx1+m,x+cy1);
    glVertex2d (-y+cx1+m,-x+cy1);
    glEnd();

    glColor3ub (255, 200, 0);
    glBegin(GL_POINTS);
    glVertex2d (x+cx2+m,y+cy2);
    glVertex2d (x+cx2+m,-y+cy2);
    glVertex2d (-x+cx2+m,y+cy2);
    glVertex2d (-x+cx2+m,-y+cy2);
    glVertex2d (y+cx2+m,x+cy2);
    glVertex2d (y+cx2+m,-x+cy2);
    glVertex2d (-y+cx2+m,x+cy2);
    glVertex2d (-y+cx2+m,-x+cy2);
    glEnd();
    if(p<0){
        x+=1;
        p=p+(2*x)+1;
    }
    else{
        x+=1;
        y-=1;
        p=p+(2*x)+1-(2*y);
    }
}

glColor3ub (255, 200, 0);
glBegin(GL_LINES);
glVertex2d (-640+m, 52);
glVertex2d (-530+m, 52);
glEnd();

glColor3ub (255, 200, 0);
glBegin(GL_LINES);
glVertex2d (-530+m, 52);
glVertex2d (-470+m, 120);
glEnd();

glColor3ub (255, 200, 0);
glBegin(GL_LINES);
glVertex2d (-470+m, 120);
glVertex2d (-580+m, 120);
glEnd();

glColor3ub (255, 200, 0);
glBegin(GL_LINES);
glVertex2d (-580+m, 120);
glVertex2d (-640+m, 52);
glEnd();

glColor3ub (255, 200, 0);
glBegin(GL_LINES);
glVertex2d (-440+m, 52);
glVertex2d (-500+m, 170);
glEnd();

glColor3ub (255, 200, 0);
glBegin(GL_LINES);
glVertex2d (-500+m, 170);
glVertex2d (-520+m, 170);
glEnd();

glColor3ub (255, 200, 0);
glBegin(GL_LINES);
glVertex2d (-580+m, 120);
glVertex2d (-580+m, 140);
glEnd();

glColor3ub (255, 200, 0);
glBegin(GL_LINES);
glVertex2d (-590+m, 140);
glVertex2d (-570+m, 140);
glEnd();

if(m<700){
    m+=0.05;
}
else{
    m=0;
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
glClearColor (0.0, 0.0, 0.0, 0.0);
/* initialize viewing values */
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
//glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
gluOrtho2D(-700, 700, -300, 900);
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
glutInitWindowSize (700, 700);
glutInitWindowPosition (100, 100);
glutCreateWindow ("191-15-12179");
init ();
glutDisplayFunc(display);
glutMainLoop();
return 0; /* ISO C requires main to return int. */
}
