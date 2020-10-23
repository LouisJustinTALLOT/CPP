#include <iostream>
#include "sys/ioctl.h"

#include "stdlib.h"

#include "config.h"
#include "internals.h"
#include "display.h"
#include "food.h"


void backgroundSetup(const int nx, const int ny, int* bg ){             

    for (int i = 0; i < nx ; i++){
        for(int j = 0; j < ny; j++){
            if (i == 0 or i+1 == nx){
                bg[i + j * nx] = 1;
            }
            if (j == 0 or j+1 == ny){
                bg[i + j * nx] = 1;
            }
      }
    }
}

void add_snake( int* snake,int*  bg, int snl,const int& nx, const int& ny ){
    // met le nouveau serpent en entier dans background
    for (int i = 0; i < SNAKE_LEN; i++){
        bg[snake[i] + snake[i + SNAKE_LEN] * nx] = 3; // on met un serpent aux bons endroits
    }     
}


void remove_snake(int* snake,int* bg,int& snl,const int nx, const int ny){
    // vire tout sauf la pomme
    // on va juste parcourir le tableau bg en remplaçant les 3 par des -1 ...
    for (int i = 0; i < nx * ny; i++ ){
        if (bg[i] == 3){
            bg[i] = -1;   // on remplace un endroit où il y a un serpent par du blanc
        }
    }
}

void snake_movement(char key, int* dxdy){
    // remplit dxdy en fonction de key
    // attention c'est inversé car l'axe des y est descendant
    if (key == 'z'){
        // on va en haut
        dxdy[0] = 0;
        dxdy[1] = -1;
    }
    else if (key ==  's'){
        // on va en bas
        dxdy[0] = 0;
        dxdy[1] = 1;
    }
    else if (key == 'q'){
        // on va à gauche
        dxdy[0] = -1;
        dxdy[1] = 0;
    }
    else if (key == 'd'){
        // on va à droite 
        dxdy[0] = 1; 
        dxdy[1] = 0;
    }
    else if (key == 'm'){
        // on décide de sortir du jeu
        std::cerr << "" << std::endl;
            exit(1);
    }
}

bool verifyBorder( int* snake, const int nx, const int ny ){
    // retourne true si le serpent est sorti, false si il est toujours dans les bornes
    if (snake[0] <= 0 or snake[0] >= nx-1){
        return true;
    }
    if (snake[SNAKE_LEN] <= 0 or snake[SNAKE_LEN] >= ny-1){
        return true;
    }
    return false;
}

void setupSnake( int* snake, int snake_len ){
    for(int i =0; i < snake_len; i++){
        snake[i] = i + 4;
        snake[ i + SNAKE_LEN ] = 4;
    }
}

void update_snake_coordinates(int* snake, int snl, int* dxdy ){
    // met dans snake les nouvelles coordonnées
 
}

void startGame(const int& lap, const int& nx, const int& ny, int& snl, int* snake, int* bg){
    char key;
    int dxdy[2] = {1,0};
    int food[2] = {0,0};

    createFood( bg, food, nx, ny );

    while( true ){
        internal::frameSleep(lap);
        if( internal::keyEvent() ){
            std::cin >> key; 
            snake_movement(key, dxdy);
        }
        backgroundClear();
        add_snake( snake, bg, snl, nx, ny );
        printFrame(nx, ny, bg);
        remove_snake(snake, bg, snl, nx, ny);
        bool out =  verifyBorder(snake, nx, ny);
        if( out == true){   // le serpent est alors sorti de l'aire définie
            std::cerr << "" << std::endl;
            exit(1);
        }
        bool eat = eatFood(food, snake);
        if(eat){
            createFood(bg, food, nx, ny);
            snl++;
        }
        update_snake_coordinates(snake, snl, dxdy);

    }
}



int main(){
    const int nx = 50;
    const int ny = 25;
    const int lap=200;

    int snake_len = 3;
    int background[nx*ny] ;
    for( int i=0; i<nx*ny; i++){
        background[i] = -1;
    }
    int snake[2*SNAKE_LEN];

    backgroundSetup(nx, ny, background);
    setupSnake(snake, snake_len);


    startGame(lap, nx, ny, snake_len, snake, background);

}



