#include "losowanieprzesylek.h"
#include <QRandomGenerator>
#include <vector>

Przesylka LosowaniePrzesylek::losujPrzesylke()
{
    std::vector<QString> typy = {
        "List",
        "Mała paczka",
        "Średnia paczka",
        "Duża paczka"
    };

    int index = QRandomGenerator::global()->bounded(static_cast<int>(typy.size()));
    return Przesylka(typy.at(index));
}
