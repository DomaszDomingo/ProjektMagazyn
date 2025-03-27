#ifndef PRZESYLKA_H
#define PRZESYLKA_H

#include <QString>

class Przesylka
{
public:
    Przesylka(const QString& typ);

    QString getTyp() const;
    QString getId() const;

private:
    QString typ;
    QString id;

    static int globalIdCounter;
};

#endif // PRZESYLKA_H
