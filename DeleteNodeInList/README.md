# 题目:删除链表的节点
## 题目描述：
给定单向链表的头指针和一个节点指针，定义一个函数在O(1)时间内删除该节点。链表节点与函数的定义如下。
```c++
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
void DeleteNode(ListNode* head, ListNode* ToBeDeleted);
```

# 本题考点：
  
  链表的编程能力，创新思维能力，思维的全面性
  
# 解题思路:
  ![1]()
  思路一：删除节点时不一定直接是直接删除，还可以是将下一节点的内容复制到被删除节点的内容，然后把下一节点删掉。
  
  思路二：直接删除该节点，按顺序遍历，被删除节点的前一个节点指向被删除节点的下一节点，即删除指定节点，但此时需要从头指针遍历得到被删除节点的前一个节点(单向链表无法得到指向前一个节点的指针)，所以时间复杂度为O(n)。
# 代码

[C++](./DeleteNodeInList.cpp)

[Python](./DeleteNodeInList.py)

# C++: 
### 
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
