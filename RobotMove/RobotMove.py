class Solution:
    def movingCount(self, m: int, n: int, k: int) -> int:
        if (m<=0 or n<=0 or k<0):
            return 0
        visited = [[0 for _ in range(n)]for _ in range(m)]
        res = self.dfs(m,n,0,0,k,visited)
        return res
    def dfs(self, m, n, i, j, k, visited):
        if i<0 or i>=m or j<0 or j>=n or self.bitSum(i) + self.bitSum(j) >k or visited[i][j]==1:
            return 0
        visited[i][j]=1
        return self.dfs(m,n,i-1,j,k,visited) + self.dfs(m,n,i+1,j,k,visited) + self.dfs(m,n,i,j+1,k,visited) +  self.dfs(m,n,i,j-1,k,visited) + 1
    def bitSum(self, num):
        s = 0
        while num:
            s+=num%10
            num = num//10
        return s
