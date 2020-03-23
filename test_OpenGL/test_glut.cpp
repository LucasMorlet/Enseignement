#include <GL/gl.h>
#include <GL/freeglut.h>

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(0,0,0,0);
    glLoadIdentity();

    glBegin(GL_TRIANGLES);
        glColor3f(1.0f, 0.0f, 0.0f);
        glVertex3f(-1.0f, -1.0f, 0.0f);

        glColor3f(0.0f, 1.0f, 0.0f);
        glVertex3f(1.0f, -1.0f, 0.0f);

        glColor3f(0.0f, 0.0f, 1.0f);
        glVertex3f(0.0f, 1.0f, 0.0f);
    glEnd();
    glFlush();
}

void creationFenetreGlut ( int argc, char* argv[] )
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA | GLUT_SINGLE | GLUT_DEPTH);
    glutInitWindowSize(350, 300);
    glutCreateWindow("Triangle");
}

void affichageGlut()
{
    glutDisplayFunc(display);
    glutMainLoop();
}

int test_glut ( int argc, char* argv[] )
{
    creationFenetreGlut( argc, argv );
    affichageGlut();

    return 0;
}
