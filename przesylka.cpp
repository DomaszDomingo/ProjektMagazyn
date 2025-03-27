#include "przesylka.h"

int Przesylka::globalIdCounter = 0;

Przesylka::Przesylka(const QString& typ) : typ(typ)
{
    id = QString("P%1").arg(++globalIdCounter);
}

QString Przesylka::getTyp() const
{
    return typ;
}

QString Przesylka::getId() const
{
    return id;
}
