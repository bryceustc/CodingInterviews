# 题目: 机器人的运动范围

## 题目描述：
地上有一个m行n列的方格，从坐标 [0,0] 到坐标 [m-1,n-1] 。一个机器人从坐标 [0, 0] 的格子开始移动，它每次可以向左、右、上、下移动一格（不能移动到方格外），也不能进入行坐标和列坐标的数位之和大于k的格子。例如，当k为18时，机器人能够进入方格 [35, 37] ，因为3+5+3+7=18。但它不能进入方格 [35, 38]，因为3+5+3+8=19。请问该机器人能够到达多少个格子？
  
  **示例：**
  ```
输入：m = 2, n = 3, k = 1
输出：3
  ```
  
# 解题思路:
1.从(0,0)开始走，每成功走一步标记当前位置为true,然后从当前位置往四个方向探索，返回1 + 4 个方向的探索值之和。

2.探索时，判断当前节点是否可达的标准为：

1）当前节点在矩阵内；

2）当前节点未被访问过；

3）当前节点满足limit限制。

# 时间复杂度：
O(n^2)
# 空间复杂度
 O(n)
# 代码

[C++](./RobotMove.cpp)

[Python](./RobotMove.py)

# C++: 
###  回溯
```c++
class Solution {
public:
    int movingCount(int threshold, int rows, int cols)
    {
        int res = 0;
        vector<vector<int>> visited (rows, vector<int>(cols,0));
        res = helper(threshold, rows, cols,0, 0, visited);
        return res;
    }
    int helper(int threshold, int rows, int cols, int i, int j, vector<vector<int>> &visited)
    {
        int sum = bitSum(i) + bitSum(j);
        // 或者转成字符串来计算
        //string s1 = to_string(i);
        // string s2 = to_string(j);
        // int sum = 0;
        // for (int x =0; x<s1.size();x++)
        // {
        //     sum+=s1[x]-'0';
        // }
        // for (int y =0; y<s2.size();y++)
        // {
        //     sum+=s2[y]-'0';
        // }
        // if (sum> k|| i<0|| i>=m || j<0|| j>=n||visited[i][j]==1)
        // {
        //     return 0;
        // }
        if (sum > threshold || i<0 || i>=rows || j<0 || j>=cols || visited[i][j]==1)
            return 0;
        visited[i][j]=1;
        return helper(threshold, rows, cols,i-1, j, visited) + helper(threshold, rows, cols,i+1, j, visited) +
            helper(threshold, rows, cols,i, j-1, visited) + helper(threshold, rows, cols,i, j+1, visited) + 1;
    }
     //计算位置的数值
    int bitSum(int num)
    {
        int sum = 0;
        while(num>0)
        {
            sum+=num%10;
            num/=10;
        }
        return sum;
    }
};
```
# Python:
###  回溯
```python
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
```

