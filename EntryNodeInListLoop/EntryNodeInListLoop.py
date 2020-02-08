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
