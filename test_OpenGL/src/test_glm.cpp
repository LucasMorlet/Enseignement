#include <glm/vec3.hpp>
#include <glm/vec4.hpp>
#include <glm/mat4x4.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/string_cast.hpp>
#include <iostream>

void print_glm_matrix ( const glm::mat4x4 &matrice, int precision )
{
    if ( precision > 6 ) precision = 6;
    float cast = pow(10.0, precision);
    for ( int i = 0 ; i < 4 ; i++ )
    {
        std::cout << "| ";
        for ( int j = 0 ; j < 4 ; j++ )
        {
            std::string s = std::to_string( (int)(cast * matrice[i][j])/cast );
            if ( matrice[i][j] >= 0 )
                s = " " + s;
            s = s.substr( 0, 3+precision );
            std::cout << s;
            if ( j < 3 ) std::cout << ", ";
        }
        std::cout << " |" << std::endl;
    }
}

void test_glm ( void )
{
    float Translate = 5.0f;
    glm::vec2 Rotate = glm::vec2(1.0f, 2.0f);
    glm::mat4 Projection = glm::perspective(glm::radians(45.0f), 4.0f / 3.0f, 0.1f, 100.f);
    glm::mat4 View = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, -Translate));
    View = glm::rotate(View, Rotate.y, glm::vec3(-1.0f, 0.0f, 0.0f));
    View = glm::rotate(View, Rotate.x, glm::vec3(0.0f, 1.0f, 0.0f));
    glm::mat4 Model = glm::scale(glm::mat4(1.0f), glm::vec3(0.5f));
    glm::mat4 MVP = Projection * View * Model;
    print_glm_matrix( MVP, 2 );
    /* Display expected :

    |  0.48, -0.92, -0.17, -0.17 |
    |  0.00, -0.50,  0.45,  0.45 |
    |  0.76,  0.59,  0.11,  0.11 |
    |  0.00,  0.00,  4.80,  5.00 |

    */
}
