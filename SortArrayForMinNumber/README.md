# 题目描述:连续子数组的最大和
## 题目：
HZ偶尔会拿些专业问题来忽悠那些非计算机专业的同学。今天测试组开完会后,他又发话了:在古老的一维模式识别中,常常需要计算连续子向量的最大和,当向量全为正数的时候,问题很好解决。但是,如果向量中包含负数,是否应该包含某个负数,并期望旁边的正数会弥补它呢？例如:{6,-3,-2,7,-15,1,2,2},连续子向量的最大和为8(从第0个开始,到第3个为止)。给一个数组，返回它的最大连续子序列的和，你会不会被他忽悠住？(子向量的长度至少是1)

# 本题考点：
  
  1). 动态规划
  
  2). 贪心算法
  
  3). 分治法
  
  
# 解题思路:
  此题与LeetCode第53题一样，主要有四种解法
  
  1). 动态规划：在整个数组或在固定大小的滑动窗口中找到总和或最大值或最小值的问题可以通过动态规划（dp）在线性时间内解决。构建一个动态数组``vector<int> dp(n)``,dp[i]表示nums中以nums[i]结尾的最大子序和，``dp[i] = max(dp[i-1]+nums[i],nums[i])``,dp[i]要么是当前数字，要么是与前面的最大子序和的和。时间复杂度:O(n),空间复杂度O(n)(空间复杂度可优化为O(1))
  
  2). 贪心算法：从左向右迭代，一个个数字加过去，如果sum<0,重新开始寻找子序列。时间复杂度O(n),空间复杂度O(1).

  3). 分治法：将一个问题拆分成多个相似的小问题，并对其分别求解，如果拆出的问题依然复杂，就通过递归调用再次将子问题拆分，直到拆出的方法可以以简单方式求得解，最后合并多个小问题的解，就是原问题的结果。
  
  4). 暴力法：枚举每一个子序列的大小，记录下最大的和返回。

# 代码

[C++](./GreatestSumOfSubarrays.cpp)

[Python](./GreatestSumOfSubarrays.py)

# C++:
## 方法一：动态规划（空间复杂度O(n)）
```c++
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> nums) {
        int res = nums[0];
        int n = nums.size();
        //dp[i]表示nums中以nums[i]结尾的最大子序和
        vector<int> dp(n);
        dp[0] = nums[0];
        for (int i=1;i<n;i++)
        {
            dp[i] = max(dp[i-1]+nums[i],nums[i]);
            res = max(res,dp[i]);
        }
        return res;
    }
};

int main()
{
    vector<int> nums = {-2,1,4};
    int res = Solution().FindGreatestSumOfSubArray(nums);
    cout << res << endl;
    system ("pause");
    return 0;
}
```

## 方法一：动态规划（空间复杂度O(1)）
```c++
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> nums) {
        int res = nums[0];
        int n = nums.size();
        int dp= nums[0];
        for (int i=1;i<n;i++)
        {
            dp = max(dp+nums[i],nums[i]);
            res = max(res,dp);
        }
        return res;
    }
};

int main()
{
    vector<int> nums = {-2,1,4};
    int res = Solution().FindGreatestSumOfSubArray(nums);
    cout << res << endl;
    system ("pause");
    return 0;
}
```



## 方法二：贪心算法
```c++
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> nums) {
        int res = nums[0];
        int n = nums.size();
        int sum = nums[0];
        for (int i=1;i<n;i++)
        {
            if (sum > 0)
                sum+=nums[i];
            else
                sum = nums[i];
            res = max(res,sum);
        }
        return res;
    }
};

int main()
{
    vector<int> nums = {-2,1,4};
    int res = Solution().FindGreatestSumOfSubArray(nums);
    cout << res << endl;
    system ("pause");
    return 0;
}

```

## 方法三：分治法
```c++
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int>& nums) 
    {
        int res = nums[0];
        int n = nums.size();
        res = maxSubArrayHelper(nums,0,n-1);
        return res;
    }
    
    int maxSubArrayHelper(vector<int> &nums, int left, int right)
    {
        if (left == right)
        {
            return nums[left];
        }
        int mid = (left + right)/2;
        int leftSum = maxSubArrayHelper(nums,left,mid);
        //注意这里应是mid + 1，否则left + 1 = right时，会无限循环
        int rightSum = maxSubArrayHelper(nums,mid+1,right);
        int midSum = findMaxCrossingSubarray(nums,left,mid,right);
        int res = max(leftSum,rightSum);
        res = max(res,midSum);
        return res;
    }

    int findMaxCrossingSubarray(vector<int> &nums, int left, int mid, int right)
    {
        int leftSum = nums[mid];
        int sum = 0;
        for (int i = mid; i >= left; i--)
        {
            sum += nums[i];
            leftSum = max(leftSum, sum);
        }
        int rightSum = nums[mid+1];
        sum = 0;
        //注意这里i = mid + 1，避免重复用到nums[i]
        for (int i = mid + 1; i <= right; i++)
        {
            sum += nums[i];
            rightSum = max(rightSum, sum);
        }
        return (leftSum + rightSum);
    }
};

int main()
{
    vector<int> nums = {-2,1,4};
    int res = Solution().FindGreatestSumOfSubArray(nums);
    cout << res << endl;
    system ("pause");
    return 0;
}
```

## 方法四：暴力遍历
```c++
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> nums) {
        int res = nums[0];
        int n = nums.size();
        for (int i=0;i<n;i++)
        {
            int sum = 0;
            for (int j=i;j<n;j++)
            {
                sum+=nums[j];
                res = max(sum,res);
            }
        }
        return res;
    }
};

int main()
{
    vector<int> nums = {-2,1,4};
    int res = Solution().FindGreatestSumOfSubArray(nums);
    cout << res << endl;
    system ("pause");
    return 0;
}

```



# Python:
## 方法一：动态规划
```python
# -*- coding:utf-8 -*-
class Solution:
    def FindGreatestSumOfSubArray(self, nums):
        # write code here
        res = nums[0]
        dp = nums[0]
        n = len(nums)
        for i in range(1,n):
            dp = max(dp+nums[i],nums[i])
            res = max(res,dp)
        return res

if __name__ == '_ main__':
    nums = [-2,1,4]
    res = Solution().FindGreatestSumOfSubArray(nums)    
    print(res)
```

## 方法一：动态规划
```python
# -*- coding:utf-8 -*-
class Solution:
    def FindGreatestSumOfSubArray(self, nums):
        # write code here
        res = nums[0]
        n = len(nums)
        dp = [0 for _ in range(n)]
        dp[0] = nums[0]
        for i in range(1,n):
            dp[i] = max(dp[i-1]+nums[i],nums[i])
            res = max(res,dp[i])
        return res

if __name__ == '_ main__':
    nums = [-2,1,4]
    res = Solution().FindGreatestSumOfSubArray(nums)    
    print(res)
```

## 方法二：贪心算法
```python
# -*- coding:utf-8 -*-
class Solution:
    def FindGreatestSumOfSubArray(self, nums):
        # write code here
        res = nums[0]
        n = len(nums)
        sum_num = 0
        for num in nums:
            if sum_num>0:
                sum_num+=num
            else:
                sum_num = num
            res = max(res,sum_num)            
        return res

if __name__ == '_ main__':
    nums = [-2,1,4]
    res = Solution().FindGreatestSumOfSubArray(nums)    
    print(res)
```

## 方法三：分治算法
```python
# -*- coding:utf-8 -*-
class Solution:
    def FindGreatestSumOfSubArray(self, nums: List[int]) -> int:
        res = nums[0]
        n = len(nums)
        res = self.maxSubArrayHelper(nums,0,n-1)       
        return res
    def maxSubArrayHelper(self,nums,left,right):
        if left==right:
            return nums[left]
        mid = (left+right)//2
        leftSum = self.maxSubArrayHelper(nums,left,mid)
        rightSum = self.maxSubArrayHelper(nums,mid+1,right)
        midSum = self.maxCrossingSubArray(nums,left,mid,right)
        res = max(leftSum,midSum,rightSum)
        return res
    def maxCrossingSubArray(self,nums,left,mid,right):
        leftBoaderSum = nums[mid]
        cur_sum = 0
        for i in range(mid,left-1,-1):
            cur_sum+=nums[i]
            leftBoaderSum = max(leftBoaderSum,cur_sum)
        rightBoaderSum = nums[mid+1]
        cur_sum = 0
        for i in range(mid+1,right+1):
            cur_sum+=nums[i]
            rightBoaderSum = max(rightBoaderSum,cur_sum)
        return leftBoaderSum + rightBoaderSum

if __name__ == '_ main__':
    nums = [-2,1,4]
    res = Solution().FindGreatestSumOfSubArray(nums)    
    print(res)
```



## 方法四：暴力算法
```python
# -*- coding:utf-8 -*-
class Solution:
    def FindGreatestSumOfSubArray(self, nums):
        # write code here
        res = nums[0]
        n = len(nums)
        for i in range(n):
            sum_num = 0
            for j in range(i,n):
                sum_num+=nums[j]
                res = max(res,sum_num)            
        return res

if __name__ == '_ main__':
    nums = [-2,1,4]
    res = Solution().FindGreatestSumOfSubArray(nums)    
    print(res)
```




# 参考：
   - [LeetCode-53最大子序和](https://github.com/bryceustc/LeetCode_Note/blob/master/cpp/Maximum-Subarray/README.md)
   - [五大常用算法之一：分治算法](https://www.cnblogs.com/steven_oyj/archive/2010/05/22/1741370.html) 
   - [五大常用算法之二：动态规划算法](https://www.cnblogs.com/steven_oyj/archive/2010/05/22/1741374.html) 
   - [五大常用算法之三：贪心算法](https://www.cnblogs.com/steven_oyj/archive/2010/05/22/1741375.html)
   - [最大子序和](https://leetcode-cn.com/problems/maximum-subarray/solution/zui-da-zi-xu-he-cshi-xian-si-chong-jie-fa-bao-li-f/)






