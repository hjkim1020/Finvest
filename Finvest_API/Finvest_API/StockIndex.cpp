<<<<<<< HEAD
///*
//   StockIndex.cpp
//    * Implements index
//    * Return up/down flag
//    * author: Finvest
//*/
//
//#include "StockIndex.h"
//#include "DBHelper.h"
//#include "IndexFomula.h"
//
//bool StockIndex::CCI()
//{
//    bool buying_flag;
//
//    if(index_formula.getCCIValue() > 100)
//    {
//	buying_flag = true;
//    }
//    else if(index_formula.getCCIValue() < -100)
//    {
//        buying_flag = false;
//    }
//    return buying_flag;
//}
//
//void StockIndex::Sonar()
//{
//    if(IndexFomula.getSonarValue() > 0)
//    {
//        return �ż�flag;
//    }
//    else if(IndexFomula.getSonarValue() < 0)
//    {
//        return �ŵ�flag;
//    }
//}
//	
//void StockIndex::SCFlag(){
//
//	if(getSCValue() < 20)
//	{
//		return �ż�flag;
//	}
//	else if(getSCValue() > 80)
//	{
//		return �ŵ�flag;
//	}
/*void StockIndex::NCOFlag(){
if(getNCOValue() > 0){
 return �ż� flag;
}
else if(getNCOValue() < 0){
return �ŵ� flag;
}
} */
//
//}
=======
/*
   StockIndex.cpp
    * Implements index
    * Return up/down flag
    * author: Finvest
*/
#include <stdio.h>
#include <string>
#include "DBAccess.h"
#include "StockIndex.h"
#include "IndexFormula.h"

void StockIndex::init()
{
    formula.init();
}


/*
    Index List
        bool RSI(); // RSI
        bool MACD(); // MACD
        bool Stochastics(); // ����ĳ��ƽ
        bool RateOfChange(); // ��ȭ��
        bool PivotPoint(); // Pivot Point 
        bool SonarMomentum(); // Sonar Momentum
        bool TRIX(); // TRIX
        bool CCI(); // CCI
        bool VR(); // VR
        bool RCI(); // RCI
        bool Disparity(); // �̰ݵ�
*/

bool StockIndex::RSI()
{
    return true;
}

bool StockIndex::MACD()
{
    return true;
}

bool Stochastics()
{
    return true;
}

bool RateOfChange()
{
    return true;
}

/*
    Pivot Point
    ����
*/

bool StockIndex::SonarMomentum()
{
    // formula.GetSonarValue()
    if(34 > 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool StockIndex::TRIX()
{
    return true;
}

bool StockIndex::CCI()
{
    bool buying_flag;

    if(formula.GetCCIValue() > 100)
    {
	    buying_flag = true;
    }
    else if(formula.GetCCIValue() < -100)
    {
        buying_flag = false;
    }
    return buying_flag;
}

bool StockIndex::VR()
{
    return true;
}

bool StockIndex::RCI()
{
    return true;
}

bool StockIndex::Disparity()
{
    return true;
}

/*
    private
*/
>>>>>>> a39421a47c838982e6d251c6844b71d8f9a13a38
