//
// Created by Bryce on 2021/3/29.
//

#include "CMyString.h"
#include <iostream>

using namespace std;

int main()
{
    char *temp = "Hello World";
    CMyString myStr(temp);

    cout << "myStr: " << myStr.getData() << endl;

    CMyString test = myStr;

    cout << "test: " << test.getData() << endl;

    char *temp2 = "show the difference.";
    CMyString myStr2(temp2);
    cout << "myStr2: " << myStr2.getData() << endl;

    myStr2 = test;
    cout << "myStr2 after operator \"=\": " << myStr2.getData() << endl;

    return 0;
}
