#ifndef HISTORIAPRZESYLEK_H
#define HISTORIAPRZESYLEK_H

#include <QString>
#include <QStringList>

class HistoriaPrzesylek
{
public:
    static void dodajDoHistorii(const QString& wpis);
    static QString pobierzHistorie();

private:
    static QStringList historia;
};

#endif // HISTORIAPRZESYLEK_H
