# include <iostream>
# include <cstdio>

// bool in_liste(char caractere_a_tester, char liste){

// // cette fonction va tester si un élément qu'on lui fournit est dans la liste fournie

//     int len = sizeof(liste)/sizeof(char);
//     for(int i = 0; i<len; i++){
//         if (liste[i] == caractere_a_tester){return true;}
//     }
//     return false;
    
// }

double pop(double*& stack, int& hauteur){  
    // fonction  qui dépile le stack et renvoie la valeur
    double res;
    res = stack[hauteur - 1];
    stack[hauteur -1];

    hauteur -= 1; 

    return res;
}

int main (int argc, char *argv []){
    char operateurs [] = {'!', 'x', '+', '-'};
    double stack [argc] ;
    int hauteur_du_stack = 0; // la hauteur est le numéro de la première case vide du stack
    char chaine_consideree [];

    for(int i=1; i<argc;i++){
        chaine_consideree = argv[i]; 
        if (chaine_consideree == "!") {  //soit le token est un opérateur
            double op_2 = pop(stack, hauteur_du_stack) ; //opérande 2 = 
            //opérande 1 = pop(du stack)
            //on fait l'opération en fonction de l'opérateur
            //on met le résultat dans le stack
        }
        else {  // soit c'est un opérande
            //on le push dans le stack
            stack[hauteur_du_stack] = atof(chaine_consideree);
            hauteur_du_stack += 1;

        }

    }

// on affiche le résultat final :
    printf(pop(stack, hauteur_du_stack));

    return 0;
}