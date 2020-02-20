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
  此题与LeetCode-103题-二叉树的矩形层次遍历一样
  
  因为奇偶层的打印顺序不一样是相反的，可以用reverse来解决，但是海量数据时这个效率很低。
  
  因为奇数层的打印顺序是从左到右，偶数层的打印顺序是从右到左，可以利用STL容器deque中push_back(),push_front(),front(),back(),pop(),popfront()来解决，实现**前取后放，后取前放**，因为deque队列中的元素，都是从左到右的，当``zigzag==true;``，从左到右打印，就从前边开始取出元素，下一层的元素从后边压入，同理，从右向左打印时，从后边取出元素，下一层的元素就从前边压入，注意先压入右子树的，后压入左子树，这样新的队列还是从左到右，然后继续，直至队列为空。
  
# 代码

[C++](./PrintTreesInZigzag.cpp)

[Python](./PrintTreesInZigzag.py)

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
