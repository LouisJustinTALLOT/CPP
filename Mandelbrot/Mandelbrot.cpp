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



};


vector<int> getColor(int niter, int itermax ){
  vector<int> col(3);
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
