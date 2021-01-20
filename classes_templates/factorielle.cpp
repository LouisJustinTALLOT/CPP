#include<iostream>
#include<vector>
#include<chrono>

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
    auto start = std::chrono::steady_clock::now();

    int N = 10000000;

    for(int i = 0; i<N; i ++){
        factorielle(50);   
    }


    std::cout << factorielle(50) <<std::endl;

    auto end = std::chrono::steady_clock::now();

    auto milis = std::chrono::duration_cast<std::chrono::nanoseconds>(end-start).count();

    std::cout<<"durée de "<<milis << " nanosecondes"<<std::endl;
    return 0;
}