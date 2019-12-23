# 题目描述:数组中出现次数超过一半的数字

## 题目：
数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。例如输入一个长度为9的数组{1,2,3,2,2,2,5,4,2}。由于数字2在数组中出现了5次，超过数组长度的一半，因此输出2。如果不存在则输出0。

# 本题考点：
  
  1). 哈希表
  
  
# 解题思路:
  1). 遍历数组，利用哈希表存储数组元素，如果超过一半，就,时间复杂度为O(n),因为使用了哈希表空间复杂度为O(n)
  
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
#include <tr1/unordered_map>
using namespace std;
using namespace std::tr1;

class Solution{
    public:
        int MoreThanHalfNumber_Solution(vector<int>&nums)
        {
            int res =0;
            if (nums.empty()) return res;
            int n = nums.size();
            int half = n/2;
            unordered_map<int,int> record;
            for (auto num:nums)
            {
                record[num]++;
                if(record[num]>half)
                {
                    res = num;
                }
            }     
            return res;          
        }
};


int main()
{
    vector<int> nums = {1,2,3,2,2,2,5,4,2};
    int res=0;
    res = Solution().MoreThanHalfNumber_Solution(nums);
    cout<< res <<endl;
    system("pause");
    return 0;
}

```

## 方法二：暴力遍历
```c++
#include <iostream>
#include <vector>
using namespace std;

class Solution{
    public:
        int MoreThanHalfNumber_Solution(vector<int>&nums)
        {
            int res = 0 ;
            if (nums.empty()) return res;
            int n = nums.size();
            int half = n/2;
            for (int i=0;i<n;i++)
            {
                int count = 0;
                for (auto num : nums)
                {
                    if (nums[i] == num)
                    {
                        count+=1;
                        if (count > half)
                        {
                            res = num;
                        }
                    }
                }
            }
            return res;          
        }
};

int main()
{
    vector<int> nums = {1,2,3,2,2,2,5,4,2};
    int res=0;
    res = Solution().MoreThanHalfNumber_Solution(nums);
    cout<< res <<endl;
    system("pause");
    return 0;
}

```

## 方法三：摩尔投票
```c++
#include <iostream>
#include <vector>
using namespace std;

class Solution{
    public:
        int MoreThanHalfNumber_Solution(vector<int>&nums)
        {
            int res = 0 ;
            if (nums.empty()) return res;
            int n = nums.size();
            int half = n/2;
            int cnt = 1;
            for (auto num:nums)
            {
                if (cnt==0)
                {
                    res = num; 
                }
                if (res == num)
                {
                    cnt+=1;
                }
                else
                {
                    cnt-=1;
                }
            }
            if (!checkMoreThanHalfNumber(nums,res))
                res = 0;
            return res;          
        }
        bool checkMoreThanHalfNumber(vector<int> &nums, int res)
        {
            int times = 0;
            int n = nums.size();
            int half = n/2;
            for (int i=0;i<n;i++)
            {
                if (nums[i]==res)
                    times++;
            }
            if (times>half)
                return true;
            else
                return false;
        }
};

int main()
{
    vector<int> nums = {1,2,3,2,2,2,5,4,2};
    int res=0;
    res = Solution().MoreThanHalfNumber_Solution(nums);
    cout<< res <<endl;
    system("pause");
    return 0;
}

```

## 方法四：排序后返回
```c++
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution{
    public:
        int MoreThanHalfNumber_Solution(vector<int>&nums)
        {
            int res = 0 ;
            if (nums.empty()) return res;
            int n = nums.size();
            sort(nums.begin(),nums.end());
            res = nums[n/2];
            return res;          
        }
};

int main()
{
    vector<int> nums = {1,2,3,2,2,2,5,4,2};
    int res=0;
    res = Solution().MoreThanHalfNumber_Solution(nums);
    cout<< res <<endl;
    system("pause");
    return 0;
}

```




# Python:
## 方法一：暴力遍历
```python
# -*- coding:utf-8 -*-
class Solution:
    def MoreThanHalfNum_Solution(self, nums):
        # write code here
        res = 0
        n = len(nums)
        half = n//2
        if n==0:
            return res
        for i in range(n):
            cnt = 0
            for num in nums:
                if nums[i] == num:
                    cnt+=1
            if cnt > half:
                res = nums[i]
        return res

if __name__ == '_ main__':
    nums = [1,2,3,2,2,2,5,4,2]
    res = Solution().MoreThanHalfNum_Solution(nums)
    print(res)
```

## 方法二：排序
```python
# -*- coding:utf-8 -*-
class Solution:
    def MoreThanHalfNum_Solution(self, nums):
        # write code here
        res = 0
        n = len(nums)
        nums=sorted(nums)
        res = nums[n//2]
        return res
```

## 方法三：摩尔投票
```python
# -*- coding:utf-8 -*-
class Solution:
    def MoreThanHalfNum_Solution(self, nums):
        # write code here
        res = nums[0]
        cnt = 0
        n = len(nums)
        half = n//2
        if n==0:
            return 0
        for i in range(1,n):
            if cnt == 0:
                res = nums[i]
            if res == nums[i]:
                cnt+=1
            else:
                cnt-=1
        m = 0
        for num in nums:
            if (res == num):
                m+=1
        if m<=half:
            res = 0
        return res
```

# 参考：
   - [LeetCode-169多数元素](https://github.com/bryceustc/LeetCode_Note/blob/master/cpp/Spiral-Matrix/README.md) 


