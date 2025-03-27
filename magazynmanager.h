#ifndef MAGAZYNMANAGER_H
#define MAGAZYNMANAGER_H

#include "magazyn.h"
#include "przesylka.h"
#include <QRegularExpression>


class MagazynManager {
public:
    enum TypMagazynu { A, B };

    void ustawMagazynAktywny(TypMagazynu typ);
    QString dodajDoAktywnego(const Przesylka& przesylka);
    QMap<QString, int> pobierzStanMagazynu(TypMagazynu typ) const;

    void oproznijAktywnyMagazyn();
    QString usunOstatniaZAktywnego(); // zamiast bool
    QString przeniesJednaPaczke(MagazynManager::TypMagazynu zTyp, MagazynManager::TypMagazynu doTyp);


private:
    Magazyn magazynA;
    Magazyn magazynB;
    TypMagazynu aktywny = A;
};

#endif // MAGAZYNMANAGER_H
