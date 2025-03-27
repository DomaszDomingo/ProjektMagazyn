#ifndef MAGAZYN_H
#define MAGAZYN_H

#include <QString>
#include <QStack>
#include <QMap>
#include "przesylka.h"

class Magazyn {
public:
    QString dodajPrzesylke(const Przesylka& przesylka);
    QMap<QString, QStack<Przesylka>> pobierzStosy() const;
    int liczbaPrzesylek(const QString& typ) const;

    void oproznij();
    QString usunOstatnia(); // teraz zwraca komunikat


private:
    QMap<QString, QStack<Przesylka>> stosy;         // stosy per typ
    QStack<Przesylka> globalnyStos;                 // kolejność dodawania
    const int maxNaTyp = 10;
};

#endif // MAGAZYN_H
