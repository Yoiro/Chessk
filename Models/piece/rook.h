#ifndef ROOK_H
#define ROOK_H

#include <QObject>

class Rook : public QObject
{
    Q_OBJECT
public:
    explicit Rook(QObject *parent = nullptr);

signals:

public slots:
};

#endif // ROOK_H