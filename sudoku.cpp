#include "sudoku.h"
#include "sudoku_board.h"
#include <iostream>

Sudoku::Sudoku(string filename)
: board(filename){
}

Sudoku::Sudoku()
: board(){ 


}



Sudoku::~Sudoku(){


}

void Sudoku::init(int level){
//do some random field deletions

}

void Sudoku::play(int level){
    int x,y,val;

    init(level);

    while(!board.isFull()){
        std::cout<<"zapelniono: "<<board.counter()<<"\n";
        board.print();
        
        std::cin>>x;
        std::cin>>y;
        std::cin>>val;
        board.set(x,y,val);
        std::cin.clear();
        std::cin.sync();
    }


}

