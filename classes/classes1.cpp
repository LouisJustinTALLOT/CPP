#include <iostream>
#include <stdexcept>


class Integer {

public:

  Integer (const int& x, const int& a, const int& b ) : value(x), a(a), b(b){
    if (x<a or x>b){
      throw std::runtime_error("valeur de x pas dans les bornes");
      // std::cout << "erreur" << std::endl;
    }
    
  }

  void incr(const int& entier){
    if (value < b){
      value += entier;
    }
    else{
      throw std::runtime_error("valeur de x pas dans les bornes");
    }
  }
    
  void decr (const int& entier) {
    if (value > a){
      value -= entier;
    }
    else{
      throw std::runtime_error("valeur de x pas dans les bornes");
    }
    }
  }

  void print () {
    std::cout << value << std::endl;
  }

private:
    int value ;
    int a;
    int b;

}; // attention ';' obligatoire en fin de déclaration de classe !

// la class Integer est définie

int main(){

  Integer i(13, 0, 100);
  i.print();

  i.incr(33);
  i.print();

  i.decr();
  i.print();

  return 0;

}

