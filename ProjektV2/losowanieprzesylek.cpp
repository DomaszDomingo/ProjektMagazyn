// losowanieprzesylek.cpp
#include "losowanieprzesylek.h"
#include <QRandomGenerator>
#include <vector>

QString LosowaniePrzesylek::losujPrzesylke()
{
    std::vector<QString> typyPrzesylek = {
        "List",
        "Mała paczka",
        "Średnia paczka",
        "Duża paczka"
    };

    int index = QRandomGenerator::global()->bounded(static_cast<int>(typyPrzesylek.size()));
    return typyPrzesylek.at(index);
}
