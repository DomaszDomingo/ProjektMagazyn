// === magazyn.cpp ===
#include "magazyn.h"

QString Magazyn::dodajPrzesylke(const QString& przesylka) {
    if (stosy[przesylka].size() >= 10) {
        return QString("Limit dla typu \"%1\" został osiągnięty!").arg(przesylka);
    }
    stosy[przesylka].push(przesylka);
    return QString("Dodano przesyłkę typu \"%1\"").arg(przesylka);
}

QMap<QString, QStack<QString>> Magazyn::pobierzStosy() const {
    return stosy;
}

int Magazyn::liczbaPrzesylek(const QString& typ) const {
    return stosy.contains(typ) ? stosy[typ].size() : 0;
}
