# -*- coding:utf-8 -*-
class Solution:
    def __init__(self):
        self.stack1 = []
        self.stack2 = []
    def push(self, node):
        # write code here
        self.stack1.append(node)
    def pop(self):
        # return xx
        l1 = len(self.stack1)
        l2 = len(self.stack2)
        if l2==0:
            while l1!=0:
                temp = self.stack1.pop()
                self.stack2.append(temp)
                l1 = len(self.stack1)
        res = self.stack2.pop()
        return res
