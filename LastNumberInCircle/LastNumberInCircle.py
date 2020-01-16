# -*- coding:utf-8 -*-
class Solution:
    def LastRemaining_Solution(self, n, m):
        # write code h;
        res = -1
        if n<=0 or m<0:
            return res
        nums =range(n)## 0-n-1数组
        start=0
        while len(nums)>1:
            end = (start+m-1)%(len(nums))
            del nums[end]
            start = end
        return nums[0]
