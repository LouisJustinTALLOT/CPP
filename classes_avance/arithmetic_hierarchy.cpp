#include <iostream>
#include <except>
#include <string>

class Expression{
    protected:
        std::string representation;
        double valeur;

    public :

        virtual void print(){

            std::cout<<this->representation<<std::endl;
        }

        virtual void print_value(){
            std::cout<<this->eval()<<std::endl;
        }

        virtual double eval(){
            return valeur;
        }

};

class Constant : public Expression{
    // protected:
    //     std::string representation;
    //     double valeur;

    public : 
        Constant(const double& une_constante ): valeur(une_constante){
            representation =  to_string(une_constante)
        }
    
    
};

class Plus : public Constant{
    protected:
        Expression partie1;
        Expression partie2;

    public :
        Plus(const Expression& expr1, const Expression& expr2): partie1(expr1), partie2(expr2) {
            
        }
        
    double eval(){
        return this->partie1.eval() + this->partie2.eval()
    }


};

class Minus : public Constant{

};

class Unary_minus : public Minus{

    public:
        Unary_minus(Constant& c): Minus(0, c){}
}




int main(){



    return 0;
}