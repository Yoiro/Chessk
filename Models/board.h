#ifndef BOARD_H
#define BOARD_H

#include "case.h"
#include <QList>

class Board: public QObject
{
    Q_OBJECT
public:
    Board(QObject* parent = Q_NULLPTR);
    Board(Board& origin);
    Board& operator=(Board& src);
    ~Board();

    Case cases[8][8];
};

#endif // BOARD_H
