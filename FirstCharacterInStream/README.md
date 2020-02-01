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
  
  


