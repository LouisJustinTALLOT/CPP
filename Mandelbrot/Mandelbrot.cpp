#include <iostream>
#include <cmath>
#include <fstream>
#include <vector>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <string>

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
        std::vector<double> carre_z = carre_complexe(z);
        z[0] = carre_z[0] + c[0];
        z[1] = carre_z[1] + c[1];
        if(z[0]*z[0] + z[1]*z[1] > 4){
            return k;
        }
    }
    return 0;
}

std::vector<int> getColor(int niter, int itermax ){
  std::vector<int> col(3);
  if ( niter < itermax ){
    col[0] = 0;//200+(55*niter)/100;
    col[1] = 255*niter/itermax;
    col[2] = 0;//(230*(100-niter))/100 ;
  }
  else{
    col[0] = 0;
    col[1] = 255;
    col[2] = 0;
  }
  return col;
}


int main(){

    int N = 5000;

    std::ofstream file_out;
   
    file_out.open("fractale_mandelbrot_1.ppm", std::ios::out | std::ios::binary);

    file_out.write("P3\n",3);
    std::string str_N = std::to_string(N);
    file_out.write(str_N.c_str(), str_N.size());
    file_out.write(" ", 1);
    file_out.write(str_N.c_str(), str_N.size());
    file_out.write("\n", 1);
    file_out.write("255\n", 4);

    for (int i=0; i<N; i++){
        double y = -1.25 + 2.5/N*i;
    
        for (int j=0; j<N; j++){
            double x = -2. + 2.5/N*j;

            std::vector<int> couleur = getColor(est_dedans(x, y), 100);

            for (int a = 0; a<3; a++){
                std::string valeur = std::to_string(couleur[a]);
                file_out.write(valeur.c_str(),valeur.size());
                file_out.write(" ", 1);
            }
        }
        
        file_out.write("\n",1);
    }

    file_out.close();
    return 0;
}
