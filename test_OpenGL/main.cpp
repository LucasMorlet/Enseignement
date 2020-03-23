

//#define TEST_GLUT // freeglut (anciennement GLUT) permet de créer un contexte OpenGL (ie. une fenêtre d'affichage)
#define TEST_GLEW // GLEW permet de tester quelles fonctionnalités OpenGL sont disponibles sur votre système

#ifdef WIN32
#endif

#if defined(TEST_GLUT)
    #include "test_glut.cpp"
#elif defined(TEST_GLEW)
    #include "test_glew.cpp"
#endif

#include <iostream>

int main ( int argc, char* argv[] )
{
    #if defined(TEST_GLUT)
        test_glut( argc, argv );
    #elif defined(TEST_GLEW)
        test_glew( argc, argv );
    #else
        std::cout << "Ni GLUT, ni GLEW, n'a été inclu" << std::endl;
    #endif
    return 0;
}
