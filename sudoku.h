#ifndef SUDOKU_H
    #define SUDOKU_H
    #include "sudoku_board.h"
    #include <iostream>

class Sudoku{

private:
    static const int* level; //number of fields to be deleted
    
    SudokuBoard board;
    SudokuBoard initialBoard; //copy of board used to check if we dont modify fields from file

    //prints lot of spaces to clear screen, adjust number to look good, uses default arg 20
    void clearScr(int num=20) { for(int i=0;i<num;i++) std::cout<<std::endl;  }; 
public:
    Sudoku();
    Sudoku(string filename);
    ~Sudoku();
    void init(int level);
    void play(int level);

};


#endif
