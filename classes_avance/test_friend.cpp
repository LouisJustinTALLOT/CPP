#include <iostream>
template <typename T>
class A{
    private:
        T a;

    public:
        A(const T& x): a(x){}

    friend class B;
};

class B{
    public:
    B(){}
    template <typename T>
    void affiche_A(const A<T>& aclass){
        std::cout<<aclass.a<<std::endl;
    }


};

int main(){

    A<int> a(10);
    B b;

    b.affiche_A( a );

    return 0;
}