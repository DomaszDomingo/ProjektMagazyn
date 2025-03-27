#include "magazynmanager.h"

void MagazynManager::ustawMagazynAktywny(TypMagazynu typ) {
    aktywny = typ;
}

QString MagazynManager::dodajDoAktywnego(const Przesylka& przesylka) {
    if (aktywny == A)
        return magazynA.dodajPrzesylke(przesylka);
    else
        return magazynB.dodajPrzesylke(przesylka);
}

QMap<QString, int> MagazynManager::pobierzStanMagazynu(TypMagazynu typ) const {
    const Magazyn& magazyn = (typ == A) ? magazynA : magazynB;
    QMap<QString, int> stan;
    QMap<QString, QStack<Przesylka>> stosy = magazyn.pobierzStosy();

    for (const auto& typ : stosy.keys()) {
        stan[typ] = stosy[typ].size();
    }

    return stan;
}

void MagazynManager::oproznijAktywnyMagazyn()
{
    if (aktywny == A)
        magazynA.oproznij();
    else
        magazynB.oproznij();
}

QString MagazynManager::usunOstatniaZAktywnego() {
    return (aktywny == A) ? magazynA.usunOstatnia()
                          : magazynB.usunOstatnia();
}


QString MagazynManager::przeniesJednaPaczke(MagazynManager::TypMagazynu zTyp, MagazynManager::TypMagazynu doTyp)
{
    if (zTyp == doTyp)
        return "Źródło i cel nie mogą być takie same.";

    Magazyn& magazynZ = (zTyp == A) ? magazynA : magazynB;
    Magazyn& magazynDo = (doTyp == A) ? magazynA : magazynB;

    QMap<QString, QStack<Przesylka>> stosy = magazynZ.pobierzStosy();
    if (stosy.isEmpty())
        return "Brak paczek do przeniesienia.";

    // Przeszukaj globalny stos i weź ostatnią paczkę
    QString komunikat = magazynZ.usunOstatnia();
    if (komunikat.startsWith("Usunięto paczkę: [")) {
        // Wyciągnij ID i typ z komunikatu
        QRegularExpression rx("\\[(.*?)\\] (.*)");
        QRegularExpressionMatch match = rx.match(komunikat);
        if (match.hasMatch()) {
            QString typ = match.captured(2);
            Przesylka nowa(typ);  // nowa paczka z nowym ID
            return magazynDo.dodajPrzesylke(nowa) + " (przeniesiona)";
        }
    }

    return "Nie udało się przenieść paczki.";
}
