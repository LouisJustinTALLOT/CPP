#include <iostream>
#include <string>

template<typename T>
std::string getType(){
    return "undefined";
}

template<>
std::string getType<int>(){
    return "int";
}

template<>
std::string getType<double>(){
    return "double";
}

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
            std::cout<< getType<T>() <<std::endl;
            std::cout<< this->_value <<std::endl;
        }

        template<typename U>
        void add(const Number<U>& other){
            this->_value += static_cast<T>(other.get());
        }
};

template<typename T>
void Number<T>::set(const T& x){
    this->_value = x;
}

int main(){
    Number <double> a(0.25);
    Number<int> b(10);

    a.info();
    b.info();

    a.add(b);
    a.info();
    return 0;
}