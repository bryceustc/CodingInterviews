```c++
  //main.cpp中的测试程序

#include "CMyString.h"
#include <string>
#include <iostream>

using namespace std;

int main()
{
    char *temp = "Hello World";
    CMyString myStr(tmp);

    cout << "myStr: " << myStr.getData() << endl;

    CMyString test = myStr;

    cout << "test: " << otherOne.getData() << endl;

    char *temp2 = "show the difference.";
    CMyString myStr2(temp2);
    cout << "myStr2: " << myStr2.getData() << endl;

    myStr2 = test;
    cout << "myStr2 after operator \"=\": " << myStr2.getData() << endl;

    system("pause");
    return 0;
}
  ```
