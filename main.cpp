#include <iostream>
#include "board.cpp"
using namespace std;

int main(){
    Board board =  Board();
    
    board.placeLife(0,0);
    board.displayBoard();
     
    return 0;
}