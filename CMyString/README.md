# 题目描述

如下为类型CMyString的声明。请为该类型添加赋值运算符函数。
```c++
class CMyString
{
public:
     // 构造函数
     CMyString(char*pData = nullptr);
     // 拷贝构造函数 (用来初始化对象)；
     CMyString(const CMyString & str);
     // 赋值运算函数
     ~CMyString(void);
private:
     char* m_pData;
};
```
# 本题考点：
  
  1). C++基础语法的理解，如运算符函数、常量引用等。
  
  2). 对内存泄漏的理解
  
  3). 代码异常安全性的理解
  
# 解题思路

**对于初级：**

  1). 返回值的类型声明为该类型的引用，并在函数结束前返回实例自身的引用；

  2). 把传入的参数类型声明为常量引用；

  3). 如有必要，需要释放实例自身已有的内存；

  4). 判断传入的参数和当前的实例(\*this)是不是同一个实例

**对于高级：**

  1). 其实就是一个构造函数，不过形参是该类型本身。
  
  2). 形参为const的引用，因为拷贝不影响原变量。如果不使用引用会无限循环调用构造函数。
  
  3). 在给新建变量赋值时会引用。而赋值运算符用在给已存在变量赋值的情况。

可以参考

- [C++](CMyString.cpp)


- [Python](CMystring.py)

# 代码

[C++](CMyString.cpp)

```c++
CMyString& CMyString::operator = (const CMyString &str)
{
     if(this == &str)     
          return *this;
     delete[]m_pData;
     m_pData = nullptr;
     
     m_pData = new char[strlen(str.m_pData)+1];
     strcpy(m_pData,str.m_pData);
     
     return *this;
}
```
# 代码解读
[this指针](https://www.runoob.com/cplusplus/cpp-this-pointer.html):在 C++ 中，每一个对象都能通过 this 指针来访问自己的地址。this 指针是所有成员函数的隐含参数。因此，在成员函数内部，它可以用来指向调用对象。



[Python](CMyString.py)

```python
# -*- coding:utf-8 -*-
```


