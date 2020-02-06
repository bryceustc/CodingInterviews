# 题目:删除链表中重复的节点
## 题目描述：
在一个排序的链表中，存在重复的结点，请删除该链表中重复的结点，重复的结点不保留，返回链表头指针。 例如，链表1->2->3->3->4->4->5 处理后为 1->2->5

# 本题考点：
  
  链表编程能力，思维全面性，考虑重复节点所处位置，以及删除重复节点之后的结果。
  
# 解题思路:
此题与LeetCode第82题和83题类似，删除排序链表中重复的元素。

  方法一：直接法，
  - 定义一个虚拟头结点，链接上原链表，prev指向虚拟头结点，cur 指向原链表头部
  - 1.当前结点value ！= 当前结点的下一结点value。那么让pre指针来到当前结点，这样就链接了前一结点和当前结点。然后当前结点移至下一结点
  - 2.当前结点value == 当前结点的下一结点value。那么就让 cur 一直往下走直到 当前结点value ！= 当前结点的下一结点value，然后此时是不能动 pre 指针的，要避免后面还有重复的，所以让 pre->next = cur->next。然后当前结点移至下一结点。
  - 循环结束的条件，``cur!=NULL&&cur->next!=NULL;``
  
  方法二：递归法。
  
# 代码

[C++](./DeleteDuplicatedNode.cpp)

[Python](./DeleteDuplicatedNode.py)

# C++: 
### 方法一：直接法
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
    ListNode* deleteDuplication(ListNode* head)
    {
        if (head == NULL || head->next == NULL)
            return head;
        ListNode* p = new ListNode(-1);
        p->next = head;
        ListNode* prev = p;
        ListNode* cur = head;
        while(cur && cur->next)
        {
            if (cur->val == cur->next->val)
            {
                while(cur->next && cur->val == cur->next->val)
                {
                    cur = cur->next;
                }
                prev->next = cur->next;
            }
            else
            {
                prev = cur;
            }
            cur = cur->next;
        }
        return p->next;
    }
};
```
### 方法二：递归法
```c++
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplication(ListNode* head) {
        if(head==NULL || head->next == NULL)
            return head;
        //如果是这种情况
        //      1 --> 1 --> 1 --> 2 --> 3
        //     head  next
        //1.则需要移动next直到出现与当前head.value不相等的情况（含null）
        //2.并且此时的head已经不能要了，因为已经head是重复的节点
        //--------------else-------------
        //      1 --> 2 --> 3
        //     head  next
        //3.如果没有出现1的情况，则递归返回的节点就作为head的子节点
        if (head->val == head->next->val)
        {
            // 1
            while(head->next && head->val == head->next->val)
            {
                head = head->next;
            }
            // 2
            head = deleteDuplicates(head->next);
        }
        else
        {
            // 3
            head->next = deleteDuplicates(head->next);
        }
        return head;
    }
};
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
    def deleteDuplication(self, head):
        # write code here
        if head == None or head.next == None:
            return head
        p = ListNode(-1)
        p.next = head
        prev = p
        cur = head
        while cur and cur.next:
            if cur.val == cur.next.val:
                while cur.next and cur.val == cur.next.val:
                    cur = cur.next
                prev.next = cur.next
            else:
                prev = cur
            cur = cur.next
        return p.next
```
### 方法二：递归法
```python
# -*- coding:utf-8 -*-
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None
class Solution:
    def deleteDuplication(self, head):
        # write code here
        if head == None or head.next == None:
            return head
        if head.val == head.next.val:
            while head.next and head.val == head.next.val:
                head = head.next
            head = self.deleteDuplication(head.next)
        else:
            head.next = self.deleteDuplication(head.next)
        return head
```
## 参考
  -  [LeetCode—82题—删除排序链表中的重复元素II](https://github.com/bryceustc/LeetCode_Note/blob/master/cpp/Remove-Duplicates-From-Sorted-List-II/README.md)
  -  [LeetCode—83题—删除排序链表中的重复元素](https://github.com/bryceustc/LeetCode_Note/blob/master/cpp/Remove-Duplicates-From-Sorted-List/README.md)
  -  [三道题套路解决递归问题](https://lyl0724.github.io/2020/01/25/1/)
