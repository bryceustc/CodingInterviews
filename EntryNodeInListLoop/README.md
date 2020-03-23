# 题目: 链表中环的入口节点
## 题目描述：
给一个链表，若其中包含环，请找出该链表的环的入口结点，否则，输出null。

# 本题考点：
  
  链表编程能力，代码的鲁棒性。考虑到特殊情况
  
# 解题思路:
  此题利用快慢双指针
  
  设置快慢指针，都从链表头出发，快指针每次走两步，慢指针一次走一步，假如有环，一定相遇于环中某点（设置快慢指针fast和low，fast每次走两步，low每次走一步。假如有环，两者一定会相遇（因为low一旦进环，可看作fast在后面追赶low的过程，每次两者都接近一步，最后一定能追上））。接着让两个指针分别从相遇点和链表头出发，两者都改为每次走一步，最终相遇于环入口。
```
  原理：首先初始化快指针 fast = head.next.next 和 slow = head.next，
    此时快指针走的路长为2, m慢指针走的路长为1，之后令快指针每次走两步，
    慢指针每次走一步，这样快指针走的路长始终是慢指针走的路长的两倍，
    若不存在环，直接返回None，
    若存在环，则 fast 与 slow 肯定会在若干步之后相遇；
    性质1：
        设从head需要走 a 步到达环的入口，如果环存在的话，
        再走 b 步可以再次到达该入口（即环的长度为b），
        如果存在环的话，上述描述的 快指针 fast 和 
        慢指针slow 必然会相遇，且此时slow走的路长
        小于 a + b(可以自行证明)，设其为 a + x，
        当快慢指针相遇时，快指针已经至少走完一圈环了，
        不妨设相遇时走了完整的m圈(m >= 1)，有：    
        快指针走的路长为 a + mb + x
        慢指针走的路长为 a + x
        
        由于快指针fast 走的路长始终是慢指针的 2倍，所以：
        
        a + mb + x = 2(a + x)
        
        化简可得：
        
        a = mb - x  -------------  (*)
    
    当快指针与慢指针相遇时，由于 <性质1> 的存在，
    可以在链表的开头初始化一个新的指针，
    称其为 detection, 此时 detection 距离环的入口的距离为 a，
    
    此时令 detection 和 fast 每次走一步，
    会发现当各自走了 a 步之后，两个指针同时到达了环的入口，理由分别如下：
    
    detection不用说了，走了a步肯定到刚好到入口
    fast已经走过的距离为 a + mb + x，当再走 a 步之后，
    fast走过的总距离为 2a + mb + x，带入性质1的(*)式可得：
    2a + mb + x = a + 2mb，会发现，fast此时刚好走完了
    整整 2m 圈环，正好处于入口的位置。
    
    基于此，我们可以进行循环，直到 detection 和 
    fast 指向同一个对象，此时指向的对象恰好为环的入口。
```
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


