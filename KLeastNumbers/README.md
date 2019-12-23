# 题目描述:最小的k个数

## 题目：
输入n个整数，找出其中最小的K个数。例如输入4,5,1,6,2,7,3,8这8个数字，则最小的4个数字是1,2,3,4,。

# 本题考点：
  
  1). 哈希表
  
  
# 解题思路:
  1). 对数组排序，然后返回，前k个数
  
  2). 暴力遍历，暴力算法遍历整个数组，然后用另一重循环统计每个数字出现的次数。将出现次数大于n/2的元素返回，时间复杂度为O(n<sup>2)
  
  3). 摩尔投票法，先假设第一个数过半数并设cnt=1；遍历后面的数如果相同则cnt+1，不同则减一，当cnt为0时则更换新的数字为候选数（成立前提：有出现次数大于n/2的数存在）

# 代码

[C++](MoreThanHalfNumber.cpp)

[Python](MoreThanHalfNumber.py)

# C++:
## 方法一：哈希表
```c++
#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

class Solution {
public:
   vector<int> KLeastNumbers(vector<int>& nums,int k ) 
    {
        vector<int> res;
        if (nums.empty()) return res; 
        int n = nums.size();
        if (k>n) return res;
        sort(nums.begin(),nums.end());
        for (int i=0;i<k;i++)
        {
            res.push_back(nums[i]);
        }
        return res;
    }
};


int main()
{
   vector<int> nums = {4,5,1,6,2,7,3,8};
   int k = 4;
    vector<int>  res;
    res = Solution().KLeastNumbers(nums,k);
    int n = res.size();
    for (int i = 0; i < n; i++)
    {
        cout<< res[i]<<endl;
    }
    system("pause");
    return 0;
}
```

# Python:
## 方法一：直接法
```python
# -*- coding:utf-8 -*-
class Solution:
    def KLeastNumbers(self, nums, k):
        # write code here
        res = []
        n = len(nums)
        if n==0 or n<k:
            return res
        nums=sorted(nums)
        for i in range(k):
            res.append(nums[i])
        return res

if __name__ == '_ main__':
    nums = [4,5,1,6,2,7,3,8]
    res = Solution().KLeastNumbers(nums)
    print(res)
```

# 参考：
   - [LeetCode-169多数元素](https://github.com/bryceustc/LeetCode_Note/blob/master/cpp/Spiral-Matrix/README.md) 



