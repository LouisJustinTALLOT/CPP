#include<iostream>
#include<string>

template<typename T>
class Translator{
    public:
     // le static permet de ne pas créer d'instance de la classe
        static T toType(const std::string& x){
            throw std::invalid_argument("Invalid template type");
        }

        static std::string toString(const T& x){
            throw std::invalid_argument("Invalid template type");
        }
};

template<>
class Translator<double>{
    public:
        static double toType(const std::string& x){
            return atof(x.c_str());
        }

        static std::string toString(const double& x){
            return std::to_string(x);
        }
};

template<>
class Translator<int>{
    public:
        static int toType(const std::string& x){
            return atoi(x.c_str());
        }

        static std::string toString(const int& x){
            return std::to_string(x);
        }
};

template<>
class Translator<bool>{
    public:
        static bool toType(const std::string& x){
            if(x == "true"){return true;}
            return false;

        }

        static std::string toString(const bool& x){
            return std::to_string(x);
        }
};



int main(){
    std::string token;

    token = "10";
    int a = Translator<int>::toType(token);

    token = "10.01";
    double b = Translator<double>::toType(token);

    token = "true";
    bool c = Translator<bool>::toType(token);


    std::cout<<a<<std::endl;
    std::cout<<b<<std::endl;
    std::cout<<c<<std::endl;

    return 0;
}