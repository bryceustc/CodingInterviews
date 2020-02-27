## Solution 1:
class Solution:
    def TreeDepth(self, root):
        # write code here
        if root is None:
            return 0
        left = self.TreeDepth(root.left)
        right = self.TreeDepth(root.right)
        return max(left, right)+1
## Solution 2:
class Solution:
    def TreeDepth(self, root):
        # write code here
        depth = 0
        if root is None:
            return depth
        q = []
        q.append(root)
        while q:
	    # count 是每一层的节点数
            count = len(q)
            while count > 0:
                node = q.pop(0)
                if node.left:
                    q.append(node.left)
                if node.right:
                    q.append(node.right)
                count-=1
	    # 遍历完一层后，深度+1
            depth+=1
        return depth
