#include "model.h"
#include <QtGui/QApplication>

calculatorModel::calculatorModel(QWidget *parent)
	: QWidget(parent)
{
	result=0;		//計算結果
	temp=0;			
	oper=0;			//有operator時為1
	point=0;		//有小數點時為1
	numbersize=0;	//計算數字小數點後位數
	comparison;		//記錄result*10後的整數部分。
	decimal=0;
	error=1E-8;		//為double計算時產生的誤差(10^-8)
	statechange=0;
	numbertostring=0; //QString is used=1;
}

calculatorModel::~calculatorModel()
{

}

calculatorModel calculatorModel::setstate()	//當計算完成後將狀態設為1，並回傳整個model供view->display重繪
{
	statechange=1;
	return this;
}

void calculatorModel::backspace() //<- (backspace)
{
	numbersize=0;	//小數位歸0
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
	}
	comparison=0;
	setstate();
}

void calculatorModel::clearall() //CE (clear all)，將所有狀態歸0
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
/*		傳入參數：形態為char，由view的slot傳入       */
/*			計算完後將結果回存model->result          */
/*****************************************************/
void calculatorModel::arithmetics(char symbol)	//計算 + - * / +/- Sqrt x^2 1/x .
{
	if(symbol=='+' || symbol=='-' || symbol=='*' || symbol=='/'){ //set operator： + / * -
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
/*	  傳入參數：形態為int(0~9)，由view的slot傳入     */
/*	 除輸入為0的情形外皆後將結果回存model->result    */
/*			  輸入為0時回存model->resultstr          */
/*****************************************************/
void calculatorModel::compute(int digit)
{
	comparison=result;	//用以判別輸入的case為整數或有小數
	if(digit==0){		//case：0，以字串處理
		if(oper==0){
			if(result!=comparison){						//(case a)整數+小數或純小數
				QString str= QString::number(result,'f',numbersize);	//在末位直接接上0，Ex1.20、0.530
				numbersize++;
				numbertostring=1;
				resultstr = str;
			}else if(result == comparison && point== 1){	//(case b)整數開頭，第一位小數為0的純小數
				QString str= QString::number(result);			//在整數位後直接接上"."及"0"
				QString str2='.';
				str+=str2;
				QString str3='0';
				for(int i=0;i<numbersize;i++){	//其後有幾位0連按便加上幾位0
					str+=str3;
				}
				numbersize++;
				numbertostring=1;
				resultstr = str;
			}else{								//(case c)整數直接加0
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
/*					由view的slot呼叫			     */
/*			  計算按下'.'時的小位數後有幾位			 */
/*****************************************************/
void calculatorModel::decimalpoint()
{
	point=1;						//設point已按下的狀態
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
	}
}