#ifndef INDEXFORMULA_H
#define INDEXFORMULA_H
#include <string>
#include "DBAccess.h"

class IndexFormula
{
    DBAccess db_acc;

    public:
        void init();
        int GetRSIValue();
        void GetMACDValue();
        int GetStochasticValue();
        int GetRatioValue();
	    int GetPivotValue();
        void GetSonarValue();
    	void GetTrixValue();
    	int GetCCIValue();
        void GetVRValue();
        void GetRCIValue();
        void GetDisparityValue();
        int GetNCOValue();
        int GetPriceOSValue();
        int GetADLineValue();

    /* s -- hyeyeng.ahn - 2012. 04. 29 */
        int GetEMA(int day, int* data); // �����̵����
};

#endif