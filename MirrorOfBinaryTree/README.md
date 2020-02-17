
# 题目: 二叉树的镜像
## 题目描述：
请完成一个函数，输入一个二叉树，该函数输出它的镜像。

例如输入：
```
     8
   /   \
  6     10
 / \   /  \
5   7 9    11
```
镜像输出：
```
      8
   /    \
  10      9
 /  \    /  \
11   9  7    5
```
# 本题考点：
  
  二叉树的遍历算法和递归编程能力，代码的鲁棒性。
  
# 解题思路:
  此题与LeetCode226题翻转二叉树类似。
  
  思路：先交换根节点的两个子结点之后，我们注意到值为10、6的结点的子结点仍然保持不变，因此我们还需要交换这两个结点的左右子结点。做完这两次交换之后，我们已经遍历完所有的非叶结点。此时变换之后的树刚好就是原始树的镜像。交换示意图如下所示：
  
  ![1](https://github.com/bryceustc/CodingInterviews/blob/master/MirrorOfBinaryTree/Images/1.png)
# 代码

[C++](./MirrorOfBinaryTree.cpp)

[Python](./MirrorOfBinaryTree.py)

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
    void Mirror(TreeNode *root) {
        if (root ==NULL)
            return;
        //交换根节点的左右结点
        TreeNode* temp = root->left;
        root->left = root->right;
        root->right =temp;
        
        //递归左子树
        if (root->left)
            Mirror(root->left);
        
        //递归右子树
        if (root->right)
            Mirror(root->right);
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
    # 返回镜像树的根节点
    def Mirror(self, root):
        # write code here
        if root == None:
            return
        temp = root.left
        root.left = root.right
        root.right = temp
        if root.left:
            self.Mirror(root.left)
        if root.right:
            self.Mirror(root.right)
```
## 参考
  -  [LeetCode-226-翻转二叉树](https://github.com/bryceustc/LeetCode_Note/blob/master/cpp/Invert-Binary-Tree/README.md)

