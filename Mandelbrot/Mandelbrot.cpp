#include <iostream>
#include <cmath>
#include <fstream>
#include <vector>

// Nous allons tracer la fractale de Mandelbrot au format .ppm
// et le sauvegarder en mode binaire


//class Complex{ // de la forme a+bi
//private:
    //double a;
    //double b;
//public:
    //Complex(const double& x, const double& y): a(x), b(y) {}

//};

std::vector<double> carre_complexe(std::vector<double>& z){
    std::vector<double> res = {z[0]*z[0] - z[1]*z[1], 2*z[0]*z[1]};

    return res;
}


int est_dedans(double& x, double& y){
    double p = sqrt((x-0.25)*(x-0.25) + y*y);

    if(x < p -2 * p * p + 0.25){
        return 0;
    }

    if ((x+1)*(x+1) + y*y < 0.0625){
        return 0;
    }
    std::vector<double> z = {0.,0.};
    std::vector<double> c = {x, y};
    
    for(int k = 0; k<100; k++){
        z[0] = carre_complexe(z)[0] + c[0];
        z[1] = carre_complexe(z)[1] + c[1];
        if(z[0]*z[0] + z[1]*z[1] > 4){
            return k;
        }
    }
    return 0;
}

std::vector<int> getColor(int niter, int itermax ){
  std::vector<int> col(3);
  if ( niter < itermax ){
    col[0] = 200+(55*niter)/100;
    col[1] = (230*(100-niter))/100;
    col[2] = (230*(100-niter))/100 ;
  }
  else{
    col[0] = 0;
    col[1] = 255;
    col[2] = 255;
  }
  return col;
}


int main(){

    int N = 100;

    for (int i=0; i<N; i++){
        double x = -2. + 2.5/N;
    
        for (int j=0; j<N; j++){
            double y = -1.25 + 2.5/N;

            std::vector<int> couleur = getColor(est_dedans(x, y), 100);

            // puis faire l'affichage.....
            // la suite demain



        }
    }





    return 0;
}
