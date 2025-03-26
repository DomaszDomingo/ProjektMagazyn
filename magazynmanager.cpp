// === magazynmanager.cpp ===
#include "magazynmanager.h"

void MagazynManager::ustawMagazynAktywny(TypMagazynu typ) {
    aktywny = typ;
}

QString MagazynManager::dodajDoAktywnego(const QString& przesylka) {
    if (aktywny == A)
        return magazynA.dodajPrzesylke(przesylka);
    else
        return magazynB.dodajPrzesylke(przesylka);
}

QMap<QString, int> MagazynManager::pobierzStanMagazynu(TypMagazynu typ) const {
    QMap<QString, int> wynik;
    const Magazyn& mag = (typ == A) ? magazynA : magazynB;
    QMap<QString, QStack<QString>> stosy = mag.pobierzStosy();
    for (auto it = stosy.begin(); it != stosy.end(); ++it) {
        wynik[it.key()] = it.value().size();
    }
    return wynik;
}
