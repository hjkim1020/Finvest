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
    string name;
    cout << "���� �̸� �Է�: ";
    cin >> name;

    if(db_access.SetStock(name))
    {
        cout << "Success!" << endl;
    }

    return 0;
}