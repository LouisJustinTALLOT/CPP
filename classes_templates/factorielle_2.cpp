#include <iostream>
#include <chrono>

template<long unsigned int N>
class Factorial{
    public:
        enum{
            value = N * Factorial<N-1>::value
        };
};

template<>
class Factorial<1>{
    public:
        enum{
            value=1
        };
};

int main(){
    auto start = std::chrono::steady_clock::now();

    int N = 10000000;

    for(int i = 0; i<N; i ++){
        Factorial<50>::value;   
    }

    std::cout << Factorial<50>::value <<std::endl;

    auto end = std::chrono::steady_clock::now();

    auto milis = std::chrono::duration_cast<std::chrono::nanoseconds>(end-start).count();

    std::cout<<"durée de "<<milis << " nanosecondes"<<std::endl;
    return 0;
}

