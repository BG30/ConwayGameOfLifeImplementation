#include <iostream>
#include "board.cpp"

int main(){
    Board board =  Board();
    
    board.placeLife(0,0);
    board.placeLife(0,1);
    board.placeLife(1,0);
    board.placeLife(1,1);
    board.displayBoard();
    board.nextGeneration();
    board.displayBoard();


    return 0;
}