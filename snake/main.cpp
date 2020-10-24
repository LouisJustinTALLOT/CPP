#include <iostream>
#include "sys/ioctl.h"

#include "stdlib.h"

#include "config.h"
#include "internals.h"
#include "display.h"
#include "food.h"

#include <cstdio>
#include <string>

void test_debug(char * chaine = "ici"){
    printf(chaine);
    printf("\n");
    std::cin.get();
}

void print_chiffre(int chiffre){
    std::cout << std::to_string(chiffre) << std::endl;
}
void print_chiffre(double chiffre){
    std::cout << std::to_string(chiffre) << std::endl;
}

void backgroundSetup(const int nx, const int ny, int* bg ){             

    for (int i = 0; i < nx ; i++){
        for(int j = 0; j < ny; j++){
           
        //    print_chiffre(i);
        //    print_chiffre(j);

            if (i == 0 or i+1 == nx){
                bg[i + j * nx] = 1;
            }
            if (j == 0 or j+1 == ny){
                bg[i + j * nx] = 1;
            }
      }
    }
}


void add_snake( int* snake,int*  bg, int snl,const int nx, const int ny ){
    // met le nouveau serpent en entier dans background

    // test_debug("dans add snake");

    for (int i = 0; i < snl; i++){
        bg[snake[i] + snake[i + SNAKE_LEN] * nx] = 3; // on met un serpent aux bons endroits
        // print_chiffre(i);
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
    // test_debug("setupsnake"); // ok ça marche aussi
}

void update_snake_coordinates(int* snake, int snl, int* dxdy ){
    // met dans snake les nouvelles coordonnées
    for (int i  = snl; i >= 1; i--){
        // on décale toutes les cases sauf la dernière que l'on écrase
        snake[i] = snake[i-1]; 
        snake[i + SNAKE_LEN] = snake[i + SNAKE_LEN -1];
    }

    // puis on update la première avec dxdy
    snake[0] = snake[0] + dxdy[0];
    snake[SNAKE_LEN] = snake[SNAKE_LEN] + dxdy[1];
}

void startGame(const int& lap, const int& nx, const int& ny, int& snl, int* snake, int* bg){
    char key;
    int dxdy[2] = {1,0};
    int food[2] = {0,0};

    createFood( bg, food, nx, ny );

    // test_debug("après create food"); // c'est bon

    while( true ){
        internal::frameSleep(lap);
        if( internal::keyEvent() ){
            std::cin >> key; 
            snake_movement(key, dxdy);
        }

        // test_debug("après mouvment"); // c'est bon

        backgroundClear();
        // test_debug("après bg_clear"); //c'est bon

        add_snake( snake, bg, snl, nx, ny );
        // test_debug("après add snake");

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

    // printf("là \n");
 
    for( int i=0; i<nx*ny; i++){
        // std::cout<<i<<"\n";
        background[i] = -1;
    }
    int snake[2*SNAKE_LEN];

    // std::cin.get(); 
    // printf("début \n");
    // test_debug("teeeeeest");

    backgroundSetup(nx, ny, background);

  
    // printFrame(nx, ny, background);
    // test_debug("bg setup fait"); // ok ça ça marche

    setupSnake(snake, snake_len);
    // test_debug("après setup snake"); // on arrive bien là :)

    startGame(lap, nx, ny, snake_len, snake, background);

}



