#include "Integer.h"


bool Integer::isInBounds(){
    return (this->value <= this->max) && (this->value >= this->min );
}

Integer::Integer(const int& v, const int& vmin, const int& vmax): value(v), min(vmin), max(vmax){
    if( !this->isInBounds()){
        throw std::runtime_error("Invalid initialization");
    }
}

void Integer::incr(){
    this->value += 1; 
    if( !this->isInBounds() ){
        throw std::runtime_error("Invalid value after Integer::incr");
    }
}

void Integer::decr(){
    this->value -= 1; 
    if( !this->isInBounds() ){
        throw std::runtime_error("Invalid value after Integer::incr");
    }
}

void Integer::print(){
    std::cout << "Integer with value " << this->value << " and bounds [" << this->min << ", " << this->max << "]" << std::endl;
}

