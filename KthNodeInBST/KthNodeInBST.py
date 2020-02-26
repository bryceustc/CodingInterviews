### Solution 1:
class Solution:
    def kthLargest(self, root: TreeNode, k: int) -> int:
        res = 0
        if root is None or k < 1:
            return res
        out = []
        self.helper(root, out)
        res = out[-k]
        return res
    def helper(self, root, out):
        if root is None:
            return
        self.helper(root.left, out)
        out.append(root.val)
        self.helper(root.right, out)
### Solution 2:
class Solution:
    def __init__(self):
        self.res = 0
        self.count = 0
    def kthLargest(self, root: TreeNode, k: int) -> int:
        if root is None or k < 1:
            return self.res
        self.helper(root, k)
        return self.res
    def helper(self, root, k):
        if (root==None):
            return
        self.helper(root.right, k)
        self.count =  self.count + 1
        if self.count == k:
            self.res = root.val
            return
        self.helper(root.left, k)
### Solution 3:
class Solution:
    def kthLargest(self, root: TreeNode, k: int) -> int:
        n = 0
        s = []
        p = root
        while s or p:
            while p:
                s.append(p)
                p = p.right
            p = s.pop()
            n+=1
            if n == k:
                return p.val
            p = p.left
        return 0
