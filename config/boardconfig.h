#ifndef BOARDCONFIG_H
#define BOARDCONFIG_H

#include <QObject>

class BoardConfig : public QObject
{
    Q_OBJECT
public:
    explicit BoardConfig(QObject *parent = nullptr);

signals:

public slots:
};

#endif // BOARDCONFIG_H