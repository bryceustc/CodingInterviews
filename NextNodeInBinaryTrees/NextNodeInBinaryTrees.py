class Solution:
    def GetNext(self, Node):
        # write code here
        if Node is None:
            return None
        res = None
        if Node.right:
            pRight = Node.right
            while pRight.left:
                pRight = pRight.left
            res = pRight
        elif Node.next:
            pCur = Node
            pNext = Node.next
            while pNext and pNext.right == pCur:
                pCur = pNext
                pNext = pNext.next
            res = pNext
        return res
