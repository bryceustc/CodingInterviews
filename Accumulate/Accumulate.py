class Solution:
    def sumNums(self, n: int) -> int:
        res = n
        if res:
            res+= self.sumNums(n-1)
        return res
