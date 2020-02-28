# 题目: 不用加减乘除做加法
## 题目描述：
写一个函数，求两个整数之和，要求在函数体内不得使用+、-、\*、/四则运算符号。
# 本题考点：
  
  二进制与位运算的理解。
  
# 解题思路:

根据 与运算 定义，设二进制数字 n ，则有：
    - 若 n&1=0 ，则 n 二进制 最右一位 为 0
    - 若 n&1=1 ，则 n 二进制 最右一位 为 1

如果一个整数不为0，那么这个整数至少有一位是1。如果我们把这个整数减1，那么原来处在整数最右边的1就会变为0，原来在1后面的所有的0都会变成1(如果最右边的1后面还有0的话)。其余所有位将不会受到影响。

举个例子：一个二进制数1100，从右边数起第三位是处于最右边的一个1。减去1后，第三位变成0，它后面的两位0变成了1，而前面的1保持不变，因此得到的结果是1011.我们发现减1的结果是把最右边的一个1开始的所有位都取反了。这个时候如果我们再把原来的整数和减去1之后的结果做与运算，从原来整数最右边一个1那一位开始所有位都会变成0。如1100&1011=1000.也就是说，把一个整数减去1，再和原整数做与运算，会把该整数最右边一个1变成0.那么一个整数的二进制有多少个1，就可以进行多少次这样的操作。

  如图所示：
  ![](https://pic.leetcode-cn.com/abfd6109e7482d70d20cb8fc1d632f90eacf1b5e89dfecb2e523da1bcb562f66-image.png)
  
# 代码

[C++](./AddTwoNumbers.cpp)

[Python](./AddTwoNumbers.py)

# C++: 
###  尝试一：只能通过正数情况，负数右移不是除以2，未通过OJ
```c++
class Solution {
public:
     int  NumberOf1(int n) {
         int count = 0;
         while(n!=0)
         {
             if (n&1==1)
                 count++;
             n = n>>1;
         }
         return count;
     }
};
```
###  数字右移不行，换个思路，1左移
```c++
class Solution {
public:
     int  NumberOf1(int n) {
         int count = 0;
         unsigned int flag = 1;
         // 循环次数等于二进制整数的位数
         while(flag)
         {
             if (n&flag)
                 count++;
             flag = flag << 1;
         }
         return count;
     }
};
```
###  最优解法
```c++
class Solution {
public:
     int  NumberOf1(int n) {
         int count = 0;
         while(n)
         {
             count++;
             n = (n-1)&n;
         }
         return count;
     }
};
```
在Python中，由于负数使用补码表示的，对于负数，最高位为1，而负数在计算机是以补码存在的，往右移，符号位不变，符号位1往右移，最终可能会出现全1的情况，导致死循环。与0xffffffff相与，去掉负数前面的负号,就可以消除负数的影响。[Python 对于负数的存储方式和 c++/c/java 不一样](https://www.runoob.com/w3cnote/python-negative-storage.html)
# Python:
```python
# -*- coding:utf-8 -*-
class Solution:
    def NumberOf1(self, n):
        # write code here
        count = 0
        if n<0:
            n = n & 0xffffffff
        while n:
            count += 1
            n = n & (n-1)
        return count
```
```python
Python
# -*- coding:utf-8 -*-
class Solution:
    def NumberOf1(self, n):
        # write code here
        return sum([(n >> i & 1) for i in range(0,32)])
```
## 参考
  -  [LeetCode-191题-位1的个数](https://github.com/bryceustc/LeetCode_Note/blob/master/cpp/Number-Of-1-Bits/README.md)
