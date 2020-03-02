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
