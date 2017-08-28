#ifndef ROOK_H
#define ROOK_H

#include <QObject>
#include "Models/board.h"
#include "piece.h"

namespace Models
{
    namespace piece
    {
        class Rook
        : public virtual Piece
        , public QObject
        {
        Q_OBJECT
        public:
            Rook(board::Board &b, Position_t const &pos, Suit_t const &s, Class_t const &pc);
            explicit Rook(QObject *parent=nullptr);

            //canon
            Rook(QObject* parent = Q_NULLPTR);
            Rook(Rook& origin);
            Rook& operator=(Rook& src);
            ~Rook();


        protected:
            virtual void calcTrajectory() override;
        };
    }
}

#endif // ROOK_H
