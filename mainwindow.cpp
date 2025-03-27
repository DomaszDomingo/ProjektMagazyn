// mainwindow.cpp
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "losowanieprzesylek.h"
#include "historiaprzesylek.h"
#include "sortowanieprzesylek.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Ustaw limity progów
    ui->progressListA->setMaximum(10);
    ui->progressMalaA->setMaximum(10);
    ui->progressSredniaA->setMaximum(10);
    ui->progressDuzaA->setMaximum(10);

    connect(ui->magazynComboBox, QOverload<int>::of(&QComboBox::currentIndexChanged), this, [=](int index){
        manager.ustawMagazynAktywny(index == 0 ? MagazynManager::A : MagazynManager::B);
        aktualizujMagazyn();
    });
    manager.ustawMagazynAktywny(MagazynManager::A);
    aktualizujMagazyn();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_losujButton_clicked()
{
    // 1. Wylosuj przesyłkę jako obiekt Przesylka
    Przesylka przesylka = LosowaniePrzesylek::losujPrzesylke();

    // 2. Ustal wybrany magazyn na podstawie comboboxa
    MagazynManager::TypMagazynu wybrany =
        (ui->magazynComboBox->currentIndex() == 0)
            ? MagazynManager::A
            : MagazynManager::B;

    manager.ustawMagazynAktywny(wybrany);

    // 3. Dodaj przesyłkę do aktywnego magazynu i pobierz komunikat
    QString wynik = manager.dodajDoAktywnego(przesylka);

    // 4. Wyświetl komunikat
    ui->infoText->setText(wynik);

    // 5. Pokoloruj na czerwono jeśli limit
    if (wynik.contains("Limit")) {
        ui->infoText->setStyleSheet("color: red;");
    } else {
        ui->infoText->setStyleSheet("color: black;");
        HistoriaPrzesylek::dodajDoHistorii(wynik);  // teraz dodajemy cały wynik z ID
        ui->historiaPaczek->setText(HistoriaPrzesylek::pobierzHistorie());
    }

    // 6. Odśwież GUI
    aktualizujMagazyn();
}


void MainWindow::aktualizujMagazyn()
{
    const int maks = 10;

    auto ustawEtykiete = [](QLabel* label, int wartosc, int maks) {
        QString pierwszaLinia = label->text().split('\n')[0];  // np. "Listy"
        label->setText(QString("%1\n%2/%3").arg(pierwszaLinia).arg(wartosc).arg(maks));
    };
    QMap<QString, int> stanA = manager.pobierzStanMagazynu(MagazynManager::A);
    QMap<QString, int> stanB = manager.pobierzStanMagazynu(MagazynManager::B);

    // Progress bary - ustawiamy maksymalną wartość tylko raz (opcjonalnie)
    QList<QProgressBar*> bary = {
        ui->progressListA, ui->progressMalaA, ui->progressSredniaA, ui->progressDuzaA,
        ui->progressListB, ui->progressMalaB, ui->progressSredniaB, ui->progressDuzaB
    };
    for (QProgressBar* bar : bary) {
        bar->setMaximum(maks);
    }

    ui->progressListA->setValue(stanA.value("List", 0));
    ui->progressMalaA->setValue(stanA.value("Mała paczka", 0));
    ui->progressSredniaA->setValue(stanA.value("Średnia paczka", 0));
    ui->progressDuzaA->setValue(stanA.value("Duża paczka", 0));

    ui->progressListB->setValue(stanB.value("List", 0));
    ui->progressMalaB->setValue(stanB.value("Mała paczka", 0));
    ui->progressSredniaB->setValue(stanB.value("Średnia paczka", 0));
    ui->progressDuzaB->setValue(stanB.value("Duża paczka", 0));

    // Etykiety – MAGAZYN A
    ustawEtykiete(ui->labelListA,     stanA.value("List", 0), maks);
    ustawEtykiete(ui->labelMalaA,     stanA.value("Mała paczka", 0), maks);
    ustawEtykiete(ui->labelSredniaA,  stanA.value("Średnia paczka", 0), maks);
    ustawEtykiete(ui->labelDuzaA,     stanA.value("Duża paczka", 0), maks);

    // Etykiety – MAGAZYN B
    ustawEtykiete(ui->labelListB,     stanB.value("List", 0), maks);
    ustawEtykiete(ui->labelMalaB,     stanB.value("Mała paczka", 0), maks);
    ustawEtykiete(ui->labelSredniaB,  stanB.value("Średnia paczka", 0), maks);
    ustawEtykiete(ui->labelDuzaB,     stanB.value("Duża paczka", 0), maks);

}

void MainWindow::on_usunOstatniaButton_clicked()
{
    QString komunikat = manager.usunOstatniaZAktywnego();

    ui->infoText->setText(komunikat);
    if (komunikat.contains("Usunięto paczkę")) {
        ui->infoText->setStyleSheet("color: black;");
    } else {
        ui->infoText->setStyleSheet("color: red;");
    }

    aktualizujMagazyn();
}


void MainWindow::on_oproznijMagazynButton_clicked()
{
    manager.oproznijAktywnyMagazyn();
    ui->infoText->setText("Magazyn został opróżniony.");
    aktualizujMagazyn();
}

void MainWindow::on_przeniesButton_clicked()
{
    int z = ui->comboZ->currentIndex();
    int do_ = ui->comboDo->currentIndex();

    MagazynManager::TypMagazynu zTyp = (z == 0) ? MagazynManager::A : MagazynManager::B;
    MagazynManager::TypMagazynu doTyp = (do_ == 0) ? MagazynManager::A : MagazynManager::B;

    QString wynik = manager.przeniesJednaPaczke(zTyp, doTyp);
    ui->infoText->setText(wynik);

    if (wynik.contains("przeniesiona"))
        ui->infoText->setStyleSheet("color: green;");
    else
        ui->infoText->setStyleSheet("color: red;");

    aktualizujMagazyn();
}

