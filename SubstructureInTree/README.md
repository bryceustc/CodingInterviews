
# 题目: 树的子结构
## 题目描述：
输入两棵二叉树A，B，判断B是不是A的子结构。（ps：我们约定空树不是任意一个树的子结构）
# 本题考点：
  
  二叉树的遍历算法和递归编程能力，代码的鲁棒性。
  
# 解题思路:
  思路：首先现在A中找出B的根节点，也就是要遍历A找出与B根节点相同的值，然后判断树A中以R为根节点的子树是否包含和B一样的结构。
  根节点值相等就继续判断剩余子树是否相等，直到B为NULL。
# 代码

[C++](./SubstructureInTree.cpp)

[Python](./SubstructureInTree.py)

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
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
        bool res = false;
         //当Tree1和Tree2都不为零的时候，才进行比较。否则直接返回false
        if (pRoot1 != NULL && pRoot2!=NULL)
        {
            //如果找到了对应Tree2的根节点的点
            if (pRoot1->val == pRoot2->val)
                //以这个根节点为为起点判断是否包含Tree2
                res = helper(pRoot1, pRoot2);
            //如果找不到，那么就再去Tree1的左子树当作起点，去判断是否包含Tree2
            if (!res)
                res = HasSubtree(pRoot1->left,pRoot2);
            //如果找不到，那么就再去Tree1的右子树当作起点，去判断是否包含Tree2
            if (!res)
                res = HasSubtree(pRoot1->right,pRoot2);
        }
        //返回结果
        return res;
    }
    bool helper(TreeNode* A, TreeNode* B)
    {
        //如果Tree2已经遍历完了都能对应的上，返回true
        if (B==NULL)
            return true;
        //如果Tree2还没有遍历完，Tree1却遍历完了。返回false
        if (A==NULL)
            return false;
        //如果其中有一个点没有对应上，返回false
        if (A->val != B->val)
            return false;
        //如果根节点对应的上，那么就分别去子节点里面匹配
        return helper(A->left,B->left) && helper(A->right, B->right);
    }
};
```

# Python:
###  方法一：
```python
# -*- coding:utf-8 -*-
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
class Solution:
    def HasSubtree(self, pRoot1, pRoot2):
        # write code here
        res = False
        if pRoot1 is not None and pRoot2 is not None:
            if pRoot1.val == pRoot2.val:
                res = self.helper(pRoot1,pRoot2)
            if not res:
                res = self.HasSubtree(pRoot1.left, pRoot2)
            if not res:
                res = self.HasSubtree(pRoot1.right, pRoot2)
        return res
    def helper(self,A,B):
        if B == None:
            return True
        if A == None:
            return False
        if A.val != B.val:
            return False
        return self.helper(A.left,B.left) and self.helper(A.right, B.right)
```
## 参考
  -  [LeetCode-105-从前序与中序遍历序列构造二叉树](https://github.com/bryceustc/LeetCode_Note/blob/master/cpp/Construct-Binary-Tree-From-Preorder-And-Inorder-Traversal/README.md)
