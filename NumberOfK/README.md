# 题目描述:数字在排序数组中出现的次数
## 题目：
统计一个数字在排序数组中出现的次数。

# 本题考点：
  
  1). 二分查找  
  
# 解题思路:
  此题与LeetCode第34题在排序数组中查找元素的第一个和最后一个位置问题类似，
  
  1.) 直接暴力遍历，遍历数组所有元素，k。时间复杂度:O(n),空间复杂度O(1)
  
  2.) 利用二分查找，找到数字的左边界，以及右边界，然后相减+1就是。时间复杂度:O(logn),空间复杂度O(1)

# 代码

[C++](./NumbersAppearOnce.cpp)

[Python](./NumbersAppearOnce.py)

# C++:
## 方法一：暴力遍历
```c++
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int GetNumberOfK(vector<int> nums ,int k) {
        int res = 0;
        if (nums.empty())
            return 0;
        int n = nums.size();
        for (int i=0;i<n;i++)
        {
            if (nums[i]==k)
                res++;
        }
        return res;
    }
};


int main()
{
	vector<int> nums = {1,2,3,3,3,4};
	int k = 3;
	int res = Solution().GetNumberOfK(nums,k);
	cout << res << endl;
	system("pause");
	return 0;
}
```

## 方法二：二分查找
```c++
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
class Solution {
public:
    int GetNumberOfK(vector<int> nums ,int k) {
        int res = 0;
        if (nums.empty())
            return 0;
        int n = nums.size();
        int start = 0;
        int end = n;
        while (end > start)
        {
            int mid = start + (end-start)/2;
            if (nums[mid]==k)
            {
                end=mid;
            }
            if (nums[mid]<k)
                start = mid+1;
            if (nums[mid]>k)
                end = mid;
        }
        int temp1 = start; // 一次二分查找寻找左侧边界，
        start = 0;
        end = n;
        while (end > start)
        {
            int mid = start + (end-start)/2;
            if (nums[mid]==k)
            {
                start=mid+1;
            }
            if (nums[mid]<k)
                start = mid+1;
            if (nums[mid]>k)
                end = mid;
        }
        int temp2 = end-1;   // 一次二分查找寻找右侧边界，注意寻找右侧边界要减一
        res = temp2-temp1+1;
        return res;
    }
};


int main()
{
	vector<int> nums = {1,2,3,3,3,4,5};
	int k = 3;
	int res = Solution().GetNumberOfK(nums,k);
	cout << res << endl;
	system("pause");
	return 0;
}
```



# Python:
## 方法一：暴力遍历
```python
# -*- coding:utf-8 -*-
class Solution:
    def GetNumberOfK(self, nums, k):
        # write code here
        res = 0
        n = len(nums)
        if n==0:
            return 0
        for i in range(n):
            if nums[i]==k:
                res+=1
        return res

if __name__ == '_ main__':
    nums = [1,2,3,3,3,4,5]
    k = 3
    res = Solution().GetNumberOfK(nums,k)    
    print(res)
```

## 方法二：二分查找
```python
# -*- coding:utf-8 -*-
class Solution:
    def GetNumberOfK(self, nums, k):
        # write code here
        res = 0
        n = len(nums)
        if n==0:
            return 0
        start = 0
        end = n
        while end > start:
            mid = start + (end-start)//2
            if nums[mid]==k:
                end = mid
            if nums[mid] < k:
                start = mid+1
            if nums[mid] > k:
                end = mid
        temp1 = start ## 一次二分查找寻找左侧边界
        start = 0
        end = n
        while end > start:
            mid = start + (end - start)//2
            if nums[mid] == k:
                start = mid + 1
            if nums[mid] < k:
                start = mid + 1
            if nums[mid] > k:
                end = mid
        temp2 = end - 1  ## 一次二分查找寻找右侧边界，注意右侧边界要减一
        res = temp2-temp1+1
        return res

if __name__ == '_ main__':
    nums = [1,2,3,3,3,4,5]
    k = 3
    res = Solution().GetNumberOfK(nums,k)    
    print(res)
```



# 参考：
  -  [二分查找总结](https://github.com/bryceustc/LeetCode_Note/blob/master/cpp/Find-First-And-Last-Position-Of-Element-In-Sorted-Array/BinarySearch.md)
  -  [LeetCode_34题——在排序数组中查找元素的第一个和最后一个位置](https://github.com/bryceustc/LeetCode_Note/blob/master/cpp/Find-First-And-Last-Position-Of-Element-In-Sorted-Array/README.md)


