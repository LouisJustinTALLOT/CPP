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

    return 0;    
}    std::sort(vec.begin(), vec.end()); //on trie le vecteur
        std::cout <<x<<std::endl; // on affiche notre vecteur
        return a>b; //pour trier dans le sens décroissant
