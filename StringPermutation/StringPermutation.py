# -*- coding:utf-8 -*-
class Solution:
    def Permutation(self, s):
        # write code here
        n = len(s)
        res = []
        if n==0:
            return res
        out = ""
        visited = [0 for _ in range(n)]
        self.DFS(s,0,visited,out,res)
        return res
    def DFS(self,s,level,visited,out,res):
        n = len(s)
        if level == n:
            res.append(out)
            return
        for i in range(n):
            if visited[i]==1:
                continue
            if i >= 1 and s[i]==s[i-1] and visited[i-1]==0:
                continue
            out += s[i]
            visited[i]=1
            self.DFS(s,level+1,visited,out,res)
            out = out[:-1]
            visited[i]=0
### Solution 2:
# -*- coding:utf-8 -*-
class Solution:
    def __init__(self):
        self.result = []
    def Permutation(self, ss):
        # write code here
        if len(ss) == 0:
            return []
        self.PermutationCore(ss, 0)
        sorted(self.result)
        return self.result
    def PermutationCore(self, str_, begin):
        if begin == len(str_):
            self.result.append(str_)
            return
        for i in range(begin, len(str_)):
            if i != begin and str_[i] == str_[begin]:
                continue
            str_list = list(str_)
            str_list[i], str_list[begin] = str_list[begin], str_list[i]
            str_ = ''.join(str_list)
            self.PermutationCore(str_, begin+1)
