# 题目描述
设计一个类，我们只能生成该类的一个实例
# 本题考点：
  
  1). 考察对单例的(Singleton)模式的理解。
  
  2). 基础语法的理解，如静态构造函数
  
  3). 多线程编程的理解
  
# 解题思路

书中本节的代码是采用C#编写的，这里用C++实现。

# 代码

[C++](Singleton.cpp)

## 方法一：
```c++
// CMyString.h文件中

class CMyString {
public:
     CMyString(char *pData = nullptr);
     //拷贝构造函数
     //因为是新建立的变量，所以不用考虑自赋值，不用考虑释放旧值
     CMyString(const CMyString &);
     ~CMyString();
     CMyString &operator = (const CMyString &str);
     char *getData();
private:
     char *m_pData;
};

```



```c++
// CMyString.cpp文件中

#include "CMyString.h"
#include <string.h>
#include <iostream>

using namespace std;
CMyString::CMyString(char *pData){
    m_pData = new char[strlen(pData) + 1];
    strcpy(m_pData, pData);
}

CMyString::~CMyString() {
    if (m_pData) {
        delete[] m_pData;
        m_pData = nullptr;
    }
}

//拷贝构造函数
//参数还是使用const的引用，因为不会改变参数的值，如果不使用引用，这里会存在无限赋值的情况
CMyString::CMyString(const CMyString &str) {
    cout << "这是拷贝构造函数！" << endl;
    m_pData = new char[strlen(str.m_pData) + 1];
    strcpy(m_pData, str.m_pData);
}

//赋值运算符函数
CMyString &CMyString::operator=(const CMyString &str) {
    cout << "这是拷贝赋值运算符！" << endl;
    if (this == &str) {
        //检查自赋值的情况
        return *this;
    }

    //释放原本的内存
    if (m_pData) {
        delete[] m_pData;
        m_pData = nullptr;
    }

    m_pData = new char[strlen(str.m_pData) + 1];
    strcpy(m_pData, str.m_pData);

    return *this;
}

char *CMyString::getData() {
    return m_pData;
}
```


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


```
输出结果：
myStr: Hello World
这是拷贝构造函数！
test: Hello World
myStr2: show the difference.
这是拷贝赋值函数！
myStr2 after operator "=": Hello World
请按任意键继续...
```

## 方法二：考虑new分配空间是否足够
```c++
CMyString &CMyString::operator=(const CMyString &str) {
    if (this != &str) {
        //调用拷贝构造函数
        CMyString strTmp(str);

        char *pTmp = strTmp.m_pData;
        strTmp.m_pData = m_pData;
        m_pData = pTmp;
    }

    return *this;
}
```

# 参考：


