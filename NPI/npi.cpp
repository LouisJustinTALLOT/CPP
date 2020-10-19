# include <iostream>
# include <cstdio>
# include <vector>

void afficher_stack(std::vector<double> stack){
    for (long unsigned int i = 0; i< stack.size(); i++)
        {std::cout<<stack[i]<<std::endl;}
    // std::cout << stack.size() << "size" <<std::endl;
    printf("\n");
}

int main(int argc, char *argv []){ 
    // argc le nombre d'arguments incluant le nom du programme
    // argv ces arguments
    std::vector<double> stack;
    std::cout<<"argc  "<<argc<<std::endl;

    for (int i = 1; i < argc ; i++){
        std::cout<<"i =  "<<i<<std::endl;
        std::cout<<"arg = "<<argv[i]<<std::endl;
        
        // std::cout <<"vérité " << (argv[i][0] == "+"[0]) <<"\n" ;


        if (argv[i][0] == '!'){
            stack[stack.size() -1] *= -1;
        }
        else if (argv[i][0] == "+"[0]){
            printf("là \n");
            double op_2 = stack[stack.size() - 1];
            stack.pop_back();
            stack[stack.size()-1] += op_2;
        }
        else if (argv[i][0] == 'x')
        {
            double op_2 = stack[stack.size() - 1];
            stack.pop_back();
            stack[stack.size()-1] *= op_2;
        }
        else if (argv[i][0] == '-')
        {
            double op_2 = stack[stack.size() - 1];
            stack.pop_back();
            double op_1 = stack[stack.size() - 1];
            stack.pop_back();
            
            stack.push_back(op_1 - op_2);
        }
        else if (argv[i][0] == '/')
        {
            double op_2 = stack[stack.size() - 1];
            stack.pop_back();
            double op_1 = stack[stack.size() - 1];
            stack.pop_back();
            
            stack.push_back(op_1/op_2);
        }
        else
        {
            stack.push_back(atof(argv[i]));
        }
        afficher_stack(stack);
    } 
    std::cout << stack[0] << std::endl; 
    
    return 0;
}