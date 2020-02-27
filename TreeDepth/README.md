# 题目: 二叉树的深度
## 题目描述：
输入一棵二叉树，求该树的深度。从根结点到叶结点依次经过的结点（含根、叶结点）形成树的一条路径，最长路径的长度为树的深度。
# 本题考点：
  
  二叉树递归编程能力，复杂问题的思维能力。
  
# 解题思路:
  
  推荐用递归，取左右子树最大的深度加上1
  
  两种方法：可以是递归的方法，属于DFS（深度优先搜索）；另一种方法是按照层次遍历，属于BFS（广度优先搜索）。
  
# 代码

[C++](./TreeDepth.cpp)

[Python](./TreeDepth.py)

# C++: 
###  DFS 递归
```c++
/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
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
## BFS 迭代
```c++
class Solution {
public:
    int TreeDepth(TreeNode* root)
    {
        int depth = 0;
        if (root == NULL)
            return depth;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            int count = q.size();
            while(count>0)
            {
                TreeNode* node = q.front();
                q.pop();
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
                count--;
            }
            depth++;
        }
        return depth;
    }
};
```

# Python:
###  DFS 递归
```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def TreeDepth(self, root):
        # write code here
        if root is None:
            return 0
        left = self.TreeDepth(root.left)
        right = self.TreeDepth(root.right)
        return max(left, right)+1
```
### BFS 迭代
```python
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
```
## 参考
  -  [LeetCode-104题-二叉树的最大深度](https://github.com/bryceustc/LeetCode_Note/blob/master/cpp/Maximum-Depth-Of-Binary-Tree/README.md)

