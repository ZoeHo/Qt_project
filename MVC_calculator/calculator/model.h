#ifndef MODEL_H
#define MODEL_H
#include <QWidget>

class calculatorModel : public QWidget
{
	Q_OBJECT

public:
	calculatorModel(QWidget *parent = 0);
	~calculatorModel();
	char calcoperator;	//+ - * /��sign
	void compute(int);	//��O��J���Ʀr
	calculatorModel setstate();	//�]�w�O�_����ʪ��A�A�H�i��view�O�_�n�i���s

	QString resultstr;		//��J���J���p���I�᪺0���ഫ���r��
	double result;			//�p�⵲�G
	double temp;
	int oper;				//��operator�ɬ�1
	int point;				//���p���I�ɬ�1
	int numbersize;			//�p��Ʀr�p���I����
	int comparison;			//�O��result*10�᪺��Ƴ����C
	double decimal;			//�Ȧs�p�Ʀ쪺���G
	double error;			//��double�p��ɲ��ͪ��~�t(10^-8)
	int statechange;		//model�����s�B���statechange=1�A�Ω�M�wview�O�_�n���sø�s�A�s��setstate()��
	int numbertostring;		//When QString is used=1;
	void backspace();		//�B��backspace���U�᪺���G
	void clearall();		//CE���\��
	void arithmetics(char);	//����+, - , * , / , = , x^2 , Sqrt , +/- , 1/x�Ÿ����\��
	void decimalpoint();	//�������U�p���I���\��

private:

};

#endif // MODEL_H
