#include <iostream>

// class Number{
// private:
//     std::string _name // ne peut pas être utilisé dans une classe fille

// protected:
//     std::string _name2 // privé à la classe mais accessible aux classes filles

// };

class IntStack {
public:
  IntStack (int s): size(s), top (0), tab (new int [size]) {
  }
  IntStack( const IntStack& other){ // le & est nécessaire pour éviter de s'appeler lui-même
      std::cout <<"Copy constructor "<<std::endl;
        this->size = other.size;
        this->top = other.top;
        this->tab = new int[size];
        for(int i=0; i<other.top;i++){
            this->tab[i] = other.tab[i];
        }
  }
  ~IntStack(){
        std::cout<<"Dans le destructeur"<<std::endl;
        this->delete_stack();
  }
  void push (int e) {
    tab[top] = e;
    top = top+1;
  }
  int pop () {
    top = top-1;
    return tab[top];
  }
  void print () {
    std :: cout << "[";
    for (int i=0; i<top; i++) {
      std::cout << tab[i] << ' ';
    }
    std::cout << '[' << std::endl;
  }
  void address(){
      std::cout<<this->tab<<std::endl;

  }
  void delete_stack () {
    delete [] tab;
  }
private:
  int size;
  int top;
  int* tab;
};

// class Integer: public Number{
class Integer{

    protected:
        int _value;


    public:
        Integer(): _value(0){}
        Integer(const int& x): _value(x){}

        void print(){
            std::cout <<"Integer with value: " << this-> _value <<std::endl;
        }


};

