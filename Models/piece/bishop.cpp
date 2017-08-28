#include "bishop.h"

#include <initializer_list>

namespace Models {

    namespace piece {

        static auto BishopRegistration = board::Board::registerPieceClass // a implementer
        (
            "Bishop",
            [](board::Board &b,board::Board::Position_t const &p, board::Board::Suit const &s)
                ->board::Board::Pieces_t::value_type
                {
                    return board::Board::Pieces_t::value_type(new Bishop(b,p,s, "Bishop"));
                }
        );

        Bishop::Bishop(QObject *parent,board::Board &b,Position_t const &pos_,Suit_t const &s_,Class_t const &pc)
            :Piece{b,pos_,s_,pc}
            ,QObject(parent)
        {

        }

        void Bishop::calcTrajectory()
        {
            //Bishop can move infinitly in the four diagonal directions
            using Dir = util::Direction;
            for(Dir d: {Dir::NorthEast
                        ,Dir::SouthEast
                        ,Dir::SouthWest
                        ,Dir::NorthWest})
           {
                Position_t t;
                for(signed i=1; board.valid(t=Position_t(pos).move(d,i));i++)
                {
                    addCapturing(t);
                    if(!board.occupied(t))
                    {
                        addTrajectory(t);
                    }
                    else break; //cant jump over pieces
                }
            }
        }


    }

}

