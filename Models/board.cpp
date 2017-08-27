#include "board.h"


Board::Board(QObject *parent): QObject(parent)
{
    for(int i = 0; i < 8; i++){
        for(int j = 0; i < 8; i++){
            cases[i][j] = new Case(this, i, j);
        }
    }
}

Board::Board(Board &origin): QObject()
{
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            cases[i][j] = origin.cases[i][j];
        }
    }
}

Board &Board::operator=(Board &src)
{
    if(this != &src){
        for(int i = 0; i < 8; i++){
            for(int j = 0; j < 8; j++){
                cases[i][j] = src.cases[i][j];
            }
        }
    }
    return *this;
}

Board::~Board()
{
    for(int i = 0; i < 8; i++){
        qDeleteAll(cases.at(i));
    }
    delete this;
}


