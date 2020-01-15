# -*- coding:utf-8 -*-
class Solution:
    def IsContinuous(self, nums):
        # write code here
        n = len(nums)
        if nums is None or n!=5:
            return False
        nums = sorted(nums)
        numZero = 0
        gap = 0
        for num in nums:
            if num ==0:
                numZero+=1
        for i in range(numZero,n-1):
            j=i+1
            if nums[j]==nums[i]:
                return False
            gap += nums[j]-nums[i]-1
        if gap > numZero:
            return False
        return True
