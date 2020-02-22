# 题目: 二叉搜索树与双向链表
## 题目描述：
输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。要求不能创建任何新的结点，只能调整树中结点指针的指向。

**示例:**
给定如下二叉树，以及目标和 sum = 22，
```
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1
```
返回：
```
[
   [5,4,11,2],
   [5,8,4,5]
]
```
# 本题考点：
  
  二叉树的遍历算法和递归编程能力，代码的鲁棒性。
  
# 解题思路:
  此题与LeetCode-113题-路径总和 II一样
  
  典型的带记忆的DFS来解决
  
  思路： 
  - 递归前序遍历树， 把结点加入路径。
  - 若该结点是叶子结点则比较当前路径和是否等于期待和。
  - 弹出结点，每一轮递归返回到父结点时，当前路径也应该回退一个结点
  
# 代码

[C++](./ConvertBinarySearchTree.cpp)

[Python](./ConvertBinarySearchTree.py)

# C++: 
### 
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
    vector<vector<int>> res;
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
        if (root == NULL)
            return res;
        vector<int> path;
        dfs(root,path,expectNumber);
        return res;
    }
    void dfs(TreeNode* root, vector<int>& path, int expectNumber)
    {
        if (root == NULL)
            return;
        path.push_back(root->val);
        // 如果是叶节点，并且路径上的节点值的和为输入的值，就像结果中添加这一path
        bool isLeaf = (root->left == NULL && root->right == NULL);
        if (expectNumber == root->val && isLeaf)
        {
            res.push_back(path);
        }
        // 不是叶节点就遍历他的子节点
        dfs(root->left, path, expectNumber-root->val);
        dfs(root->right, path, expectNumber-root->val);
        // 到这一步说明不满足要求，要返回父节点，需要删除路径上的当前节点
        path.pop_back();
    }
};
```
# Python:
###  
```python
# -*- coding:utf-8 -*-
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
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
```
## 参考
  -  [LeetCode-113题-路径总和 II](https://github.com/bryceustc/LeetCode_Note/blob/master/cpp/Path-Sum-II/README.md)

