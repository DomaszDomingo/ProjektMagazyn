#include "magazyn.h"

QString Magazyn::dodajPrzesylke(const Przesylka& przesylka) {
    QString typ = przesylka.getTyp();

    if (stosy[typ].size() >= maxNaTyp) {
        return QString("[%1] Limit dla typu \"%2\" został osiągnięty!")
            .arg(przesylka.getId(), typ);
    }

    stosy[typ].push(przesylka);
    globalnyStos.push(przesylka); // <- zapisz kolejność dodania
    return QString("[%1] Dodano przesyłkę typu \"%2\"")
        .arg(przesylka.getId(), typ);
}

QMap<QString, QStack<Przesylka>> Magazyn::pobierzStosy() const {
    return stosy;
}

int Magazyn::liczbaPrzesylek(const QString& typ) const {
    return stosy.contains(typ) ? stosy[typ].size() : 0;
}

void Magazyn::oproznij() {
    stosy.clear();
    globalnyStos.clear();
}

QString Magazyn::usunOstatnia() {
    if (globalnyStos.isEmpty())
        return "Brak paczek do usunięcia.";

    Przesylka ostatnia = globalnyStos.pop();
    QString typ = ostatnia.getTyp();
    QString id = ostatnia.getId();

    if (stosy.contains(typ) && !stosy[typ].isEmpty()) {
        QStack<Przesylka>& stosTypu = stosy[typ];

        // Usunięcie konkretnej paczki z właściwego stosu
        QStack<Przesylka> tymczasowy;
        while (!stosTypu.isEmpty()) {
            Przesylka p = stosTypu.pop();
            if (p.getId() == id) {
                break; // nie dodajemy z powrotem – usuwamy
            }
            tymczasowy.push(p);
        }
        // Przywracamy pozostałe paczki
        while (!tymczasowy.isEmpty()) {
            stosTypu.push(tymczasowy.pop());
        }

        return QString("Usunięto paczkę: [%1] %2").arg(id, typ);
    }

    return "Błąd usuwania paczki.";
}
