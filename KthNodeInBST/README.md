# 题目: 二叉搜索树的第k大结点
## 题目描述：
给定一颗二叉搜索树，请找出其中的第k大的结点。例如，在下图中，按结点数值大小顺序第三个结点的值为4。

![](https://cuijiahua.com/wp-content/uploads/2018/01/basis_62_1_modify.png)

这棵树是二叉搜索树，首先想到的是二叉搜索树的一个特点：左子结点的值 < 根结点的值 < 右子结点的值。
# 本题考点：
  
  二叉搜索树与双向链表的理解，以及中序遍历算法和递归编程能力，复杂问题的思维能力。
  
# 解题思路:

  如上图所示，如果使用中序遍历，则得到的序列式为{2,3,4,5,6,7,8}。因此，只需要用中序遍历一棵二叉搜索树，就很容易找出它的第k大结点。
  
  
# 代码

[C++](./KthNodeInBST.cpp)

[Python](./KthNodeInBST.py)

# C++: 
### 递归
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
    TreeNode* KthNode(TreeNode* root, int k)
    {
        if (root == NULL || k < 1)
            return NULL;
        helper(root,k);
        return res;
    }
    void helper(TreeNode* root, int k)
    {
        if (root == NULL)
            return;
	// 第k小，正常中序遍历，第k大，逆中序遍历
        helper(root->left, k);
        if (++count == k)
        {
            res = root;
            return;
        }
        helper(root->right, k);
    }
private:
    TreeNode* res = NULL;
    int count = 0;
};
```
## 递归 (返回第k大数字，空间复杂度O(n))
```c++
class Solution {
public:
    int kthLargest(TreeNode* root, int k) {
        int res = 0;
        if (root == NULL || k<1)
        {
            return res;
        }
        vector<int> out;
        helper(root, out);
        int n = out.size();
        res = out[n-k];
        return res;
    }
    void helper(TreeNode* root, vector<int> &v)
    {
        if (root==NULL)
            return;
        helper(root->left, v);
        v.push_back(root->val);
        helper(root->right,v);
    }
}
```

## 递归 (返回第k大数字，空间复杂度O(1))
```c++
class Solution {
public:
    int kthLargest(TreeNode* root, int k) {
        if (root == NULL || k<1)
        {
            return 0;
        }
        helper(root, k);
        return res;
    }
    void helper(TreeNode* root, int k)
    {
        if (root==NULL)
            return;
        helper(root->right, k);
        if (++count==k)
        {
            res = root->val;
            return;
        }
        helper(root->left, k);
    }
private:
    int res = 0;
    int count = 0;
};
```


# Python:
###  递归
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
###  迭代
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
  -  [python 可变与不可变变量](https://blog.csdn.net/god_wen/article/details/78423621)
