#include <iostream>
#include "sudoku_board.h"
#include "sudoku.h"

int main(){

try{
    Sudoku s = Sudoku("c:\\users\\magda\\desktop\\board.txt");
    std::cout<<"podaj level na jakim chcesz grac [1-3]\n> ";
    int l;
    std::cin>>l;
    s.play(l);
}
catch(std::string* e){
    std::cout<<"EXCEPTION: "<<(*e)<<std::endl;
}

}
