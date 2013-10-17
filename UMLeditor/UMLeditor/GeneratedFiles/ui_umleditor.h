/********************************************************************************
** Form generated from reading UI file 'umleditor.ui'
**
** Created: Fri Nov 30 08:37:58 2012
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UMLEDITOR_H
#define UI_UMLEDITOR_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UMLeditorClass
{
public:
    QMenuBar *menuBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *UMLeditorClass)
    {
        if (UMLeditorClass->objectName().isEmpty())
            UMLeditorClass->setObjectName(QString::fromUtf8("UMLeditorClass"));
        UMLeditorClass->resize(600, 400);
        menuBar = new QMenuBar(UMLeditorClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        UMLeditorClass->setMenuBar(menuBar);
        centralWidget = new QWidget(UMLeditorClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        UMLeditorClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(UMLeditorClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        UMLeditorClass->setStatusBar(statusBar);

        retranslateUi(UMLeditorClass);

        QMetaObject::connectSlotsByName(UMLeditorClass);
    } // setupUi

    void retranslateUi(QMainWindow *UMLeditorClass)
    {
        UMLeditorClass->setWindowTitle(QApplication::translate("UMLeditorClass", "UMLeditor", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class UMLeditorClass: public Ui_UMLeditorClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UMLEDITOR_H
