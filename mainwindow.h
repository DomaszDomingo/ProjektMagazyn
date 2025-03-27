#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "magazynmanager.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_losujButton_clicked();
    void on_usunOstatniaButton_clicked();      // <- usuwa ostatnią paczkę z aktywnego magazynu
    void on_oproznijMagazynButton_clicked();   // <- opróżnia aktywny magazyn
    void aktualizujMagazyn();
    void on_przeniesButton_clicked();


private:
    Ui::MainWindow *ui;
    MagazynManager manager;
};

#endif // MAINWINDOW_H
