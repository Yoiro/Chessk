#ifndef QUEEN_H
#define QUEEN_H

#include <QObject>

class Queen : public QObject
{
    Q_OBJECT
public:
    explicit Queen(QObject *parent = nullptr);

signals:

public slots:
};

#endif // QUEEN_H