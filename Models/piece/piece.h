#ifndef PIECE_H
#define PIECE_H

#include <QObject>

class Piece : public QObject
{
    Q_OBJECT
public:
    explicit Piece(QObject *parent = nullptr);

signals:

public slots:
};

#endif // PIECE_H