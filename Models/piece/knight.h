#ifndef KNIGHT_H
#define KNIGHT_H

#include <QObject>

class Knight : public QObject
{
    Q_OBJECT
public:
    explicit Knight(QObject *parent = nullptr);

signals:

public slots:
};

#endif // KNIGHT_H