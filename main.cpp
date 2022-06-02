#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <iostream>
using namespace std;
void display();
void reshape(int, int);
void init()
{
    glClearColor(0.0,0.0,0.0,1.0);
}

int main(int argc, char**argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB);

    //creating a window
    glutInitWindowPosition(200,100);
    glutInitWindowSize(500,500);

    // create the window and add title name
    glutCreateWindow("openGL assignment PS/CSC/18/0065");

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    //change the color of the window
    init();

    glutMainLoop();
}

void display()
{
    //clear frame buffer
    glClear(GL_COLOR_BUFFER_BIT);
    // reset the co-ordinate system
    glLoadIdentity();
    // draw on the screen
    glColor3f(1.0,1.0,1.0);
    glBegin(GL_TRIANGLES);
    glVertex2f(0.0,5.0);
    glVertex2f(4.0,-3.0);
    glVertex2f(-4.0,-3.0);
    glEnd();
    // rotation, scaling and shearing
    glRotatef(angle,0,0,1);
    glScalef(0.5, 0.5, 0.5);

    //shearing along the x-axis for homogeneous coordinate NB: Xnew = (x + sh * y) and y values remains constant
    GLfloat m[16] = {
    1.0f, 0.0f, 0.0f, 0.0f,
    sh, 1.0f, 0.0f, 0.0f,
    0.0f, 0.0f, 1.0f, 0.0f,
    0.0f, 0.0f, 0.0f, 1.0f,
    };
    glMultMatrixf(m);

    /* without the matrix multiplication, the vertices can be displayed as follows for the same shearing

    glBegin(GL_TRIANGLES);
    glColor3f(0.5,0.5,0.5);
    glVertex2f((0.0 + sh*5.0),5.0);
    glColor3f(0,0,1);
    glVertex2f((4.0 + sh*-3.0),-3.0);
    glColor3f(1,0,0);
    glVertex2f((-4.0 + sh*-3.0),-3.0);
    glEnd();

    */

    glBegin(GL_TRIANGLES);
    glColor3f(0.5,0.5,0.5);
    glVertex2f(0.0,5.0);
    glColor3f(0,0,1);
    glVertex2f(4.0,-3.0);
    glColor3f(1,0,0);
    glVertex2f(-4.0,-3.0);
    glEnd();

    glFlush();
}

//respecify the clipping window after the user reshape the window
void reshape(int w, int h)
{
    //view port
    glViewport(0,0,(GLsizei)w,(GLsizei)h);
    //projection
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-10,10,-10,10);
    glMatrixMode(GL_MODELVIEW);
}
