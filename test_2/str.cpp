# include <iostream>

int main () {
  char str1 [] = "HELLO"; // naturellement pas besoin de mettre le '\0' en fin de chaîne !
  char str2 [] = {'H', 'E', 'L', 'L', 'O', '\0'}; // là on doit le mettre
  str1[0] ='W';
  str2[0] ='Y';
  std::cout << str1 << std::endl;
  std::cout << str2 << std::endl;
  return 0;
}