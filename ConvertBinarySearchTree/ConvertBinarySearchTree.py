class Solution:
    def Convert(self, root):
        # write code here
        if root is None:
            return None
        pre = None
        self.helper(root, pre)
        res = root
        while res.left:
            res = res.left
        return res
    def helper(self, cur, pre):
        if cur is None:
            return pre
        pre = self.helper(cur.left, pre)
        cur.left = pre
        if pre:
            pre.right = cur
        pre = cur
        return self.helper(cur.right, pre)
