#ifndef KING_H
#define KING_H

#include <QObject>
#include "Models/board.h"
#include "piece.h"

namespace Models
{
    namespace piece
    {
        class King
        : public virtual Piece
                  , public QObject
        {
            Q_OBJECT
        public:
            King(board::Board &b, Position_t const &pos, Suit_t const &s, Class_t const &pc);
            explicit King(QObject *parent=nullptr);

            //canon
            King(King& origin);
            King& operator=(King& src);
            ~King();


        protected:
            virtual void calcTrajectory() override;
        };
    }
}
#endif // KING_H
