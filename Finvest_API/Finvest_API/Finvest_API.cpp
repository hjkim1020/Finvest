/*
    Finvest_API.cpp
    * API test program
    * author: Finvest
    * jag9123@gmail.com
*/

#include <iostream>
#include <string>
#include "DBAccess.h"
using namespace std;

int main()
{
    DBAccess db_access;
    string code;
    cout << "�ֽ��ڵ� �Է�: ";
    cin >> code;

    if(db_access.SetStock(code))
    {
        cout << "Success!" << endl;
    }
    return 0;
}
