#include "piece.h"


#include <algorithm>
#include <iostream>

Piece::Piece(QObject *parent,board::Board &b,Postion_t const &pos_,Suit_t const &s_,Class_t const &pc)
    : QObject(parent)
    ,board(b)
    ,p{pos_}
    ,s{s_}
    ,c{pc}
{

std::clog<<"Cration of "<< *this << std::endl;

void Piece::addTrajectory(Position_t const &case)
{
    board.pieceTrajactories().add(*this,tile);
}





}


