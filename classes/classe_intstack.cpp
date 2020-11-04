#include <iostream>
#include <stdexcept>


class IntStack { // implémente une pile
private:
    const int taille_du_stack;
    int* stack ;
    int hauteur = 0;  // le nombre d'éléments dans la pile

public: 
    IntStack (int size) : taille_du_stack(size) {
        stack = new int [taille_du_stack];
    }

    void push (int element){

        stack[hauteur] = element;
        hauteur += 1;
    }
    int pop (){
        if (not is_empty()){
            hauteur -= 1;
            int res = stack[hauteur];
            stack[hauteur] = 0;
            return res;
        }
        throw std::runtime_error("le stack est vide");
    }
    bool is_empty (){
        if (this->hauteur == -1){
            return true;
        }
        return false;
    }
    bool is_full (){
        if (this->hauteur == taille_du_stack){
            return true;
        }
        return false;
    }
    void print (){
        std::cout << "]";
        for (int i = 0; i<hauteur; i++){
            std::cout<<" "<<stack[i];
        }
        std::cout << " ]" << std::endl;
    }

};


int main () {
    IntStack s1 (3);
    s1.push(1);
    s1.push(2); 
    s1.print();    
    int e = s1.pop();

    s1.push(3);
    std::cout<<e<<std::endl;
    s1.print();
    return 0;
}
