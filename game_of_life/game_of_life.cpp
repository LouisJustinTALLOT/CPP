#include <iostream>
#include <vector>
#include <algorithm>
#include <unistd.h>

#define GRID_SIZE_X 20
#define GRID_SIZE_Y 20

// g++ game_of_life.cpp -o game_of_life


int old_grid[GRID_SIZE_Y][GRID_SIZE_X];
int new_grid[GRID_SIZE_Y][GRID_SIZE_X];

int decision(int somme_environnante, int etat_actuel){
    if (etat_actuel == 0){
        if (somme_environnante == 3){
            return 1;
        } else {
            return 0;
        }
    } else {
        if (somme_environnante <2 or somme_environnante >3){
            return 0;
        } else {
            return 1;
        }
    }
}


void game_of_life(){
    // on va calculer la nouvelle grille puis échanger

    for (int i=0; i<GRID_SIZE_Y; i++){
        for (int j=0; j<GRID_SIZE_X; j++){
            int sum = old_grid[j][(i-1)%GRID_SIZE_Y]
                    + old_grid[j][(i+1)%GRID_SIZE_Y]
                    + old_grid[(j-1)%GRID_SIZE_X][i] 
                    + old_grid[(j+1)%GRID_SIZE_X][i] 
                    + old_grid[(j-1)%GRID_SIZE_X][(i-1)%GRID_SIZE_Y] 
                    + old_grid[(j+1)%GRID_SIZE_X][(i+1)%GRID_SIZE_Y] 
                    + old_grid[(j-1)%GRID_SIZE_X][(i+1)%GRID_SIZE_Y] 
                    + old_grid[(j+1)%GRID_SIZE_X][(i-1)%GRID_SIZE_Y] ;

            new_grid[j][i] = decision(sum, old_grid[j][i]);
        }
    }

    std::swap(old_grid, new_grid);
}


// il nous faut une vieille et une nouvelle grille

int main(){


    for (int i=0; i<GRID_SIZE_Y; i++){
        for (int j=0; j<GRID_SIZE_X; j++){
            old_grid[j][i] = 0;
            new_grid[j][i] = 0;
        }
    }

    // valeurs initiales
    // old_grid[2][1] = 1;
    // old_grid[2][2] = 1;
    // old_grid[2][3] = 1;

    old_grid[0][0] = 1;
    old_grid[9][9] = 1;


    old_grid[7][1] = 1;
    old_grid[7][2] = 1;
    old_grid[7][3] = 1;
    old_grid[5][2] = 1;
    old_grid[6][3] = 1;
    return 0;
}