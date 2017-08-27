#ifndef CASE_H
#define CASE_H

#include <QObject>

class Case: public QObject
{
    Q_OBJECT
public:
    int row, col;
    Case(QObject* parent = Q_NULLPTR, int row=0, int col=0);
};

#endif // CASE_H
