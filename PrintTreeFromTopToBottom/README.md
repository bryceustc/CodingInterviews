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
  注意此题与之前的前序遍历，中序遍历，后序遍历不一样，是一个层序遍历，需要利用STL中的容器队列来实现，queue是单边队列，先进先出，deque是双边队列，两边都可以进出，push_back()与push_front(),pop_back()与pop_front()。
  
  借助队列实现：
  
  1、将第一个元素加入队列
  
  2、队列不为空时取队首元素
  
  3、将下一层元素加入队尾
  
  4、调到第二步，直到队列为空
# 代码

[C++](./PrintTreeFromTopToBottom.cpp)

[Python](./PrintTreeFromTopToBottom.py)

# C++: 
###  queue实现
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
    vector<int> PrintFromTopToBottom(TreeNode* root) {
        vector<int> res;
        if (root==NULL)
            return res;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode* temp = q.front();
            q.pop();
            res.push_back(temp->val);
            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
        }
        return res;
    }
};
```
### deque实现
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
    vector<int> PrintFromTopToBottom(TreeNode* root) {
        vector<int> res;
        if (root==NULL)
            return res;
        deque<TreeNode*> q;
        q.push_back(root);
        while(q.size())
        {
            TreeNode* temp = q.front();
            q.pop_front();
            res.push_back(temp->val);
            if (temp->left)
                q.push_back(temp->left);
            if (temp->right)
                q.push_back(temp->right);
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
    # 返回从上到下每个节点值列表，例：[1,2,3]
    def PrintFromTopToBottom(self, root):
        # write code here
        res = []
        if root is None:
            return res
        q = []
        q.append(root)
        while len(q)>0:
            temp = q.pop(0)
            res.append(temp.val)
            if temp.left:
                q.append(temp.left)
            if temp.right:
                q.append(temp.right)
        return res
```
## 参考
  -  [STL队列deque用法](https://blog.csdn.net/longshengguoji/article/details/8519812)
  -  [STL队列Queue用法](https://blog.csdn.net/l494926429/article/details/52067004)

