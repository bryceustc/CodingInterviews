## Python Solution 1:
class Solution:
    def findMin(self, nums: List[int]) -> int:
        n = len(nums)
        if n==0:
            return 0
        res = nums[0]
        for i in range (n):
            if res >nums[i]:
                res = nums[i]
        return res
## Python Solution 2:
class Solution:
    def findMin(self, nums: List[int]) -> int:
        n = len(nums)
        if n==0:
            return 0
        res = nums[0]
        start = 0
        end = n-1
        while end>=start:
            mid = start+(end-start)//2
            if nums[mid]>=res:
                start=mid+1
            if nums[mid]<res:
                end = mid-1
            res = min(res,nums[mid])
        return res
## Python Solution 3:
class Solution:
    def findMin(self, nums: List[int]) -> int:
        n = len(nums)
        if n==0:
            return 0
        res = nums[0]
        for i in range (n):
            if res >nums[i]:
                res = nums[i]
        return res
