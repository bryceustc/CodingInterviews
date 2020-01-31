# 题目:1~n整数中1出现的次数
## 题目描述：
输入一个整数n,求1\~n这n个整数的十进制表示中1出现次数。例如，输入12，1\~12中包含1的数字有1，10,11和12，1一共出现了5次

# 本题考点：
  
  数学规律的发现，时间效率的提升。
  
# 解题思路:
  方法一：对1\~n进行遍历，每一个数字都进行判断，从最高位一直判断到最低位，每次通过对10求余数判断整数的个位数字是不是1，大于10的除以10之后再判断。我们对每个数字都要做除法和求余运算以求出该数字中1出现的次数。如果输入数字n，n有O(logn)位，我们需要判断每一位是不是1，那么时间复杂度为O(n\*logn)
  时间复杂度O(n\*logn),空间复杂度O(1)。
  
  方法二：数学之美中的方法，利用数学归纳法进行判定，设定整数点（如1、10、100等等）作为位置点i（对应n的个位、十位、百位等等），分别对每个数位上有多少包含1的点进行分析。下边以百位为例，即``i=100``
  
  - 根据设定的整数位置，对n进行分割，分为两部分，高位 ``a = n/i``，低位``b = n%i``
  - 当i表示百位，且百位对应的数>=2,如n=31456,i=100，则a=314,b=56，此时百位为1的次数有a/10+1=32（最高两位0~31），每一次都包含100个连续的点，即共有(a/10+1)\*100个点的百位为1
  - 当i表示百位，且百位对应的数为1，如n=31156,i=100，则a=311,b=56，此时百位对应的就是1，则共有a/10(最高两位0-30)次是包含100个连续点，当最高两位为31（即a=311），本次只对应局部点00~56，共b+1次，所有点加起来共有（a/10\*100）+(b+1)，这些点百位对应为1\
  - 当i表示百位，且百位对应的数为0,如n=31056,i=100，则a=310,b=56，此时百位为1的次数有a/10=31（最高两位0~30）
  - 综合以上三种情况，当百位对应0或>=2时，有(a+8)/10次包含所有100个点，还有当百位为1(a%10==1)，需要增加局部点b+1
  - 之所以补8，是因为当百位为0，则a/10==(a+8)/10，当百位>=2，补8会产生进位位，效果等同于(a/10+1)
  
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
# Python:
### 方法一：
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
### 方法二：
```python
# -*- coding:utf-8 -*-
class Solution:
    def __init__(self):
        self.result = []
    def Permutation(self, ss):
        # write code here
        if len(ss) == 0:
            return []
        self.PermutationCore(ss, 0)
        sorted(self.result)
        return self.result
    def PermutationCore(self, str_, begin):
        if begin == len(str_):
            self.result.append(str_)
            return
        for i in range(begin, len(str_)):
            if i != begin and str_[i] == str_[begin]:
                continue
            str_list = list(str_)
            str_list[i], str_list[begin] = str_list[begin], str_list[i]
            str_ = ''.join(str_list)
            self.PermutationCore(str_, begin+1)
```
## 参考
  - [C++ vector去除重复元素](https://blog.csdn.net/u010141928/article/details/78671603)
  - [Python 字符串去除最后一个字符](https://www.codenong.com/15478127/)
  - [LeetCode—46题—全排列](https://github.com/bryceustc/LeetCode_Note/blob/master/cpp/Permutations/README.md)
  - [LeetCode—47题—全排列II](https://github.com/bryceustc/LeetCode_Note/blob/master/cpp/Permutations-II/README.md)


