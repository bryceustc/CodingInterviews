# 题目: 分行从上到下打印二叉树
## 题目描述：
从上到下按层打印二叉树，同一层的节点按从左到右的顺序打印，每一层打印到一行。

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
  [9,20],
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
  
  
# 代码

[C++](./PrintTreesInLines.cpp)

[Python](./PrintTreesInLines.py)

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
    # 返回二维列表[[1,2],[4,5]]
    def Print(self, root):
        # write code here
        res =[]
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

## 参考
  -  [STL队列deque用法](https://blog.csdn.net/longshengguoji/article/details/8519812)
  -  [STL队列Queue用法](https://blog.csdn.net/l494926429/article/details/52067004)
  -  [Python3：collections.deque的用法简介](https://blog.csdn.net/liangzuojiayi/article/details/51097008)

