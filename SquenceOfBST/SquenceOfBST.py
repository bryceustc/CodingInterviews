# -*- coding:utf-8 -*-
class Solution:
    def VerifySquenceOfBST(self, sequence):
        # write code here
        if sequence is None or len(sequence) == 0:
            return False
        root = sequence[-1]
        n = len(sequence)
        i=0
        for i in range(n):
            if sequence[i] > root:
                break
        for j in range(i,n):
            if sequence[j] < root:
                return False
        left = True
        if i > 0:
            left = self.VerifySquenceOfBST(sequence[:i])  # a[ : n]表示从第0个元素到第n个元素(不包括n)
        right = True
        if i < n - 1:
            right = self.VerifySquenceOfBST(sequence[i:-1])
        return left and right
