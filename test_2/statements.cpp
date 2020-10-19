#include <iostream>
int main () {
//   int i = 0;
//   std::cout << "entrez un entier: ";
//   std::cin >> i;
//   if (i == 0)
//     std::cout << "je suis nul\n";
//   else if (i%2 == 0) 
//     std::cout << "je suis pair\n";
//   else 
//     std::cout << "je suis impair\n";


//   char c = '\0';
//   std::cout << "entrez un caractère: ";
//   std::cin >> c;
//   switch (c) {
//   case 'a':
//     std::cout << "je suis 'a'\n";
//     break;
//   case 'b':
//     std::cout << "je suis 'b'\n";
//     break; 
//   case 'c':
//     std::cout << "je suis 'c'\n";
//     break;  
//   default:
//     std::cout << "défaut\n";

  // char c = '\0'; // j'initialise une variable
  //                // de type char avec le caractère null

  // do { // tant que ce caractère n'est pas 'q'
  //   std::cin >> c;   // je lis un caractère
  //   std::cout << c << std::endl; // je l'affiche
  // }while (c != 'q') ;

  int tab [] {1, 2, 3, 4, 5, 6};
  for (int i = 0; i < 6; i++)
    std::cout << tab[i] << std::endl;
    
  for (auto e : tab){
    std::cout << e<<std::endl;
  }
  
  return 0;
}