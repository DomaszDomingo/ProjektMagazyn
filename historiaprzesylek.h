// historiaprzesylek.h
#ifndef HISTORIAPRZESYLEK_H
#define HISTORIAPRZESYLEK_H

#include <QString>
#include <QStringList>

class HistoriaPrzesylek
{
public:
    static void dodajDoHistorii(const QString& przesylka);
    static QString pobierzHistorie();

private:
    static QStringList historia;
};

#endif // HISTORIAPRZESYLEK_H
