// sortowanieprzesylek.cpp
#include "sortowanieprzesylek.h"

QMap<QString, QStack<QString>> SortowaniePrzesylek::stosy;

QString SortowaniePrzesylek::dodajPrzesylke(const QString& przesylka)
{
    if (stosy[przesylka].size() >= 10) {
        return QString("Limit dla typu \"%1\" został osiągnięty!").arg(przesylka);
    }

    stosy[przesylka].push(przesylka);
    return QString("Dodano przesyłkę typu \"%1\"").arg(przesylka);
}

QMap<QString, QStack<QString>> SortowaniePrzesylek::pobierzStosy()
{
    return stosy;
}
