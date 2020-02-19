# 题目: 按之字形顺序打印二叉树
## 题目描述：
请实现一个函数按照之字形顺序打印二叉树，即第一行按照从左到右的顺序打印，第二层按照从右到左的顺序打印，第三行再按照从左到右的顺序打印，其他行以此类推。

例如:
给定二叉树: [3,9,20,null,null,15,7],
```
    3
   / \
  9  20
    /  \
   15   7
```
返回其层次遍历结果：
```
[
  [3],
  [20,9],
  [15,7]
]
```
# 本题考点：
  
  二叉树的遍历算法和递归编程能力，代码的鲁棒性。
  
# 解题思路:
  此题与LeetCode-102题-二叉树的层次遍历类似，与剑指offer-32题-从上到下打印二叉树思路类似。
  
  方法一：迭代
  
  同样借助队列实现，不过注意，与之前不同，此题要注意计算出当前层有多少个元素：等于队列的长度，按照顺序遍历完队列加入out中。
  
  第 0 层只包含根节点 root，算法实现如下：

  - 初始化队列只包含一个节点 root。
  - 当队列非空的时候：
      - 计算当前层有多少个元素：等于队列的长度。
      - 初始化一个空列表out
      - 利用循环将这些元素从队列中弹出，并加入out空列表中。
      - 将他们的孩子节点作为下一层压入队列中。
      - 将out列表加入res中，进入下一层。
      
  方法二：递归
  
  递归，首先确认树非空，然后调用递归函数 ``helper(node, level)``，参数是当前节点和节点的层次。程序过程如下：

  - 输出为 ``res``，**当前最高层数就是``res``的长度 ``res.size()``**。比较访问节点所在的层次 ``level`` 和当前最高层次 ``res.size()`` 的大小(当前所在层次level始终是不大于当前最高层次res.size()的)，如果``level == res.size()``了，就向``res``添加一个空``res.push_back(vector<int>())``。
 -  将当前节点插入到对应层的列表 ``res[level]`` 中。
 -  递归非空的孩子节点：``helper(node->left / node->right, level + 1)``。
  
# 代码

[C++](./PrintTreesInZigzag.cpp)

[Python](./PrintTreesInZigzag.py)

# C++: 
### 迭代：
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
        vector<vector<int> > Print(TreeNode* root) {
            vector<vector<int>> res;
            if (root==NULL)
                return res;
            queue<TreeNode*> q;
            q.push(root);
            while(!q.empty())
            {
                int count = q.size();
                vector<int> out;
                while(count>0)
                {
                    TreeNode* node = q.front();
                    q.pop();
                    out.push_back(node->val);
                    if (node->left)
                        q.push(node->left);
                    if (node->right)
                        q.push(node->right);
                    count--;
                }
                res.push_back(out);
            }
            return res;
        }
    
};
```
### 递归
```c++
class Solution {
public:
    vector<vector<int>> Print(TreeNode* root) {
        vector<vector<int>> res;
        if (root==NULL)
            return res;
        helper(root, res,0);
        return res;
    }

    void helper(TreeNode* root, vector<vector<int>> &res, int level)
    {
        if (root==NULL)
            return;
        if (res.size()==level)
            res.push_back(vector<int>());
        res[level].push_back(root->val);
        if (root->left)
            helper(root->left,res,level+1);
        if (root->right)
            helper(root->right,res,level+1);
    }
};
```
# Python:
###  迭代
```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def levelOrder(self, root: TreeNode) -> List[List[int]]:
        res = []
        if root is None:
            return res
        q = []
        q.append(root)
        while q:
            n = len(q)
            out = []
            while n>0:
                node = q.pop(0)
                out.append(node.val)
                if node.left:
                    q.append(node.left)
                if node.right:
                    q.append(node.right)
                n-=1
            res.append(out[:])
        return res
```
### 递归
```python
# -*- coding:utf-8 -*-
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
class Solution:
    # 返回二维列表[[1,2],[4,5]]
    def Print(self, root):
        # write code here
        res = []
        if root is None:
            return res
        self.helper(root, res, 0)
        return res
    def helper(self, root, res, level):
        if root is None:
            return
        if len(res) == level:
            res.append([])
        res[level].append(root.val)
        if root.left:
            self.helper(root.left,res,level+1)
        if root.right:
            self.helper(root.right, res, level+1)
```
## 参考
  -  [LeetCode-102题-二叉树的层次遍历](https://github.com/bryceustc/LeetCode_Note/blob/master/cpp/Binary-Tree-Level-Order-Traversal/README.md)
