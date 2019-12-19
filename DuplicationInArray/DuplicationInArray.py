# -*- coding:utf-8 -*-
class Solution:
    # 这里要特别注意~找到任意重复的一个值并赋值到duplication[0]
    # 函数返回True/False
    def duplicate(self, nums):
        duplication=[]
        n = len(nums)
        for i in range (n):
            while nums[i]!=i:
                if nums[i]==nums[nums[i]]:
                    duplication.append(nums[i])
                    return True
                temp = nums[i]
                nums[i] = nums[nums[i]]
                nums[temp] = temp
        return False

if __name__ == '__main__':
    nums=[2,3,1,0,2,5,3]
    res = Solution().duplicate(nums)
    print(res)
