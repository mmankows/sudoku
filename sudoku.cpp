#include "sudoku.h"
#include "sudoku_board.h"
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <ctime>

const int* Sudoku::level = new int[3]{50,35,25} ; //number of fields 
                                                  //to be left at
                                                  //given level

Sudoku::Sudoku(string filename)
: initialBoard(filename) {


this->board = initialBoard;  //copy board's state at the beginning of game,
                             //to check if we dont modify constant values
}

Sudoku::Sudoku()
: initialBoard(), board(){ 

}



Sudoku::~Sudoku(){

}

void Sudoku::init(int l){
//do some random field deletions
    srand(time(0));
    while(board.counter() != level[l] ){
        int x = rand()%9;
        int y = rand()%9;
        
        if(board.get(x,y)) //jak nie bylo puste
            board.set(x,y,0);
    }
    
    initialBoard = board;
}

void Sudoku::play(int level){
    int x,y,val;
    if(level>0 && level<4)
        init(level-1); //to fit c++ adressing with base 0
	
	while(1) { 
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
		if(board.isValid()) {
		    clearScr();
		    board.print();
			std::cout<<"WYGRAŁEŚ!!!\n";
			break;
		}
		else {
			std::cout<<"Zle, popraw. Nacisnij ENTER";
			getchar();
			board.set(x,y,0);
		}
	}


}

