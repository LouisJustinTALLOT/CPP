#include<iostream>


int main() {

    double a = 2.3;


    auto f = [](){
        std::cout<<"coucou "<<std::endl;
    };

    auto f2 = [&a](){
        std::cout<<"coucou "<<a<<std::endl;
        a = 1024.0;
    };

    f();
    f2();
    f2();

    return 0;
}