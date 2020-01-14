### Python Solution 1:
class Solution:
    def FindNumbersWithSum(self, nums, target):
        # write code here
        res = []
        n = len(nums)
        if n==0:
            return res
        for i in range(n):
            for j in range(i+1,n):
                if nums[i]+nums[j]==target:
                    res.append(nums[i])
                    res.append(nums[j])
                    return res
        return res
### Python Solution 2:
# -*- coding:utf-8 -*-
class Solution:
    def FindNumbersWithSum(self, nums, target):
        # write code here
        res = []
        record = {}
        n = len(nums)
        if n==0:
            return res
        for index,num in enumerate (nums):
            complement = target - num
            if complement in record:
                res.append(complement)
                res.append(num)
                return res
            record[num] = index
        return res
### Python Solution 3:
# -*- coding:utf-8 -*-
class Solution:
    def FindNumbersWithSum(self, nums, target):
        # write code here
        res = []
        n = len(nums)
        left = 0
        right = n-1
        while right>left:
            if nums[left]+nums[right]==target:
                res.append(nums[left])
                res.append(nums[right])
                return res
            if nums[left]+nums[right]>target:
                right-=1
            else:
                left+=1
        return res
