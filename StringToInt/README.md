# 题目:把字符串转换成整数
## 题目描述：
将一个字符串转换成一个整数(实现Integer.valueOf(string)的功能，但是string不符合数字要求时返回0)，要求不能使用字符串转换整数的库函数。 数值为0或者字符串不是一个合法的数值则返回0。


# 本题考点：
  
  注意特殊情况的输入，考虑边界情况，只有正负号、空字符串、数据上下溢出、有无正负号、错误字符等。
  
  这道题要考虑全面，对异常值要做出处理。

  对于这个题目，需要注意的要点有：

  - 指针是否为空指针以及字符串是否为空字符串；
  - 字符串对于正负号的处理；
  - 输入值是否为合法值，即小于等于'9'，大于等于'0'；
  - int为32位，需要判断是否溢出；
  - 使用错误标志，区分合法值0和非法值0。
  
# 解题思路:
  方法一：直接法，从字符串依次遍历。
  
  方法二：同样为直接法，但是判断溢出，用了一个小技巧。
  
  方法三：更全面，代码中用两个函数来实现该功能，其中标志位g_nStatus用来表示是否为异常输出，minus标志位用来表示是否为负数。
# 代码

[C++](./StringToInt.cpp)

[Python](./StringToInt.py)

# C++: 
### 方法一：直接法（不太好）
```c++
class Solution {
public:
    int StrToInt(string s) {
        long int res = 0;
        int n = s.size();
        int flag = 1;
        if (s.empty()||s[0]=='0') return res;
        if (s[0]=='-')
            flag = -1;
        for (int i=0;i<n;i++)
        {
            if (s[i]=='+'||s[i]=='-'&&i==0)
                continue;
            if (s[i]=='+'||s[i]=='-'&&i!=0)
                return 0;
            long int temp = s[i]-'0';
            if (temp>=0 && temp<=9)
                res = res*10+temp;
            else 
                return 0;
        }
        res *=flag;
        if (res > 2147483647 || res < -2147483648) res = 0;
        return res;
    }
};
```
### 方法二：直接法
```c++
class Solution {
public:
    int StrToInt(string str) {
        int res = 0;
        int n = str.size();
        int i=0;
        int flag = 1;
        // 去除空格和回车符号
        while(i<n&&(str[i]==' '||str[i]=='\t'))
        {
            i++;
        }
        //判断正负号
        if (str[i]=='-')
        {
            flag = -1;
            i++;
        }
        if (str[i]=='+')
        {
            if (flag==-1)
            {
                return 0;
            }
            i++;
        }
        for (int j = i;j<n;j++)
        {
            if (str[j]>='0'&&str[j]<='9')
            {
                int temp = str[j]-'0';
                if (res > 2147483647/10 || (res == 2147483647/10 && temp >7 && flag ==1) || (res == 2147483647/10 && temp >8 && flag ==-1))
                    return 0;
                按位运算
                res = (res << 1) + (res << 3) + (str[i] & 0xf);//res=res*10+str[i]-'0';
                // 字符'0'到'9'的ascii值的低4个二进制位刚好就是0到9所以str[i]&0xf等于str[i]-'0'
                res = res*10 + temp;
            }
            else
                return 0;
        }
        res *= flag;
        return res;
    }
};
```
### 方法三：
```c++
class Solution {
public:
    enum Status{kValid = 0, kInValid};
    int g_nStatus = kValid;
    int StrToInt(string str) {
        g_nStatus = kInValid;
        long long num = 0;
        const char* cstr = str.c_str();
        // 判断是否为指针和是否为空字符串
        if(cstr != NULL && *cstr != '\0'){
            // 正负号标志位，默认是加号
            bool minus = false;
            if(*cstr == '+'){
                cstr++;
            }
            else if(*cstr == '-'){
                minus = true;
                cstr++;
            }
            if(*cstr != '\0'){
                num = StrToIntCore(cstr, minus);
            }
        }
        return (int)num;
    }
private:
    long long StrToIntCore(const char* cstr, bool minus){
        long long num = 0;
        while(*cstr != '\0'){
            // 判断是否是非法值
            if(*cstr >= '0' && *cstr <= '9'){
                int flag = minus ? -1 : 1;
                num = num * 10 + flag * (*cstr - '0');
                // 判断是否溢出,32位
                if((!minus && num > 0x7fffffff) || (minus && num < (signed int)0x80000000)){
                    num = 0;
                    break;
                }
                cstr++;
            }
            else{
                num = 0;
                break;
            }
        }
        // 判断是否正常结束
        if(*cstr == '\0'){
            g_nStatus = kValid;
        }
        return num;
    }
};
```
# Python:
### 方法一：直接法
```python
# -*- coding:utf-8 -*-
class Solution:
    def StrToInt(self, s):
        # write code here
        res = 0
        n = len(s)
        if n==0:
            return 0
        flag = 1
        if s[0]=='-':
            flag = -1
        for i in range(n):
            if s[i]=='+' or s[i]=='-' and i==0:
                continue
            if s[i]=='+' or s[i]=='-' and i!=0:
                return 0
            if s[i]>='0' and s[i]<='9':
                temp = int (ord(s[i])-ord('0'))
                res = res*10+temp
            else:
                return 0
        res *= flag
        if res > 2147483647 or res < -2147483648:
            return 0
        return res
```
### 方法二：
```python
# -*- coding:utf-8 -*-
class Solution:
    def StrToInt(self, s):
        # write code here
        res = 0
        n = len(s)
        flag = 1
        if n==0:
            return 0
        i = 0
        while i<n and (s[i]==' 'or s[i]=='/t'):
            i+=1
        if i<n and s[i]=='-':
            flag = -1
            i+=1
        if i<n and s[i]=='+':
            if flag==-1:
                return 0
            i+=1
        for j in range(i,n):
            if (s[j]>='0' and s[j]<='9'):
                temp = int(ord(s[j])-ord('0'))
                res = res*10 + temp
            else:
                return 0
        res*=flag
        if res > 2147483647 or res < -2147483648:
            return 0
        return res
```
### 方法三：字符串转数字,巧妙方法
```python
# -*- coding:utf-8 -*-
class Solution:
    def StrToInt(self, s):
        # write code here
        numlist=['0','1','2','3','4','5','6','7','8','9','+','-']
        res=0
        label=1#正负数标记
        if s=='':
            return 0
        for string in s:
            if string in numlist:#如果是合法字符
                if string=='+':
                    label=1
                    continue
                if string=='-':
                    label=-1
                    continue
                else:
                    res=res*10+numlist.index(string)
            if string not in numlist:#非合法字符
                res=0
                break#跳出循环
        res*=label
        if res > 2147483647 or res < -2147483648:
            return 0
        return res
```
## 参考
  -  [LeetCode—8题—字符串转换整数(atoi)](https://github.com/bryceustc/LeetCode_Note/blob/master/cpp/String-To-Integer-Atoi/README.md)
  

