class Solution:
    def reversePairs(self, nums: List[int]) -> int:
        if nums ==[]:
            return 0
        temp = [i for i in nums]
        count = 0
        n = len(nums)
        count = self.helper(nums, temp, 0, n-1)
        return count
    def helper(self, nums, temp, start, end):
        if start == end:
            temp[start] = nums[start]
            return 0
        mid = start + (end-start)//2
        left = self.helper(temp, nums, start, mid)
        right = self.helper(temp, nums, mid+1, end)
        
        i = mid
        j = end
        index = end
        count = 0
        while i>=start and j>=mid+1:
            if nums[i] > nums[j]:
                temp[index] = nums[i]
                index-=1
                i-=1
                count+=j-mid
            else:
                temp[index] = nums[j]
                index-=1
                j-=1
        while i>=start:
            temp[index] = nums[i]
            index-=1
            i-=1
        while j>=mid+1:
            temp[index] = nums[j]
            index-=1
            j-=1
        return left + right + count
