##  Python Solution 1:
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
## Python Solution 2:
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
