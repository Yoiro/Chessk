#ifndef QUEEN_H
#define QUEEN_H

#include <QObject>
#include "Models/board.h"
#include "piece.h"

namespace Models
{
    namespace piece
    {
        class Queen
        : public virtual Piece
          , public QObject
        {
            Q_OBJECT
        public:
            Rook(board::Board &b, Position_t const &pos, Suit_t const &s, Class_t const &pc);
explicit Rook(QObject *parent=nullptr);

            //canon
            Queen(QObject* parent = Q_NULLPTR);
            Queen(Queen& origin);
            Queen& operator=(Queen& src);
            ~Queen();

        protected:
            virtual void calcTrajectory() override;
        };
    }
}
#endif // QUEEN_H
