# -*- coding:utf-8 -*-
import heapq
class Solution:
    def __init__(self):
        self.count = 0
        self.max_heap = []
        self.min_heap = []
    def Insert(self, num):
        # write code here
        if self.count % 2 == 0:
            heapq.heappush(self.max_heap,-num)
            max_heap_top = heapq.heappop(self.max_heap)
            heapq.heappush(self.min_heap,-max_heap_top)
        else:
            heapq.heappush(self.min_heap,num)
            min_heap_top = heapq.heappop(self.min_heap)
            heapq.heappush(self.max_heap,-min_heap_top)
        self.count+=1
    def GetMedian(self, data):
        # write code here
        if self.count % 2 == 0:
            return(self.min_heap[0]-self.max_heap[0])/2.0
        else:
            return self.min_heap[0]

if __name__ == '_ main__':
    nums = [4,5,1]
    
    Solution().Insert(num[0])
    res = Solution().GetMedian()
    print(res)
    Solution().Insert(num[1])
    res = Solution().GetMedian()    
    print(res)
    Solution().Insert(num[2])
    res = Solution().GetMedian()    
    print(res)

    
### Solution 2:

class Solution:
    def __init__(self):
        self.store=[]
    def Insert(self, num):
        # write code here
        self.store.append(num)
    def GetMedian(self, data):
        # write code here
        store=sorted(self.store)
        n = len(self.store)
        if n%2==0:
            return (self.store[n//2]+self.store[n//2-1])/2.0
        else:
            return self.store[n//2]

### Solution 3:


class Solution:
    def __init__(self):
        self.store=[]
    def insertSort(self,arr):
        for i in range(1,len(arr)):
            j = i-1
            key = arr[i]
            while j >= 0:
                if arr[j] > key:
                    arr[j+1] = arr[j]
                    arr[j] = key
                j -= 1
        return arr
    def Insert(self, num):
        # write code here
        self.store.append(num)
	self.store = self.insertSort(self.store)
    def GetMedian(self, data):
        # write code here
        n = len(self.store)
        if n%2==0:
            return (self.store[n//2]+self.store[n//2-1])/2.0
        else:
            return self.store[n//2]
