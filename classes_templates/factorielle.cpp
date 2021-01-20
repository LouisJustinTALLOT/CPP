#include<iostream>
#include<vector>


std::vector<long unsigned int> table_fact = {};



long unsigned int factorielle(long unsigned int n, std::vector<long unsigned int>& table = table_fact){
    if (n==0){return 1;}


    if (n < table.size()){
        return table[n];
    }

    long unsigned int res;

    res = n * factorielle(n-1);

    table.push_back(res);

    return res;


}

int main(){

    std::cout << factorielle(50) <<std::endl;
}