class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        res = 0
        for i in range(0,32):
            count = 0
            for num in nums:
                if (num&(1<<i)):
                    count+=1
            if (count%3):
                res += 1<<i
        return res
