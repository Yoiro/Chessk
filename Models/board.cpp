#include "board.h"


Board::Board(QObject *parent): QObject(parent)
{
    for(int i = 0; i < 8; i++){
        for(int j = 0; i < 8; i++){
            cases[i][j] = new Case(this, i, j);
        }
    }
}

Board::Board(Board &origin)
{
    this->cases = origin.cases;
}

Board &Board::operator=(Board &src)
{
    if(this != &src){
        this->cases = src.cases;
    }
    return *this;
}

Board::~Board()
{

}


