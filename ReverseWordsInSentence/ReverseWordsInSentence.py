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
