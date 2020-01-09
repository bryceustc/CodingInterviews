### Python Solution 1:
# -*- coding:utf-8 -*-
class Solution:
    def isUgly(self, num: int) -> bool:
        if num <1:
            return False
        while num%5 == 0:
            num//=5
        while num%3 == 0:
            num//=3
        while num%2 == 0:
            num//=2
        return num==1
    def GetUglyNumber_Solution(self, n: int) -> int:
        i = 0
        num = 0
        while i<n:
            num+=1
            if self.isUgly(num):
                i+=1
        return num
### Python Solution 2:
# -*- coding:utf-8 -*-
class Solution:
    def GetUglyNumber_Solution(self, n):
        # write code here
        if n<=0:
            return 0
        dp = [0 for _ in range(n)]
        dp[0] = 1
        l_2 = 0
        l_3 = 0
        l_5 = 0
        for i in range(1,n):
            dp[i] = min(dp[l_2]*2,dp[l_3]*3,dp[l_5]*5)
            if dp[l_2]*2<=dp[i]:
                l_2+=1
            if dp[l_3]*3<=dp[i]:
                l_3+=1
            if dp[l_5]*5<=dp[i]:
                l_5+=1
        return dp[n-1]
### Python Solution 3:
# -*- coding:utf-8 -*-
class Solution:
    def GetUglyNumber_Solution(self, n):
        # write code here
        import heapq
        if n<=0:
            return 0
        res = 0
        min_heap = []
        heapq.heappush(min_heap,1)
        for i in range (n):
            res = heapq.heappop(min_heap)
            while min_heap and res == min_heap[0]:
                res = heapq.heappop(min_heap)
            heapq.heappush(min_heap,res*2)
            heapq.heappush(min_heap,res*3)
            heapq.heappush(min_heap,res*5)
        return res
