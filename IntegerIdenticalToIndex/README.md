# 题目描述:数组中数值和下标相等的元素
## 题目：
假设一个单调递增的数组里的每个元素都是整数并且是唯一的。请编程实现一个函数找出数组中任意一个数值等于其下标的元素。例如，在数组{-3, -1, 1, 3, 5}中，数字3和它的下标相等。

# 本题考点：
  
  1). 二分查找  
  
  2). 哈希表
  
  3). 数学技巧
  
# 解题思路:
  此题与LeetCode第268题缺失数字问题类似，但此题是递增排序的数组，较为简单,注意输入数组。
  
  1.) 直接暴力遍历，遍历数组所有元素，k。时间复杂度:O(n),空间复杂度O(1)
  
  2.) 二分查找

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
	vector<int> nums = {1,2,3,4};
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
    int missingNumber(vector<int>& nums) {
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
	vector<int> nums = {1,2,3,4};
	int res = Solution().missingNumber(nums);
	cout << res << endl;
	system("pause");
	return 0;
}
```


# Python:
## 方法一：哈希表
```python
# -*- coding:utf-8 -*-
class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        res = 0
        n = len(nums)
        nums_set = set(nums)
        for num in range(n+1):
            if num not in nums_set:
                return num
        return res

if __name__ == '_ main__':
    nums = [1,2,3,4,5]
    res = Solution().missingNumber(nums)    
    print(res)
```

## 方法二：数学方法
```python
# -*- coding:utf-8 -*-
class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        res = 0;
        n = len(nums)
        x = range(n+1)
        x = list(x)           ### Python3 需要用list转换成数组
        res = sum(x)-sum(nums)
        return res

if __name__ == '_ main__':
    nums = [1,2,3,4,5]
    res = Solution().missingNumber(nums)    
    print(res)
```

## 方法二：数学方法 （异或）
```python
# -*- coding:utf-8 -*-
class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        n = len(nums)
        res = n
        for i in range(n):
            res = res ^ nums[i]
            res = res ^ i
        return res

if __name__ == '_ main__':
    nums = [1,2,3,4,5]
    res = Solution().missingNumber(nums)    
    print(res)
```

## 方法三：排序法
```python
# -*- coding:utf-8 -*-
class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        nums = sorted(nums)
        n = len(nums)
        if nums[-1] != n:
            return n
        for i in range(0,n):
            if i!=nums[i]:
                return i

if __name__ == '_ main__':
    nums = [1,2,3,4,5]
    res = Solution().missingNumber(nums)    
    print(res)
```

# 参考：
  -  [LeetCode_268题——缺失数字](https://github.com/bryceustc/LeetCode_Note/blob/master/cpp/Missing-Number/README.md)




