# 题目: 复杂链表的复制
## 题目描述：
输入一个复杂链表（每个节点中有节点值，以及两个指针，一个指向下一个节点，另一个特殊指针指向任意一个节点），返回结果为复制后复杂链表的head。（注意，输出结果中请不要返回参数中的节点引用，否则判题程序会直接返回空）

# 本题考点：
  
  链表编程能力，递归和非递归方法都要掌握
  
# 解题思路:
此题与LeetCode第21题一样，合并两个有序链表。

  方法一：非递归法，新建一个虚拟节点，然后l3=dummyhead，然后一个一个节点的判断，如果l1->val<=l2->val，l3节点就指向l1，l1指向下一指针，否则指向l2，l2指向下一指针，直到有一个指针为空，然后l3下一指针指向另一非空的，返回dummyhead->next。
  
  方法二：递归法。
  
  先判断输入的链表是否为空的指针。如果第一个链表为空，则直接返回第二个链表；如果第二个链表为空，则直接返回第一个链表。如果两个链表都是空链表，合并的结果是得到一个空链表。

两个链表都是排序好的，我们只需要从头遍历链表，判断当前指针，哪个链表中的值小，即赋给合并链表指针即可。使用递归就可以轻松实现。
  
# 代码

[C++](./CopyComplexList.cpp)

[Python](./CopyComplexList.py)

# C++: 
### 方法一：非递归法
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
    ListNode* Merge(ListNode* l1, ListNode* l2)
    {
        ListNode* dummyhead = new ListNode(-1);
        ListNode* l3 = dummyhead;
        if (l1==NULL) return l2;
        if (l2==NULL) return l1;
        if (l1==NULL && l2==NULL) return NULL;
        while(l1 && l2)
        {
            if (l1->val<=l2->val)
            {
                l3->next = l1;
                l1 = l1->next;
            }
            else
            {
                l3->next = l2;
                l2 = l2->next;
            }
            l3 = l3->next;
        }
        if (l1==NULL) l3->next = l2;
        if (l2==NULL) l3->next = l1;
        return dummyhead->next;
    }
};
```
### 方法二：递归法
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
    ListNode* Merge(ListNode* l1, ListNode* l2)
    {
        if (l1==NULL) return l2;
        if (l2==NULL) return l1;
        if (l1==NULL && l2==NULL) return NULL;
        if (l1->val <= l2->val)
        {
            l1->next = Merge(l1->next,l2);
            return l1;
        }
        else
        {
            l2->next = Merge(l1,l2->next);
            return l2;
        }
    }
};
```

# Python:
### 方法一：非递归法
```python
# -*- coding:utf-8 -*-
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None
class Solution:
    # 返回合并后列表
    def Merge(self, l1, l2):
        # write code here
        dummyhead = ListNode(-1)
        l3 = dummyhead
        if l1==None:
            return l2
        if l2==None:
            return l1
        if l1==None and l2==None:
            return None
        while l1 and l2:
            if l1.val<=l2.val:
                l3.next = l1
                l1 = l1.next
            else:
                l3.next = l2
                l2 = l2.next
            l3 = l3.next
        if l1==None:
            l3.next = l2
        if l2==None:
            l3.next = l1
        return dummyhead.next
```
### 方法二：递归法
```python
# -*- coding:utf-8 -*-
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None
class Solution:
    # 返回合并后列表
    def Merge(self, l1, l2):
        # write code here
        if l1==None:
            return l2
        if l2==None:
            return l1
        if l1==None and l2==None:
            return None
        if l1.val <= l2.val:
            l1.next = self.Merge(l1.next,l2)
            return l1
        else:
            l2.next = self.Merge(l1,l2.next)
            return l2
```
## 参考
  -  [LeetCode—21题—合并两个有序链表](https://github.com/bryceustc/LeetCode_Note/blob/master/cpp/Merge-Two-Sorted-Lists/README.md)

