# 题目描述:0到n-1中缺失的数字
## 题目：
一个长度为n-1的递增排序数组中的所有数字都是唯一的，并且每个数字都在范围0到n-1之内。在范围0到n-1的n个数字中有且只有一个数字不在该数组中，请找出这个数字。

# 本题考点：
  
  1). 二分查找  
  
# 解题思路:
  此题与LeetCode第268题缺失数字问题类似，
  
  1.) 直接暴力遍历，遍历数组所有元素，k。时间复杂度:O(n),空间复杂度O(1)
  
  2.) 哈希表
  
  2.) 利用动态规划的思想，假设要找下标i对应的丑数dp[i],可以用i之前的所有丑数乘若干个2直到大于上一个丑数dp[i-1]，记此数为num1;同理用i之前的所有丑数乘若干个3直到大于上一个丑数dp[i-1]，记此数为num2；用i之前的所有丑数乘若干个5直到大于上一个丑数dp[i-1]，记此数为num3。这三个数中的最小数字就是第i个丑数dp[i]。其实没必要把i之前的所有丑数乘2或者乘3或者乘5。在i之前的丑数中，肯定存在一个丑数（下标记为index2），乘2以后正好大于i的上一个丑数dp[i-1],index2之前的丑数乘2都小于等于dp[i-1];我们只需要记录index2，每次直接用这个下标对应的数乘2就行，并且在下标不满足时更新下标。同理我们也要记录乘3和乘5对应的下标。时间复杂度:O(n),空间复杂度:O(n)
  
  3). 最小堆

# 代码

[C++](./MissingNumber.cpp)

[Python](./MissingNumber.py)

# C++:
## 方法一：暴力遍历
```c++
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int res = 0;
        if (nums.empty())
            return 0;
        unordered_map<int,int> map;
        for (int i=0;i<n;i++)
        {
            map[nums[i]]++;
        }
        for (int num=0;num<=n;num++)
        {
            if (map[num]==0)
                return num;
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


## 方法一：哈希表(简洁)
```c++
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int res = 0;
        int n = nums.size();
        unordered_set<int> set;
        for(auto num : nums)
        {
            set.insert(num);
        }
        for (int i=0;i<=n;i++)
        {
            if (set.count(i)==0)
            {
                res = i;
                break;
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



## 方法二：数学方法
```c++
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int res =0;
        int n = nums.size();
        int sum_num = 0;
        int Sum = 0;
        for (int i=0;i<n;i++)
        {
            sum_num+=nums[i];
        }
        for (int i=0;i<=n;i++)
        {
            Sum += i;
        }
        res = Sum - sum_num;
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

## 方法二：数学方法
```c++
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int res = n;
        for (int i = 0; i < n; i++)
        {
            res ^= nums[i];
            res ^= i;
            // 异或满足交换律，i和nums[i]是肯定有重复的，剩下的只有一个那就是nums中缺失的
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

## 方法三：排序法
```c++
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int res = 0;
        if (nums[n-1]!=n)
        {
            return n;
        }
        for (int i=0;i<n;i++)
        {
            if (nums[i]!=i)
            {
                res = i;
                break;
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



