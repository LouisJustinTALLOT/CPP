#include<iostream>
void print (int)         { std::cout << "print (int)\n"; }
void print (char)        { std::cout << "print (char)\n"; }
void print (const char*) { std::cout << "print (const char*)\n"; }


int* foo () {
    int j = 17;
    return &j;  // stack 2
}
int main () {
    int* pi = nullptr;  // stack 1
    pi = foo();  // stack 3
    int k = *pi;  // stack 4
    return 0;
}