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

## 方法一：单线程解法

```c++
// 剑指offer 面试题2 实现Singleton模式
#include <iostream>
using namespace std;

class Singleton
{
public:
    static Singleton* getInstance()
    {
        // 在后面的Singleton实例初始化时，若后面是new Singleton()，则此处不必new；（废话）
        // 若后面是赋值成NULL，则此处需要判断，需要时new
        // 注意！然而这两种方式并不等价！后面的Singleton实例初始化时，new Singleton(),其实是线程安全的，因为static
        初始化是在主函数main()之前，那么后面的方法岂不是很麻烦。。。。这也是我测试的时候想到的
        /*
        if(m_pInstance == NULL)
        {
            m_pInstance = new Singleton();
        }
        */
        return m_pInstance;
    }

    static void destroyInstance()
    {
        if(m_pInstance != NULL)
        {
            delete m_pInstance;
            m_pInstance = NULL;
        }    }

private:
    Singleton(){}
    static Singleton* m_pInstance;
};

// Singleton实例初始化
Singleton* Singleton::m_pInstance = new Singleton(); // 前面不能加static，会和类外全局static混淆

// 单线程获取多次实例
void Test1(){
    // 预期结果：两个实例指针指向的地址相同
    Singleton* singletonObj = Singleton::getInstance();
    cout << singletonObj << endl;

    Singleton* singletonObj2 = Singleton::getInstance();
    cout << singletonObj2 << endl;

    Singleton::destroyInstance();
}

int main(){
    Test1();
    return 0;
}
```

## 方法二：考虑new分配空间是否足够
```c++

```

# 参考：
https://www.cnblogs.com/qiaoconglovelife/p/5851163.html
https://zhuanlan.zhihu.com/p/37469260
https://blog.csdn.net/qq_35280514/article/details/70211845
https://blog.csdn.net/huhaijing/article/details/51756225
http://www.voidcn.com/article/p-bntiwotm-ny.html
https://github.com/luofengmacheng/algorithms/blob/master/interviewOffer/2.md
https://blog.csdn.net/qq_23225317/article/details/79770230

