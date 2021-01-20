#include<iostream>
#include<vector>

// template<typename T>
// T add(const T& a, const T& b){
//     return a+b;
// }

template<typename T>
void printVector(const std::vector<T> a){
    for (T x:a){std::cout<<x<<" > ";}
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
    std::vector<double> v1={1,2,3,4.4,5};
    std::vector<int> v2 = {1,2,3,4,5};

    printVector(v1);
    printVector(v2);


    return 0;
}