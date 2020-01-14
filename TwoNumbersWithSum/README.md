# 题目描述:和为s的两个数字
## 题目：
输入一个递增排序的数组和一个数字s，在数组中查找两个数，使得它们的和正好是s。如果有多对数字的和等于s，输出任意一对即可。

# 本题考点：
  
  1). 双指针
  
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
    vector<int> FindNumbersWithSum(vector<int> nums,int target) {
        int n = nums.size();
        vector<int> res;
        if (nums.empty()) 
            return res;
        for(int i=0;i<n;i++)
        {
            for (int j=i+1;j<n;j++)
            {
                if (nums[i]+nums[j]==target)
                {
                    res.push_back(nums[i]);
                    res.push_back(nums[j]);
                    return res;
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
    res = Solution().FindNumbersWithSum(nums,9);
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
    vector<int> FindNumbersWithSum(vector<int> nums,int target) {
        vector<int> res;
        if(nums.empty())
            return res;
        int n =nums.size();
        unordered_map<int,int> record;
        for (int i=0;i<n;i++)
        {
            int complement = target - nums[i];
            if (record.find(complement)!=record.end())
            {
                res.push_back(complement);
                res.push_back(nums[i]);
                break;
            }
            record[nums[i]]=i;
        }
        return res;
    }
};

int main()
{
    vector<int> nums = {2,7,11,15};
    int target = 9;
    vector<int> res;
    res = Solution().FindNumbersWithSum(nums,target);
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
    vector<int> FindNumbersWithSum(vector<int> nums,int target) {
        vector<int> res;
        if(nums.empty())
            return res;
        int n =nums.size();
        int left=0;
        int right=n-1;
        while (right>left)
        {
            if (nums[left]+nums[right]==target)
            {
                res.push_back(nums[left]);
                res.push_back(nums[right]);
                break;
            }
            if (nums[left]+nums[right]>target)
            {
                right--;
            }
            else
                left++;
        }
        return res;
    }
};

// 输出两个数的乘积最小的。这句话的理解？
// 假设：若b>a,且存在，
// a + b = s;
// (a - m ) + (b + m) = s
// 则：(a - m )(b + m)=ab - (b-a)m - m*m < ab；说明外层的乘积更小
// 也就是说依然是左右夹逼法！！！只需要2个指针
// 1.left开头，right指向结尾
// 2.如果和小于sum，说明太小了，left右移寻找更大的数
// 3.如果和大于sum，说明太大了，right左移寻找更小的数
// 4.和相等，把left和right的数返回

int main()
{
    vector<int> nums = {2,7,11,15};
    int target = 9;
    vector<int> res;
    res = Solution().FindNumbersWithSum(nums,target);
    system("pause");
    return 0;
}
```

# Python:
## 方法一：暴力遍历
```python
# -*- coding:utf-8 -*-
class Solution:
    def FindNumbersWithSum(self, nums, target):
        # write code here
        res = []
        n = len(nums)
        if n==0:
            return res
        for i in range(n):
            for j in range(i+1,n):
                if nums[i]+nums[j]==target:
                    res.append(nums[i])
                    res.append(nums[j])
                    return res
        return res

if __name__ == '_ main__':
    nums = [2,7,11,15]
    target = 9
    res = Solution().FindNumbersWithSum(nums,target)    
    print(res)
```

## 方法二：哈希表
```python
# -*- coding:utf-8 -*-
class Solution:
    def FindNumbersWithSum(self, nums, target):
        # write code here
        res = []
        record = {}
        n = len(nums)
        if n==0:
            return res
        for index,num in enumerate (nums):
            complement = target - num
            if complement in record:
                res.append(complement)
                res.append(num)
                return res
            record[num] = index
        return res

if __name__ == '_ main__':
    nums = [2,7,11,15]
    target = 9
    res = Solution().FindNumbersWithSum(nums,target)    
    print(res)
```

## 方法三：双指针
```python
# -*- coding:utf-8 -*-
class Solution:
    def FindNumbersWithSum(self, nums, target):
        # write code here
        res = []
        n = len(nums)
        left = 0
        right = n-1
        while right>left:
            if nums[left]+nums[right]==target:
                res.append(nums[left])
                res.append(nums[right])
                return res
            if nums[left]+nums[right]>target:
                right-=1
            else:
                left+=1
        return res

if __name__ == '_ main__':
    nums = [2,7,11,15]
    target = 9
    res = Solution().FindNumbersWithSum(nums,target)    
    print(res)
```

# 参考：
  -  [LeetCode_167题——两数之和 II - 输入有序数组](https://github.com/bryceustc/LeetCode_Note/blob/master/cpp/Two-Sum-II-Input-Array-Is-Sorted/README.md)



