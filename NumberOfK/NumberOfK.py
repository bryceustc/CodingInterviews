### Python Solution 1:
# -*- coding:utf-8 -*-
class Solution:
    def GetNumberOfK(self, nums, k):
        # write code here
        res = 0
        n = len(nums)
        if n==0:
            return 0
        for i in range(n):
            if nums[i]==k:
                res+=1
        return res
### Python Solution 2:
# -*- coding:utf-8 -*-
class Solution:
    def GetNumberOfK(self, nums, k):
        # write code here
        res = 0
        n = len(nums)
        if n==0:
            return 0
        start = 0
        end = n
        while end > start:
            mid = start + (end-start)//2
            if nums[mid]==k:
                end = mid
            if nums[mid] < k:
                start = mid+1
            if nums[mid] > k:
                end = mid
        temp1 = start ## 一次二分查找寻找左侧边界
        start = 0
        end = n
        while end > start:
            mid = start + (end - start)//2
            if nums[mid] == k:
                start = mid + 1
            if nums[mid] < k:
                start = mid + 1
            if nums[mid] > k:
                end = mid
        temp2 = end - 1  ## 一次二分查找寻找右侧边界，注意右侧边界要减一
        res = temp2-temp1+1
        return res
