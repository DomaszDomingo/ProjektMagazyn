// === magazyn.h ===
#ifndef MAGAZYN_H
#define MAGAZYN_H

#include <QString>
#include <QStack>
#include <QMap>

class Magazyn {
public:
    QString dodajPrzesylke(const QString& przesylka);
    QMap<QString, QStack<QString>> pobierzStosy() const;
    int liczbaPrzesylek(const QString& typ) const;

private:
    QMap<QString, QStack<QString>> stosy;
};

#endif // MAGAZYN_H
