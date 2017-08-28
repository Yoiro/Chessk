#ifndef PAWN_H
#define PAWN_H

#include <QObject>
#include "Models/board.h"
#include "piece.h"

namespace Models
{
    namespace piece
    {
        class Pawn
        : public virtual Piece
                  , public QObject
        {
            Q_OBJECT
        public:
            Pawn(board::Board &b, Position_t const &pos, Suit_t const &s, Class_t const &pc);
            explicit Pawn(QObject *parent=nullptr);

            //canon
            Pawn(Pawn& origin);
            Pawn& operator=(Pawn& src);
            ~Pawn();


        protected:
            virtual void calcTrajectory() override;
        };
    }
}

#endif // PAWN_H
