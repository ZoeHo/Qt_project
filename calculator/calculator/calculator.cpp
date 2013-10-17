#include "calculator.h"
#include <QPushButton>
#include <QLCDNumber>
#include <QColor>
#include <QPalette>
#include <QGridLayout>
#include <QLabel>

double result=0;
double temp=0;
int oper=0; /*有operator時為1*/
int point=0;/*有小數點時為1*/
int numbersize=0;				//計算數字小數點後位數
int comparison;					//記錄result*10後的整數部分。
double decimal=0;
double error=1E-8;		//為double計算時產生的誤差(10^-8)

calculator::calculator(QWidget *parent, Qt::WFlags flags)
	: QMainWindow(parent, flags)
{
	ui.setupUi(this);

	/*QWidget *window = new QWidget;		//QWidget是Qt中所有使用者圖形介面元件的父類別，設定一個父類別使得其後的子類別只能在parent裡顯示
	window->setFixedSize(220, 280);      //Qt視窗長寬設定，單位為像素，此為固定長寬大小的設法，若要可變用"resize()"*/

	
	lcd =new QLCDNumber(this);	
	lcd->setGeometry(10, 10, 200, 40);					//設定元件的位置(x,y)及長、寬
	//lcd->setSegmentStyle( QLCDNumber::Filled );		//改變字體為填滿狀態，目前無用
	QPalette palette = lcd->palette();					//Qt4的BackgroundColor以及ForegroundColor皆由QPalette管理
	palette.setColor(QPalette::Background, QColor (255, 255 , 255, 255));		//設置顏色，一般的QPalette有ColorGroup(事件狀態)及ColorRole(前景或背景等)兩種狀態
	lcd->setAutoFillBackground(true);					//使window背景色自動填充
	lcd->setNumDigits(15);								//設定可以輸入的總位數
	lcd->setPalette(palette);

	QWidget *form = new QWidget(this);
	form->setGeometry(0,40,220,250);

	QGridLayout *mainLayout = new QGridLayout;
	mainLayout->setSpacing(3);						//設定Grid的空間與彼此之間的邊界
    mainLayout->setMargin(10);

	
	//row 0
	/*QPushButton *MC = new QPushButton("MC",this);
	QObject::connect(MC, SIGNAL(clicked()), this, SLOT(quit()));
	MC->setFixedHeight(30);
	
	QPushButton *MR = new QPushButton("MR",this);
	QObject::connect(MR, SIGNAL(clicked()), this, SLOT(quit()));
	MR->setFixedHeight(30);

	QPushButton *MS = new QPushButton("MS",this);
	QObject::connect(MS, SIGNAL(clicked()), this, SLOT(quit()));
	MS->setFixedHeight(30);

	QPushButton *MP = new QPushButton("M+",this);
	QObject::connect(MP, SIGNAL(clicked()), this, SLOT(quit()));
	MP->setFixedHeight(30);

	QPushButton *MM = new QPushButton("M-",this);
	QObject::connect(MM, SIGNAL(clicked()), this, SLOT(quit()));
	MM->setFixedHeight(30);*/

	//row 1
	QPushButton *Backspace = new QPushButton("<-",this);							/**/
	QObject::connect(Backspace, SIGNAL(clicked()), this, SLOT(backspaceClicked()));
	Backspace->setFixedHeight(30);

	QPushButton *ClearAll = new QPushButton("CE",this);
	QObject::connect(ClearAll, SIGNAL(clicked()), this, SLOT(clearallClicked()));   /**/
	ClearAll->setFixedHeight(30);

	/*QPushButton *Clear = new QPushButton("C",this);
	QObject::connect(Clear, SIGNAL(clicked()), this, SLOT(quit()));
	Clear->setFixedHeight(30);*/

	QPushButton *ChangeSign = new QPushButton("+/-",this);							/**/
	QObject::connect(ChangeSign, SIGNAL(clicked()), this, SLOT(changesignClick()));
	ChangeSign->setFixedHeight(30);

	QPushButton *SquareRoot = new QPushButton("Sqrt",this);							/**/
	QObject::connect(SquareRoot, SIGNAL(clicked()), this, SLOT(squarerootClick()));
	SquareRoot->setFixedHeight(30);
	
	//row 2
	/****************************************digit start****************************************************/
	int Number[10];

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

	//row 3
	QPushButton *Multiply = new QPushButton("*",this);
	QObject::connect(Multiply, SIGNAL(clicked()), this, SLOT(multiplyClick()));
	Multiply->setFixedHeight(30);

	QPushButton *Reciprocal = new QPushButton("1/x",this);
	QObject::connect(Reciprocal, SIGNAL(clicked()), this, SLOT(reciprocalClick()));
	Reciprocal->setFixedHeight(30);

	//row 4
	QPushButton *Minus = new QPushButton("-",this);
	QObject::connect(Minus, SIGNAL(clicked()), this, SLOT(minusClick()));
	Minus->setFixedHeight(30);

	QPushButton *Equal = new QPushButton("=",this);
	QObject::connect(Equal, SIGNAL(clicked()), this, SLOT(equalClick()));
	Equal->setFixedHeight(80);

	//row5
	QPushButton *Point = new QPushButton(".",this);
	QObject::connect(Point, SIGNAL(clicked()), this, SLOT(pointClick()));
	Point->setFixedHeight(30);

	QPushButton *Plus = new QPushButton("+",this);
	QObject::connect(Plus, SIGNAL(clicked()), this, SLOT(plusClick()));
	Plus->setFixedHeight(30);

	//row 0
	/*mainLayout->addWidget(MC, 0, 0);
	mainLayout->addWidget(MR, 0, 1);
	mainLayout->addWidget(MS, 0, 2);
	mainLayout->addWidget(MP, 0, 3);
	mainLayout->addWidget(MM, 0, 4);*/
	//row 1
	mainLayout->addWidget(Backspace , 1, 0);
	mainLayout->addWidget(ClearAll  , 1, 1, 1, 2);
	//mainLayout->addWidget(Clear     , 1, 2);
	mainLayout->addWidget(ChangeSign, 1, 3);
	mainLayout->addWidget(SquareRoot, 1, 4);
	//row 3
	mainLayout->addWidget(Division , 2, 3);
	mainLayout->addWidget(Power  , 2, 4);
	//row 4
	mainLayout->addWidget(Multiply   , 3, 3);
	mainLayout->addWidget(Reciprocal , 3, 4);
	//row 5
	mainLayout->addWidget(Minus , 4, 3);
	mainLayout->addWidget(Equal , 4, 4, 2, 1);
	//row 6
	mainLayout->addWidget(Point , 5, 2);
	mainLayout->addWidget(Plus  , 5, 3);

	form->setLayout(mainLayout);

}

calculator::~calculator()
{

}

void calculator::backspaceClicked() //<-
{
	numbersize=0;
	if(result!=0 && oper==0){
		comparison=result;			//計算result總共的位數，利用comparison比較，若不相等則*10繼續比較直至相等
		if(result!=comparison){		//case：整數+小數、純小數
			if(result>0){
				while(-(comparison-result)>error){	//當兩數相減的誤差值大於10^-8時繼續執行，直到誤差小於10^-8時判斷為兩相近的數
					result=result*10+error;		//利用result完全乘至整數後/10消去最後一位(加上誤差以免乘法過程中誤差太大)
					comparison=(int)result;		//comparison記錄result的整數位以比較result是否完全成為整數
					result=result-error;		//將方才加上的誤差減回來
					numbersize++;
				}
			}else{
				while(comparison-result>error){	//當兩數相減的誤差值大於10^-8時繼續執行，直到誤差小於10^-8時判斷為兩相近的數
					result=result*10-error;		//利用result完全乘至整數後/10消去最後一位(加上誤差以免乘法過程中誤差太大)
					comparison=(int)result;		//comparison記錄result的整數位以比較result是否完全成為整數
					result=result+error;		//將方才加上的誤差減回來
					numbersize++;
				}
			}
			result=(int)result/10;			//去除最後一位
			for(int i=0;i<numbersize-1;i++){	//將小數點移回原本位置
				result=result*0.1;
			}
		}else{						//case：整數、目前處理到消去的位數為0時
			result=(int)result/10;
		}
		lcd->display(result);
	}else if(result!=0 && oper==1){	//case：temp
		comparison=temp;
		if(temp!=comparison){
			if(temp>0){
				while(-(comparison-temp)>error){
					temp=temp*10+error;
					comparison=(int)temp;
					temp=temp-error;
					numbersize++;
				}
			}else{
				while(comparison-temp>error){
					temp=temp*10-error;
					comparison=(int)temp;
					temp=temp+error;
					numbersize++;
				}
			}
			temp=(int)temp/10;
			for(int i=0;i<numbersize-1;i++){
				temp=temp*0.1;
			}
		}else{
			temp=(int)temp/10;
		}
		lcd->display(temp);
	}
	comparison=0;
}

void calculator::clearallClicked() /*CE*/
{
	result=0;
	temp=0;
	numbersize=0;
	oper=0;
	point=0;
	lcd->display(result);
}

void calculator::changesignClick() /*+/-*/
{
	if(result!=0 && oper==0){
		result=result*(-1);
		lcd->display(result);
	}else if(result!=0 && oper==1){
		temp=temp*(-1);
		lcd->display(temp);
	}
}

void calculator::squarerootClick() /*Sqrt*/
{
	if(result!=0 && oper==0){
		result=sqrt(result);
		lcd->display(result);
	}else if(result!=0 && oper==1){
		temp=sqrt(temp);
		lcd->display(temp);
	}
}

void calculator::powerClick()		/*x^2*/
{
	if(result!=0 && oper==0){
		result=pow(result,2);
		lcd->display(result);
	}else if(result!=0 && oper==1){
		temp=pow(temp,2);
		lcd->display(temp);
	}
}

void calculator::reciprocalClick() /*1/x*/
{
	if(result!=0 && oper==0){
		result=1/result;
		lcd->display(result);
	}else if(result!=0 && oper==1){
		temp=1/temp;
		lcd->display(temp);
	}
}

/*number start*/
void calculator::compute(int digit)
{
	comparison=result;
	double re=result;
	if(digit==0){		//case：0，以字串處理
		if(oper==0){
			if(result!=comparison){						//(case a)整數+小數或純小數
				QString str= QString::number(result);	//在末位直接接上0，Ex1.20、0.530
				QString str2='0';
				str+=str2;
				numbersize++;
				lcd->display(str);
			}else if(comparison==0 && point==1 && re*1E8==0){	//(case b)整數0開頭，第一位小數也為0的純小數
				QString str= QString::number(re);				//在整數位後直接接上"."及"0"
					QString str2='.';
					str+=str2;
				QString str3='0';
				for(int i=0;i<numbersize;i++){	//其後有幾位0連按遍加上幾位0
					str+=str3;
				}
				numbersize++;
				lcd->display(str);
			}else{								//(case c)整數直接加0
				result=result*10;
				numbersize++;
				lcd->display(result);
			}
		}else if(oper==1){
			comparison=temp;
			re=temp;
			if(temp!=comparison){
				QString str= QString::number(temp);
				QString str2='0';
				str+=str2;
				numbersize++;
				lcd->display(str);
			}else if(comparison==0 && point==1 && re*1E8==0){
				QString str= QString::number(re);
					QString str2='.';
					str+=str2;
				QString str3='0';
				for(int i=0;i<numbersize;i++){
					str+=str3;
				}
				numbersize++;
				lcd->display(str);
			}else{
				temp=temp*10;
				numbersize++;
				lcd->display(temp);
			}
		}
	}
	else if(oper==0){		//case：1 ~ 9
		if(point!=1){		//沒有按下小數點
			if(result>=0){result=result*10+digit;}
			else if(result<0){result=result*10-digit;}
		}else if(point==1){	//有小數點存在
			decimal=digit*pow(0.1,numbersize);
			if(result>=0){result=result+decimal;}
			else if(result<0){result=result-decimal;}
			numbersize++;
		}
		lcd->display(result);
	}else if(result!=0 && oper==1){
		if(point!=1){
			if(temp>=0){temp=temp*10+digit;}
			else if(temp<0){temp=temp*10-digit;}
		}else if(point==1){
			decimal=digit*pow(0.1,numbersize);
			if(temp>=0){temp=temp+decimal;}
			else if(temp<0){temp=temp-decimal;}
			numbersize++;
		}
		lcd->display(temp);
	}
}

void calculator::digitset0()
{
	compute(0);
}
void calculator::digitset1()
{
	compute(1);
}
void calculator::digitset2()
{
	compute(2);
}
void calculator::digitset3()
{
	compute(3);
}
void calculator::digitset4()
{
	compute(4);
}
void calculator::digitset5()
{
	compute(5);
}
void calculator::digitset6()
{
	compute(6);
}
void calculator::digitset7()
{
	compute(7);
}
void calculator::digitset8()
{
	compute(8);
}
void calculator::digitset9()
{
	compute(9);
}
/*number end*/

void calculator::equalClick()
{
	if(oper==1 && result!=0 && temp!=0 ){
		if(calcoperator=='+'){				/*case +*/
			result=result+temp;
			lcd->display(result);
			oper=0;
			temp=0;
		}else if(calcoperator=='-'){		/*case -*/
			result=result-temp;
			lcd->display(result);
			oper=0;
			temp=0;
		}else if(calcoperator=='*'){		/*case **/
			result=result*temp;
			lcd->display(result);
			oper=0;
			temp=0;
		}
		else if(calcoperator=='/'){			/*case /*/
			result=result/temp;
			lcd->display(result);
			oper=0;
			temp=0;
		}
	}
}

void calculator::plusClick()
{
	oper=1;
	point=0;
	calcoperator='+';
}

void calculator::minusClick()
{
	oper=1;
	point=0;
	calcoperator='-';
}

void calculator::multiplyClick()
{
	oper=1;
	point=0;
	calcoperator='*';
}

void calculator::divisionClick()
{	
	oper=1;
	point=0;
	calcoperator='/';
}

void calculator::pointClick()
{
	point=1;
	numbersize=0;
	if(temp==0 && oper==0){
		comparison=result;			//計算result總共的位數，利用comparison比較，若不相等則*10繼續比較直至相等
		if(result!=comparison){		//case：整數+小數、純小數，不可再加小數點，僅計算小數點位數
			if(result>0){
				while(-(comparison-result)>error){	//當兩數相減的誤差值大於10^-8時繼續執行，直到誤差小於10^-8時判斷為兩相近的數
					result=result*10+error;		//利用result完全乘至整數後/10消去最後一位(加上誤差以免乘法過程中誤差太大)
					comparison=(int)result;		//comparison記錄result的整數位以比較result是否完全成為整數
					result=result-error;		//將方才加上的誤差減回來
					numbersize++;
				}
			}else{
				while(comparison-result>error){	//當兩數相減的誤差值大於10^-8時繼續執行，直到誤差小於10^-8時判斷為兩相近的數
					result=result*10-error;		//利用result完全乘至整數後/10消去最後一位(加上誤差以免乘法過程中誤差太大)
					comparison=(int)result;		//comparison記錄result的整數位以比較result是否完全成為整數
					result=result+error;		//將方才加上的誤差減回來
					numbersize++;
				}
			}
			for(int i=0;i<numbersize;i++){	//將小數點移回原本位置
				result=result*0.1;
			}
			numbersize+=1;
		}else{	//case：整數 or 0
			numbersize=1;
		}
	}else if(result!=0 && oper==1){	//case：temp
		comparison=temp;
		if(temp!=comparison){
			if(temp>0){
				while(-(comparison-temp)>error){
					temp=temp*10+error;
					comparison=(int)temp;
					temp=temp-error;
					numbersize++;
				}
			}else{
				while(comparison-temp>error){
					temp=temp*10-error;
					comparison=(int)temp;
					temp=temp+error;
					numbersize++;
				}
			}
			for(int i=0;i<numbersize-1;i++){
				temp=temp*0.1;
			}
			numbersize+=1;
		}else{
			numbersize=1;
		}
		lcd->display(temp);
	}
}