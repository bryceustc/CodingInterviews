# 题目描述:调整数组顺序使奇数位于偶数前面

## 题目：
输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有的奇数位于数组的前半部分，所有的偶数位于数组的后半部分，并保证奇数和奇数，偶数和偶数之间的相对位置不变。

# 本题考点：
  
  1). 构建辅助数组
  
  2). 插入排序的思想
  
  3). 冒泡排序的思想
  
# 解题思路:
  1). 构建辅助数组，时间复杂度为O(n)，空间复杂度O(n);
  
  2). 使用二分查找，时间复杂度为O(logn)
  
  3). 直接利用sort对数组进行排序，返回第一个元素

# 代码

[C++](ReorderArray.cpp)

[Python](ReorderArray.py)

# C++:
## 方法一：暴力遍历
```c++
#include <iostream>
#include <vector>
using namespace std;

class Solution{
    public:
        void reOrderArray(vector<int>&nums)
        {
            vector<int> res;
            int n = nums.size();
            for (int i = 0; i < n; i++)
            {
                if(nums[i]%2!=0)
                {
                    res.push_back(nums[i]);
                }
            }
            for (int i = 0; i < n; i++)
            {
                if(nums[i]%2==0)
                {
                    res.push_back(nums[i]);
                }
            }        
        }
};


int main()
{
    vector<int> nums = {1,2,3,4,5,6,7,8,9};
    Solution().reOrderArray(nums);
    int m=nums.size();
    for (int i=0;i<m;i++)
    {
        cout<< nums[i] <<endl;
    }
    system("pause");
    return 0;
}

```

## 方法二：插入排序的思想
```c++
#include <iostream>
#include <vector>
using namespace std;

class Solution{
    public:
        void reOrderArray(vector<int>&nums)
        {
            vector<int> res;
            if (nums.empty()) return;
            int n = nums.size();
            for (int i=0;i<n;i++)
            {
                if (nums[i]%2==0)
                {
                    for (int j=i+1;j<n;j++)
                    {
                        if (nums[j]%2!=0)
                        {
                            int temp = nums[j];
                            for (int k=j;k>i;k--)
                            {
                                nums[k] = nums[k-1];
                            }
                            nums[i] = temp;
                            break;
                        }
                    }
                }
            }
        }
};


int main()
{
    vector<int> nums = {1,2,3,4,5,6,7,8,9};
    Solution().reOrderArray(nums);
    int m=nums.size();
    for (int i=0;i<m;i++)
    {
        cout<< nums[i] <<endl;
    }
    system("pause");
    return 0;
}

```


## 方法三：冒泡排序的思想
```c++
#include <iostream>
#include <vector>
using namespace std;

class Solution{
    public:
        void reOrderArray(vector<int>&nums)
        {
            vector<int> res;
            if (nums.empty()) return;
            int n = nums.size();
            for (int i=0;i<n;i++)
            {
                for (int j=n-1;j>i;j--)
                {
                    if (nums[j]%2!=0 && nums[j-1]%2==0)
                    {
                        swap(nums[j],nums[j-1]);
                    }
                }
            }
        }
};


int main()
{
    vector<int> nums = {1,2,3,4,5,6,7,8,9};
    Solution().reOrderArray(nums);
    int m=nums.size();
    for (int i=0;i<m;i++)
    {
        cout<< nums[i] <<endl;
    }
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

# 参考：

