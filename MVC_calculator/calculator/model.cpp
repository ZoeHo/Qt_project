#include "model.h"
#include <QtGui/QApplication>

calculatorModel::calculatorModel(QWidget *parent)
	: QWidget(parent)
{
	result=0;		//�p�⵲�G
	temp=0;			
	oper=0;			//��operator�ɬ�1
	point=0;		//���p���I�ɬ�1
	numbersize=0;	//�p��Ʀr�p���I����
	comparison;		//�O��result*10�᪺��Ƴ����C
	decimal=0;
	error=1E-8;		//��double�p��ɲ��ͪ��~�t(10^-8)
	statechange=0;
	numbertostring=0; //QString is used=1;
}

calculatorModel::~calculatorModel()
{

}

calculatorModel calculatorModel::setstate()	//��p�⧹����N���A�]��1�A�æ^�Ǿ��model��view->display��ø
{
	statechange=1;
	return this;
}

void calculatorModel::backspace() //<- (backspace)
{
	numbersize=0;	//�p�Ʀ��k0
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
	}
	comparison=0;
	setstate();
}

void calculatorModel::clearall() //CE (clear all)�A�N�Ҧ����A�k0
{
	result=0;
	temp=0;
	numbersize=0;
	oper=0;
	point=0;
	setstate();
}

/*****************************************************/
/*					 arithmetics()    				 */
/*		�ǤJ�ѼơG�κA��char�A��view��slot�ǤJ       */
/*			�p�⧹��N���G�^�smodel->result          */
/*****************************************************/
void calculatorModel::arithmetics(char symbol)	//�p�� + - * / +/- Sqrt x^2 1/x .
{
	if(symbol=='+' || symbol=='-' || symbol=='*' || symbol=='/'){ //set operator�G + / * -
		oper=1;
		point=0;
		calcoperator = symbol;
	}

	if(symbol=='='){
		if(oper==1 && result!=0 && temp!=0 ){
			if(calcoperator=='+'){				//case +
				result=result+temp;
			}else if(calcoperator=='-'){		//case -
				result=result-temp;
			}else if(calcoperator=='*'){		//case *
				result=result*temp;
			}
			else if(calcoperator=='/'){			//case /
				result=result/temp;
			}
		}
		oper=0;
		temp=0;
	}else if(symbol=='c'){						//case +/-
		if(result!=0 && oper==0){ result=result*(-1); }
		else if(result!=0 && oper==1){ temp=temp*(-1); }
	}else if(symbol=='s'){						//case Sqrt
		if(result!=0 && oper==0){ result=sqrt(result); }
		else if(result!=0 && oper==1){ temp=sqrt(temp); }
	}else if(symbol=='p'){						//case x^2 (power)
		if(result!=0 && oper==0){ result=pow(result,2); }
		else if(result!=0 && oper==1){ temp=pow(temp,2); }
	}else if(symbol=='r'){						//case 1/x (reciprocal)
		if(result!=0 && oper==0){ result=1/result; }
		else if(result!=0 && oper==1){ temp=1/temp; }
	}else if(symbol=='.'){
		decimalpoint();
	}

	setstate();
}

//number
/*****************************************************/
/*					   compute()    				 */
/*	  �ǤJ�ѼơG�κA��int(0~9)�A��view��slot�ǤJ     */
/*	 ����J��0�����Υ~�ҫ�N���G�^�smodel->result    */
/*			  ��J��0�ɦ^�smodel->resultstr          */
/*****************************************************/
void calculatorModel::compute(int digit)
{
	comparison=result;	//�ΥH�P�O��J��case����ƩΦ��p��
	if(digit==0){		//case�G0�A�H�r��B�z
		if(oper==0){
			if(result!=comparison){						//(case a)���+�p�Ʃί¤p��
				QString str= QString::number(result,'f',numbersize);	//�b���쪽�����W0�AEx1.20�B0.530
				numbersize++;
				numbertostring=1;
				resultstr = str;
			}else if(result == comparison && point== 1){	//(case b)��ƶ}�Y�A�Ĥ@��p�Ƭ�0���¤p��
				QString str= QString::number(result);			//�b��Ʀ�᪽�����W"."��"0"
				QString str2='.';
				str+=str2;
				QString str3='0';
				for(int i=0;i<numbersize;i++){	//��ᦳ�X��0�s���K�[�W�X��0
					str+=str3;
				}
				numbersize++;
				numbertostring=1;
				resultstr = str;
			}else{								//(case c)��ƪ����[0
				result=result*10;
				numbersize++;
			}
		}else if(oper==1){
			comparison=temp;
			if(temp!=comparison){
				QString str= QString::number(temp,'f',numbersize);
				numbersize++;
				numbertostring=1;
				resultstr = str;
			}else if(temp == comparison && point== 1){
				QString str= QString::number(temp);
				QString str2='.';
				str+=str2;
				QString str3='0';
				for(int i=0;i<numbersize;i++){
					str+=str3;
				}
				numbersize++;
				numbertostring=1;
				resultstr = str;
			}else{
				temp=temp*10;
				numbersize++;
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
	}
	setstate();
}

//point
/*****************************************************/
/*					 decimalpoint()    				 */
/*					��view��slot�I�s			     */
/*			  �p����U'.'�ɪ��p��ƫᦳ�X��			 */
/*****************************************************/
void calculatorModel::decimalpoint()
{
	point=1;						//�]point�w���U�����A
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
	}
}