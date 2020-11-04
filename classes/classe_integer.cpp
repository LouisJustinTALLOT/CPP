#include <iostream>
#include <stdexcept>
#include <limits>



class Integer {
  
  private:
        int value;
        int a;
        int b;
        
  public:
    
    Integer (const int& x, const int& aa = std::numeric_limits<int>::min(), const int& bb = std::numeric_limits<int>::max() ) : value(x), a(aa), b(bb){
      if (x<a or x>b){
        throw std::runtime_error("valeur de x sort des bornes à l'initialisation");
        // std::cout << "erreur" << std::endl;
      }
    }

    void incr(const int& entier = 1){
      if (value + entier < b){
        value += entier;
      }
      else{
        throw std::runtime_error("valeur de x sort des bornes par valeur supérieure");
      }
    }
      
    void decr (const int& entier = 1) {
      if (value - entier> a){
        value -= entier;
      }
      else{
        throw std::runtime_error("valeur de x sort des bornes par valeur inférieure");
      }
      }
    

    void print () {
      std::cout << this->value << std::endl;
    }



}; // attention ';' obligatoire en fin de déclaration de classe !

// la class Integer est définie

int main(){
  
  Integer i(13, 0, 100);
  i.print();

  i.incr(3);
  i.print();

  i.decr();
  i.print();
  
  return 0;

}

