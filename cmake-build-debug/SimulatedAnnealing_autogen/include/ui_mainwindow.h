/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *inputDataLabel;
    QGridLayout *gridLayout;
    QDoubleSpinBox *alphaValue;
    QSpinBox *countStepsValue;
    QLabel *minTemperatureLabel;
    QSpinBox *countQueensValue;
    QLabel *countStepsLabel;
    QLabel *maxTemperatureLabel;
    QLabel *countQueensLabel;
    QDoubleSpinBox *minTemperatureValue;
    QLabel *alphaLabel;
    QDoubleSpinBox *maxTemperatureValue;
    QPushButton *startButton;
    QScrollArea *chessBoardArea;
    QWidget *chessBoardContents;
    QWidget *layoutWidget1;
    QHBoxLayout *energy;
    QLabel *energyLabel;
    QLabel *energyValue;
    QCustomPlot *graphicsEnergyToTemperature;
    QCustomPlot *graphicsCountTakeBadSolutionsToTemperature;
    QCustomPlot *graphicsTemperatureOnIteration;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1000, 1000);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(550, 20, 421, 217));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        inputDataLabel = new QLabel(layoutWidget);
        inputDataLabel->setObjectName(QString::fromUtf8("inputDataLabel"));
        QFont font;
        font.setPointSize(12);
        font.setBold(false);
        inputDataLabel->setFont(font);
        inputDataLabel->setLayoutDirection(Qt::LeftToRight);
        inputDataLabel->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(inputDataLabel);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        alphaValue = new QDoubleSpinBox(layoutWidget);
        alphaValue->setObjectName(QString::fromUtf8("alphaValue"));
        alphaValue->setMaximum(1.000000000000000);
        alphaValue->setSingleStep(0.010000000000000);
        alphaValue->setValue(0.500000000000000);

        gridLayout->addWidget(alphaValue, 2, 1, 1, 1);

        countStepsValue = new QSpinBox(layoutWidget);
        countStepsValue->setObjectName(QString::fromUtf8("countStepsValue"));
        countStepsValue->setMaximum(1000);
        countStepsValue->setValue(100);

        gridLayout->addWidget(countStepsValue, 3, 1, 1, 1);

        minTemperatureLabel = new QLabel(layoutWidget);
        minTemperatureLabel->setObjectName(QString::fromUtf8("minTemperatureLabel"));
        minTemperatureLabel->setLayoutDirection(Qt::LeftToRight);
        minTemperatureLabel->setAutoFillBackground(false);
        minTemperatureLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(minTemperatureLabel, 0, 0, 1, 1);

        countQueensValue = new QSpinBox(layoutWidget);
        countQueensValue->setObjectName(QString::fromUtf8("countQueensValue"));
        countQueensValue->setMaximum(100);
        countQueensValue->setValue(4);

        gridLayout->addWidget(countQueensValue, 4, 1, 1, 1);

        countStepsLabel = new QLabel(layoutWidget);
        countStepsLabel->setObjectName(QString::fromUtf8("countStepsLabel"));
        countStepsLabel->setLayoutDirection(Qt::LeftToRight);
        countStepsLabel->setAutoFillBackground(false);
        countStepsLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(countStepsLabel, 3, 0, 1, 1);

        maxTemperatureLabel = new QLabel(layoutWidget);
        maxTemperatureLabel->setObjectName(QString::fromUtf8("maxTemperatureLabel"));
        maxTemperatureLabel->setLayoutDirection(Qt::LeftToRight);
        maxTemperatureLabel->setAutoFillBackground(false);
        maxTemperatureLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(maxTemperatureLabel, 1, 0, 1, 1);

        countQueensLabel = new QLabel(layoutWidget);
        countQueensLabel->setObjectName(QString::fromUtf8("countQueensLabel"));
        countQueensLabel->setLayoutDirection(Qt::LeftToRight);
        countQueensLabel->setAutoFillBackground(false);
        countQueensLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(countQueensLabel, 4, 0, 1, 1);

        minTemperatureValue = new QDoubleSpinBox(layoutWidget);
        minTemperatureValue->setObjectName(QString::fromUtf8("minTemperatureValue"));
        minTemperatureValue->setMaximum(100.000000000000000);
        minTemperatureValue->setValue(1.000000000000000);

        gridLayout->addWidget(minTemperatureValue, 0, 1, 1, 1);

        alphaLabel = new QLabel(layoutWidget);
        alphaLabel->setObjectName(QString::fromUtf8("alphaLabel"));
        alphaLabel->setLayoutDirection(Qt::LeftToRight);
        alphaLabel->setAutoFillBackground(false);
        alphaLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(alphaLabel, 2, 0, 1, 1);

        maxTemperatureValue = new QDoubleSpinBox(layoutWidget);
        maxTemperatureValue->setObjectName(QString::fromUtf8("maxTemperatureValue"));
        maxTemperatureValue->setMaximum(100.000000000000000);
        maxTemperatureValue->setValue(100.000000000000000);

        gridLayout->addWidget(maxTemperatureValue, 1, 1, 1, 1);


        verticalLayout->addLayout(gridLayout);

        startButton = new QPushButton(layoutWidget);
        startButton->setObjectName(QString::fromUtf8("startButton"));

        verticalLayout->addWidget(startButton);

        chessBoardArea = new QScrollArea(centralwidget);
        chessBoardArea->setObjectName(QString::fromUtf8("chessBoardArea"));
        chessBoardArea->setGeometry(QRect(20, 20, 500, 500));
        chessBoardArea->setWidgetResizable(true);
        chessBoardContents = new QWidget();
        chessBoardContents->setObjectName(QString::fromUtf8("chessBoardContents"));
        chessBoardContents->setGeometry(QRect(0, 0, 498, 498));
        chessBoardArea->setWidget(chessBoardContents);
        layoutWidget1 = new QWidget(centralwidget);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(160, 540, 83, 24));
        energy = new QHBoxLayout(layoutWidget1);
        energy->setObjectName(QString::fromUtf8("energy"));
        energy->setContentsMargins(0, 0, 0, 0);
        energyLabel = new QLabel(layoutWidget1);
        energyLabel->setObjectName(QString::fromUtf8("energyLabel"));
        QFont font1;
        font1.setPointSize(12);
        energyLabel->setFont(font1);

        energy->addWidget(energyLabel);

        energyValue = new QLabel(layoutWidget1);
        energyValue->setObjectName(QString::fromUtf8("energyValue"));
        energyValue->setFont(font1);

        energy->addWidget(energyValue);

        graphicsEnergyToTemperature = new QCustomPlot(centralwidget);
        graphicsEnergyToTemperature->setObjectName(QString::fromUtf8("graphicsEnergyToTemperature"));
        graphicsEnergyToTemperature->setGeometry(QRect(560, 260, 391, 311));
        graphicsCountTakeBadSolutionsToTemperature = new QCustomPlot(centralwidget);
        graphicsCountTakeBadSolutionsToTemperature->setObjectName(QString::fromUtf8("graphicsCountTakeBadSolutionsToTemperature"));
        graphicsCountTakeBadSolutionsToTemperature->setGeometry(QRect(30, 620, 391, 311));
        graphicsTemperatureOnIteration = new QCustomPlot(centralwidget);
        graphicsTemperatureOnIteration->setObjectName(QString::fromUtf8("graphicsTemperatureOnIteration"));
        graphicsTemperatureOnIteration->setGeometry(QRect(460, 620, 391, 311));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1000, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        inputDataLabel->setText(QCoreApplication::translate("MainWindow", "\320\222\321\205\320\276\320\264\320\275\321\213\320\265 \320\264\320\260\320\275\320\275\321\213\320\265", nullptr));
        minTemperatureLabel->setText(QCoreApplication::translate("MainWindow", "\320\234\320\270\320\275\320\270\320\274\320\260\320\273\321\214\320\275\320\260\321\217 \321\202\320\265\320\274\320\277\320\265\321\200\320\260\321\202\321\203\321\200\320\260", nullptr));
        countStepsLabel->setText(QCoreApplication::translate("MainWindow", "\320\247\320\270\321\201\320\273\320\276 \321\210\320\260\320\263\320\276\320\262", nullptr));
        maxTemperatureLabel->setText(QCoreApplication::translate("MainWindow", "\320\234\320\260\320\272\321\201\320\270\320\274\320\260\320\273\321\214\320\275\320\260\321\217 \321\202\320\265\320\274\320\277\320\265\321\200\320\260\321\202\321\203\321\200\320\260", nullptr));
        countQueensLabel->setText(QCoreApplication::translate("MainWindow", "\320\247\320\270\321\201\320\273\320\276 \321\204\320\265\321\200\320\267\320\265\320\271", nullptr));
        minTemperatureValue->setPrefix(QString());
        alphaLabel->setText(QCoreApplication::translate("MainWindow", "\320\220\320\273\321\214\321\204\320\260", nullptr));
        startButton->setText(QCoreApplication::translate("MainWindow", "\320\235\320\260\321\207\320\260\321\202\321\214", nullptr));
        energyLabel->setText(QCoreApplication::translate("MainWindow", "\320\255\320\275\320\265\321\200\320\263\320\270\321\217:", nullptr));
        energyValue->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
