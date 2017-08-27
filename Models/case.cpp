#include "case.h"

Case::Case(QObject* parent, int row, int col):QObject(parent)
{
    this->row = row;
    this->col = col;
}

Case::Case(Case &origin): QObject()
{
    this->row = origin.row;
    this->col = origin.col;
}

Case &Case::operator=(Case &src)
{
    if(this != &src){
        this->row = src.row;
        col = src.col;
    }
    return *this;
}

Case::~Case()
{
    delete this;
}
