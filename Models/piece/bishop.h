#ifndef BISHOP_H
#define BISHOP_H

#include <QObject>
#include "Models/board.h"
#include "piece.h"

namespace Models
{
    namespace piece
    {
        class Bishop
        : public virtual Piece
                  , public QObject
        {
            Q_OBJECT
        public:
            Bishop(board::Board &b, Position_t const &pos, Suit_t const &s, Class_t const &pc);
            explicit Bishop(QObject *parent=nullptr);

            //canon
            Bishop(QObject* parent = Q_NULLPTR);
            Bishop(Bishop& origin);
            Bishop& operator=(Bishop& src);
            ~Bishop();

        protected:
            virtual void calcTrajectory() override;
        };
    }
}

#endif // BISHOP_H
