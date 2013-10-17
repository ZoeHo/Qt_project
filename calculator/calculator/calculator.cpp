#include "calculator.h"
#include <QPushButton>
#include <QLCDNumber>
#include <QColor>
#include <QPalette>
#include <QGridLayout>
#include <QLabel>

double result=0;
double temp=0;
int oper=0; /*��operator�ɬ�1*/
int point=0;/*���p���I�ɬ�1*/
int numbersize=0;				//�p��Ʀr�p���I����
int comparison;					//�O��result*10�᪺��Ƴ����C
double decimal=0;
double error=1E-8;		//��double�p��ɲ��ͪ��~�t(10^-8)

calculator::calculator(QWidget *parent, Qt::WFlags flags)
	: QMainWindow(parent, flags)
{
	ui.setupUi(this);

	/*QWidget *window = new QWidget;		//QWidget�OQt���Ҧ��ϥΪ̹ϧΤ������󪺤����O�A�]�w�@�Ӥ����O�ϱo��᪺�l���O�u��bparent�����
	window->setFixedSize(220, 280);      //Qt�������e�]�w�A��쬰�����A�����T�w���e�j�p���]�k�A�Y�n�i�ܥ�"resize()"*/

	
	lcd =new QLCDNumber(this);	
	lcd->setGeometry(10, 10, 200, 40);					//�]�w���󪺦�m(x,y)�Ϊ��B�e
	//lcd->setSegmentStyle( QLCDNumber::Filled );		//���ܦr�鬰�񺡪��A�A�ثe�L��
	QPalette palette = lcd->palette();					//Qt4��BackgroundColor�H��ForegroundColor�ҥ�QPalette�޲z
	palette.setColor(QPalette::Background, QColor (255, 255 , 255, 255));		//�]�m�C��A�@�몺QPalette��ColorGroup(�ƥ󪬺A)��ColorRole(�e���έI����)��ت��A
	lcd->setAutoFillBackground(true);					//��window�I����۰ʶ�R
	lcd->setNumDigits(15);								//�]�w�i�H��J���`���
	lcd->setPalette(palette);

	QWidget *form = new QWidget(this);
	form->setGeometry(0,40,220,250);

	QGridLayout *mainLayout = new QGridLayout;
	mainLayout->setSpacing(3);						//�]�wGrid���Ŷ��P�������������
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
		comparison=result;			//�p��result�`�@����ơA�Q��comparison����A�Y���۵��h*10�~�������ܬ۵�
		if(result!=comparison){		//case�G���+�p�ơB�¤p��
			if(result>0){
				while(-(comparison-result)>error){	//���Ƭ۴�~�t�Ȥj��10^-8���~�����A����~�t�p��10^-8�ɧP�_����۪񪺼�
					result=result*10+error;		//�Q��result�������ܾ�ƫ�/10���h�̫�@��(�[�W�~�t�H�K���k�L�{���~�t�Ӥj)
					comparison=(int)result;		//comparison�O��result����Ʀ�H���result�O�_�����������
					result=result-error;		//�N��~�[�W���~�t��^��
					numbersize++;
				}
			}else{
				while(comparison-result>error){	//���Ƭ۴�~�t�Ȥj��10^-8���~�����A����~�t�p��10^-8�ɧP�_����۪񪺼�
					result=result*10-error;		//�Q��result�������ܾ�ƫ�/10���h�̫�@��(�[�W�~�t�H�K���k�L�{���~�t�Ӥj)
					comparison=(int)result;		//comparison�O��result����Ʀ�H���result�O�_�����������
					result=result+error;		//�N��~�[�W���~�t��^��
					numbersize++;
				}
			}
			result=(int)result/10;			//�h���̫�@��
			for(int i=0;i<numbersize-1;i++){	//�N�p���I���^�쥻��m
				result=result*0.1;
			}
		}else{						//case�G��ơB�ثe�B�z����h����Ƭ�0��
			result=(int)result/10;
		}
		lcd->display(result);
	}else if(result!=0 && oper==1){	//case�Gtemp
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
	if(digit==0){		//case�G0�A�H�r��B�z
		if(oper==0){
			if(result!=comparison){						//(case a)���+�p�Ʃί¤p��
				QString str= QString::number(result);	//�b���쪽�����W0�AEx1.20�B0.530
				QString str2='0';
				str+=str2;
				numbersize++;
				lcd->display(str);
			}else if(comparison==0 && point==1 && re*1E8==0){	//(case b)���0�}�Y�A�Ĥ@��p�Ƥ]��0���¤p��
				QString str= QString::number(re);				//�b��Ʀ�᪽�����W"."��"0"
					QString str2='.';
					str+=str2;
				QString str3='0';
				for(int i=0;i<numbersize;i++){	//��ᦳ�X��0�s���M�[�W�X��0
					str+=str3;
				}
				numbersize++;
				lcd->display(str);
			}else{								//(case c)��ƪ����[0
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
	else if(oper==0){		//case�G1 ~ 9
		if(point!=1){		//�S�����U�p���I
			if(result>=0){result=result*10+digit;}
			else if(result<0){result=result*10-digit;}
		}else if(point==1){	//���p���I�s�b
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
		comparison=result;			//�p��result�`�@����ơA�Q��comparison����A�Y���۵��h*10�~�������ܬ۵�
		if(result!=comparison){		//case�G���+�p�ơB�¤p�ơA���i�A�[�p���I�A�ȭp��p���I���
			if(result>0){
				while(-(comparison-result)>error){	//���Ƭ۴�~�t�Ȥj��10^-8���~�����A����~�t�p��10^-8�ɧP�_����۪񪺼�
					result=result*10+error;		//�Q��result�������ܾ�ƫ�/10���h�̫�@��(�[�W�~�t�H�K���k�L�{���~�t�Ӥj)
					comparison=(int)result;		//comparison�O��result����Ʀ�H���result�O�_�����������
					result=result-error;		//�N��~�[�W���~�t��^��
					numbersize++;
				}
			}else{
				while(comparison-result>error){	//���Ƭ۴�~�t�Ȥj��10^-8���~�����A����~�t�p��10^-8�ɧP�_����۪񪺼�
					result=result*10-error;		//�Q��result�������ܾ�ƫ�/10���h�̫�@��(�[�W�~�t�H�K���k�L�{���~�t�Ӥj)
					comparison=(int)result;		//comparison�O��result����Ʀ�H���result�O�_�����������
					result=result+error;		//�N��~�[�W���~�t��^��
					numbersize++;
				}
			}
			for(int i=0;i<numbersize;i++){	//�N�p���I���^�쥻��m
				result=result*0.1;
			}
			numbersize+=1;
		}else{	//case�G��� or 0
			numbersize=1;
		}
	}else if(result!=0 && oper==1){	//case�Gtemp
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