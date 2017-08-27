#include "case.h"

Case::Case(QObject* parent, int row, int col):QObject(parent)
{
    this->row = row;
    this->col = col;
}
