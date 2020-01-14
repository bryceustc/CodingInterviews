# 题目描述:数组中数值和下标相等的元素
## 题目：
假设一个单调递增的数组里的每个元素都是整数并且是唯一的。请编程实现一个函数找出数组中任意一个数值等于其下标的元素。例如，在数组{-3, -1, 1, 3, 5}中，数字3和它的下标相等。

# 本题考点：
  
  1). 二分查找  
  
  
# 解题思路:
  
  1.) 直接暴力遍历，遍历数组所有元素，k。时间复杂度:O(n),空间复杂度O(1)
  
  2.) 二分查找,由于数组是单调递增排序的，用二分查找，如果``nums[mid]==mid``返回``nums[mid]``，如果``nums[mid] == m > mid == i``，由于数组中的所有数字都唯一且单调递增，那么对于任意大于0的k,位于下标i+k的数字的值大于等于m+k,另外，因为m>i,所以m+k>i+k。因此位于下标i+k的数字的值一定大于它的下标。这意味着如果第i个数字的值大于i，那么它右边的数字都大于对应的下标，可以忽略，下一轮查找我们需要从左边的数字查找。

# 代码

[C++](./IntegerIdenticalToIndex.cpp)

[Python](./IntegerIdenticalToIndex.py)

# C++:
## 方法一：暴力遍历
```c++
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int IntegerIdenticalToIndex(vector<int>& nums) {
        int n = nums.size();
        int res = 0;
        if (nums.empty())
            return 0;
        for (int i=0;i<n;i++)
        {
            if (nums[i]==i)
	    {
	    	res = nums[i];
		break;
	    }
        }
        return res;
    }
};


int main()
{
	vector<int> nums = {-1,0,2};
	int res = Solution().IntegerIdenticalToIndex(nums);
	cout << res << endl;
	system("pause");
	return 0;
}
```


## 方法二：二分查找
```c++
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int IntegerIdenticalToIndex(vector<int>& nums) {
        int res = 0;
        int n = nums.size();
        int start = 0;
	int end = n-1;
	while(end>=start)
	{
	    int mid = start + (end -start) /2;
	    if (nums[mid]==mid)
	    {
	    	res = mid;
		break;
	    }
	    if (nums[mid]>mid)
	    {
	    	end = mid-1;
	    }
	    else
	    {
	    	start = mid +1;
	    }
	}
        return res;
    }
};


int main()
{
	vector<int> nums = {-1,0,2};
	int res = Solution().IntegerIdenticalToIndex(nums);
	cout << res << endl;
	system("pause");
	return 0;
}
```


# Python:
## 方法一：直接遍历
```python
# -*- coding:utf-8 -*-
class Solution:
    def IntegerIdenticalToIndex(self, nums: List[int]) -> int:
        res = 0
        n = len(nums)
        for i in range(n):
            if nums[i] == i:
	    	res = nums[i]
		break
        return res

if __name__ == '_ main__':
    nums = [-1,0,2]
    res = Solution().IntegerIdenticalToIndex(nums)    
    print(res)
```

## 方法二：二分查找
```python
# -*- coding:utf-8 -*-
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
if __name__ == '_ main__':
    nums = [-1,0,2]
    res = Solution().IntegerIdenticalToIndex(nums)    
    print(res)
```
