# 题目: 链表中环的入口节点
## 题目描述：
给一个链表，若其中包含环，请找出该链表的环的入口结点，否则，输出null。

# 本题考点：
  
  链表编程能力，代码的鲁棒性。考虑到特殊情况
  
# 解题思路:
此题与LeetCode第19题类似，但比19题情形要更复杂一点。

  
# 代码

[C++](./EntryNodeInListLoop.cpp)

[Python](./EntryNodeInListLoop.py)

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


