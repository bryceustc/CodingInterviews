# 题目描述:二维数组中的查找

## 题目：
在一个二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。请完成一个函数，输入这样的一个二维数组和一个整数，
判断数组中是否含有该整数

# 本题考点：
  
  1). 二维数组的理解
  
  2). 查找
  
# 解题思路:
  1). 直接暴力遍历二维数组所有元素，时间复杂度为O(m\*n)
  
  2). 对每一行使用一次二分查找，时间复杂度为O(m\*logn)
  
  3). 根据简单的例子寻找规律，从右上角开始寻找，时间复杂度为O(m+n)

# 代码

[C++](FindInPartiallySortedMatrix.cpp)

[Python](FindInPartiallySortedMatrix.py)

# C++:
## 方法一：暴力遍历
```c++
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        if (nums.empty()) return 0;
        int n = nums.size();     
        int res = nums[0];
        for (int i=1;i<n;i++)
        {
            if (res>nums[i])
                res = nums[i];
        }
        return res;
    }
};


int main()
{
    vector<int> nums = {3,1};
    int res=nums[0];
    res = Solution().MinNumberInRotatedArray(nums);
    cout<< res <<endl;
    system("pause");
    return 0;
}
```

## 方法二：二分查找：
```c++
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        if (nums.empty()) return 0;
        int n = nums.size();     
        int start = 0;
        int end = n-1;
        int res = nums[0];
        while (end>=start)
        {
            int mid = start + (end-start)/2;
            if (nums[mid]>=res)
            {
                start = mid+1;
            }
            if (nums[mid]<res)
            {
                end = mid-1;
            }
            res = min(res,nums[mid]);
        }
        return res;   
    }
};


int main()
{
    vector<int> nums = {3,1};
    int res=nums[0];
    res = Solution().MinNumberInRotatedArray(nums);
    cout<< res <<endl;
    system("pause");
    return 0;
}
```

## 方法三：sort排序后返回：
```c++
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        if (nums.empty()) return 0;
        int res = 0;
        sort(nums.begin(),nums.end());
        res =nums[0];
        return res;
    }
};


int main()
{
    vector<int> nums = {3,1};
    int res=nums[0];
    res = Solution().MinNumberInRotatedArray(nums);
    cout<< res <<endl;
    system("pause");
    return 0;
}
```



# Python:
## 方法一：暴力遍历：
```python
# -*- coding:utf-8 -*-
class Solution:
    def findMin(self, nums: List[int]) -> int:
        n = len(nums)
        if n==0:
            return 0
        res = nums[0]
        for i in range (n):
            if res >nums[i]:
                res = nums[i]
        return res


if __name__ == '_ main__':
    nums = [3,4,5,1,2]
    res = Solution().findMin(nums)
    print(res)
```

## 方法二：一次二分查找：
```python
# -*- coding:utf-8 -*-
class Solution:
    def findMin(self, nums: List[int]) -> int:
        n = len(nums)
        if n==0:
            return 0
        res = nums[0]
        start = 0
        end = n-1
        while end>=start:
            mid = start+(end-start)//2
            if nums[mid]>=res:
                start=mid+1
            if nums[mid]<res:
                end = mid-1
            res = min(res,nums[mid])
        return res


if __name__ == '_ main__':
    nums = [3,4,5,1,2]
    res = Solution().findMin(nums)
    print(res)
```

## 方法三：sorted排序后返回：
```python
# -*- coding:utf-8 -*-
class Solution:
    def findMin(self, nums: List[int]) -> int:
        n = len(nums)
        if n==0:
            return 0
        res = nums[0]
        for i in range (n):
            if res >nums[i]:
                res = nums[i]
        return res


if __name__ == '_ main__':
    nums = [3,4,5,1,2]
    res = Solution().findMin(nums)
    print(res)

```

# 参考：
 -  [二分查找算法](https://github.com/bryceustc/LeetCode_Note/blob/master/cpp/Find-First-And-Last-Position-Of-Element-In-Sorted-Array/BinarySearch.md)
 
 -  [寻找旋转排序数组中的最小值](https://github.com/bryceustc/LeetCode_Note/blob/master/cpp/Find-Minimum-In-Rotated-Sorted-Array/README.md)

