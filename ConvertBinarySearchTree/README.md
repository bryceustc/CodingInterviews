# 题目: 二叉搜索树与双向链表
## 题目描述：
输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。要求不能创建任何新的结点，只能调整树中结点指针的指向。

# 本题考点：
  
  二叉搜索树与双向链表的理解，以及中序遍历算法和递归编程能力，复杂问题的思维能力。
  
# 解题思路:
  此题与LeetCode-426题-将二叉搜索树转换为双向链表类似
  
  思路：
  
  举例说明：
  
  ![](https://cuijiahua.com/wp-content/uploads/2017/12/basis_26_1.jpg)
  
  二叉搜索树如上图所示，我们将其转换为配需双向链表。

根据二叉搜索树的特点：左结点的值<根结点的值<右结点的值，我们不难发现，使用二叉树的中序遍历出来的数据的数序，就是排序的顺序。因此，首先，确定了二叉搜索树的遍历方法。

接下来，我们看下图，我们可以把树分成三个部分：值为10的结点、根结点为6的左子树、根结点为14的右子树。根据排序双向链表的定义，值为10的结点将和它的左子树的最大一个结点链接起来，同时它还将和右子树最小的结点链接起来。
  
  ![](https://cuijiahua.com/wp-content/uploads/2017/12/basis_26_3.jpg)
  
  按照中序遍历的顺序，当我们遍历到根结点时，它的左子树已经转换成一个排序的好的双向链表了，并且处在链表中最后一个的结点是当前值最大的结点。我们把值为8的结点和根结点链接起来，10就成了最后一个结点，接着我们就去遍历右子树，并把根结点和右子树中最小的结点链接起来。
  
  
# 代码

[C++](./ConvertBinarySearchTree.cpp)

[Python](./ConvertBinarySearchTree.py)

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
    TreeNode* Convert(TreeNode* root)
    {
        if (root == NULL)
            return NULL;
	// 定义一个pre指针
        TreeNode* pre = NULL;
        helper(root, pre);
        TreeNode* res = root; 
	// 寻找到头结点
        while (res->left)
        {
            res = res->left;
        }
        return res;
    }
    void helper(TreeNode* cur, TreeNode* &pre)  // 中序遍历
    {
        if (cur == NULL)
            return;
        // 先递归遍历左子树
        helper(cur->left, pre);
        // 修改为双向链表
	//左指针
        cur->left = pre;
	 //右指针
        if(pre != NULL)
        {
            pre->right = cur;
        }
	 //更新双向链表尾结点
        pre = cur;
        // 再递归遍历右子树
        helper(cur->right, pre);
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
