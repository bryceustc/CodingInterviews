# 题目:左旋转字符串
## 题目描述：
字符串的左旋转操作是把字符串前面若干个字符转移到字符串尾部。请定义一个函数实现字符串左旋转操作的功能。比如，输入字符串"abcdefg"和数字2，该函数返回左旋转两位得到的结果"cdefgab"。


# 本题考点：
  
  数组与字符串的编程能力，哈希表的运用。
  
# 解题思路:
  方法一：直接法，定义一个左移一位函数leftmove，先定义一个``char temp = s[0];``。其余``s[i]==s[i+1];``，n-1位置最后一个字符替换为temp。左移几位就循环几次左移函数。
  
  方法二：利用字符串翻转的，原理：YX=(X<sup>T</sup> Y<sup>T</sup>)^<sup>T</sup>
  
  以”abcdefg“为例，我们可以把它分为两部分。由于想把它的前两个字.符移到后面，我们就把前两个字符分到第一部分， 把后面的所有字符分到第二部分。我们先分别翻转这两部分，于是就得到”bagfedc“。接下来翻转整个字符串，得到的”cdefgab“刚好就是把原始字符串左旋转两位的结果。
  
  方法三：取巧法，``s+=s;``，复制一遍字符串，从n开始处截取原字符串长度返回即可。
# 代码

[C++](./LeftRotateString.cpp)

[Python](./LeftRotateString.py)

# C++: 
### 方法一：直接左移
```c++
class Solution {
public:
    void move(string &s)
    {
        int n = s.size();
        char temp = s[0];
        for (int i=0;i<n;i++)
        {
            if (i!=n-1)
                s[i]=s[i+1];
            else
                s[i]=temp;
        }
    }
    string LeftRotateString(string s, int n) {
        int m = s.size();
        if (m<n) return "";
        for (int i=0;i<n;i++)
        {
            move(s);
        }
        return s;
    }
};
```
### 方法二：利用翻转单词顺序中的Reverse函数，YX=(X<sup>T</sup> Y<sup>T</sup>)^<sup>T</sup>
```c++
class Solution {
public:
    void Reverse(string &s，int i, int j)
    {
        while(i<j)
        {
            swap(s[i++],s[j--]);
        }
    }
    string LeftRotateString(string s, int n) {
        int m = s.size();
        if (m<n) return "";
        // 将字符分为两部分，一是移动的部分，二是剩余部分
        // 翻转需要移动的字符
        Reverse(s,0,n-1);
        // 翻转剩余部分字符
        Reverse(s,n,m-1);
        // 整体翻转
        Reverse(s,0,m-1);
        return s;
    }
};
```
### 方法三：
```c++
class Solution {
public:
    string LeftRotateString(string s, int n) {
        int m = s.size();
        if (m<n) return "";
        s+=s;
        int start = n%m;
        s = s.substr(start,m);
        return s;
    }
};
```
# Python:
### 方法一：直接法
```python
# -*- coding:utf-8 -*-
class Solution:
    def LeftRotateString(self, s, n):
        # write code here
        m = len(s)
        if n>m:
            return ""
        for i in range(n):
            s = self.move(s)
        return s
    def move(self,s):
        s = list(s)
        n = len(s)
        temp  = s[0]
        for i in range(n):
            if i!=n-1:
                s[i]=s[i+1]
            else:
                s[i] = temp
        return ''.join(s)
```
### 方法二：利用翻转函数：
```python
# -*- coding:utf-8 -*-
class Solution:
    def LeftRotateString(self, s, n):
        # write code here
        m = len(s)
        if n>m:
            return ""
        s = self.Reverse(s,0,n-1)
        s = self.Reverse(s,n,m-1)
        s = self.Reverse(s,0,m-1)
        return s
    def Reverse(self,s,i,j):
        s = list(s)
        while i<j:
            s[i],s[j]=s[j],s[i]
            i+=1
            j-=1
        return ''.join(s)
```
### 方法三：取巧法
```python
# -*- coding:utf-8 -*-
class Solution:
    def LeftRotateString(self, s, n):
        # write code here
        m = len(s)
        if m<n:
            return ""
        s = s+s
        s = list(s)
        s = ''.join(s[n:m+n])
        return s
```
## 参考
  -  [LeetCode—796题—旋转的字符串](https://github.com/bryceustc/LeetCode_Note/blob/master/cpp/Rotate-String/README.md)
  -  [剑指offer—58题—翻转单词顺序](https://github.com/bryceustc/CodingInterviews/blob/master/ReverseWordsInSentence/README.md)
  
