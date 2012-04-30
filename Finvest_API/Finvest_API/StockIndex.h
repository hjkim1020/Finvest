#ifndef stockindex_h
#define stockindex_h
#include "IndexFormula.h"

class StockIndex
{
    IndexFormula formula;

    public:
        void init();

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
        
        int GetEMA(int day);
};
#endif;
