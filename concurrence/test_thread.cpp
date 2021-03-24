#include <thread>
#include <iostream>
/*
    pour compiler, il faut lui donner l'argument -l pthread pour link la librairie pthread :

    g++ test_thread.cpp -o test_thread -l pthread

*/


int main(){
    std::thread t ([]()->void{
        for(int i=0; i<10; i++){
            std::cout<<"hello world from thread "<<i<<std::endl;
        }
    });

    std::cout<<"from the main function"<<std::endl;

    t.join();
    return 0;
}