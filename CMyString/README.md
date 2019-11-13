# 题目描述

如下为类型CMyString的声明。请为该类型添加赋值运算符函数。
```c++
class CMyString
{
public:
     // 构造函数
     CMyString(char*pData = nullptr);
     // 拷贝构造函数
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

可以参考

- [C++](CMyString.cpp)


- [Python](CMystring.py)

**部分重要思想总结：**

- 向链表从后向前添加元素：将新加节点的next指向当前链表（即在首部加节点），生成新的链表，再赋值给当前链表即可
- 向链表从前向后添加元素：找到当前链表的最后节点，将当前链表最后节点的next指向新的节点，即实现链表的扩展，此时不需要重新赋值（因为是在原来的链表上添加的）

# 代码

[C++](PrintListInReversedOrder.cpp)

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

[Python](PrintListInReversedOrder.py)

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


