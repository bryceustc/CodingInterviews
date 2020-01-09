# 题目描述:0~n-1中缺失的数字
## 题目：
一个长度为n-1的递增排序数组中的所有数字都是唯一的，并且每个数字都在范围0~n-1之内。在范围0~n-1内的n个数字中有且只有一个数字不在该数组中，请找出这个数字。

# 本题考点：
  
  1). 二分查找  
  
# 解题思路:
  此题与LeetCode第268题缺失数字问题类似，
  
  1.) 直接暴力遍历，遍历数组所有元素，k。时间复杂度:O(n),空间复杂度O(1)
  
  2.) 利用动态规划的思想，假设要找下标i对应的丑数dp[i],可以用i之前的所有丑数乘若干个2直到大于上一个丑数dp[i-1]，记此数为num1;同理用i之前的所有丑数乘若干个3直到大于上一个丑数dp[i-1]，记此数为num2；用i之前的所有丑数乘若干个5直到大于上一个丑数dp[i-1]，记此数为num3。这三个数中的最小数字就是第i个丑数dp[i]。其实没必要把i之前的所有丑数乘2或者乘3或者乘5。在i之前的丑数中，肯定存在一个丑数（下标记为index2），乘2以后正好大于i的上一个丑数dp[i-1],index2之前的丑数乘2都小于等于dp[i-1];我们只需要记录index2，每次直接用这个下标对应的数乘2就行，并且在下标不满足时更新下标。同理我们也要记录乘3和乘5对应的下标。时间复杂度:O(n),空间复杂度:O(n)
  
  3). 最小堆

# 代码

[C++](./MissingNumber.cpp)

[Python](./MissingNumber.py)

# C++:
## 方法一：暴力遍历
```c++
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int res = 0;
        if (nums.empty())
            return 0;
        unordered_map<int,int> map;
        for (int i=0;i<n;i++)
        {
            map[nums[i]]++;
        }
        for (int num=0;num<=n;num++)
        {
            if (map[num]==0)
                return num;
        }
        return res;
    }
};


int main()
{
	vector<int> nums = {1,2,3,4};
	int res = Solution().missingNumber(nums);
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



