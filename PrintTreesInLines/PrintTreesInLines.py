### Python Solution 1:
class Solution:
    # 返回二维列表[[1,2],[4,5]]
    def Print(self, root):
        # write code here
        res =[]
        if root is None:
            return res
        q = []
        q.append(root)
        while q:
            n = len(q)
            out = []
            while n>0:
                node = q.pop(0)
                out.append(node.val)
                if node.left:
                    q.append(node.left)
                if node.right:
                    q.append(node.right)
                n-=1
            res.append(out[:])
        return res
### Python Solution 2:
class Solution:
    # 返回二维列表[[1,2],[4,5]]
    def Print(self, root):
        # write code here
        res = []
        if root is None:
            return res
        self.helper(root, res, 0)
        return res
    def helper(self, root, res, level):
        if root is None:
            return
        if len(res) == level:
            res.append([])
        res[level].append(root.val)
        if root.left:
            self.helper(root.left,res,level+1)
        if root.right:
            self.helper(root.right, res, level+1)
