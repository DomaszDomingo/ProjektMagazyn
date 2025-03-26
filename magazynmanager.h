// === magazynmanager.h ===
#ifndef MAGAZYNMANAGER_H
#define MAGAZYNMANAGER_H

#include "magazyn.h"

class MagazynManager {
public:
    enum TypMagazynu { A, B };

    void ustawMagazynAktywny(TypMagazynu typ);
    QString dodajDoAktywnego(const QString& przesylka);
    QMap<QString, int> pobierzStanMagazynu(TypMagazynu typ) const;

private:
    Magazyn magazynA;
    Magazyn magazynB;
    TypMagazynu aktywny = A;
};

#endif // MAGAZYNMANAGER_H
