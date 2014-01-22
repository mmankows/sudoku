#include "sudoku.h"
#include "sudoku_board.h"
#include <iostream>

Sudoku::Sudoku(string filename)
: initialBoard(filename){
this->board = initialBoard;  //copy board's state at the beginning of game,
                             //to check if we dont modify constant values
}

Sudoku::Sudoku()
: initialBoard(), board(){ 


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
        clearScr();
        std::cout<<"zapelniono: "<<board.counter()<<"\n";
        board.print(" ",initialBoard);
        
        std::cin>>x;
        std::cin>>y;
        std::cin>>val;
    
        try{
            if(cin.fail())
                throw new string("User input error!\n");
            if(initialBoard.get(x,y)==0){ //if we modify 'editable' field
                board.set(x,y,val);
            }
            else{
                std::cout<<"WARNING: Non editable field. Press <ENTER>\n";
                std::cin.get();
            }
            std::cin.ignore(256,'\n'); //if user typed to many digits ignore it    
        }
        catch(string *e) {     //idiot-proof behavior on crazy inputs like : dksado 1 2 12 120
            std::cout<<"input shout be like: x-field y-field value <ENTER>\n";
            std::cin.clear();  //clear error flags
            std::cin.ignore(256,'\n'); //throw out if some data in the buffer
            std::cin.sync();   //prepare stream
        }
    }


}

