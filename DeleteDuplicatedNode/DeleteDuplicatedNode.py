# -*- coding:utf-8 -*-
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None
class Solution:
    def deleteDuplication(self, head):
        # write code here
        if head == None or head.next == None:
            return head
        p = ListNode(-1)
        p.next = head
        prev = p
        cur = head
        while cur and cur.next:
            if cur.val == cur.next.val:
                while cur.next and cur.val == cur.next.val:
                    cur = cur.next
                prev.next = cur.next
            else:
                prev = cur
            cur = cur.next
        return p.next
## Solution 2:
# -*- coding:utf-8 -*-
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None
class Solution:
    def deleteDuplication(self, head):
        # write code here
        if head == None or head.next == None:
            return head
        if head.val == head.next.val:
            while head.next and head.val == head.next.val:
                head = head.next
            head = self.deleteDuplication(head.next)
        else:
            head.next = self.deleteDuplication(head.next)
        return head
