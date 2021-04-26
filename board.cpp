#include <iostream>

const int Xsize = 50;
const int Ysize = 50;

class Board {
    private:
        char universe[Xsize][Ysize];
    public:
        Board();
        void displayBoard();
        int getX();
        int getY();
        void placeLife(int x, int y);
        int livingNeighbors(int x, int y);
};

Board::Board(){
    for(int i = 0; i < getX(); i++){
        for(int j = 0; j < getY(); j++){
            universe[i][j] = '.';
        }
    }
}

void Board::displayBoard(){
    for(int i = 0; i < getX(); i++){
        for(int j = 0; j < getY(); j++){
            std::cout << universe[i][j];
        }
        std::cout << std::endl;
    }
}

int Board::getX(){
    return Xsize;
}

int Board::getY(){
    return Ysize;
}

void Board::placeLife(int x, int y){
    if(x < getX() && x < getY())
        universe[x][y] = 'X';
}