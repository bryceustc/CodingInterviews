# 题目:字符流中第一个不重复的字符
## 题目描述：
请实现一个函数用来找出字符流中第一个只出现一次的字符。例如，当从字符流中只读出前两个字符"go"时，第一个只出现一次的字符是"g"。当从该字符流中读出前六个字符“google"时，第一个只出现一次的字符是"l"。

**输入描述:**
```
如果当前字符流没有存在出现一次的字符，返回#字符。
```

# 本题考点：
  
  数组与字符串的编程能力，哈希表的运用。
  
# 解题思路:
  方法一：哈希表，与字符串中第一个出现一次的字符类似。重点理解字符流，需要定义全局变量``string s;``还有``unordered_map<char,int> m;``，Insert函数是插入一个ch字符，那么对应就是string操作就是``s+=ch;``，然后再用哈希表进行操作，``m[ch]++;``，再遍历字符串s,判断第一个只出现一次的字符。
  
  时间复杂度为O(n),空间复杂度O(n)。
  
  方法二：数学之美中的方法，利用数学归纳法进行判定，设定整数点（如1、10、100等等）作为位置点i（对应n的个位、十位、百位等等），分别对每个数位上有多少包含1的点进行分析。下边以百位为例，即``i=100``
  
  - 根据设定的整数位置，对n进行分割，分为两部分，高位 ``a = n/i``，低位``b = n%i``
  - 当i表示百位，且百位对应的数>=2,如n=31456,i=100，则a=314,b=56，此时百位为1的次数有a/10+1=32（最高两位0~31），每一次都包含100个连续的点，即共有(a/10+1)\*100个点的百位为1
  - 当i表示百位，且百位对应的数为1，如n=31156,i=100，则a=311,b=56，此时百位对应的就是1，则共有a/10(最高两位0-30)次是包含100个连续点，当最高两位为31（即a=311），本次只对应局部点00~56，共b+1次，所有点加起来共有（a/10\*100）+(b+1)，这些点百位对应为1\
  - 当i表示百位，且百位对应的数为0,如n=31056,i=100，则a=310,b=56，此时百位为1的次数有a/10=31（最高两位0~30）
  - 综合以上三种情况，当百位对应0或>=2时，有(a+8)/10次包含所有100个点，还有当百位为1(a%10==1)，需要增加局部点b+1
  - 之所以补8，是因为当百位为0，则a/10==(a+8)/10，当百位>=2，补8会产生进位位，效果等同于(a/10+1)
  时间复杂度O(logn),空间复杂度O(1)。
  
# 代码

[C++](./FirstCharacterInStream.cpp)

[Python](./FirstCharacterInStream.py)

# C++: 
### 方法一：哈希表，时间复杂度O(n)
```c++
class Solution
{
public:
  //Insert one char from stringstream
    unordered_map<char,int> m;
    string s;
    void Insert(char ch)
    {
        s += ch;
        m[ch]++;
    }
  //return the first appearence once char in current stringstream
    char FirstAppearingOnce()
    {
        char res = '#';
        int n = s.size();
        for (int i=0;i<n;i++)
        {
            if (m[s[i]]==1)
                return s[i];
        }
        return res;
    }
};
```
# Python:
### 哈希表
```python
# -*- coding:utf-8 -*-
class Solution:
    # 返回对应char
    def __init__(self):
        self.s= ""
    def FirstAppearingOnce(self):
        # write code here
        res = "#"
        for ch in self.s:
            if self.s.count(ch)==1:
                return ch
        return res
    def Insert(self, char):
        # write code here
        self.s+=char
```
### 哈希表另一种写法：
```python
# -*- coding:utf-8 -*-
class Solution:
    # 返回对应char
    def __init__(self):
        self.s= ""
    def FirstAppearingOnce(self):
        # write code here
        res = list(filter(lambda c: self.s.count(c)==1,self.s))
        return res[0] if res else "#"
    def Insert(self, char):
        # write code here
        self.s+=char
```

## 参考
  -  [LeetCode—387题—字符串中第一个唯一字符](https://github.com/bryceustc/LeetCode_Note/blob/master/cpp/First-Unique-Character-In-A-String/README.md)
  -  [剑指offer—50题—第一个只出现一次的字符](https://github.com/bryceustc/CodingInterviews/blob/master/FirstNotRepeatingChar/README.md)
  -  [c++ count函数用法](https://blog.csdn.net/qq_36122764/article/details/82429976)
  -  [Python lambda用法()](https://blog.csdn.net/u011630575/article/details/79450225)
  -  [Python count()方法](https://www.runoob.com/python/att-string-count.html)
  -  [Python3 filter()函数用法](https://www.runoob.com/python3/python3-func-filter.html)注意：Pyhton2.7 返回列表，Python3.x 返回迭代器对象
  
  


