# 题目:链表中倒数第k个节点
## 题目描述：
输入一个链表，输出该链表中倒数第k个结点。为了符合大多数人的习惯，本题从1开始计数，即链表的尾节点是倒数第一个节点。例如，一个链表有6个节点。这链表的倒数第三个节点是值为4的节点

# 本题考点：
  
  链表编程能力，代码的鲁棒性。考虑到特殊情况
  
# 解题思路:
此题与LeetCode第19题类似，但比19题情形要更复杂一点。

  方法一：直接法，
  两次遍历
  
  1.第一次遍历求出链表长度。
  
  2.第二次遍历返回指定结点。
  
  3.注意**特殊情况**。
  
  方法二：双指针法。
  
  递归套路解决链表问题：

   - 找终止条件：当head指向链表只剩一个元素的时候，return
   - 想想应该返回什么值：应该返回的自然是已经去重的链表的头节点
   - 每一步要做什么：宏观上考虑，如果当前head和head->next相等，相等则需要一直判断并后移``head = head->next;``，此时head指向重复元素的最后一个值，但这个head我们也不能要，就需要重新建立head，所以``head = deleteDuplicates(head->next);``，如果不相等，head->next指向的就是一个去重的链表。然后返回head
  
# 代码

[C++](./KthNodeFromEnd.cpp)

[Python](./KthNodeFromEnd.py)

# C++: 
### 方法一：直接法(两次遍历)
```c++
/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
    ListNode* FindKthToTail(ListNode* head, unsigned int k) {
        if (head==NULL || k<=0)
            return NULL;
        int n = 0;
        for (ListNode* temp = head;temp!=NULL;temp=temp->next)
        {
            n++;
        }
        if (n<k) return NULL;
        ListNode* p = head;
        for (int i=0;i<n-k;i++)
        {
            p = p->next;
        }
        return p;
    }
};
```
### 方法二：双指针法
```c++
/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
    ListNode* FindKthToTail(ListNode* head, unsigned int k) {
        if (head==NULL || k<=0)
            return NULL;
        ListNode* p = head;
        ListNode* q = head;
        // 从第1一个节点开始计数，所以走k-1步到达k节点，注意判断k是否超过链表总长度
        for (int i=0;i<k-1;i++)
        {
            if (q->next!=NULL)
                q = q->next;
            else
                return NULL;
        }
        while(q->next!=NULL)
        {
            p = p->next;
            q = q->next;
        }
        return p;
    }
};
```

# Python:
### 方法一：直接法（两次遍历）
```python
# -*- coding:utf-8 -*-
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def FindKthToTail(self, head, k):
        # write code here
        if head==None or k<=0:
            return None
        temp = head
        n = 0
        while temp:
            n+=1
            temp = temp.next
        if n<k:
            return None
        p = head
        for i in range(n-k):
            p = p.next
        return p
```
### 方法二：双指针法(一次遍历)
```python
# -*- coding:utf-8 -*-
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def FindKthToTail(self, head, k):
        # write code here
        if head==None or k<=0:
            return None
        p = head
        q = head
        for i in range(k-1):
            if q.next!=None:
                q = q.next
            else:
                return None
        while q.next!=None:
            p = p.next
            q = q.next
        return p
```
## 参考
  -  [LeetCode—19题—删除链表的倒数第N个节点](https://github.com/bryceustc/LeetCode_Note/blob/master/cpp/Remove-Nth-Node-From-End-Of-List/README.md)

