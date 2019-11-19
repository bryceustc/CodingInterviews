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

## 方法二：多线程+加锁
```c++

    /*解法一是最简单，也是最普遍的实现方式。但是，这种实现方式有很多问题，比如没有考虑多线程的问题，在多线程的情况下，就可能会创建多个Singleton实例，以下是改善的版本。*/
    #include <iostream>
    #include <mutex>
    #include <thread>
    #include <vector>
    using namespace std;
    
    class Singleton
    {
    private:
        static mutex m_mutex; // 互斥量
    
        Singleton(){}
        static Singleton* m_pInstance;
    
    public:
        static Singleton* getInstance(){
            if(m_pInstance == nullptr){
                m_mutex.lock(); // 使用C++11中的多线程库
                if(m_pInstance == nullptr){ // 两次判断是否为NULL的双重检查
                    m_pInstance = new Singleton();
                }
                m_mutex.unlock();
            }
            return m_pInstance;
        }
    
        static void destroyInstance(){
            if(m_pInstance != nullptr){
                delete m_pInstance;
                m_pInstance = nullptr;
            }
        }
    };
    
    Singleton* Singleton::m_pInstance = nullptr;
    mutex Singleton::m_mutex;
    
    
    void print_singleton_instance(){
        Singleton *singletonObj = Singleton::getInstance();
        cout << singletonObj << endl;
    }
    
    // 多个进程获得单例
    void Test1(){
        // 预期结果，打印出相同的地址，之间可能缺失换行符，也属正常现象
        vector<thread> threads;
        for(int i = 0; i < 10; ++i){
            threads.push_back(thread(print_singleton_instance));
        }
    
        for(auto& thr : threads){
            thr.join();
        }
    }
    
    int main(){
        Test1();
        Singleton::destroyInstance();
        return 0;
    }
    /*此方法中进行了两次m_pInstance == nullptr的判断，使用了所谓的“双检锁”机制。因为进行一次加锁和解锁是需要付出对应的代价的，而进行两次判断，就可以避免多次加锁与解锁操作，只在m_pInstance不为nullptr时才需要加锁，同时也保证了线程安全。但是，如果进行大数据的操作，加锁操作将成为一个性能的瓶颈，为此，一种新的单例模式的实现也就出现了。*/
```
## 方法三：const + 实例
```c++
#include <iostream>
    #include <thread>
    #include <vector>
    using namespace std;
    
    class Singleton
    {
    private:
        Singleton(){}
        static const Singleton* m_pInstance;
    public:
        static Singleton* getInstance(){
            return const_cast<Singleton*>(m_pInstance); // 去掉“const”特性
            // 注意！若该函数的返回值改为const static型，则此处不必进行const_cast静态转换
            // 所以该函数可以改为：
            /*
            const static Singleton* getInstance(){
                return m_pInstance;
            }
            */
        }
    
        static void destroyInstance(){
            if(m_pInstance != NULL){
                delete m_pInstance;
                m_pInstance = NULL;
            }
        }
    };
    const Singleton* Singleton::m_pInstance = new Singleton(); // 利用const只能定义一次，不能再次修改的特性，static继续保持类内只有一个实例
    
    void print_singleton_instance(){
        Singleton *singletonObj = Singleton::getInstance();
        cout << singletonObj << endl;
    }
    
    // 多个进程获得单例
    void Test1(){
        // 预期结果，打印出相同的地址，之间可能缺失换行符，也属正常现象
        vector<thread> threads;
        for(int i = 0; i < 10; ++i){
            threads.push_back(thread(print_singleton_instance));
        }
        for(auto& thr : threads){
            thr.join();
        }
    }
    
    int main(){
        Test1();
        Singleton::destroyInstance();
        return 0;
    }
    /*因为静态初始化在程序开始时，也就是进入主函数之前，由主线程以单线程方式完成了初始化，所以静态初始化实例保证了线程安全性。在性能要求比较高时，就可以使用这种方式，从而避免频繁的加锁和解锁造成的资源浪费。由于上述三种实现，都要考虑到实例的销毁，关于实例的销毁，待会在分析。*
```

# 参考：
https://www.cnblogs.com/qiaoconglovelife/p/5851163.html
https://zhuanlan.zhihu.com/p/37469260
https://blog.csdn.net/qq_35280514/article/details/70211845
https://blog.csdn.net/huhaijing/article/details/51756225
http://www.voidcn.com/article/p-bntiwotm-ny.html
https://github.com/luofengmacheng/algorithms/blob/master/interviewOffer/2.md
https://blog.csdn.net/qq_23225317/article/details/79770230

