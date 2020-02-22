class Solution:
    # 返回二维列表，内部每个列表表示找到的路径
    def __init__(self):
        self.res = []
        self.path = []
    def FindPath(self, root, expectNumber):
        # write code here
        if root is None:
            return self.res
        self.dfs(root, self.path, expectNumber)
        return self.res
    def dfs(self, root, path, expectNumber):
        if root is None:
            return
        self.path.append(root.val)
        if expectNumber == root.val and (root.left is None and root.right is None):
            self.res.append(self.path[:])
        self.dfs(root.left, self.path, expectNumber - root.val)
        self.dfs(root.right, self.path, expectNumber - root.val)
        self.path.pop()
