#ifndef PAWN_H
#define PAWN_H

#include <QObject>

class Pawn : public QObject
{
    Q_OBJECT
public:
    explicit Pawn(QObject *parent = nullptr);

signals:

public slots:
};

#endif // PAWN_H