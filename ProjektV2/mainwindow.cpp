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
    ui->progressList->setMaximum(10);
    ui->progressMala->setMaximum(10);
    ui->progressSrednia->setMaximum(10);
    ui->progressDuza->setMaximum(10);

    aktualizujMagazyn();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_losujButton_clicked()
{
    QString przesylka = LosowaniePrzesylek::losujPrzesylke();
    QString wynik = SortowaniePrzesylek::dodajPrzesylke(przesylka);
    ui->infoText->setText(wynik);

    if (wynik.contains("Limit")) {
        ui->infoText->setStyleSheet("color: red;");
    } else {
        ui->infoText->setStyleSheet("color: black;");
        HistoriaPrzesylek::dodajDoHistorii(przesylka);
        ui->historiaPaczek->setText(HistoriaPrzesylek::pobierzHistorie());
    }

    aktualizujMagazyn();
}

void MainWindow::aktualizujMagazyn()
{
    const int maks = 10;
    auto stosy = SortowaniePrzesylek::pobierzStosy();

    int listy = stosy["List"].size();
    int mala = stosy["Mała paczka"].size();
    int srednia = stosy["Średnia paczka"].size();
    int duza = stosy["Duża paczka"].size();

    ui->progressList->setValue(listy);
    ui->progressMala->setValue(mala);
    ui->progressSrednia->setValue(srednia);
    ui->progressDuza->setValue(duza);

    ui->labelList->setText(QString("Listy\n%1/%2").arg(listy).arg(maks));
    ui->labelMala->setText(QString("Małe paczki\n%1/%2").arg(mala).arg(maks));
    ui->labelSrednia->setText(QString("Średnie paczki\n%1/%2").arg(srednia).arg(maks));
    ui->labelDuza->setText(QString("Duże paczki\n%1/%2").arg(duza).arg(maks));
}
