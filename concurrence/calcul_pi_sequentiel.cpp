#include <iostream> 

int main(){

    int nb_point = 100000000;
    double l=1./nb_point;

    double pi=0;
    for( int i=0; i<nb_point; i++){
        double x=l*(i+0.5);
        pi += l*( 4. / (1. + x*x ) );
    }

    std::cout << "PI = " << pi << std::endl;

    return 0;
}