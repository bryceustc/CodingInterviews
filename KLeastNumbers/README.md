# 题目描述:最小的k个数

## 题目：
输入n个整数，找出其中最小的K个数。例如输入4,5,1,6,2,7,3,8这8个数字，则最小的4个数字是1,2,3,4,。

# 本题考点：
  
  1). 哈希表
  
  
# 解题思路:
  1). 对数组排序，然后返回，前k个数
  

# 代码

[C++](MoreThanHalfNumber.cpp)

[Python](MoreThanHalfNumber.py)

# C++:
## 方法一：利用sort排序
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


## 方法二：利用STL容器 priority_queue 大顶堆/小顶堆

### 大顶堆：
```c++
#include <iostream>
#include <vector>
#include <queue>
#include<algorithm>
using namespace std;

class Solution {
public:
   vector<int> KLeastNumbers(vector<int>& nums,int k ) 
    {
        vector<int> res;
        int n = nums.size();
        if (nums.empty() || k>n) return res;
        priority_queue<int> q;    // 大顶堆 优先输入大数据
        for (auto num : nums)
        {
            q.push(num);
            if (q.size()>k)
            {
                q.pop();
            }
        }
        while(!q.empty())
        {
            res.push_back(q.top());
            q.pop();
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
### 小顶堆：
```c++
#include <iostream>
#include <vector>
#include <queue>
#include<algorithm>
using namespace std;

class Solution {
public:
   vector<int> KLeastNumbers(vector<int>& nums,int k ) 
    {
        vector<int> res;
        int n = nums.size();
        if (nums.empty() || k>n) return res;
        priority_queue<int,vector<int>, greater<int>> q;    // 小顶堆 优先输入小数据
        for (auto num : nums)
        {
            q.push(num);
            if (q.size()>n-k)
            {
                res.push_back(q.top());
                q.pop();
            }
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
   - [C/C++ | STL | 大顶堆 | 小顶堆 | std::priority_queue](https://blog.csdn.net/stone_fall/article/details/89010656) 
   - [【c++】STL里的priority_queue用法总结](https://blog.csdn.net/xiaoquantouer/article/details/52015928) 



