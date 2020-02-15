# -*- coding:utf-8 -*-
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
class Solution:
    # 返回构造的TreeNode根节点
    def reConstructBinaryTree(self, pre, tin):
        # write code here
        n = len(pre)
        if n==0:
            return None
        root = pre[0]
        t = TreeNode(root)
        if n==1:
            return t
        rooot_index = 0
        for i in range(n):
            if tin[i]==root:
                root_index = i
                break
        left_pre = []
        left_in = []
        right_pre = []
        right_in = []
        for i in range(root_index):
            left_pre.append(pre[i+1])
            left_in.append(tin[i])
        for i in range(root_index+1,n):
            right_pre.append(pre[i])
            right_in.append(tin[i])
        t.left = self.reConstructBinaryTree(left_pre,left_in)
        t.right = self.reConstructBinaryTree(right_pre,right_in)
        return t
