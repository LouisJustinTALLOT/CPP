#include<iostream>

template<typename T>
T add(const T& a, const T& b){
    return a+b;
}

int main(){
    double a, b, c;
    int d, e, f;
    a=b = 10.0;
    d=e = 12;
    std::cout<<add(a, b)<<std::endl;
    std::cout<<add(d, e)<<std::endl;
    // std::cout<<add(a,b)<<std::endl;

}