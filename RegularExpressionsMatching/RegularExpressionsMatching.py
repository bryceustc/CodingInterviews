### Solution 1:
# -*- coding:utf-8 -*-
class Solution:
    # s, pattern都是字符串
    def match(self, s, p):
        # write code here
        if len(s)==0 and len(p)==0:
            return True
        if len(s)!=0 and len(p)==0:
            return False
        if  len(p)>1 and p[1]=='*':
            if len(s)>0 and (s[0] == p[0] or p[0]=='.'):
                return self.match(s,p[2:]) or self.match(s[1:],p)
            else:
                return self.match(s,p[2:])
        if len(s)>0 and (s[0] == p[0] or p[0]=='.'):
            return self.match(s[1:],p[1:])
        else:
            return False


### Solution 2：
# -*- coding:utf-8 -*-
class Solution:
    # s, pattern都是字符串
    def match(self, s, p):
        # write code here
        n = len(s)
        m = len(p)
        dp = [[0 for _ in range(m+2)] for _ in range(n+2)]
        s = ' ' + s
        p = ' ' + p
        dp[0][0] = 1
        for i in range(n+1):
            for j in range(1,m+1):
                if i > 0 and (s[i]==p[j] or p[j]=='.'):
                    dp[i][j] = dp[i][j] or dp[i-1][j-1]
                if p[j]=='*':
                    if j>=2:
                        dp[i][j] = dp[i][j] or dp[i][j-2]
                    if i > 0 and (s[i]==p[j-1] or p[j-1]=='.'):
                        dp[i][j] = dp[i][j] or dp[i-1][j]
        return dp[n][m]
