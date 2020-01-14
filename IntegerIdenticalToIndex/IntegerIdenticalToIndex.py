class Solution:
    def IntegerIdenticalToIndex(self, nums: List[int]) -> int:
        res = 0
        n = len(nums)
        for i in range(n):
            if nums[i] == i:
	    	res = nums[i]
		break
        return res
### Python Solution 2:
class Solution:
    def IntegerIdenticalToIndex(self, nums: List[int]) -> int:
        n = len(nums)
	start = 0
	end = n-1
	while end>=start:
	    mid = start + (end-start)//2
	    if nums[mid] == mid:
	    	return mid
	    if nums[mid] > mid:
	    	end = mid - 1
	    else:
	    	start = mid + 1
	if start == n:
	    return n
	return -1
