#include <fstream>
#include <iostream>
#include <string> // optionnel en fait

int main(){
    // Ecriture

    std::ofstream  file_out;

    file_out.open("output.txt");

    file_out <<"Bonjour tout le monde" <<std::endl;
    file_out.close();
    

    return 0;
}