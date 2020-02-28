class Solution:
    def singleNumbers(self, nums: List[int]) -> List[int]:
        number = 0
        res = [0,0]
        for num in nums:
            number ^= num
        pos = 1
        while (number&pos) == 0:
            pos <<=1
        for num in nums:
            if (num&pos) == pos:
                res[0] ^= num
            else:
                res[1] ^= num
        return res
