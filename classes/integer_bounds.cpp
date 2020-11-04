#include "Integer.h"

int main(){

    Integer a(10); // No bounds 
    a.incr();
    a.incr();
    a.print();

    Integer b(2, 0); // Only min bound set 
    b.print();
    b.decr();
    b.decr();
    b.print();
    // b.decr(); // Should give an Error 

    Integer c(5, 0, 6);
    c.print();
    c.incr();
    //c.incr(); // Should give an Error 


    Integer* pi;
    pi = &c;
    std::cout << pi << std::endl;

    (*pi).print();
    pi->print();
    return 0; 
}

