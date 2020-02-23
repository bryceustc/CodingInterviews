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
    TreeNode* Convert(TreeNode* root)
    {
        if (root == NULL)
            return NULL;
	// 定义一个pre指针
        TreeNode* pre = NULL;
        helper(root, pre);
        TreeNode* res = root; 
	// 寻找到头结点
        while (res->left)
        {
            res = res->left;
        }
        return res;
    }
    void helper(TreeNode* cur, TreeNode* &pre)  // 中序遍历
    {
        if (cur == NULL)
            return;
        // 先遍历左子树
        helper(cur->left, pre);
        // 修改为双向链表
        cur->left = pre;
        if(pre != NULL)
        {
            pre->right = cur;
        }
        pre = cur;
        // 再遍历右子树
        helper(cur->right, pre);
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
```
## 参考
  -  [LeetCode-426 题-将二叉搜索树转换为双向链表](https://github.com/bryceustc/LeetCode_Note/blob/master/cpp/Convert-Binary-Search-Tree-To-Sorted-Doubly-Lnked-List/README.md)

