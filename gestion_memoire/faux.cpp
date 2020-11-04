// dans le fichier faux.cpp
#include<iostream>

void push (int stack [], int* top, int token) {
   stack[*top] = token; 
   *top = *top + 1;
}
int pop (int stack [], int* top) {
  *top = *top - 1;
  return stack[*top];
}
// int main (int argc, char* argv []) {
//    int stack [argc];
//    int top = 0;
//    push(stack, &top, 12);
//    std::cout << pop(stack, &top) << std::endl;
//   return 0;
// }


int* init_stack (int n) {
  int* tab = new int [n];
  return tab; // mais c'est horrrrrible !!
}

int main (int argc, char* argv []) {
  int* stack = init_stack(argc);
  int top = 0;
  push(stack, &top, 12);
  std::cout << pop(stack, &top) << std::endl;
  return 0;
}