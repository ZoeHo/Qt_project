/********************************************************************************
** Form generated from reading UI file 'calculator.ui'
**
** Created: Tue Mar 12 16:55:01 2013
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CALCULATOR_H
#define UI_CALCULATOR_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_calculatorClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *calculatorClass)
    {
        if (calculatorClass->objectName().isEmpty())
            calculatorClass->setObjectName(QString::fromUtf8("calculatorClass"));
        calculatorClass->resize(600, 400);
        menuBar = new QMenuBar(calculatorClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        calculatorClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(calculatorClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        calculatorClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(calculatorClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        calculatorClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(calculatorClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        calculatorClass->setStatusBar(statusBar);

        retranslateUi(calculatorClass);

        QMetaObject::connectSlotsByName(calculatorClass);
    } // setupUi

    void retranslateUi(QMainWindow *calculatorClass)
    {
        calculatorClass->setWindowTitle(QApplication::translate("calculatorClass", "calculator", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class calculatorClass: public Ui_calculatorClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CALCULATOR_H
