#include <iostream>
#include "sudoku_board.h"
#include "sudoku.h"

int main(){

try{
    Sudoku s = Sudoku("board.txt");
    s.play(1);
}
catch(std::string* e){
    std::cout<<"EXCEPTION: "<<(*e)<<std::endl;
}

}
