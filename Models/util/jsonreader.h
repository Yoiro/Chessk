#ifndef JSONREADER_H
#define JSONREADER_H

#include <QObject>

class JsonReader : public QObject
{
    Q_OBJECT
public:
    explicit JsonReader(QObject *parent = nullptr);

signals:

public slots:
};

#endif // JSONREADER_H