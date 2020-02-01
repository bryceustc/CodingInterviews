# -*- coding:utf-8 -*-
class Solution:
    def FirstNotRepeatingChar(self, s):
        # write code here
        import collections
        n = len(s)
        res = -1
        if n==0:
            return res
        count = collections.Counter(s)
        for index,ch in enumerate(s):
            if count[ch]==1:
                return index
        return res
