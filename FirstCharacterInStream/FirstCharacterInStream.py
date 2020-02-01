# -*- coding:utf-8 -*-
class Solution:
    # 返回对应char
    def __init__(self):
        self.s= ""
    def FirstAppearingOnce(self):
        # write code here
        res = "#"
        for ch in self.s:
            if self.s.count(ch)==1:
                return ch
        return res
    def Insert(self, char):
        # write code here
        self.s+=char

        
        
# -*- coding:utf-8 -*-
class Solution:
    # 返回对应char
    def __init__(self):
        self.s= ""
    def FirstAppearingOnce(self):
        # write code here
        res = list(filter(lambda c: self.s.count(c)==1,self.s))
        return res[0] if res else "#"
    def Insert(self, char):
        # write code here
        self.s+=char
