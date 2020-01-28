# 题目:表示数值的字符串
## 题目描述：
请实现一个函数用来判断字符串是否表示数值（包括整数和小数）。例如，字符串"+100","5e2","-123","3.1416"和"-1E-16"都表示数值。 但是"12e","1a3.14","1.2.3","+-5"和"12e+4.3"都不是。
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

用一张图表示如下：

![](https://github.com/bryceustc/CodingInterviews/blob/master/RegularExpressionsMatching/Image/1.png)

除此之外，还要注意对空指针的处理


复杂度分析：
![](https://github.com/bryceustc/CodingInterviews/blob/master/RegularExpressionsMatching/Image/%E5%A4%8D%E6%9D%82%E5%BA%A6%E5%88%86%E6%9E%90.png)
# 代码

[C++](./NumericStrings.cpp)

[Python](./NumericStrings.py)

# C++: 
```c++
class Solution {
public:
    // 数字的格式可以用A[.[B]][e|EC]或者.B[e|EC]表示，
    // 其中A和C都是整数（可以有正负号，也可以没有）
    // 而B是一个无符号整数
    bool isNumeric(char* str)
    {
        // 非法输入处理
        if (*str == '\0')
            return false;
        // 标记符号、小数点、e是否出现过
        bool sign = false, decimal = false, hasE = false;
        int n = strlen(str);
        for (int i=0;i<n;i++)
        {
            if (str[i]=='e' || str[i] == 'E')
            {
                if (i == n-1)  return false; // e后面一定要接数字
                if (hasE)  return false; // 不能同时存在两个e
                hasE = true;
            }
            else if (str[i] == '+' || str[i]=='-')
            {
                if (sign && str[i-1]!='e' && str[i-1]!= 'E') // 第二次符号出现必须接在e之后
                    return false;
                if (!sign && i>0 && str[i-1]!='e' && str[i-1]!='E') // 第一次出现'+''-'符号且不在字符串开头 则必须出现在e之后
                    return false;
                sign = true;
            }
            else if (str[i]=='.')
            {
                if (hasE || decimal)
                    return false;
                decimal = true;
            }
            else if (str[i]<'0'||str[i]>'9')
                return false;
        }
        return true;
    }
};
```
# Python:
```python
# -*- coding:utf-8 -*-
class Solution:
    # s字符串
    def isNumeric(self, s):
        # write code here
        n = len(s)
        if n==0:
            return False
        sign = False
        decimal = False
        hasE = False
        for i in range(0,n):
            if s[i] == 'e' or s[i]=='E':
                if i == n-1:
                    return False
                if hasE:
                    return False
                hasE = True
            elif s[i]=='+' or s[i]=='-':
                if sign and s[i-1]!= 'e' and s[i-1] != 'E':
                    return False
                if not sign and i>0 and s[i-1] != 'e' and s[i-1]!='E':
                    return False
                sign = True
            elif s[i]=='.':
                if hasE or decimal:
                    return False
                decimal = True
            elif s[i]<'0' or s[i]>'9':
                return False
        return True
```
