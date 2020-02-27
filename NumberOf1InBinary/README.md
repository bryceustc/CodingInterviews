# 题目: 二进制中1的个数
## 题目描述：
输入一个整数，输出该数二进制表示中1的个数。其中负数用补码表示。
# 本题考点：
  
  二叉树递归编程能力，复杂问题的思维能力。
  
# 解题思路:
 解题思路有两种，只遍历一次的方法最优。

**重复遍历多次：自顶向下** 


时间复杂度O(nlogn), 空间复杂度O(n)[复杂度分析](https://leetcode-cn.com/problems/balanced-binary-tree/solution/ping-heng-er-cha-shu-by-leetcode/)

自顶向下在遍历树的每个结点的时候，调用函数TreeDepth得到它的左右子树的深度。如果每个结点的左右子树的深度相差都不超过1，则这是一颗平衡的二叉树。这种方法的缺点是，首先判断根结点是不是平衡的，需要使用TreeDepth获得左右子树的深度，然后还需要继续判断子树是不是平衡的，还是需要使用TreeDepth获得子树的左右子树的深度，这样就导致了大量的重复遍历。

**只遍历一次：自底向上**

时间复杂度O(n), 空间复杂度O(n)[复杂度分析](https://leetcode-cn.com/problems/balanced-binary-tree/solution/ping-heng-er-cha-shu-by-leetcode/)

自底向上与自顶向下的逻辑相反，首先判断子树是否平衡，然后比较子树高度判断父节点是否平衡。检查子树是否平衡。如果平衡，则使用它们的高度判断父节点是否平衡，并计算父节点的高度。自底向上计算，每个子树的高度只会计算一次。可以递归先计算当前节点的子节点高度，然后再通过子节点高度判断当前节点是否平衡，从而消除冗余。
  
# 代码

[C++](./NumberOf1InBinary.cpp)

[Python](./NumberOf1InBinary.py)

# C++: 
###  重复遍历多次 时间复杂度O(nlogn)
```c++
class Solution {
public:
    bool IsBalanced_Solution(TreeNode* root) {
        if (root == NULL)
            return true;
        int left = TreeDepth(root->left);
        int right = TreeDepth(root->right);
        if (left-right > 1 || left-right<-1)
            return false;
        return IsBalanced_Solution(root->left) && IsBalanced_Solution(root->right);
    }
    int TreeDepth(TreeNode* root)
    {
        if (root == NULL)
            return 0;
        int left = TreeDepth(root->left);
        int right = TreeDepth(root->right);
        return max(left, right) + 1;
    }
};
```
### 只遍历一次
```c++
class Solution {
public:
    bool IsBalanced_Solution(TreeNode* root) {
        if (root == NULL)
            return true;
        int depth = 0;
        return helper(root, depth);
    }
    bool helper(TreeNode* root, int &depth)
    {
        if (root == NULL)
        {
            depth = 0;
            return true;
        }
        int left, right;
        if (helper(root->left, left) && helper(root->right, right) && abs(left-right)<=1)
        {
            depth = max(left,right)+1;
            return true;
        }
        return false;
    }
};
```

# Python:
###   重复遍历多次
```python
class Solution:
    def IsBalanced_Solution(self, root):
        # write code here
        if root is None:
            return True
        left = self.TreeDepth(root.left)
        right = self.TreeDepth(root.right)
        if left - right > 1 or left - right < -1:
            return False
        return self.IsBalanced_Solution(root.left) and self.IsBalanced_Solution(root.right)
    def TreeDepth(self, root):
        if root is None:
            return 0
        left = self.TreeDepth(root.left)
        right = self.TreeDepth(root.right)
        return max(left, right) + 1
```
### 只遍历一次
```python
class Solution:
    def __init__(self):
        self.depth = 0
    def IsBalanced_Solution(self, root):
        # write code here
        if root is None:
            return True
        return self.helper(root)[0]
    def helper(self,root):
        if root is None:
            return True, 0
        leftIsBalanced, left = self.helper(root.left)
        if not leftIsBalanced:
            return False, 0
        rightIsBalanced, right = self.helper(root.right)
        if not rightIsBalanced:
            return False, 0
        return abs(left-right)<=1, max(left,right)+1
```
## 参考
  -  [LeetCode-110题-平衡二叉树](https://github.com/bryceustc/LeetCode_Note/blob/master/cpp/Balanced-Binary-Tree/README.md)

