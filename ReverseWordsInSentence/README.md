# 题目:翻转单词顺序
## 题目描述：
输入一个英文句子，翻转句子中单词的顺序，但单词内的字符的顺序不变。为简单起见，标点符号和普通字母一样处理。例如输入字符串"I am a student."，则输出"student. am I"。


# 本题考点：
  
  数组与字符串的编程能力，哈希表的运用。
  
# 解题思路:
  方法一：直接法，利用双指针``i=n;j=n-1;``，j从后向前遍历，如果遇到空格，就将所在位置j+1到i的一个单词加入res中(因为j位置为空格)，然后在添加空格，并更新i所指位置``i=j``，因为使用了j+1所以不要忘记当j=0时。但是需要考虑没有空格的情形，例如只有一个单词 student，需要判断``if(j==0&&res!="")``这时将位置j到i的位置的单词加入res即可。当``if(j==0&&res=="")``，此时直接``res=s;``即可，然后返回res。
  
  时间复杂度为O(n<sup>2</sup>),空间复杂度O(1)。  
# 代码

[C++](./ReverseWordsInSentence.cpp)

[Python](./ReverseWordsInSentence.py)

# C++: 
### 方法一：直接法，不推荐
```c++
class Solution {
public:
    string ReverseSentence(string s) {
        string res="";
        int n = s.size();
        if (n==0)
            return res;
        if (n==1)
            return s;
        for (int i=n,j=n-1;j>=0;j--)
        {
            if (s[j]==' ')
            {
                for(int k=j+1;k<i;k++)
                {
                    res+=s[k];
                }
                res += s[j];
                i=j;
            }
            if (j==0 && res!="")
            {
                for (int x=j;x<i;x++)
                {
                    res+=s[x];
                }
            }
            if (j==0 && res=="")
            {
                res = s;
            }
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
  
  



