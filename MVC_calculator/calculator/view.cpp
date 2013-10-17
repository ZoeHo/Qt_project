#include <QPushButton>
#include <QLCDNumber>
#include <QColor>
#include <QPalette>
#include <QGridLayout>
#include "view.h"

calculatorView::calculatorView(calculatorModel *model,QWidget *parent, Qt::WFlags flags )
	: QMainWindow(parent, flags)
{
	ui.setupUi(this);
	tempmodel = model;									//接回傳的model

	lcd =new QLCDNumber(this);	
	lcd->setGeometry(10, 10, 200, 40);					//設定元件的位置(x,y)及長、寬
	QPalette palette = lcd->palette();					//Qt4的BackgroundColor以及ForegroundColor皆由QPalette管理
	palette.setColor(QPalette::Background, QColor (255, 255 , 255, 255));		//設置顏色，一般的QPalette有ColorGroup(事件狀態)及ColorRole(前景或背景等)兩種狀態
	lcd->setAutoFillBackground(true);					//使window背景色自動填充
	lcd->setNumDigits(15);								//設定可以輸入的總位數
	lcd->setPalette(palette);

	QWidget *form = new QWidget(this);					//設定內部所有配置的格局
	form->setGeometry(0,40,220,250);

	QGridLayout *mainLayout = new QGridLayout;
	mainLayout->setSpacing(3);							//設定Grid的空間與彼此之間的邊界
    mainLayout->setMargin(10);

	//row 0	按鍵配置開始
	QPushButton *Backspace = new QPushButton("<-",this);
	QObject::connect(Backspace, SIGNAL(clicked()), this, SLOT(backspaceClicked()));
	Backspace->setFixedHeight(30);

	QPushButton *ClearAll = new QPushButton("CE",this);
	QObject::connect(ClearAll, SIGNAL(clicked()), this, SLOT(clearallClicked()));
	ClearAll->setFixedHeight(30);

	QPushButton *ChangeSign = new QPushButton("+/-",this);
	QObject::connect(ChangeSign, SIGNAL(clicked()), this, SLOT(changesignClick()));
	ChangeSign->setFixedHeight(30);

	QPushButton *SquareRoot = new QPushButton("Sqrt",this);	
	QObject::connect(SquareRoot, SIGNAL(clicked()), this, SLOT(squarerootClick()));
	SquareRoot->setFixedHeight(30);
	
	//row 1
	/****************************************digit start****************************************************/

	QPushButton *NumberButton0 = new QPushButton("0",this);
	QObject::connect(NumberButton0, SIGNAL(clicked()), this, SLOT(digitset0()));
	mainLayout->addWidget(NumberButton0, 5, 0, 1, 2);
	NumberButton0->setFixedHeight(30);

	QPushButton *NumberButton1 = new QPushButton("1",this);
	QObject::connect(NumberButton1, SIGNAL(clicked()), this, SLOT(digitset1()));
	mainLayout->addWidget(NumberButton1, 4, 0);
	NumberButton1->setFixedHeight(30);

	QPushButton *NumberButton2 = new QPushButton("2",this);
	QObject::connect(NumberButton2, SIGNAL(clicked()), this, SLOT(digitset2()));
	mainLayout->addWidget(NumberButton2, 4, 1);
	NumberButton2->setFixedHeight(30);

	QPushButton *NumberButton3 = new QPushButton("3",this);
	QObject::connect(NumberButton3, SIGNAL(clicked()), this, SLOT(digitset3()));
	mainLayout->addWidget(NumberButton3, 4, 2);
	NumberButton3->setFixedHeight(30);

	QPushButton *NumberButton4 = new QPushButton("4",this);
	QObject::connect(NumberButton4, SIGNAL(clicked()), this, SLOT(digitset4()));
	mainLayout->addWidget(NumberButton4, 3, 0);
	NumberButton4->setFixedHeight(30);

	QPushButton *NumberButton5 = new QPushButton("5",this);
	QObject::connect(NumberButton5, SIGNAL(clicked()), this, SLOT(digitset5()));
	mainLayout->addWidget(NumberButton5, 3, 1);
	NumberButton5->setFixedHeight(30);

	QPushButton *NumberButton6 = new QPushButton("6",this);
	QObject::connect(NumberButton6, SIGNAL(clicked()), this, SLOT(digitset6()));
	mainLayout->addWidget(NumberButton6, 3, 2);
	NumberButton6->setFixedHeight(30);

	QPushButton *NumberButton7 = new QPushButton("7",this);
	QObject::connect(NumberButton7, SIGNAL(clicked()), this, SLOT(digitset7()));
	mainLayout->addWidget(NumberButton7, 2, 0);
	NumberButton7->setFixedHeight(30);

	QPushButton *NumberButton8 = new QPushButton("8",this);
	QObject::connect(NumberButton8, SIGNAL(clicked()), this, SLOT(digitset8()));
	mainLayout->addWidget(NumberButton8, 2, 1);
	NumberButton8->setFixedHeight(30);

	QPushButton *NumberButton9 = new QPushButton("9",this);
	QObject::connect(NumberButton9, SIGNAL(clicked()), this, SLOT(digitset9()));
	mainLayout->addWidget(NumberButton9, 2, 2);
	NumberButton9->setFixedHeight(30);
	/****************************************digit end****************************************************/

	QPushButton *Division = new QPushButton("/",this);
	QObject::connect(Division, SIGNAL(clicked()), this, SLOT(divisionClick()));
	Division->setFixedHeight(30);

	QPushButton *Power = new QPushButton("x\262",this);
	QObject::connect(Power, SIGNAL(clicked()), this, SLOT(powerClick()));
	Power->setFixedHeight(30);

	//row 2
	QPushButton *Multiply = new QPushButton("*",this);
	QObject::connect(Multiply, SIGNAL(clicked()), this, SLOT(multiplyClick()));
	Multiply->setFixedHeight(30);

	QPushButton *Reciprocal = new QPushButton("1/x",this);
	QObject::connect(Reciprocal, SIGNAL(clicked()), this, SLOT(reciprocalClick()));
	Reciprocal->setFixedHeight(30);

	//row 3
	QPushButton *Minus = new QPushButton("-",this);
	QObject::connect(Minus, SIGNAL(clicked()), this, SLOT(minusClick()));
	Minus->setFixedHeight(30);

	QPushButton *Equal = new QPushButton("=",this);
	QObject::connect(Equal, SIGNAL(clicked()), this, SLOT(equalClick()));
	Equal->setFixedHeight(80);

	//row4
	QPushButton *Point = new QPushButton(".",this);
	QObject::connect(Point, SIGNAL(clicked()), this, SLOT(pointClick()));
	Point->setFixedHeight(30);

	QPushButton *Plus = new QPushButton("+",this);
	QObject::connect(Plus, SIGNAL(clicked()), this, SLOT(plusClick()));
	Plus->setFixedHeight(30);


	//row 0
	mainLayout->addWidget(Backspace , 1, 0);
	mainLayout->addWidget(ClearAll  , 1, 1, 1, 2);
	mainLayout->addWidget(ChangeSign, 1, 3);
	mainLayout->addWidget(SquareRoot, 1, 4);
	//row 1
	mainLayout->addWidget(Division , 2, 3);
	mainLayout->addWidget(Power  , 2, 4);
	//row 2
	mainLayout->addWidget(Multiply   , 3, 3);
	mainLayout->addWidget(Reciprocal , 3, 4);
	//row 3
	mainLayout->addWidget(Minus , 4, 3);
	mainLayout->addWidget(Equal , 4, 4, 2, 1);
	//row 4
	mainLayout->addWidget(Point , 5, 2);
	mainLayout->addWidget(Plus  , 5, 3);

	form->setLayout(mainLayout);
}

calculatorView::~calculatorView()
{

}

void calculatorView::display()	//當狀態被設置為1時重繪lcd的內容
{
	if(tempmodel->statechange==1 && tempmodel->numbertostring==0){			//case：狀態為1且輸入非0
		if(tempmodel->oper==0){
			this->lcd->display(tempmodel->result);
		}else if(tempmodel->oper==1){
			this->lcd->display(tempmodel->temp);
		}
	}else if(tempmodel->statechange==1 && tempmodel->numbertostring==1){	//case：狀態為1且輸入為0
		if(tempmodel->oper==0){
			this->lcd->display(tempmodel->resultstr);
		}else if(tempmodel->oper==1){
			this->lcd->display(tempmodel->resultstr);
		}
	}
	tempmodel->statechange=0;		//狀態設置為未更改的狀態
	tempmodel->numbertostring=0;
}

//digit set start
//輸入的數字傳到model->computer中
void calculatorView::digitset0()
{
	tempmodel->compute(0);
	display();
}
void calculatorView::digitset1()
{
	tempmodel->compute(1);
	display();
}
void calculatorView::digitset2()
{
	tempmodel->compute(2);
	display();
}
void calculatorView::digitset3()
{
	tempmodel->compute(3);
	display();
}
void calculatorView::digitset4()
{
	tempmodel->compute(4);
	display();
}
void calculatorView::digitset5()
{
	tempmodel->compute(5);
	display();
}
void calculatorView::digitset6()
{
	tempmodel->compute(6);
	display();
}
void calculatorView::digitset7()
{
	tempmodel->compute(7);
	display();
}
void calculatorView::digitset8()
{
	tempmodel->compute(8);
	display();
}
void calculatorView::digitset9()
{
	tempmodel->compute(9);
	display();
}
//digit set end

//symbol set (<-、 CE)
void calculatorView::backspaceClicked()
{
	tempmodel->backspace();
	display();
}

void calculatorView::clearallClicked()
{
	tempmodel->clearall();
	display();
}

//+ - * / +/- Sqrt x^2 1/x set
//輸入的符號傳到model->arithmetics中進行計算
void calculatorView::plusClick()
{
	tempmodel->arithmetics('+');
}

void calculatorView::minusClick()
{
	tempmodel->arithmetics('-');
}

void calculatorView::multiplyClick()
{
	tempmodel->arithmetics('*');
}

void calculatorView::divisionClick()
{	
	tempmodel->arithmetics('/');
}

void calculatorView::equalClick()
{
	tempmodel->arithmetics('=');
	display();
}

void calculatorView::changesignClick()	// +/-
{
	tempmodel->arithmetics('c');
	display();
}

void calculatorView::squarerootClick()  // Sqrt
{
	tempmodel->arithmetics('s');
	display();
}

void calculatorView::powerClick()		// power
{
	tempmodel->arithmetics('p');
	display();
}

void calculatorView::reciprocalClick()  // 1/x
{
	tempmodel->arithmetics('r');
	display();
}

void calculatorView::pointClick()		// .
{
	tempmodel->arithmetics('.');
	display();
}