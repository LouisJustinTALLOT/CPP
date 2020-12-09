#include <algorithm>

#include <vector>
#include <iostream>










int main(){

    std::vector<int> vec = {2,3,1,4,5,6,7,10}; //notre vecteur de travail


    // find

    auto x =    std::find(vec.begin(), vec.end(),  3);

    if (x != vec.end()){  
        std::cout<<"ok"<<std::endl; // ça a été trouvé
    }
    else{
        std::cout <<"pas ok" <<std::endl;
    }

    // sort
    for (auto x:vec){
        std::cout <<x<<std::endl;
    }
    std::cout <<"-----------------"<<std::endl;

    std::sort(vec.begin(), vec.end()); //on trie le vecteur

    for (auto x:vec){
        std::cout <<x<<std::endl; // on affiche notre vecteur
    }
   
    std::cout <<"-----------------"<<std::endl;

    std::sort(vec.begin(), vec.end(), [](const int& a, const int& b){
        return a>b; //pour trier dans le sens décroissant
    });

    for (auto x:vec){
        std::cout <<x<<std::endl;
    }

    return 0;    
}