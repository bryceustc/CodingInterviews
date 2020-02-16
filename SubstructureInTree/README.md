
# 题目: 重建二叉树
## 题目描述：
输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。假设输入的前序遍历和中序遍历的结果中都不含重复的数字。例如输入前序遍历序列{1,2,4,7,3,5,6,8}和中序遍历序列{4,7,2,1,5,3,8,6}，则重建二叉树并返回。
# 本题考点：
  
  二叉树的三种遍历（前序遍历(DLR)，中序遍历(LDR)，后序遍历(LRD)）实现。
  
# 解题思路:
  此题与LeetCode-105题一样，与106题从中序与后序遍历序列构造二叉树思路类似

   理解二叉树以及三种遍历的概念。[二叉树 - 前序遍历、中序遍历、后序遍历](https://www.jianshu.com/p/acb33735b933)
   
   注意前序遍历中的第一个数字是根节点的值，在中序遍历中根节点的值在序列中间，左子树的节点的值在根节点的值的左边，而右子树的节点的值位于根节点的右边，所以先扫描中序遍历，找到根节点所在位置，然后找到左子树和右子树的前序遍历和中序遍历即可。如图所示：
   
   ![1](https://github.com/bryceustc/CodingInterviews/blob/master/ConstructBinaryTree/Images/1.jpg)
# 代码

[C++](./ConstructBinaryTree.cpp)

[Python](./ConstructBinaryTree.py)

# C++: 
### 
```c++
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        if (pre.empty() || vin.empty())
            return NULL;
        int n = pre.size();
        // 前序遍历的第一个数字是根节点的值
        int root = pre[0];
        // 创建根节点
        TreeNode* t = new TreeNode(root);
        // 如果长度为1，直接返回根节点
        if (n==1) return t;
        // 找到root所在的位置，确定好前序和中序中左子树和右子树序列的范围
        int root_index = 0;
        for (int i=0;i<n;i++)
        {
            if (vin[i]==root)
            {
                root_index = i;
                break;
            }
        }
        // 左子树
        vector<int> left_pre,left_in, right_pre, right_in;
        for (int i=0;i<root_index;i++)
        {
            left_pre.push_back(pre[i+1]); // +1 是因为前序遍历的第一个节点是根节点
            left_in.push_back(vin[i]);
        }
        // 右子树
        for (int i=root_index+1;i<n;i++)
        {
            right_pre.push_back(pre[i]);
            right_in.push_back(vin[i]);
        }
        t->left = reConstructBinaryTree(left_pre,left_in);
        t->right = reConstructBinaryTree(right_pre,right_in);
        return t;
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
    # 返回构造的TreeNode根节点
    def reConstructBinaryTree(self, pre, tin):
        # write code here
        n = len(pre)
        if n==0:
            return None
        root = pre[0]
        t = TreeNode(root)
        if n==1:
            return t
        rooot_index = 0
        for i in range(n):
            if tin[i]==root:
                root_index = i
                break
        left_pre = []
        left_in = []
        right_pre = []
        right_in = []
        for i in range(root_index):
            left_pre.append(pre[i+1])
            left_in.append(tin[i])
        for i in range(root_index+1,n):
            right_pre.append(pre[i])
            right_in.append(tin[i])
        t.left = self.reConstructBinaryTree(left_pre,left_in)
        t.right = self.reConstructBinaryTree(right_pre,right_in)
        return t
```

### 方法二：简洁
```python
# -*- coding:utf-8 -*-
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
class Solution:
    # 返回构造的TreeNode根节点
    def reConstructBinaryTree(self, pre, tin):
        # write code here
        if not pre or not tin:
            return None
        root = TreeNode(pre.pop(0))
        index = tin.index(root.val)
        root.left = self.reConstructBinaryTree(pre, tin[:index])
        root.right = self.reConstructBinaryTree(pre, tin[index + 1:])
        return root
```
## 参考
  -  [LeetCode-105-从前序与中序遍历序列构造二叉树](https://github.com/bryceustc/LeetCode_Note/blob/master/cpp/Construct-Binary-Tree-From-Preorder-And-Inorder-Traversal/README.md)
   -  [LeetCode-106-从中序与后序遍历序列构造二叉树](https://github.com/bryceustc/LeetCode_Note/blob/master/cpp/Construct-Binary-Tree-From-Ineorder-And-Postorder-Traversal/README.md)
