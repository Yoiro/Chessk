#include "move.h"


::move::Generator::MoveGenerator(Board* board)
{
    this->board = board;
}

bool ::move::Generator::isMoveLegal(Move* move)
{
    Case* destination = move->destination;
    Case* origin = move->origin;
    Piece* piece = move->piece;
    if(board->cases.count(destination) <= 0){
        return false;
    }
    //horizontal move
    if((destination->col - origin->col !=0) && origin->row == destination->row){
        if (King* k = dynamic_cast<King*>(piece)){
            if(destination->col - origin->col == 1){
                //Check if check, checkmate or enemy piece
            }
        }
        else if (Queen* q = dynamic_cast<Queen*>(piece)){
            //Check if check, checkmate or enemy piece
        }
        else if(Rook* r= dynamic_cast<Rook*>(piece)){
            //Check if check, checkmate or enemy piece
        }
    }
    //vertical move
    else if((destination->row - origin->row !=0) && origin->col == destination->col){
        if (King* k = dynamic_cast<King*>(piece)){
            if(destination->col - origin->col == 1){
                //Check if check, checkmate or enemy piece
            }
        }
        else if (Queen* q = dynamic_cast<Queen*>(piece)){
            //Check if check, checkmate or enemy piece
        }
        else if(Rook* r= dynamic_cast<Rook*>(piece)){
            //Check if check, checkmate or enemy piece
        }
        else if(Pawn* p = dynamic_cast<Pawn*>(piece)){
            //Check if check, checkmate or enemy piece
        }
    }
    //diagonal move - some other special move
    else if((destination->row - origin->row !=0) && destination->col - origin->col !=0){
        if (King* k = dynamic_cast<King*>(piece)){
            if(destination->col - origin->col == 1){
                //Check if check, checkmate or enemy piece
            }
        }
        else if (Queen* q = dynamic_cast<Queen*>(piece)){
            //Check if check, checkmate or enemy piece
        }
        else if (Bishop * b = dynamic_cast<Bishop*>(piece)){
            //Check if check, checkmate or enemy piece
        }
        else if (Knight* k = dynamic_cast<Knight*>(piece)){
            //Check if check, checkmate or enemy piece
        }
        else if(Pawn* p = dynamic_cast<Pawn*>(piece)){
            //Check if check, checkmate or enemy piece
        }
    }
}

move::Move::Move(Piece *piece, Case *origin, Case *destination)
{
    this->piece = piece; this->origin = origin; this->destination = destination;
}

move::Move::Move(move::Move &origin)
{
    this->piece = new Piece(origin.piece);
    this->origin = new Case(origin.origin);
    this->destination = new Case(origin.destination);
}

move::Move::execute()
{
    if(Generator::isMoveLegal(this)){
        //move the piece
    }
}


