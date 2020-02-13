# -*- coding:utf-8 -*-
class Solution:
    def __init__(self):
        self.stack1 = []
        self.stack2 = []
    def push(self, node):
        # write code here
        self.stack1.append(node)
        if len(self.stack2)==0 or node < self.stack2[-1]:
            self.stack2.append(node)
        else:
            temp = self.stack2[-1]
            self.stack2.append(temp)
    def pop(self):
        # write code here
        self.stack1.pop()
        self.stack2.pop()
    def top(self):
        # write code here
        return self.stack1[-1]
    def min(self):
        # write code here
        return self.stack2[-1]
