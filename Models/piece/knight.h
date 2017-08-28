#ifndef KNIGHT_H
#define KNIGHT_H

#include <QObject>
#include "Models/board.h"
#include "piece.h"

namespace Models
{
    namespace piece
    {
        class Knight
        : public virtual Piece
                  , public QObject
        {
            Q_OBJECT
        public:
            Knight(board::Board &b, Position_t const &pos, Suit_t const &s, Class_t const &pc);
            explicit Rook(QObject *parent=nullptr);

            //canon
            Knight(QObject* parent = Q_NULLPTR);
            Knight(Knight& origin);
            Knight& operator=(Knight& src);
            ~Knight();


        protected:
            virtual void calcTrajectory() override;
        };
    }
}

#endif // KNIGHT_H
