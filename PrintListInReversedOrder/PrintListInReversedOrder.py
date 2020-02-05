### Python Solution 1:
# -*- coding:utf-8 -*-
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    # 返回从尾部到头部的列表值序列，例如[1,2,3]
    def printListFromTailToHead(self, listNode):
        # write code here
        res = []
        p = listNode
        while p:
            res.append(p.val)
            p = p.next
        ## 列表反转的两种方法
        res = res[::-1]
        # res.reverse()
        return res
### Python Solution 2:
# -*- coding:utf-8 -*-
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    # 返回从尾部到头部的列表值序列，例如[1,2,3]
    def printListFromTailToHead(self, head):
        # write code here
        res = []
        if head == None:
            return res
        prev = head
        cur = head.next
        temp = head.next.next
        while cur:
            temp = cur.next
            cur.next = prev
            prev = cur
            cur = temp
        head.next = None
        while prev:
            res.append(prev.val)
            prev = prev.next
        return res
