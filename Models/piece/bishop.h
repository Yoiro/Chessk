#ifndef BISHOP_H
#define BISHOP_H

#include <QObject>

class Bishop : public QObject
{
    Q_OBJECT
public:
    explicit Bishop(QObject *parent = nullptr);

signals:

public slots:
};

#endif // BISHOP_H