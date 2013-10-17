/*#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QtGui/QMainWindow>
#include "ui_calculator.h"
#include <QLCDNumber>
#include "model.h"
#include "view.h"

class calculator : public QMainWindow
{
	Q_OBJECT

public:
	calculator(QWidget *parent = 0, Qt::WFlags flags = 0);
	~calculator();
	calculatorModel *model;
	calculatorView *view;

private:
	Ui::calculatorClass ui;
};

#endif // CALCULATOR_H*/