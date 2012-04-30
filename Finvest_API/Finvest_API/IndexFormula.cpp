/*
    IndexFormula.cpp
    * A set of fomulars
    * author: Finvest
*/
#include <stdio.h>
#include <string>
#include <math.h>
#include "DBAccess.h"
#include "IndexFormula.h"

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

void IndexFormula::init()
{
    printf("Enter the stock name: ");
    std::string name;
    std::cin >> name;
    if(db_acc.SetStock(name))
    {
        printf("Load data complete \n");
    }
}

int IndexFormula::GetRSIValue()
{
    //RSI = {(14�ϰ� ����� �հ�) / (14�ϰ� ����� �հ� + 14�ϰ� �϶��� �հ�) } * 10
    return 0;
}

/* s :: hyeyeong.ahn - 2012. 04. 30 */
int IndexFormula::GetStochasticValue()
{
    /*
        Stochastic
        (���� - 5�ϵ����� ������) / (5�ϵ����� �ְ� - 5�ϵ����� ������)
    */
    int st_k;
    int* low_arr = db_acc.GetLow(5);
    int* high_arr = db_acc.GetHigh(5);
    int min_low, max_high;
    int close = db_acc.GetTodayClose();

    min_low = low_arr[0];
    max_high = high_arr[0];

    for(int cnt = 1; cnt < 5; cnt++)
    {
        if(low_arr[cnt] < min_low)
        {
            min_low = low_arr[cnt];
        }

        if(high_arr[cnt] > max_high)
        {
            max_high = high_arr[cnt];
        }
    }

    st_k = (close - min_low) / (max_high - min_low);
    return st_k;
}

/* s --hyeyeng.ahn - 2012. 04. 29 */
int IndexFormula::GetRatioValue() 
{
    /*
        ��ȭ��
        ���̳ʽ� �������� 0���� ����Ͽ� �÷����� ���� �ż�
        �÷��� �������� 0���� ����Ͽ� ���̳ʽ��� ���� �ŵ�
        ��ȭ�� = {(�������� - 12���� ����) / 12���� ���� } * 100
    */

    int ratio;
    int t_close = db_acc.GetTodayClose();
    int p_close = db_acc.GetPrevClose(12);

    ratio = ((t_close - p_close) / p_close) * 100;
    return ratio;
}
/* e -- hyeyeng.ahn - 2012. 04. 29 */

///* s -- hyeunjeong.song */
int IndexFormula::GetPivotValue()
{
    
    //pivot point = (������ �� + ������ ���� + ������ ����) / 3
    int y_high = db_acc.GetPrevHigh(1);
    int y_low = db_acc.GetPrevLow(1);
    int y_close = db_acc.GetPrevClose(1);

    int ppoint = (y_high + y_low + y_close) / 3;

     /*
        res: ���׼�
        sup: ������
    */
    int res1 = (2 * ppoint) - y_low;
    int sup1 = (2 * ppoint) - y_high;
    int res2 = (ppoint - sup1) + res1;
    int sup2 = ppoint - (res1 - sup1);

    return ppoint;
}
///* e -- hyeunjeong.song */

/* s -- hyeyeng.ahn - 2012. 04. 29 */
int IndexFormula::GetCCIValue()
{
    /* 
        CCI = (M - m) / (d * 0.015)
        M(��հ���) = (������ �� + ������ ���� + ������ ����) / 3
        m = M�� n�� �ܼ��̵����
          = M + M + .... M / 20
    */
    int* h_arr = db_acc.GetHigh(20);
    int* l_arr = db_acc.GetLow(20);
    int* c_arr = db_acc.GetClose(20);

    int M[20];
    int m_sum = 0;
    int d_sum = 0;
    int n_cci = 0;
    int m, d, cnt; // cnt: for loop index

    for(cnt = 0; cnt < 20; cnt++)
    {
        M[cnt] = (h_arr[cnt] + l_arr[cnt] + c_arr[cnt]) / 3;
        m_sum += M[cnt];
    }
    m = m_sum / 20;

    int abs_d[20];
    for(cnt = 0; cnt < 20; cnt++)
    {
        abs_d[cnt] = abs(M[cnt] - m);
        d_sum += abs_d[cnt];
    }
    d = d_sum / 20;

    //n_cci = (M[0] - m) / (d * 0.015);
    
    return n_cci;
}
/* e -- hyeyeng.ahn - 2012. 04. 29 */

/* s -- hyeyeng.ahn - 2012. 04. 30 */
void IndexFormula::GetSonarValue()
{
    /*
        sonar momentum = (���������̵���� - n���� �����̵����) / n���� �����̵����
        sonar momentum signal = sonar momentum�� m�� �����̵����
        m = 5, n = 10 ��õ
     */
     int today_ema = GetEMA(1, db_acc.GetClose(1));
     int nday_ema = GetEMA(10, db_acc.GetClose(10));
     //int sonar_m_signal[5];
     /*for(int cnt = 0; cnt < 5; cnt++)
     {
        sonar_m_signal[cnt] = 
     }
     sonar momentum�� n�ϵ��� ���ؾ� ��? -> ���� ���� �̵� ��� 5��.. ��¥�� 5�� �ٲ�����;;
     */
}

int IndexFormula::GetEMA(int day, int* data)
{
    /*
        �����̵���� exponential moving average
        1��: 11,200
        2��: 10,800 * 0.33 + 11,200 * 0.67 = 11,068
        3��: (���� * k) + (���� �����̵����(11,068) * (1-k)) = 3��° �����̵����
    */
    int cnt, sum = 0;

    // ��Ȱ���
    float k = 2 / (float)(day + 1);
    float ma;

    ma = data[0];
    if(day > 1)
    {
        for(cnt = 1; cnt < day; cnt++)
        {
            printf("ma: %f\n", ma);
            printf("close: %d \n", data[cnt]);
            printf("k: %f\n", k);
            printf("close*k: %f \n", (data[cnt] * k));
            printf("ma*(1-k): %f \n", (ma * (1-k)));

            float ck = data[cnt] * k;
            float mk = ma * (1-k);
            ma = ck + mk;
            printf("ck: %f \n", ck);
            printf("mk: %f \n", mk);
            printf("ma: %d \n", (int)ma);
        }
    }
    else if(day == 1)
    {
        float ck = data[0] * k;
        float mk = ma * (1-k);
        ma = ck + mk;
        printf("ck: %f \n", ck);
        printf("mk: %f \n", mk);
        printf("ma: %d \n", (int)ma);
    }

    return (int) ma;
}
/* e -- hyeyeng.ahn - 2012. 04. 30 */