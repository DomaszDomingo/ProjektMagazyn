#include "historiaprzesylek.h"
#include <QDateTime>

QStringList HistoriaPrzesylek::historia;

void HistoriaPrzesylek::dodajDoHistorii(const QString& wpis)
{
    QString timestamp = QDateTime::currentDateTime().toString("dd/MM/yyyy HH:mm:ss");
    historia.append(timestamp + " - " + wpis);
}

QString HistoriaPrzesylek::pobierzHistorie()
{
    return historia.join("\n");
}
