# 题目: 矩阵中的路径

## 题目描述：
请设计一个函数，用来判断在一个矩阵中是否存在一条包含某字符串所有字符的路径。路径可以从矩阵中的任意一格开始，每一步可以在矩阵中向左、右、上、下移动一格。如果一条路径经过了矩阵的某一格，那么该路径不能再次进入该格子。例如，在下面的3×4的矩阵中包含一条字符串“bfce”的路径（路径中的字母用加粗标出）。

[["a","**b**","c","e"],
["s","**f**","**c**","s"],
["a","d","**e**","e"]]

但矩阵中不包含字符串“abfb”的路径，因为字符串的第一个字符b占据了矩阵中的第一行第二个格子之后，路径不能再次进入这个格子。
  
  **示例：**
  ```
输入：board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
输出：true
  ```
  
# 解题思路:
  1. 动态规划，从已知值 F(2)逐步迭代到目标值 F(n)，它是一种**自底向上**的方法。
  
  建立一维动态数组 dp：
  
  - 边界条件：dp[1] = dp[2] = 1，表示长度为 2 的绳子最大乘积为 1；
  - 状态转移方程：dp[i] = max(dp[i], max((i - j) * j, j * dp[i - j]))，可以这样理解：
  
  ![](https://pic.leetcode-cn.com/82b25ac6bcb742f31e5202e4af993d98abfea6a0c385379b214440bbb84b9bb4-14.jpg)
  
  2. 动态规划优化，[任何大于 3的数都可以拆分为数字 1，2，3的和](https://zhuanlan.zhihu.com/p/108832910)，且它们对 3的余数总是 0，1，2，因此我们可以仅用 dp[0]，dp[1]，dp[2] 表示所有大于 3 的值，这样空间复杂度可降到 O(1)。
  
  ![](https://pic.leetcode-cn.com/3be12f435b2a0668eecd747c5d08188128fde7764b99116123b86880280f62ca-14.gif)


3. 贪心算法

![](https://github.com/bryceustc/CodingInterviews/blob/master/CuttingRope/1.jpg)
# 时间复杂度：
1： O(n^2)
 
2:  O(n);

3:  O(1);
# 空间复杂度
  1: O(n)
  
  2: O(1)
  
  3: O(1)
# 代码

[C++](./StringPathInMatrix.cpp)

[Python](./StringPathInMatrix.py)

# C++: 
###  回溯
```c++
class Solution {
public:
    bool hasPath(char* matrix, int rows, int cols, char* str)
    {
        if(matrix == NULL || rows <1 || cols < 1 || str == NULL)
            return false;
        vector<vector<int>> visited (rows, vector<int>(cols,0));
        for (int i=0;i<rows;i++)
        {
            for (int j=0;j<cols;j++)
            {
                if (helper(matrix, rows, cols, i, j, str, 0, visited))
                {
                    return true;
                }
            }
        }
        return false;
    }
    bool helper(char* matrix, int rows, int cols, int i, int j, char* str, int k, vector<vector<int>> &visited)
    {
        //因为是一维数组存放二维的值，index值就是相当于二维数组的（i，j）在一维数组的下标
        int index = i*cols + j;
        if(i<0||i>=rows||j<0||j>=cols||matrix[index]!=str[k]||visited[i][j]==1)
            return false;
        //字符串已经查找结束，说明找到该路径了
        if (str[k+1]=='\0')
            return true;
        //标记访问过
        visited[i][j]=1;
        //向四个方向进行递归查找,向左，向右，向上，向下查找
        if (helper(matrix, rows, cols, i, j-1, str, k+1, visited)||
           helper(matrix, rows, cols, i, j+1, str, k+1, visited)||
           helper(matrix, rows, cols, i-1, j, str, k+1, visited)||
           helper(matrix, rows, cols, i+1, j, str, k+1, visited))
        {
            return true;
        }
        visited[i][j]=0;
        return false;
    }
};
```
### 回溯（力扣）
```c++
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if (board.empty()) return false;
        int rows = board.size();
        int cols = board[0].size();
        vector<vector<int>> visited (rows, vector<int>(cols, 0));
        for (int i=0;i<rows;i++)
        {
            for(int j =0;j<cols;j++)
            {
                if (dfs(board,rows, cols, i, j, word, 0, visited))
                {
                    return true;
                }
            }
        }
        return false;
    }
    bool dfs(vector<vector<char>>& board, int rows, int cols, int i, int j, string word, int k, vector<vector<int>> &visited)
    {
        if (i<0||i>=rows||j<0||j>=cols||board[i][j]!=word[k]||visited[i][j]==1)
            return false;
        if (k==word.size()-1)
            return true;
        visited[i][j]=1;
        if (dfs(board,rows, cols, i-1, j, word, k+1, visited)||
        dfs(board,rows, cols, i+1, j, word, k+1, visited)||
        dfs(board,rows, cols, i, j-1, word, k+1, visited)||
        dfs(board,rows, cols, i, j+1, word, k+1, visited))
        {
            return true;
        }
        visited[i][j]=0;
        return false;
    }
};
```
# Python:
###  动态规划
```python
# -*- coding:utf-8 -*-
class Solution:
    def hasPath(self, matrix, rows, cols, path):
        # write code here
        if matrix == None or rows<1 or cols<1 or path == None:
            return False
        visited = [[0 for x in range(cols)] for y in range(rows)]
        for i in range(0,rows):
            for j in range(0,cols):
                if (self.dfs(matrix, rows, cols, i, j, path, 0, visited)):
                    return True
        return False
    def dfs(self, matrix, rows, cols, i, j, path, k, visited):
        index = i*cols+j
        if i<0 or i>=rows or j<0 or j>=cols or matrix[index]!=path[k] or visited[i][j]==1:
            return False
        if k==len(path)-1:
            return True
        visited[i][j]=1
        if self.dfs(matrix, rows, cols, i-1, j, path, k+1, visited):
            return True
        if self.dfs(matrix, rows, cols, i+1, j, path, k+1, visited):
            return True
        if self.dfs(matrix, rows, cols, i, j-1, path, k+1, visited):
            return True
        if self.dfs(matrix, rows, cols, i, j+1, path, k+1, visited):
            return True
        visited[i][j]=0
        return False
```
