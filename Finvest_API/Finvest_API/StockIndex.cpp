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
