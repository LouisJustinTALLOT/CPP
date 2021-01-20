#include <iostream>


template<typename T>
class Number{
    protected:
        T _value;

    public:
        Number(const T& x): _value(x){};

        T get() const{
            return this->_value;
        }

        void set (const T& x){
            this->_value = x;
        }
        void info(){
            std::cout<< this->_value <<std::endl;
        }

        template<typename U>
        void add(const Number<U>& other){
            this->_value += static_cast<T>(other.get());
        }
};

int main(){
    Number <double> a(0.25);
    Number<int> b(10);

    a.info();
    b.info();

    a.add(b);
    a.info();
    return 0;
}