# 题目: 机器人的运动范围

## 题目描述：
地上有一个m行n列的方格，从坐标 [0,0] 到坐标 [m-1,n-1] 。一个机器人从坐标 [0, 0] 的格子开始移动，它每次可以向左、右、上、下移动一格（不能移动到方格外），也不能进入行坐标和列坐标的数位之和大于k的格子。例如，当k为18时，机器人能够进入方格 [35, 37] ，因为3+5+3+7=18。但它不能进入方格 [35, 38]，因为3+5+3+8=19。请问该机器人能够到达多少个格子？
  
  **示例：**
  ```
输入：m = 2, n = 3, k = 1
输出：3
  ```
  
# 解题思路:
0.根据给定数组，初始化一个标志位数组visited，初始化为0，表示未走过，1表示已经走过，不能走第二次

1.根据行数和列数，遍历数组，先找到一个与str字符串的第一个元素相匹配的矩阵元素，进入dfs

2.根据i和j先确定一维数组的位置，因为给定的matrix是一个一维数组

3.确定递归终止条件：越界，当前找到的矩阵值不等于数组对应位置的值，已经走过的，这三类情况，都直接false，说明这条路不通

4.若k，就是待判定的字符串str的索引已经判断到了最后一位，此时说明是匹配成功的

5.下面就是本题的精髓，递归不断地寻找周围四个格子是否符合条件，只要有一个格子符合条件，就继续再找这个符合条件的格子的四周是否存在符合条件的格子，直到k到达末尾或者不满足递归条件就停止。

6.走到这一步，说明本次是不成功的，我们要还原一下标志位数组index处的标志位，进入下一轮的判断。
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
###  回溯
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
### 回溯法（力扣）
```python
class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        if board == None:
            return False
        rows = len(board)
        cols = len(board[0])
        visited = [[0 for x in range(cols)] for y in range(rows)]
        for i in range(rows):
            for j in range(cols):
                if self.dfs(board, rows,  cols, i, j, word, 0, visited):
                    return True
        return False
    def dfs(self, board, rows, cols, i, j, word, k, visited):
        if i<0 or i>=rows or j<0 or j>=cols or board[i][j]!=word[k] or visited[i][j]==1:
            return False
        if k==len(word)-1:
            return True
        visited[i][j]=1
        if self.dfs(board, rows, cols, i-1, j, word, k+1, visited):
            return True
        if self.dfs(board, rows, cols, i+1, j, word, k+1, visited):
            return True
        if self.dfs(board, rows, cols, i, j-1, word, k+1, visited):
            return True
        if self.dfs(board, rows, cols, i, j+1, word, k+1, visited):
            return True
        visited[i][j]=0
        return False
```

