/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QTextEdit *historiaPaczek;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QTextEdit *infoText;
    QPushButton *losujButton;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_2;
    QProgressBar *progressList;
    QLabel *labelList;
    QVBoxLayout *verticalLayout_3;
    QProgressBar *progressMala;
    QLabel *labelMala;
    QVBoxLayout *verticalLayout_5;
    QProgressBar *progressSrednia;
    QLabel *labelSrednia;
    QVBoxLayout *verticalLayout_4;
    QProgressBar *progressDuza;
    QLabel *labelDuza;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        historiaPaczek = new QTextEdit(centralwidget);
        historiaPaczek->setObjectName("historiaPaczek");
        historiaPaczek->setGeometry(QRect(550, 470, 231, 61));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(387, 471, 157, 61));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        infoText = new QTextEdit(layoutWidget);
        infoText->setObjectName("infoText");

        verticalLayout->addWidget(infoText);

        losujButton = new QPushButton(layoutWidget);
        losujButton->setObjectName("losujButton");

        verticalLayout->addWidget(losujButton);

        widget = new QWidget(centralwidget);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(20, 10, 311, 191));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        progressList = new QProgressBar(widget);
        progressList->setObjectName("progressList");
        progressList->setValue(24);
        progressList->setOrientation(Qt::Vertical);

        verticalLayout_2->addWidget(progressList);

        labelList = new QLabel(widget);
        labelList->setObjectName("labelList");

        verticalLayout_2->addWidget(labelList);


        horizontalLayout->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        progressMala = new QProgressBar(widget);
        progressMala->setObjectName("progressMala");
        progressMala->setValue(24);
        progressMala->setOrientation(Qt::Vertical);

        verticalLayout_3->addWidget(progressMala);

        labelMala = new QLabel(widget);
        labelMala->setObjectName("labelMala");

        verticalLayout_3->addWidget(labelMala);


        horizontalLayout->addLayout(verticalLayout_3);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName("verticalLayout_5");
        progressSrednia = new QProgressBar(widget);
        progressSrednia->setObjectName("progressSrednia");
        progressSrednia->setValue(24);
        progressSrednia->setOrientation(Qt::Vertical);

        verticalLayout_5->addWidget(progressSrednia);

        labelSrednia = new QLabel(widget);
        labelSrednia->setObjectName("labelSrednia");

        verticalLayout_5->addWidget(labelSrednia);


        horizontalLayout->addLayout(verticalLayout_5);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName("verticalLayout_4");
        progressDuza = new QProgressBar(widget);
        progressDuza->setObjectName("progressDuza");
        progressDuza->setValue(24);
        progressDuza->setOrientation(Qt::Vertical);

        verticalLayout_4->addWidget(progressDuza);

        labelDuza = new QLabel(widget);
        labelDuza->setObjectName("labelDuza");

        verticalLayout_4->addWidget(labelDuza);


        horizontalLayout->addLayout(verticalLayout_4);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);
        QWidget::setTabOrder(losujButton, infoText);
        QWidget::setTabOrder(infoText, historiaPaczek);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        losujButton->setText(QCoreApplication::translate("MainWindow", "Losuj Przesy\305\202k\304\231", nullptr));
        labelList->setText(QCoreApplication::translate("MainWindow", "\n"
"Listy\n"
" x/10", nullptr));
        labelMala->setText(QCoreApplication::translate("MainWindow", "Paczki\n"
" Ma\305\202e\n"
" x/10", nullptr));
        labelSrednia->setText(QCoreApplication::translate("MainWindow", "Paczki\n"
"\305\232rednie\n"
" x/10", nullptr));
        labelDuza->setText(QCoreApplication::translate("MainWindow", "Paczki\n"
"Du\305\274e\n"
" x/10", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
