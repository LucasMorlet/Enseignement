#include <GL/glew.h> // GLEW embarque OpenGL et GLU, donc pas besoin de les inclure
#include <GL/freeglut.h> // Toujours inclure GLEW avant GLUT
#include "test_glut.cpp"

#include <iostream>

int test_glew ( int argc, char* argv[] )
{
    creationFenetreGlut( argc, argv );

    // GLEW doit être initialisé après la création d'un contexte OpenGL (ie. une fenêtre)
    glewExperimental = GL_TRUE;
    GLenum err = glewInit();
    if ( err != GLEW_OK )
    {
        std::cout << "Erreur de GLEW" << std::endl;
        std::cout << glewGetErrorString( err ) << std::endl;
    }
    else
    {
        std::cout << "********** Info GPU **********" << std::endl;
        std::cout << "* Fabricant : "         << glGetString (GL_VENDOR)                      << std::endl;
        std::cout << "* Carte graphique: "    << glGetString (GL_RENDERER)                    << std::endl;
        std::cout << "* Version : "           << glGetString (GL_VERSION)                     << std::endl;
        std::cout << "* Version GLSL : "      << glGetString (GL_SHADING_LANGUAGE_VERSION)    << std::endl;
        std::cout << "******************************" << std::endl;
    }

    // Mais avant tout appel d'une fonction OpenGL
    affichageGlut();
    return 0;
}
