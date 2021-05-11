#include <iostream>
#include <array>

#define GRID_TYPE std::array<std::array<int, GRID_SIZE_X>, GRID_SIZE_Y>
#define GRID_SIZE_X 4
#define GRID_SIZE_Y 2

// g++ game_of_life.cpp -o game_of_life

// il nous faut une vieille et une nouvelle grille

int main(){

    // std::array<std::array<int, GRID_SIZE_X>, GRID_SIZE_Y> main_grid;
    GRID_TYPE main_grid;


    for (int i=0; i<GRID_SIZE_Y; i++){
        for (int j=0; j<GRID_SIZE_X; j++){
            // std::cout<< main_grid[j][i]<<"|";
            std::cout<< 0 <<"|";
        }
        std::cout << std::endl;
    }
    // std::cout<<main_grid[0][1]<<std::endl;

    return 0;
}