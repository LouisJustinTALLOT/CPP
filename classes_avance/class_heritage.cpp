#include <iostream>
#include <string>
#include <vector>
#include <memory>

class Shape{

    protected:

    std::string _type;

    public:

    Shape() : _type("null"){}

    virtual void info(){
        std::cout <<"Objet Shape de type "<< this->_type<<std::endl;
    }

    // virtual int area(){
    //     return 0; // va marcher pour tout le monde mais pas intéressant
    // }

    // méthode virtuelle pure:
    virtual double area() = 0; // elle va être définie dans les classes filles

};

class Circle : public Shape{
    protected:
        int _radius;


    public :
        Circle() :Shape() {
            this->_type = "circle";
            this->_radius = 1;
        }
        
        Circle(const int& r): Shape(){
            this->_type="circle";
            this->_radius = r;

        }


        void info(){
            Shape::info();// on appelle d'abord la méthode de la classe mère puis on l'enrichit

            std::cout << "Radius= "<< this->_radius <<std::endl;
        }

        double area(){
            std::cout<< 3.14 * this->_radius * this->_radius<<std::endl;
            return 3.14 * _radius * _radius;
        }

};

class Rectangle :public Shape{
    protected:
        int _length;
        int _width;
    public:
        Rectangle(const int& l, const int& w): Shape(), _length(l), _width(w){
            this->_type =  "rectangle";
        }

        void info(){
            Shape::info();
            std::cout << this->_length << "x"<<this->_width<<std::endl;
        }
        double area(){
            return this->_length * this->_width;
        }
        void coucou(){
            std::cout<<"coucou depuis rectangle"<<std::endl;
        }
};


int main(){

    // Shape a;

    // a.info();
    // a.area(); // vs code rale
    // on ne peut plus définir de Shape

    Circle b(10);

    b.info();
    b.area();

    Rectangle r(12, 14);
    r.info();

    // test sans le virtual
    std::cout<<"*************************"<<std::endl;
    Shape* pa;
    // pa = &a;
    // pa->info();
    pa = &b;
    pa->info(); // on va appliquer la méthode de Shape à b
    // le virtual permet simplement de lui dire que ça peut être redéfini
    // polymorphisme dynamique du C++

    std::cout<<"*************************"<<std::endl;

    std::vector<Shape *> shapes(3,nullptr);

    shapes[0] = new Circle(5);
    shapes[1] = new Circle(2);
    shapes[2] = new Rectangle(4,5);


    for(int i=0; i<shapes.size(); i++){
        shapes[i]->info();
        
    }
    // ou : 
    for(auto x:shapes){
        (*x).info();
    }
    
    // std::vector<std::shared_ptr<Shape> > shapes2(3, nullptr);
    // shapes[0] = std::shared_ptr<Shape>(new Circle(5));
    // shapes[1] = std::shared_ptr<Shape>(new Circle(2));
    // shapes[2] = std::shared_ptr<Shape>(new Rectangle(4,5));
    
    // for(int i=0; i<shapes2.size(); i++){
    //     shapes2[i]->info();
    // }


    ((Rectangle*)shapes[2])->coucou();
    // ou c'est pareil
    static_cast<Rectangle*>(shapes[2])->coucou();
    // ou pas pareil
    dynamic_cast<Rectangle*>(shapes[2])->coucou();

    return 0;
}