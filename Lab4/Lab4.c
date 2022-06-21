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

int x=150, y=150, i, j;


for(i=0;i<6;i++){
    for(j=0;j<6;j++){
        if(i%2==0){
            if(j%2==0){
                glColor3ub (0, 0, 0);
            }
            else{
                glColor3ub (178, 190, 181);
            }
        }
        else{
            if(j%2==1){
                glColor3ub (0, 0, 0);
            }
            else{
                glColor3ub (178, 190, 181);
            }
        }
        glBegin(GL_POLYGON);
        glVertex2d (x, y);
        glVertex2d (x+50, y);
        glVertex2d (x+50, y+50);
        glVertex2d (x, y+50);
        glEnd();

        x+=50;
        }
        x=150;
        y+=50;
}

/* don't wait!
* start processing buffered OpenGL routines
*/
glFlush ();
}
void init (void)
{
/* select clearing (background) color */
glClearColor (0.2, 0.2, 0.2, 0.2);
/* initialize viewing values */
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
//glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
gluOrtho2D(0, 600, 0, 600);
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
