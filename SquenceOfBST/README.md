# 题目: 二叉搜索树的后序遍历序列
## 题目描述：
输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。如果是则输出Yes,否则输出No。假设输入的数组的任意两个数字都互不相同。

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
已知条件：后序序列最后一个值为root；二叉搜索树左子树值都比root小，右子树值都比root大。

1、确定root；

2、遍历序列（除去root结点），找到第一个大于root的位置，则该位置左边为左子树，右边为右子树；

3、遍历右子树，若发现有小于root的值，则直接返回false；

4、分别判断左子树和右子树是否仍是二叉搜索树（即递归步骤1、2、3）。
  
# 代码

[C++](./SquenceOfBST.cpp)

[Python](./SquenceOfBST.py)

# C++: 
### 
```c++
class Solution {
public:
    bool VerifySquenceOfBST(vector<int> sequence) {
        bool res = false;
        if (sequence.empty())
            return res;
        int n = sequence.size();
        res = helper(sequence,0,n-1);
        return res;
    }
    bool helper(vector<int> seq, int start, int end)
    {
        if (seq.empty() || start > end)
        {
            return false;
        }
        //根结点
        int root = seq[end];
        
        //在二叉搜索树中左子树的结点小于根结点
        int i = start;
        for (;i<end;i++)
        {
            if (seq[i]>root)
                break;
        }
        
        //在二叉搜索书中右子树的结点大于根结点
        for (int j =i;j<end;j++)
        {
            if (seq[j]<root)
                return false;
        }
        
        //判断左子树是不是二叉搜索树
        bool left = true;
        if (i>start)
        {
            left = helper(seq, start, i-1);
        }
        
        //判断右子树是不是二叉搜索树
        bool right = true;
        if (i < end-1)
        {
            right = helper(seq, i, end-1);
        }
        return left && right;
    }
};
```
# Python:
###  
```python
# -*- coding:utf-8 -*-
class Solution:
    def VerifySquenceOfBST(self, sequence):
        # write code here
        if sequence is None or len(sequence) == 0:
            return False
        root = sequence[-1]
        n = len(sequence)
        i=0
        for i in range(n):
            if sequence[i] > root:
                break
        for j in range(i,n):
            if sequence[j] < root:
                return False
        left = True
        if i > 0:
            left = self.VerifySquenceOfBST(sequence[:i])  # a[ : n]表示从第0个元素到第n个元素(不包括n)
        right = True
        if i < n - 1:
            right = self.VerifySquenceOfBST(sequence[i:-1])
        return left and right
```
## 参考
  -  [python 列表的中括号[]与冒号:的作用](https://blog.csdn.net/jingyu7/article/details/82934446)
