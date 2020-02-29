# -*- coding:utf-8 -*-
class Solution:
    def jumpFloorII(self, n):
        # write code here
        if n==0:
            return 0
        res = 1
        for i in range(1,n):
            res *= 2
        return res
