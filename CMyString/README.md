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
     CMyString &operator=(const CMystring &str);
private:
     char* m_pData;
};
```

# 解题思路

思路1：此题要求打印链表每个节点的值，由于不用考虑链表的生成（其实有点复杂），所以我们直接在函数中依次将链表中的节点值取出来，保存至一个容器（对于C++）或者列表（对于Python）中；然后再逆序打印这个容器或者列表即可。

思路2：思路1其实偷懒了，因为严格意义上来说，既然是对于链表来操作，那么其实返回结果其实也应该是链表，而不应该是简单的容器或者列表。按这样理解，我们其实应该直接对链表进行逆序打印，而不是转换成中间变量来操作。

对于初级：

  1). 返回值的类型声明为该类型的引用，并在函数结束前返回实例自身的引用；

  2). 把传入的参数类型声明为常量引用；

  3). 如有必要，需要释放实例自身已有的内存；

  4). 判断传入的参数和当前的实例(\*this)是不是同一个实例

**思考：**自己实现测试用例，自己提供函数输入，即手写链表，你会写吗？

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


