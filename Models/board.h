#ifndef BOARD_H
#define BOARD_H

#include "case.h"
#include <QList>
#include <QObject>

class Board: public QObject
{
    Q_OBJECT
public:
    //args
    Case* cases[8][8];

    //canon
    Board(QObject* parent = Q_NULLPTR);
    Board(Board& origin);
    Board& operator=(Board& src);
    ~Board();
};

#endif // BOARD_H
