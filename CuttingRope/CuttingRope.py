class Solution:
    def cuttingRope(self, n: int) -> int:
        dp = [0 for _ in range(n+1)]
        dp[2] = 1
        for i in range(3,n+1):
            for j in range(1,  i-1):
                dp[i] = max(dp[i], j*(i-j), j*dp[i-j])
        return dp[n]
## Solution 2:
class Solution:
    def cuttingRope(self, n: int) -> int:
        dp = [0, 1, 1]

        for i in range(3, n + 1):
            dp[i % 3] = max(max(dp[(i - 1) % 3], i - 1),
                    2 * max(dp[(i - 2) % 3], i - 2),
                    3 * max(dp[(i - 3) % 3], i - 3))
        return dp[n % 3]
## Solution 3:
class Solution:
    def cuttingRope(self, n: int) -> int:
        if n <= 3: return n - 1
        a, b = n // 3, n % 3
        if b == 0: return int(math.pow(3, a))
        if b == 1: return int(math.pow(3, a - 1) * 4)
        return int(math.pow(3, a) * 2)
