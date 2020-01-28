# 题目:表示数值的字符串
## 题目描述：
请实现一个函数用来判断字符串是否表示数值（包括整数和小数）。例如，字符串"+100","5e2","-123","3.1416"和"-1E-16"都表示数值。 但是"12e","1a3.14","1.2.3","+-5"和"12e+4.3"都不是。
# 本题考点：
  
  字符串编程能力，正则表达式的理解，思维的全面性。
  
# 解题思路:
  
  表示数值的字符串遵循如下模式A[.[B]][e|EC]或者.B[e|EC],其中A 为数值的整数部分，B紧跟着小数点为小数部分，C紧跟着'e'或'E'为数值的指数部分。
  
  上述A和C都是可能以'+'或'-'开头的0~9的数位串，B是0~9的数位串，但不能有+-号。
  
  判断一个字符串是否符合上述模式时，可以先判断字符是不是是不是'e'或'E'。如果是，判断i是否为strlen(str)-1，是就返回False，因为e后边必须要有数字，再判断是否应有'e'或者'E'，有也返回False，因为一个数值串不允许有两个'E'，然后将hasE 设为True。然后继续判断是否是'+'或'-'，如果是第二次出现也str[i-1]必须为e或E，否则返回False，如果是第一次出现且不在开头（i>0）则str[i-1]必须为e或E，否则返回False，然后令sign为True。然后判断是不是小数点符号，是的话在此之前不能有e后者E或者出现过小数点，否则就返回False。然后判断字符是否在0~9范围内，不在就返回False。最后满足所有条件，就返回True。
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

