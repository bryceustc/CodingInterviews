# -*- coding:utf-8 -*-
class Solution:
    def Power(self, x, n):
        # write code here
        if x==0.0 and n<0:
            return 0.0
        res = 1.0
        if n <0:
            x=1.0/x
            n=-n
        while n:
            if n&1==1:
                res*=x
            x*=x
            n=n>>1
        return res
