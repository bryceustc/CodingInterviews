## Solution 
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
## Solution 2:
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
## Solution 3:
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
