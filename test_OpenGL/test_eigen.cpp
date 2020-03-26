// On ignore certains Warning dans la compilation d'Eigen pour ne pas les afficher
// Pour l'insant, Microsoft Visual Studio n'est pas défini
// Ref --> https://www.fluentcpp.com/2019/08/30/how-to-disable-a-warning-in-cpp/
#if defined(_MSC_VER)
    // Pour Microsoft Visual Studio
    #pragma warning( push )
        #pragma warning( disable : <numéro du warning> )
        #include <Eigen/Eigenvalues>
        #include <Eigen/Dense>
    #pragma warning( pop )
#elif defined(__GNUC__) || defined(__clang__)
    // Pour le gcc/g++ d'Unix et pour CLang
    #pragma GCC diagnostic push
        #pragma GCC diagnostic ignored "-Wattributes"
        #include <Eigen/Eigenvalues>
        #include <Eigen/Dense>
    #pragma GCC diagnostic pop
#else
    // Normalement, vous n'avez rien à faire là !
    #include <Eigen/Eigenvalues>
    #include <Eigen/Dense>
#endif

#include <iostream>

Eigen::MatrixXd simplification_matrice ( Eigen::MatrixXd matrice )
{
    // Mets le premier coefficient non-nul de chaque ligne à 1 en conservant la direction des vecteurs
    for ( int i = 0 ; i < matrice.rows() ; i++ )
    {
        double div = 1;
        for ( int j = 0 ; j < matrice.cols() ; j++ )
        {
            if ( abs(matrice(i,j)) > 0.0001 )
            {
                div = matrice(i,j);
                break;
            }
        }
        for ( int j = 0 ; j < matrice.cols() ; j++ )
        {
            matrice(i,j) /= div;
        }
    }
    return matrice;
}

void calcul_diagonalisation ( const Eigen::MatrixXd &matrice, Eigen::MatrixXd &iP, Eigen::MatrixXd &D, Eigen::MatrixXd &P )
{
    // Rappel diagonalisation -> https://www.supinfo.com/cours/1LAL/chapitres/04-diagonalisation-matrices-carrees
    if ( matrice.cols() != matrice.rows() )
    {
        std::cout << "Erreur, tentative de diagonalisation d'une matrice non-carrée" << std::endl;
        return;
    }
    Eigen::EigenSolver<Eigen::MatrixXd> es( matrice );
    Eigen::VectorXcd valeurs_propres_complexes = es.eigenvalues();
    Eigen::VectorXd valeurs_propres = valeurs_propres_complexes.real();
    for ( int i = 0 ; i < valeurs_propres.size() ; i++ )
    {
        D(i,i) = valeurs_propres[i];
    }
    Eigen::MatrixXcd vecteurs_propres_complexes = es.eigenvectors();
    P = vecteurs_propres_complexes.inverse().real();
    P = simplification_matrice(P);
    iP = P.inverse();
}

void print_eigen_matrix ( Eigen::MatrixXd matrice, int precision )
{
    // On met les zéros à 0
    for ( int i = 0 ; i < 3 ; i++ )
    {
        for ( int j = 0 ; j < 3 ; j++ )
        {
            if ( std::abs(matrice (i,j)) < 0.0001 ) matrice (i,j) = 0;
        }
    }

    // Définition de l'affichage
    int flags = 0;
    std::string entre_2_coeff = ", ";
    std::string entre_2_lignes = "\n";
    std::string debut_ligne = "| ";
    std::string fin_ligne = " |";
    std::string debut_matrice = "";
    std::string fin_matrice = "";

    Eigen::IOFormat format( precision, flags, entre_2_coeff, entre_2_lignes, debut_ligne, fin_ligne, debut_matrice, fin_matrice);
    std::cout << matrice.format(format) << std::endl;
}

void test_eigen ( void )
{
    Eigen::MatrixXd matrice (3,3);
    matrice(0,0) =  3;  matrice(0,1) =  5; matrice(0,2) = -5;
    matrice(1,0) = -5;  matrice(1,1) = -7; matrice(1,2) =  5;
    matrice(2,0) = -5;  matrice(2,1) = -5; matrice(2,2) =  3;
    std::cout << "M =" << std::endl;
    print_eigen_matrix( matrice, 2 );
    std::cout << std::endl;

    Eigen::MatrixXd iP(3,3);
    Eigen::MatrixXd D(3,3);
    Eigen::MatrixXd P(3,3);
    calcul_diagonalisation ( matrice, iP, D, P );

    std::cout << "inv(P) =" << std::endl;
    print_eigen_matrix( iP, 2 );
    std::cout << std::endl;

    std::cout << "D =" << std::endl;
    print_eigen_matrix( D, 2 );
    std::cout << std::endl;

    std::cout << "P =" << std::endl;
    print_eigen_matrix( P, 2 );
    std::cout << std::endl;

    std::cout << "inv(P) * D * P =" << std::endl;
    print_eigen_matrix( iP * D * P, 2 );
    std::cout << std::endl;
}
