# 题目描述:数组中唯一只出现一次的数字
## 题目：
在一个数组 nums 中除一个数字只出现一次之外，其他数字都出现了三次。请找出那个只出现一次的数字。

**示例1：**
```
输入：nums = [3,4,3,3]
输出：4
```

# 本题考点：
  
  1). 哈希表
  
# 解题思路:
  
  1.) 碰到次数，首先想到用哈希表。时间复杂度:O(n),空间复杂度O(n)
  
  2.) 排序数组中寻找只出现一次，时间复杂度:O(nlogn),空间复杂度O(1)
  
  3.) hash_set， 将输入数组存储到 HashSet，然后使用 HashSet 中数字和的三倍与数组之和比较。时间复杂度:O(n),空间复杂度O(n)
  ```
  3×(a+b+c)−(a+a+a+b+b+b+c)=2c
  ```
  4.) 时间复杂度:O(n),空间复杂度:O(1)

# 代码

[C++](./NumbersAppearOnce.cpp)

[Python](./NumbersAppearOnce.py)

# C++:

###  方法一：unordered_set
```c++
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        long sum_set = 0;
        long sum_array = 0;
        unordered_set<long> s;
        for (int n : nums)
        {
            sum_array+=n;
            s.insert((long)n);
        }
        for (auto num : s)
        {
            sum_set+=num;
        }
        res =(3 * sum_set - sum_array)/2;
        return res;
    }
};
```

## 方法一：哈希表unordered_map
```c++
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        unordered_map<int, int> m;
        for (int num : nums)
        {
            m[num]++;
        }
        for (auto num :nums)
        {
            if (m[num]==1)
            {
                res = num;
                break;
            }
        }
        return res;
    }
};
```

## 方法二：位运算
```c++
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for (int i = 0; i < 32; i++)
        {
            int count = 0;
            for (auto n : nums)
            {
                if ((1 << i ) & n) 
                    count++;
            }
            if (count % 3) 
                ans += (1 << i);
        }
        return ans;
    }
};
```

## 方法二：位运算(未搞懂)
```c++
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int b1 = 0;
        int b2 = 0;
        for (int x : nums)
        {
            b1 = (b1^x) & ~b2;
            b2 = (b2^x) & ~b1;
        }
        return b1;
    }
};
```

# Python:
## 方法一：hast_set
```python
class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        return  (3*sum(set(nums)) - (sum(nums))) // 2
```

## 方法一：哈希表
```python
from collections import Counter
class Solution:
    def singleNumber(self, nums):
        hashmap = Counter(nums)
            
        for k in hashmap.keys():
            if hashmap[k] == 1:
                return k
```
## 方法二：位运算
```python
class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        res = 0
        for i in range(0,32):
            count = 0
            for num in nums:
                if (num&(1<<i)):
                    count+=1
            if (count%3):
                res += 1<<i
        return res
```
### 方法二：位运算（最简版）未搞懂
```python
class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        b1,b2 = 0,0#出现一次的位，和两次的位
        for n in nums:
            b1 = (b1 ^ n) & ~ b2 #既不在出现一次的b1，也不在出现两次的b2里面，我们就记录下来，出现了一次，再次出现则会抵消
            b2 = (b2 ^ n) & ~ b1 #既不在出现两次的b2里面，也不再出现一次的b1里面(不止一次了)，记录出现两次，第三次则会抵消
        return b1
```


# 参考：
  -  [力扣题解](https://leetcode-cn.com/problems/single-number-ii/solution/zhi-chu-xian-yi-ci-de-shu-zi-ii-by-leetcode/)
