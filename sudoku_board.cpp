#include "sudoku_board.h"
#include <iostream>
#include <fstream>

/* Private member, alocates matrix for sudoku board
 * val - value to be assigned to every entry, default 0
 */
int** SudokuBoard::init(int val){
    int** newtab = new int*[9];
    for(int i=0; i<9; i++){
        newtab[i] = new int[9];
        for(int j=0; j<9; j++)
            newtab[i][j] = val;
    }   
return newtab;
}

/* Constructor
 * filename - name of file containing space separated 9x9 matrix
 *            representing sudoku board
 *  only puts values into fields, requires previous mem alloc by init
 */

bool SudokuBoard::loadFromFile(string filename){

    std::fstream fs(filename.c_str(), std::fstream::in);
    
    if(!fs.is_open() || !fs.good())
        return false;
   
    int k=0;
    for(int i=0;k<81 && !fs.eof() ; k++ ){
        int val;
        fs>>val;
        set(i,k%9,val);
        if(k>0 && !(k%9)) //i increments only after 9 new records in
            i++;
    }
    if(k!=81){
        std::cout<<"Nie wczytano wszystkich wyrazów";
        return false;
    }
    fs.close();

return true;
}


/* Default constructor, initializing board with zeros
 */
SudokuBoard::SudokuBoard(){
    this->tab = init();
}

SudokuBoard::SudokuBoard(string filename){
    this->tab = init();
    if(!loadFromFile(filename))
        throw new string("Can't read file, terminating.");
}

SudokuBoard::SudokuBoard(const SudokuBoard& tocopy){

    this->c     = tocopy.c;
    this->level = tocopy.level;
    this->tab   = copyTab(tocopy.tab);

}
/* Destructor, clears board
 */
SudokuBoard::~SudokuBoard(){
    clear(this->tab);
}

/* sets x,y field with value
 *
 * x - vertical
 * y - horizontal
 * val - value to assign
 */
bool SudokuBoard::set(int x, int y, int val){
    if(x<9 && y<9 && x>=0 && y>=0){
        int current = tab[x][y];
        if(!current && val ) //if field was 'empty'
            this->c++;
        else if(current && !val) //if we delete
            this->c--;
        tab[x][y] = val;
        }
    else return false;
    
    return true;
}

/* similar to set, returns value at given field
 * x - vertical
 * y - horizontal
 * return 0-9 value if valid, -1 if x,y out of board
 */
int SudokuBoard::get(int x, int y) const{
    if(x<9 && y<9 && x>=0 && y>=0)
        return tab[x][y];
    else 
        return -1;
}

/* prints the board
 * sep - separator
 */
void SudokuBoard::print(string sep) const{
    
    std::cout<<"___________________\n";
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++)
            std::cout<<sep<<get(i,j);
    std::cout<<sep<<"#\n";
    }
    std::cout<<"####################\n";
}

bool SudokuBoard::isValid(void) const {
    if(!isFull()) 
        return  false;
    
    //sum -- and | directions
    int sum_h = 0;
    int sum_v = 0;
    for(int i=0; i<9; i++){
        for(int j=0 ; j<9; j++){
            sum_h+= get(i,j);
            sum_v+= get(j,i);
        }
        if(sum_h != 45 || sum_v != 45)       //1+2+3+4+5+6+7+8+9
            return false;
        else{
        sum_h = sum_v = 0;
        }
    }
return true;
}

SudokuBoard& SudokuBoard::operator=(SudokuBoard board){
    if(&board == this) //self-assignment a=a
        return *this;

    this->c = board.c;
    this->level = board.level;
    clear(this->tab);
    this->tab = copyTab(board.tab);
return *this;
}

void SudokuBoard::clear(int** ptr){
    for(int i=0; i<9; i++)
        delete [] ptr[i];
    delete[] ptr;
}

int**  SudokuBoard::copyTab(int** ctab){
    int** newtab = init();
     
     for(int i=0 ; i<9; i++)
        for(int j=0; j<9; j++)
            newtab[i][j] = ctab[i][j];

return newtab;
}
