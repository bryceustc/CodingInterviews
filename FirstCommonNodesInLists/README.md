# 题目: 两个链表的第一个公共节点
## 题目描述：
输入两个链表，找出它们的第一个公共结点。
# 本题考点：
  
  链表编程能力
  
# 解题思路:
   方法一：暴力遍历法，对l1，l2进行遍历，时间复杂度为O(n\*m)
    
   方法二：方法一的时间复杂度有点高，考虑方法二，找出2个链表的长度，然后让长的先走两个链表的长度差，然后再一起走（因为2个链表用公共的尾部）。如果存在共同节点的话，那么从该节点，两个链表之后的元素都是相同的。 也就是说两个链表从尾部往前到某个点，节点都是一样的。
# 代码

[C++](./FirstCommonNodesInLists.cpp)

[Python](./FirstCommonNodesInLists.py)

# C++: 
### 方法一：直接遍历(不推荐)
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
### 方法二：
```c+++
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
        int n=0,m=0;
        // 计算l1链表的长度
        while (p)
        {
            n++;
            p = p->next;
        }
        // 计算l2链表的长度
        while(q)
        {
            m++;
            q = q->next;
        }
        // 如果链表长度不一样，计算两个链表长度的差值
        int k = 0;
        ListNode* temp_long = l1;
        ListNode* temp_short = l2;
        if (n>=m)
        {
            k = n-m;
        }
        else
        {
            k = m-n;
            temp_long = l2;
            temp_short = l1;
        }
        // 长的链表先移动差值k,剩余长度与短链表的长度一致
        for (int i=0;i<k;i++)
        {
            temp_long = temp_long->next;
        }
        // 然后同时移动，判断是否有公共节点
        while(temp_long && temp_short && temp_short!=temp_long)
        {
            temp_short = temp_short->next;
            temp_long = temp_long->next;
        }
        ListNode* res = temp_long;
        return res;
    }
};
```

# Python:
### 方法一：直接遍历法
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
### 方法二：
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
        n=0
        m=0
        while p:
            n+=1
            p = p.next
        while q:
            m+=1
            q = q.next
        temp_long = l1
        temp_short = l2
        k = 0
        if n>=m:
            k = n-m
        else:
            k = m-n
            temp_long = l2
            temp_short = l1
        for i in range(k):
            temp_long = temp_long.next
        while temp_long and temp_short and temp_long!=temp_short:
            temp_long = temp_long.next
            temp_short = temp_short.next
        res = temp_long
        return res
```
## 参考
  -  [复杂链表的复制牛客讨论](https://www.nowcoder.com/questionTerminal/6ab1d9a29e88450685099d45c9e31e46?f=discussion)
