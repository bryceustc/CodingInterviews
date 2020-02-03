# 题目:左旋转字符串
## 题目描述：
字符串的左旋转操作是把字符串前面若干个字符转移到字符串尾部。请定义一个函数实现字符串左旋转操作的功能。比如，输入字符串"abcdefg"和数字2，该函数返回左旋转两位得到的结果"cdefgab"。


# 本题考点：
  
  数组与字符串的编程能力，哈希表的运用。
  
# 解题思路:
  方法一：直接法，定义一个左移一位函数leftmove，先定义一个``char temp = s[0];``。其余``s[i]==s[i+1];``，n-1位置最后一个字符替换为temp。左移几位就循环几次左移函数。
  
  方法二：利用字符串翻转的，原理：YX=\left(X^{\top} Y^{\top}\right)^{\top}
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
### 方法二：利用翻转单词顺序中的Reverse函数，YX=\left(X^{\top} Y^{\top}\right)^{\top}
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
  -  [LeetCode—796题—旋转的字符串](https://github.com/bryceustc/LeetCode_Note/blob/master/cpp/First-Unique-Character-In-A-String/README.md)
  -  [剑指offer—50题—第一个只出现一次的字符](https://github.com/bryceustc/CodingInterviews/blob/master/FirstNotRepeatingChar/README.md)
  -  [c++ count函数用法](https://blog.csdn.net/qq_36122764/article/details/82429976)
  -  [Python lambda用法()](https://blog.csdn.net/u011630575/article/details/79450225)
  -  [Python count()方法](https://www.runoob.com/python/att-string-count.html)
  -  [Python3 filter()函数用法](https://www.runoob.com/python3/python3-func-filter.html)注意：Pyhton2.7 返回列表，Python3.x 返回迭代器对象
  
  



