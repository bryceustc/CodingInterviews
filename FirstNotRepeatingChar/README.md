# 题目:第一个只出现一次的字符
## 题目描述：
在一个字符串(0<=字符串长度<=10000，全部由字母组成)中找到第一个只出现一次的字符,并返回它的位置, 如果没有则返回 -1（需要区分大小写）.

# 本题考点：
  
  数学规律的发现，时间效率的提升。
  
# 解题思路:
  方法一：哈希表，时间复杂度为O(n\*logn),空间复杂度O(1)。
  
  方法二：数学之美中的方法，利用数学归纳法进行判定，设定整数点（如1、10、100等等）作为位置点i（对应n的个位、十位、百位等等），分别对每个数位上有多少包含1的点进行分析。下边以百位为例，即``i=100``
  
  - 根据设定的整数位置，对n进行分割，分为两部分，高位 ``a = n/i``，低位``b = n%i``
  - 当i表示百位，且百位对应的数>=2,如n=31456,i=100，则a=314,b=56，此时百位为1的次数有a/10+1=32（最高两位0~31），每一次都包含100个连续的点，即共有(a/10+1)\*100个点的百位为1
  - 当i表示百位，且百位对应的数为1，如n=31156,i=100，则a=311,b=56，此时百位对应的就是1，则共有a/10(最高两位0-30)次是包含100个连续点，当最高两位为31（即a=311），本次只对应局部点00~56，共b+1次，所有点加起来共有（a/10\*100）+(b+1)，这些点百位对应为1\
  - 当i表示百位，且百位对应的数为0,如n=31056,i=100，则a=310,b=56，此时百位为1的次数有a/10=31（最高两位0~30）
  - 综合以上三种情况，当百位对应0或>=2时，有(a+8)/10次包含所有100个点，还有当百位为1(a%10==1)，需要增加局部点b+1
  - 之所以补8，是因为当百位为0，则a/10==(a+8)/10，当百位>=2，补8会产生进位位，效果等同于(a/10+1)
  时间复杂度O(logn),空间复杂度O(1)。
  
# 代码

[C++](./NumberOf1.cpp)

[Python](./NumberOf1.py)

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

