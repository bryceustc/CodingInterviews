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
