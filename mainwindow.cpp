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
    QString przesylka = LosowaniePrzesylek::losujPrzesylke();
    QString wynik = manager.dodajDoAktywnego(przesylka);
    ui->infoText->setText(wynik);
    aktualizujMagazyn();

    if (wynik.contains("Limit")) {
        ui->infoText->setStyleSheet("color: red;");
    } else {
        ui->infoText->setStyleSheet("color: black;");
        HistoriaPrzesylek::dodajDoHistorii(przesylka);
        ui->historiaPaczek->setText(HistoriaPrzesylek::pobierzHistorie());

    QString przesylka = LosowaniePrzesylek::losujPrzesylke();
    QString wynik = manager.dodajDoAktywnego(przesylka);
    }


}

void MainWindow::aktualizujMagazyn()
{
    const int maks = 10;

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

    // MAGAZYN A
    ui->progressListA->setValue(stanA["List"]);
    ui->progressMalaA->setValue(stanA["Mała paczka"]);
    ui->progressSredniaA->setValue(stanA["Średnia paczka"]);
    ui->progressDuzaA->setValue(stanA["Duża paczka"]);

    // MAGAZYN B
    ui->progressListB->setValue(stanB["List"]);
    ui->progressMalaB->setValue(stanB["Mała paczka"]);
    ui->progressSredniaB->setValue(stanB["Średnia paczka"]);
    ui->progressDuzaB->setValue(stanB["Duża paczka"]);

    // ✅ Nie ruszamy żadnych QLabel – zostają takie, jak ustawiłeś w edytorze!
}
