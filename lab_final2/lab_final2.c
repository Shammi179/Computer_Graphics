#include <GL/gl.h>
#include <GL/glut.h>
#include <stdio.h>

int x, y, i, cx, cy, r;
double p;

void display(void)
{
/* clear all pixels */
glClear (GL_COLOR_BUFFER_BIT);
/* draw white polygon (rectangle) with corners at
* (0.25, 0.25, 0.0) and (0.75, 0.75, 0.0)
*/
glColor3f (1, 1, 1);
glBegin(GL_POLYGON);
glVertex2d(-300,-30);
glVertex2d(0,-40);
glVertex2d(0,40);
glVertex2d(-300,30);
glEnd();

glBegin(GL_POLYGON);
glVertex2d(300,-30);
glVertex2d(0,-40);
glVertex2d(0,40);
glVertex2d(300,30);
glEnd();

glBegin(GL_POLYGON);
glVertex2d(-40,0);
glVertex2d(40, 0);
glVertex2d(30,300);
glVertex2d(-30,300);
glEnd();

glBegin(GL_POLYGON);
glVertex2d(-40,0);
glVertex2d(40, 0);
glVertex2d(30,-300);
glVertex2d(-30,-300);
glEnd();


glColor3f (0.5, 0.5, 0.5);
glBegin(GL_POLYGON);
glVertex2d(400,400);
glVertex2d(550, 400);
glVertex2d(550, 550);
glVertex2d(400,550);
glEnd();

glColor3f (1, 1, 1);
glBegin(GL_POLYGON);
glVertex2d(490,450);
glVertex2d(520, 450);
glVertex2d(520, 500);
glVertex2d(490,500);
glEnd();



r=75;
x = 0;
y = r;
cx=0;
cy=0;
glColor3f (0.5, 0.2, 0.7);
glBegin(GL_POLYGON);

glVertex2d(x  + cx, -y + cy);
glVertex2d(-x + cx, y  + cy);
glVertex2d(-x + cx, -y + cy);
glVertex2d(y  + cx, x  + cy);
glVertex2d(y  + cx, -x + cy);
glVertex2d(-y + cx, x  + cy);
glVertex2d(-y + cx, -x + cy);
glVertex2d(x  + cx, y  + cy);
glEnd();

p = 1 - r;

for(i=0; x<y; i++){
    if (p<0){
        x=x + 1;
        p = p + 2*x + 1;
    }
    else{
        x = x+1;
        y = y-1;
        p = p + 2*x + 1 - 2*y;
    }

    glColor3f (0.5, 0.2, 0.7);
    glBegin(GL_POLYGON);

    glVertex2d(x  + cx, -y + cy);
    glVertex2d(-x + cx, y  + cy);
    glVertex2d(-x + cx, -y + cy);
    glVertex2d(y  + cx, x  + cy);
    glVertex2d(y  + cx, -x + cy);
    glVertex2d(-y + cx, x  + cy);
    glVertex2d(-y + cx, -x + cy);
    glVertex2d(x  + cx, y  + cy);
    glEnd();
}


r=25;
x = 0;
y = r;
cx=450;
cy=475;

glColor3f (1, 0, 0);
glBegin(GL_POLYGON);

glVertex2d(x  + cx, -y + cy);
glVertex2d(-x + cx, y  + cy);
glVertex2d(-x + cx, -y + cy);
glVertex2d(y  + cx, x  + cy);
glVertex2d(y  + cx, -x + cy);
glVertex2d(-y + cx, x  + cy);
glVertex2d(-y + cx, -x + cy);
glVertex2d(x  + cx, y  + cy);
glEnd();

p = 1 - r;

for(i=0; x<y; i++){
    if (p<0){
        x=x + 1;
        p = p + 2*x + 1;
    }
    else{
        x = x+1;
        y = y-1;
        p = p + 2*x + 1 - 2*y;
    }

    glColor3f (1, 0, 0);
    glBegin(GL_POLYGON);

    glVertex2d(x  + cx, -y + cy);
    glVertex2d(-x + cx, y  + cy);
    glVertex2d(-x + cx, -y + cy);
    glVertex2d(y  + cx, x  + cy);
    glVertex2d(y  + cx, -x + cy);
    glVertex2d(-y + cx, x  + cy);
    glVertex2d(-y + cx, -x + cy);
    glVertex2d(x  + cx, y  + cy);
    glEnd();
}

glFlush ();
}
void init (void)
{
/* select clearing (background) color */
glClearColor (0.0, 0.0, 0.0, 0.0);
/* initialize viewing values */
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(-600,600,-600,600);
}

int main(int argc, char** argv)
{

    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (500, 500);
    glutInitWindowPosition (100, 100);
    glutCreateWindow ("191-15-12381 :: Sajal Das");
    init ();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0; /* ISO C requires main to return int. */
}
