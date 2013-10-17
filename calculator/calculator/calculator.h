#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QtGui/QMainWindow>
#include "ui_calculator.h"
#include <QLCDNumber>
class calculator : public QMainWindow
{
	Q_OBJECT

public:
	calculator(QWidget *parent = 0, Qt::WFlags flags = 0);
	~calculator();
	QLCDNumber *lcd;
	char calcoperator;
	void compute(int);


public slots:
	void digitset0();
	void digitset1();
	void digitset2();
	void digitset3();
	void digitset4();
	void digitset5();
	void digitset6();
	void digitset7();
	void digitset8();
	void digitset9();

	void backspaceClicked();
	void clearallClicked();
	void changesignClick();
	void squarerootClick();
	void powerClick();
	void reciprocalClick();
	void pointClick();

	void equalClick();
	void plusClick();
	void minusClick();
	void multiplyClick();
	void divisionClick();

private:
	Ui::calculatorClass ui;
};

#endif // CALCULATOR_H