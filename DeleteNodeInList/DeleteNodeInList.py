# -*- coding:utf-8 -*-
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None
class Solution:
    def DeleteNode(self, head,tobedeleted):
        # write code here
        if head==None or tobedeleted == None:
            return
        ### 非尾节点
        if tobedeleted.next!= None:
            tobedeleted.val = tobedeleted.next.val
            tobedeleted.next = tobedeleted.next.next
        ## 链表只有一个节点，既是头结点，又是尾节点
        if head == tobedeleted:
            tobedeleted = None
            head = None
        p = head
        while p.next:
            if p.next!=None:
                p=p.next
            p.next = None         
