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
## Solution 2：
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
