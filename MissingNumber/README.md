# 题目描述:0到n-1中缺失的数字
## 题目：
一个长度为n-1的递增排序数组中的所有数字都是唯一的，并且每个数字都在范围0到n-1之内。在范围0到n-1的n个数字中有且只有一个数字不在该数组中，请找出这个数字。

# 本题考点：
  
  1). 二分查找  
  
  2). 哈希表
  
  3). 数学技巧
  
# 解题思路:
  此题与LeetCode第268题缺失数字问题类似，但此题是递增排序的数组，较为简单,注意输入数组。
  
  1.) 直接暴力遍历，遍历数组所有元素，k。时间复杂度:O(n),空间复杂度O(1)
  
  2.) 哈希表
  
  3). 数学方法(高斯公式，异或)
  
  4). 排序法、二分查找

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


## 方法三：二分查找
```c++
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        if (nums.empty()) return 0;
        int l = nums.size();
        sort(nums.begin(),nums.end());
        int start = 0;
        int end = l-1;
        while(end >= start)
        {
            int mid = start + (end - start)/2;
            if (nums[mid]==mid)
            {
                start = mid+1;
            }
            else
            {
                if(mid == 0 || nums[mid-1]==mid-1)
                {
                    return mid;
                }
                end = mid - 1;
            }
        }
        if (start==l)
        {
            return l;
        }
        // 无效的输入，比如数组不是按照要求排序的
        // 或者有数字不在0~n-1范围之内
        return -1;
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



