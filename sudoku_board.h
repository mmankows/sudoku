#ifndef SUDOKU_BOARD_H
    #define SUDOKU_BOARD_H
    #include <string>

using namespace std;
class SudokuBoard {

private:
    int** tab;
    unsigned level;
    int c; //counter
    bool loadFromFile(string filename);
    int** init(int val=0);
    int** copyTab(int** ptr ); //copy board fields
    void clear(int** ptr);
public:
    
    SudokuBoard();
    SudokuBoard(const SudokuBoard &); //copy constr
    SudokuBoard(string filename);
    ~SudokuBoard();

    SudokuBoard& operator=(SudokuBoard board);
    int counter(void) const  { return c;}
    bool set(int x,int y, int val);
    int  get(int x, int y) const;
    bool isFull(void) const { return (counter()==81);} //all 81 fields filled
    bool isValid(void) const;
    void print(string sep=" ",SudokuBoard noneditable=SudokuBoard()) const; //if noneditable board pattern specified
                                                                   //prints some fields in specil way

};

 

 #endif
