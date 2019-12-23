# -*- coding:utf-8 -*-
class Solution:
    def printMatrix(self, matrix):
        res = []
        m = len(matrix)
        if m==0:
            return res
        n = len(matrix[0])
        u = 0
        d = m-1
        l = 0
        r = n-1
        while (true):
            for i in range(l,r+1):
                res.append(matrix[u][i])
            u+=1
            if u>d:
                break
            for i in range(u,d+1):
                res.append(matrix[i][r])
            r-=1
            if r<l:
                break
            for i in range(r,l-1,-1):
                res.append(matrix[d][i])
            d-=1
            if d<u:
                break
            for i in range(d,u-1,-1):
                res.append(matrix[i][l])
            l+=1
            if l>r:
                break
        return res


if __name__ == '_ main__':
    nums = [[1,2,3,4],[5,6,7,8,[9,10,11,12],[13,14,15,16]]
    res = Solution().printMatrix(nums)
    print(res)
