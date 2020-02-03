## Python Solution 1:
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
## Python Solution 2:
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
## Python Solution 3:
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
