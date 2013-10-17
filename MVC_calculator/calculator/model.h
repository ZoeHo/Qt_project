#ifndef MODEL_H
#define MODEL_H
#include <QWidget>

class calculatorModel : public QWidget
{
	Q_OBJECT

public:
	calculatorModel(QWidget *parent = 0);
	~calculatorModel();
	char calcoperator;	//+ - * /的sign
	void compute(int);	//辨別輸入的數字
	calculatorModel setstate();	//設定是否有更動狀態，以告知view是否要進行更新

	QString resultstr;		//當遇到輸入為小數點後的0時轉換成字串
	double result;			//計算結果
	double temp;
	int oper;				//有operator時為1
	int point;				//有小數點時為1
	int numbersize;			//計算數字小數點後位數
	int comparison;			//記錄result*10後的整數部分。
	double decimal;			//暫存小數位的結果
	double error;			//為double計算時產生的誤差(10^-8)
	int statechange;		//model有重新運算時statechange=1，用於決定view是否要重新繪製，存於setstate()中
	int numbertostring;		//When QString is used=1;
	void backspace();		//運算backspace按下後的結果
	void clearall();		//CE的功能
	void arithmetics(char);	//對應+, - , * , / , = , x^2 , Sqrt , +/- , 1/x符號的功能
	void decimalpoint();	//對應按下小數點的功能

private:

};

#endif // MODEL_H
