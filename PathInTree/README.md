# 题目: 二叉树中和为某一值的路径
## 题目描述：
输入一棵二叉树和一个整数，打印出二叉树中节点值的和为输入整数的所有路径。从树的根节点开始往下一直到叶节点所经过的节点形成一条路径。

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
  此题与LeetCode-113题-二叉树的矩形层次遍历一样
  
  因为奇偶层的打印顺序不一样是相反的，可以用reverse来解决，但是海量数据时这个效率很低。
  
  因为奇数层的打印顺序是从左到右，偶数层的打印顺序是从右到左，可以利用STL容器deque中push_back(),push_front(),front(),back(),pop(),popfront()来解决，实现**前取后放，后取前放**，因为deque队列中的元素，都是从左到右的，当``zigzag==true;``，从左到右打印，就从前边开始取出元素，下一层的元素从后边压入，同理，从右向左打印时，从后边取出元素，下一层的元素就从前边压入，注意先压入右子树的，后压入左子树，这样新的队列还是从左到右，然后继续，直至队列为空。
  
# 代码

[C++](./PathInTree.cpp)

[Python](./PathInTree.py)

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
    vector<vector<int> > Print(TreeNode* root) {
        vector<vector<int>> res;
        if (root==NULL)
            return res;
        deque<TreeNode*> q;
        q.push_back(root);
        bool zigzag = true; // 从右打印为True，从左打印为False
        while (!q.empty())
        {
            int count = q.size();
            vector<int> out;
            TreeNode* node;
            while (count>0)
            {
                if (zigzag) //前取后放：从左向右，所以从前边取，后边放入
                {
                    node = q.front();
                    q.pop_front();
                    if (node->left)
                        q.push_back(node->left);
                    if (node->right)
                        q.push_back(node->right);
                } 
                else  // 后取前放：从右向左，从后边取，前边放入
                {
                    node = q.back();
                    q.pop_back();
                    if (node->right)
                        q.push_front(node->right);
                    if (node->left)
                        q.push_front(node->left);
                }
                out.push_back(node->val);
                count--;
            }
            res.push_back(out);
            zigzag = !zigzag;
        }
        return res;
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
    def Print(self, root):
        # write code here
        res = []
        if root is None:
            return res
        import collections
        q = collections.deque()
        q.append(root)
        zigzag = True
        while q:
            n = len(q)
            out = []
            node = None
            while n>0:
                if zigzag:
                    node = q.popleft()
                    if node.left:
                        q.append(node.left)
                    if node.right:
                        q.append(node.right)
                else:
                    node = q.pop()
                    if node.right:
                        q.appendleft(node.right)
                    if node.left:
                        q.appendleft(node.left)
                out.append(node.val)
                n-=1
            res.append(out[:])
            zigzag = not zigzag
        return res
```
## 参考
  -  [LeetCode-103题-二叉树的锯齿形层次遍历](https://github.com/bryceustc/LeetCode_Note/blob/master/cpp/Binary-Tree-Zigzag-Level-Order-Traversal/README.md)
  -  [Python：collections.deque的用法](https://docs.python.org/zh-cn/3/library/collections.html?highlight=deque#collections.deque)

