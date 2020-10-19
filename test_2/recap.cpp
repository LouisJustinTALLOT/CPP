# include <iostream>

int main(int argc, char* argv[]){
    // variarbles et types de base

    int un_entier = -10;
    unsigned int un_entier_positif;
    un_entier_positif = 10;
    float un_float = 2.3456;
    double un_autre = 10.05;
    bool unboleen = true; //or false
    char un_caractere = 'A';


    // pointeur : 

    int* un_pointeur_int = nullptr;
    std::cout << un_pointeur_int << std::endl;

    un_pointeur_int = &un_entier;
    std::cout << "un_pointeur_int = " << un_pointeur_int <<std::endl;
    std::cout << "*un_pointeur_int = "<< *un_pointeur_int <<std::endl;
    *un_pointeur_int = 20;
    std::cout << "*un_pointeur_int = "<< *un_pointeur_int <<std::endl;
    std::cout << "un_entier = " << un_entier_positif <<std::endl;


    return 0;
}