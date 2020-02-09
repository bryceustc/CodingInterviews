### Solution 1:
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

### Solution 2:
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
