#include <iostream>

const int Xsize = 10;
const int Ysize = 10;

class Board {
    private:
        char universe[Xsize][Ysize];
        int generation;
    public:
        Board();
        void displayBoard();
        int getX();
        int getY();
        void placeLife(int x, int y);
        int livingNeighbors(int x, int y);
        void nextGeneration();
        int getGeneration();
        void commenceSim();
};

void Board::commenceSim(){
    //get number of original living cells

}

Board::Board(){
    for(int i = 0; i < getX(); i++){
        for(int j = 0; j < getY(); j++){
            universe[i][j] = '.';
        }
    }
    generation = 0;
}

void Board::nextGeneration(){
    for(int i = 0; i < getX(); i++){
        for(int j = 0; j < getY(); j++){
            //get number of neighbors for cell
            int neighbors = livingNeighbors(i, j);
            //if living cell
            if(universe[i][j] == 'X'){
                //kill cell if not having exactly 2 or 3 neighbors
                if(neighbors < 2)
                    universe[i][j] = '.';
                else if(neighbors > 3)
                    universe[i][j] = '.';
            }
            else{
                //revive dead cell if exactly 3 neighbors
                if(neighbors == 3)
                    universe[i][j] = 'X';
            }
        }
    }

    generation++; 
}

int Board::livingNeighbors(int x, int y){
    int neighbors = 0;

    if(universe[x-1][y+1] == 'X')
        neighbors++;
    if(universe[x][y+1] == 'X')
        neighbors++;
    if(universe[x+1][y+1] == 'X')
        neighbors++;
    if(universe[x-1][y] == 'X')
        neighbors++;
    if(universe[x+1][y] == 'X')
        neighbors++;
    if(universe[x-1][y-1] == 'X')
        neighbors++;
    if(universe[x][y-1] == 'X')
        neighbors++;
    if(universe[x+1][y-1] == 'X')
        neighbors++;
    
    return neighbors;
}

void Board::displayBoard(){
    for(int i = 0; i < getX(); i++){
        for(int j = 0; j < getY(); j++){
            std::cout << universe[i][j];
        }
        std::cout << std::endl;
    }
    std::cout << "Generation: " << getGeneration() << std::endl;
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

int Board::getGeneration(){
    return generation;
}