# 题目: 链表中环的入口节点
## 题目描述：
给一个链表，若其中包含环，请找出该链表的环的入口结点，否则，输出null。

# 本题考点：
  
  链表编程能力，代码的鲁棒性。考虑到特殊情况
  
# 解题思路:
  此题利用快慢双指针
  
  设置快慢指针，都从链表头出发，快指针每次走两步，慢指针一次走一步，假如有环，一定相遇于环中某点（设置快慢指针fast和low，fast每次走两步，low每次走一步。假如有环，两者一定会相遇（因为low一旦进环，可看作fast在后面追赶low的过程，每次两者都接近一步，最后一定能追上））。接着让两个指针分别从相遇点和链表头出发，两者都改为每次走一步，最终相遇于环入口。
  
# 代码

[C++](./EntryNodeInListLoop.cpp)

[Python](./EntryNodeInListLoop.py)

# C++: 
### 快慢双指针法
```c++
/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
*/
class Solution {
public:
    ListNode* EntryNodeOfLoop(ListNode* head)
    {
        if (head==NULL || head->next==NULL)
            return NULL;
        ListNode* p = head;
        ListNode* q = head;
        while(q && q->next)
        {
            p = p->next;//慢指针走一步
            q = q->next->next;//快指针走两步
            if (p==q)  // 找到环中相遇点,如果没找到就会跳出循环，因为会指向NULL
            {
                p = head; //将两个指针设置为一个在开头，一个在相遇点
                // 并同时同步移动，再次相遇时就是环的入口节点
                while(p!=q)
                {
                    p = p->next;
                    q = q->next;
                }
                if (p==q)
                    return p;
            }
        }
        return NULL;
    }
};
```
# Python:
### 快慢双指针法
```python
# -*- coding:utf-8 -*-
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None
class Solution:
    def EntryNodeOfLoop(self, head):
        # write code here
        if head==None or head.next==None:
            return None
        p = head
        q = head
        while q and q.next:
            p = p.next
            q = q.next.next
            if p == q:
                p = head
                while p!=q:
                    p = p.next
                    q = q.next
                if p==q:
                    return p
        return None
```

## 参考
  -  [剑指offer—22题—链表中倒数第k个节点](https://github.com/bryceustc/CodingInterviews/blob/master/KthNodeFromEnd/README.md)


