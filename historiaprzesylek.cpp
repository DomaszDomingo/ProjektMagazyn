// historiaprzesylek.cpp
#include "historiaprzesylek.h"
#include <QDateTime>

QStringList HistoriaPrzesylek::historia;

void HistoriaPrzesylek::dodajDoHistorii(const QString& przesylka)
{
    QString timestamp = QDateTime::currentDateTime().toString("dd/MM/yyyy HH:mm:ss");
    historia.append(timestamp + " - " + przesylka);
}

QString HistoriaPrzesylek::pobierzHistorie()
{
    return historia.join("\n");
}
