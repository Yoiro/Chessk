#ifndef MOVEGENERATOR_H
#define MOVEGENERATOR_H

#include "Models/piece/piece.h"
#include "Models/piece/king.h"
#include "Models/piece/queen.h"
#include "Models/piece/bishop.h"
#include "Models/piece/knight.h"
#include "Models/piece/pawn.h"
#include "Models/piece/rook.h"

namespace move {

    class Generator{
    private:
        Board* board;
    public:
        Generator(Board* board = new Board());
        bool isMoveLegal(Move* move);
    };

    class Move{
    private:
        Piece* piece;
        Case* destination;
        Case* origin;
    public:
        Move(Piece* piece, Case* origin, Case* destination);
        Move(Move& origin);
        execute();
    };
}

#endif // MOVEGENERATOR_H
