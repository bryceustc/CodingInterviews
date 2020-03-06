# 题目:数字序列中某一位的数字
## 题目描述：
数字以0123456789101112131415…的格式序列化到一个字符序列中。在这个序列中，第5位（从下标0开始计数）是5，第13位是1，第19位是4，等等。

请写一个函数，求任意第n位对应的数字。

**示例1：**
```
输入：n = 3
输出：3
```

# 本题考点：
  
  数学规律的发现，时间效率的提升。
  
# 解题思路:

  ![](https://pic.leetcode-cn.com/4f913f7a795d55038dc3a480c8268d8cc3367b14cb0cb4a7ea0c9d23f26fff9b-1.png)
  
  对于第 n 位对应的数字，我们令这个数字对应的数为 target，然后分三步进行。
    - 首先找到这个数字对应的数是几位数，用 digits 表示；
    - 然后确定这个对应的数的数值 target；
    - 最后确定返回值是 target 中的哪个数字。
  
# 代码

[C++](./FindNthDigit.cpp)

[Python](./FindNthDigit.py)

# C++: 
### 方法一：直接暴力法，时间复杂度O(n\*logn)
```c++
class Solution {
public:
    int NumberOf1Between1AndN_Solution(int n)
    {
        int res = 0;
        if (n<1)
            return res;
        for (int i=1;i<=n;i++)
        {
            res += NumberOf1(i);
        }
        return res;
    }
    int NumberOf1(int n)
    {
        int num = 0;
        while (n)
        {
            if(n%10==1)
                num++;
            n /= 10;
        }
        return num;
    }
};
```
### 方法二：寻找数学规律，归纳法,时间复杂度O(logn)
```c++
class Solution {
public:
    int NumberOf1Between1AndN_Solution(int n)
    {
        // 统计次数
        int res = 0;
        //i表示当前分析的是哪一个数位
        for (long int i= 1; i<=n; i*=10)
        {
            // 分别以个位、十位、百位...分隔数字，然后统计1出现的次数
            long int a = n/i;
            long int b = n%i;
            // 以百位为例，如果百位数字>=2，n=31456为例，a=314,b=56,百位为4>=2，
            // 则总共有0~31个百位为1的，也就是（a/10+1）*100=3200个百位为1的数字，同理从个位统计到最高位再相加。
            // 如果百位为1，n=31156为例，a=311,b=56，百位1==1
            // 则总共最高两位有0~30开头且百位为1的，100~199共100个,所以（a/10）* 100 = 3100 再加上31开头百位为1的（b+1）=57个1
            // 如果百位为0，以n=31056为例，a=310,b=56,百位0==0
            // 则总共最高两位有0~30开头且百位为1的，所以（a/10）* 100 = 3100，31开头没有百位为1的，所以不加
            // 综上：三种情况，可以用（a+8）/10来表示，因为只有>=2时+8才等价于（a/10+1）
            // 而b的数字，要结合a%10取a的最低位，也就是实际数字相应的位数，就是对应个位、十位、百位...判断是否为1，在进行相加
            res += (a+8)/10*i + (a%10==1)*(b+1);
        }
        return res;
    }
};
```
### 方法三：转成字符串形式，可以表示更大的数字
```c++
class Solution {
public:
    int NumberOf1Between1AndN_Solution(int n)
    {
        int res = 0;
        for (int i = 1; i <= n; i++) {
            string str = to_string(i);
            res += count(str.begin(), str.end(), '1');
        }
        return res;
    }
};
```
# Python:
### 方法一：直接暴力遍历
```python
# -*- coding:utf-8 -*-
class Solution:
    def NumberOf1Between1AndN_Solution(self, n):
        # write code here
        res = 0
        for i in range(1,n+1):
            res += self.NumberOf1(i)
        return res
    def NumberOf1(self,n):
        num = 0
        while n>0:
            if n%10==1:
                num+=1
            n/=10
        return num
```
### 方法二：数学规律
```python
# -*- coding:utf-8 -*-
class Solution:
    def NumberOf1Between1AndN_Solution(self, n):
        # write code here
        res = 0
        i = 1
        while i<=n:
            a = n//i
            b = n%i
            res += (a+8)//10*i + (a%10==1)*(b+1)
            i*=10
        return res
```
### 方法三：转成字符串
```python
# -*- coding:utf-8 -*-
class Solution:
    def NumberOf1Between1AndN_Solution(self, n):
        # write code here
        res = 0
        for i in range(1,n+1):
            s = str(i)
            res+=s.count('1')
        return res
```
## 参考
  -  [LeetCode—233题—数字 1 的个数](https://github.com/bryceustc/LeetCode_Note/blob/master/cpp/Number-Of-Digit-One/README.md)
  -  [c++ count函数用法](https://blog.csdn.net/qq_36122764/article/details/82429976)
  -  [Python count()方法](https://www.runoob.com/python/att-string-count.html)

