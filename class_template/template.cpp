#include<iostream>
#include<vector>

// template<typename T>
// T add(const T& a, const T& b){
//     return a+b;
// }

// template<typename T>
// void printVector(const std::vector<T> a){
//     for (T x:a){std::cout<<x<<" > ";}
//     std::cout<<std::endl;
// }

template<typename T, int N>
void printVector(const std::vector<T> a){
    for (int i =0; i<N; i++){std::cout<<a[i]<<" > ";}
    std::cout<<std::endl;
}


int main(){
    // double a, b, c;
    // int d, e, f;
    // a=b = 10.0;
    // d=e = 12;
    // std::cout<<add(a, b)<<std::endl;
    // std::cout<<add(d, e)<<std::endl;
    // // std::cout<<add(a,b)<<std::endl;

    ///////////
    std::vector<double> v1={1,2,3,4.4,5,6.6};
    std::vector<int> v2 = {1,2,3};

    // printVector(v1);
    // printVector(v2);    

    // la vraie notation c'est printvector<type> (aaa) pour dire au compilo

    printVector<double,6>(v1);
    printVector<int, 3>(v2);


    return 0;
}