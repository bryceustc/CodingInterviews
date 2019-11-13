# 题目描述

如下为类型CMyString的声明。请为该类型添加赋值运算符函数。
```c++
class CMyString
{
public:
     // 构造函数
     CMyString(char*pData = nullptr);
     // 拷贝构造函数 (用来初始化对象)；
     CMyString(const CMyString & str);
     // 赋值运算函数
     ~CMyString(void);
private:
     char* m_pData;
};
```
# 本题考点：
  
  1). C++基础语法的理解，如运算符函数、常量引用等。
  
  2). 对内存泄漏的理解
  
  3). 代码异常安全性的理解
  
# 解题思路

**对于初级：**

  1). 返回值的类型声明为该类型的引用，并在函数结束前返回实例自身的引用；

  2). 把传入的参数类型声明为常量引用；

  3). 如有必要，需要释放实例自身已有的内存；

  4). 判断传入的参数和当前的实例(\*this)是不是同一个实例

**对于高级：**

  1). 其实就是一个构造函数，不过形参是该类型本身。
  
  2). 形参为const的引用，因为拷贝不影响原变量。如果不使用引用会无限循环调用构造函数。
  
  3). 在给新建变量赋值时会引用。而赋值运算符用在给已存在变量赋值的情况。

可以参考

- [C++](CMyString.cpp)


- [Python](CMystring.py)

# 代码

[C++](CMyString.cpp)

```c++
/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/
class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head){
        vector<int> temp;
        vector<int> temp2;
        //while(head != NULL){
        //    temp.push_back(head->val);
        //    head = head->next;
        //}
        // 逆序方法1: for循环
        //for(int i=temp.size()-1; i>=0; --i){
        //    temp2.push_back(temp[i]);
        //}
        
        // 逆序方法2: vector迭代器
        //for (vector<int>::reverse_iterator it = temp.rbegin(); it!= temp.rend(); it++){
        //    temp2.push_back(*it);
        //}
        // 逆序方法3: C++ < algorithm > 中定义的reverse函数
        //reverse(temp.begin(), temp.end());
        // 逆序方法4: 栈
        std::stack<ListNode*> nodes;
        ListNode *pNode = head;
        while(pNode!=NULL){
            nodes.push(pNode);
            pNode = pNode->next;
        }
        while(!nodes.empty()){
            pNode = nodes.top();
            temp.push_back(pNode->val);
            nodes.pop();
        }
        return temp;
    }
};
```

[Python](CMyString.py)

```python
# -*- coding:utf-8 -*-
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    # 返回从尾部到头部的列表值序列，例如[1,2,3]
    def printListFromTailToHead(self, listNode):
        # write code here
        list_numbers = []
        while listNode != None:
            list_numbers.append(listNode.val)
            listNode = listNode.next
        list_numbers.reverse()
        return list_numbers
```


