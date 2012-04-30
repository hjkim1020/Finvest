#include "IndexFomular.h"
#include "DBHelper.h"
#include <math.h>
/*
    IndexFomular.cpp
    * A set of fomulars
    * author: Finvest
*/

#include "IndexFomular.h"

DBHelper dbhelper;


int IndexFomular::getSC_KValue(){ //n�Ⱓ���� �ϴ°� ������ �ذ� ��� �ϴ��� �ФФ�

	
	int sc_k = ((dbhelper.GetClose() - dbhelper.GetPeriodLow())/(dbhelper.GetPeriodHigh()- dbhelper.GetPeriodLow()))*100;
	
	return sc_k;
	

	
}

int IndexFomular::getSC_DValue(){

	int sc_d = 0;

	for(int i=0; i<3; i++){

		sc_d = ((dbhelper.GetClose() - dbhelper.GetPeriodLow())/(dbhelper.GetPeriodHigh() - dbhelper.GetPeriodLow()))*100 + sc_d;
		
	}
	sc_d = sc_d/3;

	return sc_d;
}






int IndexFomular::getCCIValue(){
	
	int M = (dbhelper.GetHigh() + dbhelper.GetLow() + dbhelper.GetClose()) / 3;
	int m;

	for(int i=0; i<20; i++)
	{
		m = ((dbhelper.GetHigh() + dbhelper.GetLow() + dbhelper.GetClose()) / 3)+m;
	}
	m = m/20;

	int d;
	for(int i=0; i<20; i++)
	{
		d= abs(M-m) + d;
	}
	d = d/20;

	int cci = (M-m)/(d*0.015);

	return cci;

} 

int IndexFomular::getSONARValue()  //day�� 10���� ��õ

{
	int sonar = (dbhelper.GetClose() - dbhelper.GetPrevClose(10))/dbhelper.GetPrevClose(10);
	
	return sonar;

}

int IndexFomular::getSONARAve() //�Ⱓ�� 5���� ��õ
{
	int sonarave = 0;

	for(int i=0; i<5; i++){

		sonarave = ((dbhelper.GetClose() -dbhelper.GetPrevClose(10))/dbhelper.GetPrevClose(10))+sonarave;
	}

	sonarave = sonarave/5;

	return sonarave;

}