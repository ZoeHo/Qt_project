#ifndef VIEW_H
#define VIEW_H

#include <QtGui/QMainWindow>
#include "ui_calculator.h"
#include "model.h"
#include <QLCDNumber>

class calculatorView : public QMainWindow
{
	Q_OBJECT

public:
	calculatorView(calculatorModel *model,QWidget *parent = 0, Qt::WFlags flags = 0);
	~calculatorView();
	QLCDNumber *lcd;
	calculatorModel *tempmodel;		//view�����s�^�Ǫ�model���
	void display();					//���A�Q�]�����Ϋ᪺���A�ɡA���s���result

public slots:
	void digitset0();	//��0~9�Q���U��
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
	calculatorModel intermodel;
};

#endif // VIEW_H