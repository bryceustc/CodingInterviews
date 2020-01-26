# 题目:正则表达式匹配
## 题目描述：
请实现一个函数用来匹配包括’.’和’\*‘的正则表达式。模式中的字符’.’表示任意一个字符，而’\*‘表示它前面的字符可以出现任意次（包含0次）。 在本题中，匹配是指字符串的所有字符匹配整个模式。例如，字符串”aaa”与模式”a.a”和”abaca”匹配，但是与”aa.a”和”ab\*a”均不匹配
# 本题考点：
  
  字符串编程能力，正则表达式的理解，思维的全面性。
  
# 解题思路:
  
  1.) 回溯 
  先分析下如何匹配一个字符，现在只考虑字符'.'，不考虑'\*'看一下：

如果字符串和模式串的当前字符相等，那么我们继续匹配它们的下一个字符；如果模式串中的字符是'.'，那么它可以匹配字符串中的任意字符，我们也可以继续匹配它们的下一个字符。

接下来，把字符'\*'考虑进去，它可以匹配任意次的字符，当然出现0次也可以。

我们分两种情况来看：

模式串的下一个字符不是'\*'，也就是上面说的只有字符'.'的情况。
如果字符串中的第一个字符和模式串中的第一个字符相匹配，那么字符串的模式串都向后移动一个字符，然后匹配剩余的字符串和模式串。如果字符串中的第一个字符和模式中的第一个字符不相匹配，则直接返回false。

模式串的下一个字符是'\*'，此时就要复杂一些。
因为可能有多种不同的匹配方式。

选择一：无论字符串和模式串当前字符相不相等，我们都将模式串后移两个字符，相当于把模式串中的当前字符和'\*'忽略掉，因为'\*'可以匹配任意次的字符，所以出现0次也可以。

选择二：如果字符串和模式串当前字符相等，则字符串向后移动一个字符。而模式串此时有两个选择：

1、我们可以在模式串向后移动两个字符，继续匹配；

2、也可以保持模式串不变，这样相当于用字符'\*'继续匹配字符串，也就是模式串中的字符'\*'匹配字符串中的字符多个的情况。
 
![]()
# 代码

[C++](./RegularExpressionsMatching.cpp)

[Python](./RegularExpressionsMatching.py)

# C++: 
###
```c++

/*
    首先，考虑特殊情况：
         1>两个字符串都为空，返回true
         2>当第一个字符串不空，而第二个字符串空了，返回false（因为这样，就无法
            匹配成功了,而如果第一个字符串空了，第二个字符串非空，还是可能匹配成
            功的，比如第二个字符串是“a*a*a*a*”,由于‘*’之前的元素可以出现0次，
            所以有可能匹配成功）
    之后就开始匹配第一个字符，这里有两种可能：匹配成功或匹配失败。但考虑到pattern
    下一个字符可能是‘*’， 这里我们分两种情况讨论：pattern下一个字符为‘*’或
    不为‘*’：
          1>pattern下一个字符不为‘*’：这种情况比较简单，直接匹配当前字符。如果
            匹配成功，继续匹配下一个；如果匹配失败，直接返回false。注意这里的
            “匹配成功”，除了两个字符相同的情况外，还有一种情况，就是pattern的
            当前字符为‘.’,同时str的当前字符不为‘\0’。
          2>pattern下一个字符为‘*’时，稍微复杂一些，因为‘*’可以代表0个或多个。
            这里把这些情况都考虑到：
               a>当‘*’匹配0个字符时，str当前字符不变，pattern当前字符后移两位，
                跳过这个‘*’符号；
               b>当‘*’匹配1个或多个时，str当前字符移向下一个，pattern当前字符
                不变。（这里匹配1个或多个可以看成一种情况，因为：当匹配一个时，
                由于str移到了下一个字符，而pattern字符不变，就回到了上边的情况a；
                当匹配多于一个字符时，相当于从str的下一个字符继续开始匹配）
    之后再写代码就很简单了。
*/
class Solution {
public:
    bool match(char* str, char* pattern)
    {
        if (*str == '\0' && *pattern == '\0')
            return true;
        if (*str != '\0' && *pattern == '\0')
            return false;
        if (*(pattern +1) !='*')
        {
            if (* str == * pattern || (*str !='\0'&& *pattern =='.'))
                return match(str+1,pattern+1);
            else
                return false;
        }
        else
        {
            if (* str == * pattern || (*str!='\0')&& *pattern == '.')
                return (match(str,pattern+2) || match(str+1,pattern));
            else
                return (match(str,pattern+2));
        }
    }
};
```

### 方法二：动态规划
```c++

```
# Python:
### 方法一：回溯法
```python
# -*- coding:utf-8 -*-
class Solution:
    # s, pattern都是字符串
    def match(self, s, p):
        # write code here
        if len(s)==0 and len(p)==0:
            return True
        if len(s)!=0 and len(p)==0:
            return False
        if  len(p)>1 and p[1]=='*':
            if len(s)>0 and (s[0] == p[0] or p[0]=='.'):
                return self.match(s,p[2:]) or self.match(s[1:],p)
            else:
                return self.match(s,p[2:])
        if len(s)>0 and (s[0] == p[0] or p[0]=='.'):
            return self.match(s[1:],p[1:])
        else:
            return False
```
### 方法二：动态规划
```python
# -*- coding:utf-8 -*-
class Solution:
    # s 源字符串
    def replaceSpace(self, s):
        # write code here
        s = list(s)
        count = len(s)
        for i in range(0,count):
            if s[i] == ' ':
                s[i] = '%20'
        return ''.join(s)
```

