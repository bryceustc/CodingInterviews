# 题目: 从上到下打印二叉树
## 题目描述：
从上到下打印出二叉树的每个节点，同一层的节点按照从左到右的顺序打印。

例如:
给定二叉树: [3,9,20,null,null,15,7],
```
    3
   / \
  9  20
    /  \
   15   7
```
返回：
```
[3,9,20,15,7]
```
# 本题考点：
  
  二叉树的遍历算法和递归编程能力，代码的鲁棒性。
  
# 解题思路:
  此题与LeetCode101题对称二叉树类似。
  
  思路：**递归**
  
  1.怎么判断一棵树是不是对称二叉树？ 答案：如果所给根节点，为空，那么是对称。如果不为空的话，当他的左子树与右子树对称时，他对称
  
  2.那么怎么知道左子树与右子树对不对称呢？在这我直接叫为左树和右树 答案：如果左树的左孩子与右树的右孩子对称，左树的右孩子与右树的左孩子对称，那么这个左树和右树就对称。
  
  那用递归分别比较左右子树
  
  递归结束条件：
   - 都为空指针则返回 true
   - 只有一个为空则返回 false
   - 两个指针当前节点值不相等 返回false
   
 递归过程：
   - 判断 A 的右子树与 B 的左子树是否对称
   - 判断 A 的左子树与 B 的右子树是否对称

# 代码

[C++](./PrintTreeFromTopToBottom.cpp)

[Python](./PrintTreeFromTopToBottom.py)

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
};
*/
class Solution {
public:
    bool isSymmetrical(TreeNode* pRoot)
    {
        bool res = true;
        if (pRoot!=NULL)
        {
            res = helper(pRoot->left,pRoot->right);
        }
        return res;
    }
    bool helper(TreeNode* A, TreeNode* B)
    {
        // 先写递归终止条件
        if (A==NULL && B==NULL)
            return true;
        // 如果其中之一为空，也不是对称的
        if (A==NULL || B==NULL)
            return false;
        // 走到这里二者一定不为空
        if (A->val != B->val)
            return false;
        // 前序遍历
        return helper(A->left,B->right) && helper(A->right,B->left);
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
    def isSymmetrical(self, pRoot):
        # write code here
        res = True
        if pRoot:
            res = self.helper(pRoot.left, pRoot.right)
        return res
    def helper(self, A, B):
        if A is None and B is None:
            return True
        if A is None or B is None:
            return False
        if A.val != B.val:
            return False
        return self.helper(A.left, B.right) and self.helper(A.right,B.left)
```
## 参考
  -  [LeetCode-101-对称二叉树](https://github.com/bryceustc/LeetCode_Note/blob/master/cpp/Symmetric-Tree/README.md)

