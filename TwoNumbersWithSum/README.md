# 题目描述:和为s的两个数字
## 题目：
输入一个递增排序的数组和一个数字s，在数组中查找两个数，使得它们的和正好是s。如果有多对数字的和等于s，输出任意一对即可。

# 本题考点：
  
  1). 二分查找  
  
# 解题思路:
  此题与LeetCode第268题缺失数字问题类似，
  
  1.) 直接暴力遍历，遍历数组所有元素，k。时间复杂度:O(n<sup>2</sup>),空间复杂度O(1)
  
  2.) 哈希表。时间复杂度O(n)，空间复杂度O(n).
  
  3.) 双指针。时间复杂度:O(n),空间复杂度:O(n)

# 代码

[C++](./TwoNumbersWithSum.cpp)

[Python](./TwoNumbersWithSum.py)

# C++:
## 方法一：暴力遍历
```c++
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector <int> res (2,0);
        if (numbers.empty())
            return res;
        int n = numbers.size();
        for (int i=0;i<n;i++)
        {
            for (int j = i+1; j<n;j++)
            {
                if (numbers[i]+numbers[j]==target)
                {
                    res[0] = numbers[i];
                    res[1] = numbers[j];
                    break;
                }
            }
        }
        return res;
    }
};


int main()
{
    vector<int> nums = {2,7,11,15};
    vector<int> res;
    res = Solution().twoSum(nums,9);
    system("pause");
    return 0;
}
```


## 方法二：哈希表
```c++
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
using namespace std::tr1;
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector <int> res (2,0);
        if (numbers.empty())
            return res;
        int n = numbers.size();
        unordered_map<int,int> record;
        for (int i=0;i<n;i++)
        {
            int complement = target -numbers[i];
            if (record.find(complement)!=record.end())
            {
                res[0] = complement;
                res[1] = nums[i];
                break;
            }
            record[numbers[i]] = i;
        }
        return res;
    }
};


int main()
{
    vector<int> nums = {2,7,11,15};
    vector<int> res;
    res = Solution().twoSum(nums,9);
    system("pause");
    return 0;
}
```

## 方法三：双指针
```c++
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector <int> res (2,0);
        if (nums.empty())
            return res;
        int n = nums.size();
        int left = 0;
        int right = n-1;
        while (right>left)
        {
            if (nums[left]+nums[right]==target)
            {
                res[0] = nums[left];
                res[1] = nums[right];
                break;
            }
            if (nums[left]+nums[right]>target)
            {
                right--;
            }
            if (nums[left]+nums[right]<target)
            {
                left++;
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
## 方法一：暴力遍历
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

## 方法二：哈希表
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

## 方法三：双指针
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



