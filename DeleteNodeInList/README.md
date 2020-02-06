# 题目:删除链表的节点
## 题目描述：
给定单向链表的头指针和一个节点指针，定义一个函数在O(1)时间内删除该节点。链表节点与函数的定义如下。
```c++
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
void DeleteNode(ListNode* head, ListNode* ToBeDeleted);
```

# 本题考点：
  
  链表的编程能力，创新思维能力，思维的全面性
  
# 解题思路:
  ![1](https://github.com/bryceustc/CodingInterviews/blob/master/DeleteNodeInList/Images/1.png)
  思路一：删除节点时不一定直接是直接删除，还可以是将下一节点的内容复制到被删除节点的内容，然后把下一节点删掉。分析这种思路的时间复杂度，对于n-1个非尾节点而言，我们可以在O(1)时间内把下一个节点的内存，复制到要删除的节点，并删除下一节点；对于尾节点而言，由于仍然需要顺序查找，时间复杂度是O(n),因此总的p平均时间复杂度是[(n-1)\*O(1)+O(n)]/n,结果还是O(1).
  
  思路二：直接删除该节点，按顺序遍历，被删除节点的前一个节点指向被删除节点的下一节点，即删除指定节点，但此时需要从头指针遍历得到被删除节点的前一个节点(单向链表无法得到指向前一个节点的指针)，所以时间复杂度为O(n)。
# 代码

[C++](./DeleteNodeInList.cpp)

[Python](./DeleteNodeInList.py)

# C++: 
### 
```c++
void DeleteNode(ListNode* head,ListNode* ToBeDeleted)
{
    if (head == NULL ||ToBeDeleted == NULL)
        return;
    // 删除节点不是尾节点
    if (ToBeDeleted->next != NULL)
    {
        ListNode* p = ToBeDeleted->next;
        ToBeDeleted->val = p->val;
        ToBeDeleted->next = p->next;
        delete p;
        p = NULL;
    }
    // 链表只有一个节点，既是头结点，又是尾节点
    if (head == ToBeDeleted)
    {
        delete ToBeDeleted;
        ToBeDeleted = NULL;
        head = NULL;
    }
    // 链表中有多个节点，删除尾节点
    else
    {
        ListNode* p = head;
        while(p->next)
        {
            if (p->next != ToBeDeleted)
            {
                p = p->next;
            }
            p->next = NULL;
            delete ToBeDeleted;
            ToBeDeleted = NULL;
        }
    }
}
```
# Python:
### 方法一：直接法
```python
# -*- coding:utf-8 -*-
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None
class Solution:
    def DeleteNode(self, head,tobedeleted):
        # write code here
        if head==None or tobedeleted == None:
            return
        ### 非尾节点
        if tobedeleted.next!= None:
            tobedeleted.val = tobedeleted.next.val
            tobedeleted.next = tobedeleted.next.next
        ## 链表只有一个节点，既是头结点，又是尾节点
        if head == tobedeleted:
            tobedeleted = None
            head = None
        p = head
        while p.next:
            if p.next!=None:
                p=p.next
            p.next = None            
```
## 参考
  -  [LeetCode—203题—移除链表元素](https://github.com/bryceustc/LeetCode_Note/tree/master/cpp/Remove-Linked-List-Elements)
