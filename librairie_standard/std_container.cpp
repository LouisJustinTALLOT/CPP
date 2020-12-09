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
    std::array<int, 10> array1 = {1,2,3,4,5};
    std::vector<int> vector1 = {1,2,3,4,5};
    std::vector<int> vector2(10);
    std::vector<int> vector3(10, 1);

    vector1.push_back(100);

    for (int i=0; i<vector1.size(); i++){

        std::cout<< "vector1["<<i<<"] = "<<vector1[i]<<std::endl;
    }

    for (auto x:vector3){
        std::cout<< x<<std::endl;

    }
    return 0;
}