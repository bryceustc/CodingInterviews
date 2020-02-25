# 题目: 序列化二叉树
## 题目描述：
请实现两个函数，分别用来序列化和反序列化二叉树。

二叉树的序列化是指：把一棵二叉树按照某种遍历方式的结果以某种格式保存为字符串，从而使得内存中建立起来的二叉树可以持久保存。序列化可以基于先序、中序、后序、层序的二叉树遍历方式来进行修改，序列化的结果是一个字符串，序列化时通过 某种符号表示空节点（#），以 ！ 表示一个结点值的结束（value!）。

二叉树的反序列化是指：根据某种遍历顺序得到的序列化字符串结果str，重构二叉树。

**示例: **
```
你可以将以下二叉树：

    1
   / \
  2   3
     / \
    4   5

序列化为 "[1,2,3,null,null,4,5]"
```
返回：
```
[3,9,20,15,7]
```
# 本题考点：
  
  二叉树的遍历算法和递归编程能力，代码的鲁棒性。
  
# 解题思路:
  使用前序遍历来序列化和反序列化, 可以使用$符号表示NULL，同时每个结点之间，需要添加逗号，即','进行分隔。
  
  可以使用队列，主要就是将字符串分割
# 代码

[C++](./SerializeBinaryTrees.cpp)

[Python](./SerializeBinaryTrees.py)

# C++: 
###  递归
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
    char* Serialize(TreeNode *root) {    
        if(!root){
            return NULL;
        }
        string str;
        SerializeCore(root, str);
        // 把str流中转换为字符串返回
        int length = str.length();
        char* res = new char[length+1];
        // 把str流中转换为字符串返回
        for(int i = 0; i < length; i++){
            res[i] = str[i];
        }
        res[length] = '\0';
        return res;
    }
    TreeNode* Deserialize(char *str) {
        if(!str){
            return NULL;
        }
        TreeNode* res = DeserializeCore(&str);
        return res;
    }
    void SerializeCore(TreeNode* root, string& str){
        // 如果指针为空，表示左子节点或右子节点为空，则在序列中用#表示
        if(!root){
            str += '#';
            return;
        }
        string tmp = to_string(root->val);
        str += tmp;
        // 加逗号，用于区分每个结点
        str += ',';
        SerializeCore(root->left, str);
        SerializeCore(root->right, str);
    }
    // 递归时改变了str值使其指向后面的序列，因此要声明为char**
    TreeNode* DeserializeCore(char** str){
        // 到达叶节点时，调用两次，都返回null，所以构建完毕，返回父节点的构建
        if(**str == '#'){
            (*str)++;
            return NULL;
        }
        // 因为整数是用字符串表示，一个字符表示一位，先进行转换
        int num = 0;
        while(**str != ',' && **str != '\0'){
            num = num * 10 + ((**str) - '0');
            (*str)++;
        }
        TreeNode* root = new TreeNode(num);
        if(**str == '\0'){
            return root;
        }
        else{
            (*str)++;
        }
        root->left = DeserializeCore(str);
        root->right = DeserializeCore(str);
        return root;
    }
};
```
### 队列
```c++
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root == NULL)
            return "#_";
        string res = to_string(root->val) + "_";
        res += serialize(root->left);
        res += serialize(root->right);
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        std::stringstream ss(data);
        std::string item;
        queue<string> q;
        while (std::getline(ss, item, '_')) 
            q.push(item);
        return helper(q);
    }
    TreeNode* helper(queue<string>& q)
    {
        string val = q.front();
        q.pop();
        if (val == "#")
            return NULL;
        TreeNode* head = new TreeNode(stoi(val));
        head->left = helper(q);
        head->right = helper(q);
        return head;
    }
};
```
# Python:
### 递归
```python
# -*- coding:utf-8 -*-
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
class Solution:
    flag=-1
    def Serialize(self, root):
        # write code here
        if not root:
            return 'n'
        return str(root.val)+','+self.Serialize(root.left)+','+self.Serialize(root.right)
        
    def Deserialize(self, s):
        # write code here
        self.flag+=1
        lis = s.split(",")
        
        if self.flag > len(lis):
            return
        root = None
        if lis[self.flag] != "n":
            root = TreeNode(int(lis[self.flag]))
            root.left = self.Deserialize(s)
            root.right = self.Deserialize(s)
        return root
```
###  队列
```python
# -*- coding:utf-8 -*-
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
class Solution:
    def Serialize(self, root):
        # write code here
        s = ""
        q = []
        q.append(root)
        while q:
            node = q.pop(0)
            if node:
                s += str(node.val) + ","
                q.append(node.left)
                q.append(node.right)
            else:
                s += "n,"
        return s
    def Deserialize(self, s):
        # write code here
        s = s.split(",")
        if s[0] == 'n':
            return None
        q = []
        i = 1
        res = TreeNode(int(s[0]))
        q.append(res)
        while q:
            node = q.pop(0)
            if node == None:
                continue
            if s[i] != 'n':
                node.left = TreeNode(int(s[i]))
            else:
                node.left = None
            if s[i+1] != 'n':
                node.right = TreeNode(int(s[i+1]))
            else:
                node.right = None
            i+=2
            q.append(node.left)
            q.append(node.right)
        return res
```

## 参考
  -  [LeetCode-297题-二叉树的序列化与反序列化](https://blog.csdn.net/longshengguoji/article/details/8519812)
