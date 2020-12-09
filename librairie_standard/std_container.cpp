// std::array
// std::vector
// std::set
// std::map
// std::stack
//std::queue

#include <array>
#include <vector>
#include <iostream> 
#include <set>
#include <map>


class Integer {

private:
    int _value;
    int _min;
    int _max;

public: 
    Integer(): _value(0){}
    Integer(const int& x): _value(x){}
    Integer(const int& x, const int& a, const int& b): _value(x), _min(a), _max(b){
    }

    void print() const {
        std::cout << "Value = " << this->_value << std::endl;
    }

    static void coucou(){
        std::cout << "Une methode statique " << std::endl;
    }

    bool operator<(const Integer& other) const {
        return this->_value < other._value ;
    }

};

int main(){
    return 0;
}