class Solution:
    flag=-1
    def Serialize(self, root):
        # write code here
        if not root:
            return 'n'
        return str(root.val)+','+self.Serialize(root.left)+','+self.Serialize(root.right)
        
    def Deserialize(self, s):
        # write code here
        self.flag+=1
        lis = s.split(",")
        
        if self.flag > len(lis):
            return
        root = None
        if lis[self.flag] != "n":
            root = TreeNode(int(lis[self.flag]))
            root.left = self.Deserialize(s)
            root.right = self.Deserialize(s)
        return root
## Solution 2:
class Solution:
    def Serialize(self, root):
        # write code here
        s = ""
        q = []
        q.append(root)
        while q:
            node = q.pop(0)
            if node:
                s += str(node.val) + ","
                q.append(node.left)
                q.append(node.right)
            else:
                s += "n,"
        return s
    def Deserialize(self, s):
        # write code here
        s = s.split(",")
        if s[0] == 'n':
            return None
        q = []
        i = 1
        res = TreeNode(int(s[0]))
        q.append(res)
        while q:
            node = q.pop(0)
            if node == None:
                continue
            if s[i] != 'n':
                node.left = TreeNode(int(s[i]))
            else:
                node.left = None
            if s[i+1] != 'n':
                node.right = TreeNode(int(s[i+1]))
            else:
                node.right = None
            i+=2
            q.append(node.left)
            q.append(node.right)
        return res
