# -*- coding:utf-8 -*-
class Solution:
    def IsPopOrder(self, pushV, popV):
        # write code here
        n = len(pushV)
        m = len(popV)
        if n!=m:
            return False
        s = []
        index = 0
        for i in range(n):
            s.append(pushV[i])
            while len(s)>0 and s[-1]==popV[index]:
                s.pop()
                index+=1
        if len(s)==0:
            return True
        return False
