# 题目: 两个链表的第一个公共节点
## 题目描述：
输入两个链表，找出它们的第一个公共结点。
# 本题考点：
  
  链表编程能力，复杂问题的思维能力，分析时间空间效率
  
# 解题思路:
  三步法：
  
  1、把复制的结点链接在原始链表的每一对应结点后面
  ![1](https://github.com/bryceustc/CodingInterviews/blob/master/CopyComplexList/Images/1.png)
  
  ![4](https://github.com/bryceustc/CodingInterviews/blob/master/CopyComplexList/Images/4.png)
  
  2、把复制的结点的random指针指向被复制结点的random指针的下一个结点
  ![2](https://github.com/bryceustc/CodingInterviews/blob/master/CopyComplexList/Images/2.png)
  
  3、拆分成两个链表，奇数位置组成原链表，偶数位置组成复制链表。
  ![3](https://github.com/bryceustc/CodingInterviews/blob/master/CopyComplexList/Images/3.png)
  
  ![5](https://github.com/bryceustc/CodingInterviews/blob/master/CopyComplexList/Images/5.png)
# 代码

[C++](./FirstCommonNodesInLists.cpp)

[Python](./FirstCommonNodesInLists.py)

# C++: 
### 三步法
```c++
/*
struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};
*/
class Solution {
public:
    RandomListNode* Clone(RandomListNode* head)
    {
        if (head==NULL) return NULL;
        RandomListNode* cur = head;
        //复制next 如原来是A->B->C 变成A->A'->B->B'->C->C'
        while(cur)
        {
            RandomListNode* temp = new RandomListNode(cur->label);
            temp->next = cur->next;
            cur->next = temp;
            cur = temp->next;
        }
        cur = head;
        //复制random cur是原来链表的结点 cur->next是复制cur的结点
        while(cur)
        {
            RandomListNode* temp = cur->next;
            if (cur->random)
            {
                temp->random = cur->random->next;
            }
            cur = temp->next;
        }
        // 拆分链表，将链表拆分为原链表和复制后的链表
        cur = head;
        RandomListNode* p = head->next;
        while(cur)
        {
            RandomListNode* temp = cur->next;
            cur->next = temp->next;
            if (temp->next!=NULL)
                temp->next = temp->next->next;
            cur = cur->next;
        }
        return p;
    }
};
```


# Python:
### 三步法
```python
# -*- coding:utf-8 -*-
# class RandomListNode:
#     def __init__(self, x):
#         self.label = x
#         self.next = None
#         self.random = None
class Solution:
    # 返回 RandomListNode
    def Clone(self, head):
        # write code here
        if head==None:
            return None
        cur = head
        while cur:
            temp = RandomListNode(cur.label)
            temp.next = cur.next
            cur.next = temp
            cur = temp.next
        cur = head
        while cur:
            temp = cur.next
            if cur.random:
                temp.random = cur.random.next
            cur = temp.next
        cur = head
        p = head.next
        while cur:
            temp = cur.next
            cur.next = temp.next
            if temp.next:
                temp.next = temp.next.next
            cur = cur.next
        return p
```
## 参考
  -  [复杂链表的复制牛客讨论](https://www.nowcoder.com/questionTerminal/f836b2c43afc4b35ad6adc41ec941dba?f=discussion)
