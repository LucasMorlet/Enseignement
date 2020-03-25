#include <Eigen/Eigenvalues>
#include <Eigen/Dense>
#include <iostream>

void calcul_decomposition ( const Eigen::MatrixXd &matrice, Eigen::MatrixXd &gauche, Eigen::MatrixXd &lambda, Eigen::MatrixXd &droite )
{
    Eigen::EigenSolver<Eigen::MatrixXd> es( matrice );
    Eigen::VectorXcd valeurs_propres_complexes  = es.eigenvalues();
    Eigen::VectorXd valeurs_propres  = valeurs_propres_complexes.real();
    for ( int i = 0 ; i < valeurs_propres.size() ; i++ )
    {
        lambda(i,i) = valeurs_propres[i];
    }
    Eigen::MatrixXcd vecteurs_propres_complexes = es.eigenvectors();
    gauche = vecteurs_propres_complexes.inverse().real();
    droite = vecteurs_propres_complexes.real();
}

void print_eigen_matrix ( const Eigen::MatrixXd &matrice, int precision )
{
    if ( precision > 6 ) precision = 6;
    float cast = pow(10.0, precision);
    for ( int i = 0 ; i < 4 ; i++ )
    {
        std::cout << "| ";
        for ( int j = 0 ; j < 4 ; j++ )
        {
            std::string s = std::to_string( (int)(cast * matrice(i,j))/cast );
            if ( matrice(i,j) >= 0 )
                s = " " + s;
            s = s.substr( 0, 3+precision );
            std::cout << s;
            if ( j < 3 ) std::cout << ", ";
        }
        std::cout << " |" << std::endl;
    }
}

void test_eigen ( void )
{
    Eigen::MatrixXd matrice (3,3);
    matrice(0,0) = 1;  matrice(0,1) = 0; matrice(0,2) = 0;
    matrice(1,0) = 0;  matrice(1,1) = 2; matrice(1,2) = 0;
    matrice(2,0) = 0;  matrice(2,1) = 0; matrice(2,2) = 3;

    Eigen::MatrixXd gauche(3,3);
    Eigen::MatrixXd lambda(3,3);
    Eigen::MatrixXd droite(3,3);
    calcul_decomposition( matrice, gauche, lambda, droite );

    //print_eigen_matrix( gauche, 2 );
    //print_eigen_matrix( lambda, 2 );
    //print_eigen_matrix( droite, 2 );
    //print_eigen_matrix( gauche * lambda * droite, 2 );
}
