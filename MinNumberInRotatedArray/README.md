# 题目描述:旋转数组的最小数字

## 题目：
把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。 输入一个非减排序的数组的一个旋转，输出旋转数组的最小元素。 例如数组{3,4,5,1,2}为{1,2,3,4,5}的一个旋转，该数组的最小值为1。 NOTE：给出的所有元素都大于0，若数组大小为0，请返回0。

# 本题考点：
  
  1). 数组非减排序
  
  2). 二分查找
  
# 解题思路:
  1). 直接暴力遍历数组所有元素，寻找最小元素，时间复杂度为O(n)
  
  2). 使用二分查找，时间复杂度为O(logn)
  
  3). 直接利用sort对数组进行排序，返回第一个元素

# 代码

[C++](MinNumberInRotatedArray.cpp)

[Python](MinNumberInRotatedArray.py)

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
using namespace std;

class Solution{
    public:
        int MinNumberInRotatedArray(vector<int>&nums)
        {
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

## 方法三：sort后返回：
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

## 方法二：二分查找：
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
