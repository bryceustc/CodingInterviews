class Solution:
    def translateNum(self, num: int) -> int:
        s = str(num)
        n = len(s)
        dp = [1 for _ in range(n+1)]
        for i in range(2,n+1):
            if s[i-2] == '0' or (s[i-2:i]>"25"):
                dp[i] = dp[i-1]
            else:
                dp[i] = dp[i-1] + dp[i-2]
        return dp[n]
