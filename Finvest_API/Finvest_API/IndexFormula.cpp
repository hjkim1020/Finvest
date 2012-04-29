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

//int IndexFormula::GetRSIValue()
//{
//    //RSI = {(14�ϰ� ����� �հ�) / (14�ϰ� ����� �հ� + 14�ϰ� �϶��� �հ�) } * 10
//}

int IndexFormula::GetRatioValue() 
{
    // ��ȭ�� = {(�������� - 12���� ����) / 12���� ���� } * 100
    int ratio;

    /* s --hyeyeng.ahn - 2012. 04. 29 */
    int t_close = db_acc.GetTodayClose();
    int p_close = db_acc.GetPrevClose(12);

    ratio = ((t_close - p_close) / p_close) * 100;
    /* e -- hyeyeng.ahn - 2012. 04. 29 */
    return ratio;
}

int IndexFormula::GetPivotValue()
{
    //pivot point = (������ �� + ������ ���� + ������ ����) / 3
    int y_high = db_acc.GetPrevHigh(1);
    int y_low = db_acc.GetPrevLow(1);
    int y_close = db_acc.GetPrevClose(1);
 
    std::cout << "test: " << y_high << std::endl;
    std::cout << "test: " << y_low << std::endl;
    std::cout << "test: " << y_close << std::endl;

    int ppoint = (y_high + y_low + y_close) / 3;

    /* s --hyeyeng.ahn - 2012. 04. 29 */
    // what res, sup means?
    //int res1 = (2 * ppoint) - y_low;
    //int sup1 = (2 * ppoint) - y_high;
    //int res2 = (ppoint - sup1) + res1;
    //int sup2 = ppoint - (res1 - sup1);

    return ppoint;
    /* e -- hyeyeng.ahn - 2012. 04. 29 */
}

void IndexFormula::GetSC_KValue()
{ 
    //n�Ⱓ���� �ϴ°� ������ �ذ� ��� �ϴ��� �ФФ�	
    //int sc_k = ((db_acc.GetClose() - db_acc.GetPeriodLow())/(db_acc.GetPeriodHigh()- dbhelper.GetPeriodLow()))*100;
}

void IndexFormula::GetSC_DValue()
{
    int sc_d = 0;
    for(int i=0; i<3; i++)
    {
        //sc_d = ((db_acc.GetClose() - dbhelper.GetPeriodLow())/(dbhelper.GetPeriodHigh() - dbhelper.GetPeriodLow()))*100 + sc_d;		
    }
    sc_d = sc_d/3;
}

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

void IndexFormula::GetSonarValue()
{
    /*
        sonar momentum = (���������̵���� - n���� �����̵����) / n���� �����̵����
        sonar momentum signal = sonar momentum�� m�� �����̵����
        m = 5, n = 10 ��õ
     */

    //int sonar_m;
}
//
//void IndexFormula::GetSonarAve()
//{
//    int Sonarave = 0;
//    for(int i=0; i<5; i++)
//    {
//        Sonarave = ((db_acc.GetClose() - db_acc.GetPrevClose(10)) / db_acc.GetPrevClose(10))+Sonarave;
//    }
//    Sonarave = Sonarave/5;
//}

int IndexFormula::GetEMA(int day)
{
    /*
        �����̵���� exponential moving average
        1��: 11,200
        2��: 10,800 * 0.33 + 11,200 * 0.67 = 11,068
        3��: (���� * k) + (���� �����̵����(11,068) * (1-k)) = 3��° �����̵����
    */
    int cnt, sum = 0;

    int* close = new int[day];
    // ��Ȱ���
    int k = 0;
    printf("%d \t", day);
    printf("%d \t", day+1);
    printf("%d \t", (2 / 6));
    printf("%f \n", (2 / (day+1)));
    float ma = 0;

    // n�ϰ��� ����
    close = db_acc.GetClose(day);
    ma = close[0];
    for(cnt = 1; cnt < day; cnt++)
    {
        printf("close: %d \n", close[cnt]);
        printf("k: %f", k);
        ma = (close[cnt] * k) + (ma * (1-k));
        printf("ma: %d \n", ma);
    }

    return (int) ma;
}