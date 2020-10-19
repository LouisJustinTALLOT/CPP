#include <iostream>

void incremente(int i ){
    // std::cout<<i<<std::endl;
    i++;
    std::cout<<&i<<std::endl;    
}
void incremente(int * pa){
    *pa += 1; 
}

void incremente(int& a){
    a +=1; 
}

// void print(auto a){
//     std::cout<<a<<std::endl;
// }


void swap (int* a, int*b){
    int tmp = *a;
    *a = *b;
    *b = tmp;

}


void swap2(int& a, int& b){
    int tmp = a; 
    a = b;
    b = tmp;
}

int main (){

    int j   = 3;
    incremente(&j);
    std::cout<<j<<std::endl;
    incremente(&j);
    std::cout<<j<<std::endl;

    // swap 

    int a = 12;
    int b = 81;
    std::cout << a << ' ' << b << std::endl;
    swap2(a,b);
    std::cout << a << ' ' << b << std::endl;



    // print(a);
    // print(&a);
    // int aaa [] = {2,4,1,3};
    // print(aaa);

    return 0;
}