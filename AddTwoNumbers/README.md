# 题目: 不用加减乘除做加法
## 题目描述：
写一个函数，求两个整数之和，要求在函数体内不得使用+、-、\*、/四则运算符号。
# 本题考点：
  
  二进制与位运算的理解。
  
# 解题思路:

^异或 ----相当于 无进位的求和，即：1+0=1, 0+1=1, 0+0 =0,1+1=0;

& 与 ----相当于求每位的进位数， 先看定义：1&1=1；1&0=0；0&0=0；即都为1的时候才为1，正好可以模拟进位数的情况,还是想象10进制下模拟情况：（9+1=10，如果是用&的思路来处理，则9+1得到的进位数为1，而不是10，所以要用<<1向左再移动一位，这样就变为10了）；

这样公式就是：（a^b) ^ ((a&b)<<1) 即：每次无进位求 + 每次得到的进位数--------我们需要不断重复这个过程，直到进位数为0为止；
  
# 代码

[C++](./AddTwoNumbers.cpp)

[Python](./AddTwoNumbers.py)

# C++: 
###  
```c++
class Solution {
public:
    int add(int a, int b) {
        while(b!=0)  // 当进位为 0 时跳出
        {
            int c = (unsigned int)(a & b) << 1;  // c = 进位
            a= a^b;  // a = 非进位和
            b = c; // b = 进位
        }
        return a;
    }
};

/*
递归写法
*/
class Solution {
public:
    int add(int a, int b) { // b是进位  a是非进位和
        if (b ==0) return a;

        int c = (unsigned int) (a&b) << 1;  // 进位赋值给c，准备下一次递归使用
        int d = a^b;   // 非进位和赋值给d ，准备下一次递归使用
        return add(d, c);
    }
};

```
C/C++版本输出负数时，是采用补码格式输出的，其实和python输出的前32项是一模一样的。问题是在于C语言版本中int是32位的，进入下最后一个循环后，b左移一位后，最高位的1就溢出了，那么b就变成了0. 但是python由于支持大int值，它的整数不是32位，而是某种程度上可以无限扩展，结果左移的1跑到33位，b仍然不是0，实际上永远也不是0，于是就无限循环了......
# Python:
```python
# -*- coding:utf-8 -*-
class Solution:
    def Add(self, num1, num2):
        # write code here
        MAX = 0x7fffffff
        mask = 0xffffffff
        while num2 != 0:
            num1, num2 = (num1 ^ num2), ((num1 & num2) << 1)
            num1 = num1 & mask
            num2 = num2 & mask
        return num1 if num1 <= MAX else ~(num1 ^ mask)
```
## 参考
  -  [Python 运算符](https://www.runoob.com/python/python-operators.html)
