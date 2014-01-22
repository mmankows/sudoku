#ifndef SUDOKU_H
    #define SUDOKU_H
    #include "sudoku_board.h"

class Sudoku{

private:
    static const int L1 = 30; //variables holding number of field to cover
    static const int L2 = 50;
    static const int L3 = 65;
    SudokuBoard board;
    
    bool getCommand();
    bool validate();


public:
    Sudoku();
    Sudoku(string filename);
    ~Sudoku();
    void init(int level);
    void play(int level);

};


#endif
