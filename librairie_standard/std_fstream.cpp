#include <fstream>
#include <iostream>
#include <string> // optionnel en fait

int main(){
    // Ecriture

    std::ofstream  file_out;

    file_out.open("output.txt");

    file_out <<"Bonjour tout le monde" <<std::endl;
    file_out.close();
    
    // Lecture

    std::ifstream file_in;

    file_in.open("output.txt");
    std::string a; 
    file_in >> a;
    std::cout<<a<<std::endl; // pb on ne lit que le premmier mot...
    file_in >> a;
    std::cout<<a<<std::endl; // puis le 2e...


    std::string b;
    std::getline(file_in, b);
    std::cout<<b<<std::endl; 

    std::cout<<file_in.eof()<<std::endl; 

    // fichier binaire

    std::ofstream file_out_bin; 
    file_out_bin.open("output.bin", std::ios::out | std::ios::binary);
    file_out_bin.write((char*)"TEst aufgeihojfa");
    file_out_bin.close();


    return 0;
}