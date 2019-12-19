# -*- coding:utf-8 -*-
class Solution:
    # 这里要特别注意~找到任意重复的一个值并赋值到duplication[0]
    # 函数返回True/False
    def duplicate(self, nums):
        n = len(nums)-1
        start = 1
        end = n
        while start < end:
            m = 0
            mid = start + (end-start)//2
            for i in range(n+1):
                if nums[i] >= start and nums[i] <= mid:
                    m += 1
            if m > mid-start+1:
                end = mid
            else:
                start = mid+1
        return start


if __name__ == '_ main__':
    nums = [2, 3, 5, 4, 3, 2, 6, 7]
    res = Solution().duplicate(nums)
    print(res)
