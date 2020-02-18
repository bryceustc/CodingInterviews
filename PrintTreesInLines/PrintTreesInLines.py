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
