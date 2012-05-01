#ifndef stockindex_h
#define stockindex_h
#include "IndexFormula.h"

class StockIndex
{
    IndexFormula formula;

    public:
        void init();

        bool RSI(); // RSI
        bool MACD(); // MACD ==����
        bool Stochastics(); // ����ĳ��ƽ ==�ϼ�
        bool RateOfChange(); // ��ȭ�� ==�ϼ�
        bool PivotPoint(); // Pivot Point ==���� --> �켱�ϼ�
        bool SonarMomentum(); // Sonar Momentum ==����
        bool TRIX(); // TRIX ==����
        bool CCI(); // CCI ==�ϼ�
        bool VR(); // VR
        bool RCI(); // RCI
        bool Disparity(); // �̰ݵ�
        bool NCO(); //NCO ==�ϼ�
        bool PriceOS(); //Price Oscillator ==�ϼ�
        bool ADLine(); //ADLine ==�ϼ�
};
#endif;
