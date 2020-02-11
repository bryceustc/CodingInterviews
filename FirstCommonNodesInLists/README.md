# 题目: 两个链表的第一个公共节点
## 题目描述：
输入两个链表，找出它们的第一个公共结点。
# 本题考点：
  
  链表编程能力
  
# 解题思路:
   方法一：直接遍历法，对l1，l2进行遍历，时间复杂度为O(n\*m)
    
# 代码

[C++](./FirstCommonNodesInLists.cpp)

[Python](./FirstCommonNodesInLists.py)

# C++: 
### 直接遍历
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
    ListNode* FindFirstCommonNode( ListNode* l1, ListNode* l2) {
        if (l1==NULL || l2 == NULL) return NULL;
        ListNode* p = l1;
        ListNode* q = l2;
        while(p)
        {
            q = l2;
            while(q)
            {
                if (p->val==q->val)
                {
                    return p;
                }
                else
                {
                    q = q->next;
                }
            }
            p = p->next;
        }
        return NULL;
    }
};
```


# Python:
### 直接遍历法
```python
# -*- coding:utf-8 -*-
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None
class Solution:
    def FindFirstCommonNode(self, l1, l2):
        # write code here
        if l1==None or l2 == None:
            return None
        p = l1
        q = l2
        while p:
            q = l2
            while q:
                if p.val==q.val:
                    return p
                else:
                    q = q.next
            p = p.next
        return None
```
## 参考
  -  [复杂链表的复制牛客讨论](https://www.nowcoder.com/questionTerminal/f836b2c43afc4b35ad6adc41ec941dba?f=discussion)
