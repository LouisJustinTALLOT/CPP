#include <algorithm>

#include <vector>
#include <iostream>

int main(){



        
    // find

    auto x =    std::find(vec.begin(), vec.end(),  3);

    if (x != vec.end()){
        std::cout<<"ok"<<std::endl;
    }
    else{
        std::cout <<"pas ok" <<std::endl;
    }

}