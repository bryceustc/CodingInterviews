# 题目:翻转单词顺序
## 题目描述：
输入一个英文句子，翻转句子中单词的顺序，但单词内的字符的顺序不变。为简单起见，标点符号和普通字母一样处理。例如输入字符串"I am a student."，则输出"student. am I"。


# 本题考点：
  
  字符串的编程能力。
  
# 解题思路:
  此题与LeetCode151题类似，但比那题简单一点，无需去除多余空格

  方法一：直接法，利用双指针``i=n;j=n-1;``，j从后向前遍历，如果遇到空格，就将所在位置j+1到i的一个单词加入res中(因为j位置为空格)，然后在添加空格，并更新i所指位置``i=j``，因为使用了j+1所以不要忘记当j=0时。但是需要考虑没有空格的情形，例如只有一个单词 student，需要判断``if(j==0&&res!="")``这时将位置j到i的位置的单词加入res即可。当``if(j==0&&res=="")``，此时直接``res=s;``即可，然后返回res。
  
  方法二：先翻转整个句子，然后翻转单词。
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
### 方法二：翻转整个句子，然后翻转单词，推荐
```c++
class Solution {
public:
    void Reverse(string &s, int start,int end)
    {
        while(start<end)
        {
            swap(s[start],s[end]);
            start++;
            end--;
        }
    }
    string ReverseSentence(string s) 
    {
        string res;
        int n = s.size();
        // 整体翻转整个句子
        Reverse(s,0,n-1);
        int i=0;
        int start = 0;
        int end = 0;
        while(i<n)
        {
            while(i<n && s[i]==' ') i++;
            start = end = i;
            while(i<n && s[i]!=' ')
            {
                i++;
                end++;
            }
            Reverse(s,start,end-1);
        }
        return s;
    }
};
```
# Python:
```python
# -*- coding:utf-8 -*-
class Solution:
    def ReverseSentence(self, s):
        # write code here
        s = list(s)
        n = len(s)
        self.Reverse(s,0,n-1)
        i =0
        while i<n:
            while i<n and s[i]==' ':
                i+=1
            start = end = i
            while i<n and s[i]!= ' ':
                i+=1
                end+=1
            self.Reverse(s,start,end-1)
        s = ''.join(s)
        return s
    def Reverse(self,s,start,end):
        while start<end:
            s[start],s[end] = s[end],s[start]
            start+=1
            end-=1
```

## 参考
  -  [LeetCode—151题—翻转字符串里的单词](https://github.com/bryceustc/LeetCode_Note/blob/master/cpp/Reverse-Words-In-A-String/README.md)


