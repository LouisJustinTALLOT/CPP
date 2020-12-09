#include <iostream>
#include <limits>
#include <stdexcept>

class Integer{
private: 
    int value; 
    int min; 
    int max; 
    bool isInBounds();

public: 

    Integer(const int& v, const int& vmin=std::numeric_limits<int>::min(), const int& vmax=std::numeric_limits<int>::max() );
    void incr(); 
    void decr(); 
    void print(); 
};