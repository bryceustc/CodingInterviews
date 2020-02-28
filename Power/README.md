# 题目: 数值的整数次方
## 题目描述：
实现函数double Power(double base, int exponent)，求base的exponent次方。不得使用库函数，同时不需要考虑大数问题。
# 本题考点：
  
  二进制与位运算的理解。
  
# 解题思路:
  方法一：直接根据定义暴力求解
  
  方法二：使用折半计算，每次把n缩小一半，这样n最终会缩小到0，任何数的0次方都为1，这时候我们再往回乘，如果此时n是偶数，直接把上次递归得到的值算个平方返回即可，如果是奇数，则还需要乘上个x的值。还有一点需要引起我们的注意的是n有可能为负数，对于n是负数的情况，我们可以先用其绝对值计算出一个结果再取其倒数即可。我们让i初始化为n，然后看i是否是2的倍数，是的话x乘以自己，否则res乘以x，i每次循环缩小一半，直到为0停止循环。最后看n的正负，如果为负，返回其倒数
  
  ![](https://cuijiahua.com/wp-content/uploads/2017/11/basis_12_1.jpg)
  
# 时间复杂度：

  方法一：O(N)
  
  方法二：O(log(N))
  
# 空间复杂度
  方法一和方法二都为O(1)
  
# 代码

[C++](./Power.cpp)

[Python](./Power.py)

# C++: 
###  
```c++
class Solution {
public:
    double Power(double x, int n) {
        double res = 1.0;
        for (int i=n;i!=0;i/=2)
        {
            if  (i & 1 ==1)  // 用位与运算符比取模更高效， (i%2!=0)
            {
                res*=x;
            }
            x*=x;
        }
        if (n<0)
            res = 1/res;
        return res;
    }
};
```
###   完善版
```c++
class Solution {
public:
    double Power(double x, int n) {
        long a = n;
        if (x==0 && n<0)
            return 0.0;
        double res = 1.0;
        // 负数的右移操作不是除2，所以要先转换成非负
        if (n<0)
        {
            x = 1/x;
            a=-a;
        }
        while(a!=0)
        {
            if (a&1==1)
                res *= x;
            x*=x;
            a = a>>1;
        }
        return res;
    }
};
```
# Python:
```python
# -*- coding:utf-8 -*-
class Solution:
    def Power(self, x, n):
        # write code here
        if x==0.0 and n<0:
            return 0.0
        res = 1.0
        if n <0:
            x=1.0/x
            n=-n
        while n:
            if n&1==1:
                res*=x
            x*=x
            n=n>>1
        return res
```
## 参考
  -  [LeetCode-50题-Pow(x, n)](https://github.com/bryceustc/LeetCode_Note/blob/master/cpp/PowX-N/README.md)
