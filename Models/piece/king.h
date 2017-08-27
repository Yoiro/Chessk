#ifndef KING_H
#define KING_H

#include <QObject>

class King : public QObject
{
    Q_OBJECT
public:
    explicit King(QObject *parent = nullptr);

signals:

public slots:
};

#endif // KING_H