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
## Solution 2:
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
