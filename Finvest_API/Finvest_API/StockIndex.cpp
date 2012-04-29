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

bool StockIndex::Sonar()
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
//	
//void StockIndex::SCFlag(){
//
//	if(formula.GetSCValue() < 20)
//	{
//		return �ż�flag;
//	}
//	else if(GetSCValue() > 80)
//	{
//		return �ŵ�flag;
//	}
//}

int StockIndex::GetEMA(int day)
{
    return formula.GetEMA(day);
}