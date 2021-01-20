#include <iostream>

template<class T>
void print(T value){
    std::cout << value <<"\n";
}

template<class T, class ...Args>
void print(T value, Args... args){
    print(value);
    print(args...);
}

int main(){
    print(1);
    print(1,2);
    print(1,"coucou", false);
}