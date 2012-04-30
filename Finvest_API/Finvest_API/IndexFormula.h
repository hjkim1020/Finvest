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
        int GetRatioValue();
	    int GetPivotValue();

    	void GetSC_KValue();
	    void GetSC_DValue();

    	void GetSonarValue();
    	void GetSonarAve();

    	int GetCCIValue();

    /* s -- hyeyeng.ahn - 2012. 04. 29 */
        int GetEMA(int day, int* data); // �����̵����
};

#endif