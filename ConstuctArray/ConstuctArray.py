### Python Solution 1：
# -*- coding:utf-8 -*-
class Solution:
    def multiply(self, A):
        # write code here
        n = len(A)
        if n==0:
            return []
        B = [0 for _ in range(n)]
        for i in range(n):
            temp = 1
            for j in range(n):
                if j==i:
                    continue
                temp*=A[j]
            B[i] = temp
        return B
### Python Solution 2：
# -*- coding:utf-8 -*-
class Solution:
    def multiply(self, A):
        # write code here
        n = len(A)
        if n==0:
            return []
        B = [0 for _ in range(n)]
        ## 计算下三角
        B[0]=1
        for i in range(1,n):
            B[i]=B[i-1]*A[i-1]
        ## 计算上三角
        temp = 1
        for i in range(n-2,-1,-1):
            temp *= A[i+1]
            B[i] *= temp
        return B
 ## Python Solution 3:
# -*- coding:utf-8 -*-
class Solution:
    def multiply(self, A):
        # write code here
        B = []
        n = len(A)
        if n == 0:
            return B
        else:
            for i in range(n):
                ## 求B[i]，就把A[i]设为1，完了把A[i]值恢复
                temp = A[i]
                A[i] = 1
                B.append(reduce(lambda x,y:x*y, A))
                # reduce() 函数会对参数序列中元素进行累积。
                # 函数将一个数据集合（链表，元组等）中的所有数据进行下列操作：用传给 reduce 中的函数 
                # function（有两个参数）先对集合中的第 1、2 个元素进行操作，
                # 得到的结果再与第三个数据用 function 函数运算，最后得到一个结果。
                A[i] = temp
        return B
