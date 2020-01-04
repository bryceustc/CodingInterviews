# -*- coding:utf-8 -*-
class Solution:
    def FindGreatestSumOfSubArray(self, nums):
        # write code here
        res = nums[0]
        dp = nums[0]
        n = len(nums)
        for i in range(1,n):
            dp = max(dp+nums[i],nums[i])
            res = max(res,dp)
        return res

if __name__ == '_ main__':
    nums = [-2,1,4]
    res = Solution().FindGreatestSumOfSubArray(nums)    
    print(res)

    
### Python Solution 1:
class Solution:
    def FindGreatestSumOfSubArray(self, nums):
        # write code here
        res = nums[0]
        n = len(nums)
        dp = [0 for _ in range(n)]
        dp[0] = nums[0]
        for i in range(1,n):
            dp[i] = max(dp[i-1]+nums[i],nums[i])
            res = max(res,dp[i])
        return res
  
  
### Python Solution 2:

class Solution:
    def FindGreatestSumOfSubArray(self, nums):
        # write code here
        res = nums[0]
        n = len(nums)
        sum_num = 0
        for num in nums:
            if sum_num>0:
                sum_num+=num
            else:
                sum_num = num
            res = max(res,sum_num)            
        return res
  
  
  ### Python Solution 3:
  class Solution:
    def FindGreatestSumOfSubArray(self, nums: List[int]) -> int:
        res = nums[0]
        n = len(nums)
        res = self.maxSubArrayHelper(nums,0,n-1)       
        return res
    def maxSubArrayHelper(self,nums,left,right):
        if left==right:
            return nums[left]
        mid = (left+right)//2
        leftSum = self.maxSubArrayHelper(nums,left,mid)
        rightSum = self.maxSubArrayHelper(nums,mid+1,right)
        midSum = self.maxCrossingSubArray(nums,left,mid,right)
        res = max(leftSum,midSum,rightSum)
        return res
    def maxCrossingSubArray(self,nums,left,mid,right):
        leftBoaderSum = nums[mid]
        cur_sum = 0
        for i in range(mid,left-1,-1):
            cur_sum+=nums[i]
            leftBoaderSum = max(leftBoaderSum,cur_sum)
        rightBoaderSum = nums[mid+1]
        cur_sum = 0
        for i in range(mid+1,right+1):
            cur_sum+=nums[i]
            rightBoaderSum = max(rightBoaderSum,cur_sum)
        return leftBoaderSum + rightBoaderSum
      
  ### Python Solution 4:
  class Solution:
    def FindGreatestSumOfSubArray(self, nums):
        # write code here
        res = nums[0]
        n = len(nums)
        for i in range(n):
            sum_num = 0
            for j in range(i,n):
                sum_num+=nums[j]
                res = max(res,sum_num)            
        return res
