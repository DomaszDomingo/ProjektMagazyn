// sortowanieprzesylek.h
#ifndef SORTOWANIEPRZESYLEK_H
#define SORTOWANIEPRZESYLEK_H

#include <QString>
#include <QMap>
#include <QStack>

class SortowaniePrzesylek
{
public:
    static QString dodajPrzesylke(const QString& przesylka);
    static QMap<QString, QStack<QString>> pobierzStosy();

private:
    static QMap<QString, QStack<QString>> stosy;
};

#endif // SORTOWANIEPRZESYLEK_H
