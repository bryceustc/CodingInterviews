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
  4.) 位运算，
  
   -   记录每一位不为0的数字出现的次数
   -   如果出现的次数对3取模为1，则说明只出现一次的数字此位也是1
   -   将所有模3为1的位想加，得到最终结果
  
  时间复杂度:O(n),空间复杂度:O(1)

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
//对于出现三次的数字，各 二进制位 出现的次数都是 3 的倍数。因此，统计所有数字的各二进制位中 1 的出现次数，并对 3 求余，结果则为只出现一次的数字
// 这个时分开某一位都单独计算，上边那个是 因为每一个的位运算是一样的，所以作为一个整体去运算
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int counts[32] = {0};            // C++ 初始化数组需要写明初始值 0
        for(int action : actions) {
            for(int i = 0; i < 32; i++) {
                counts[i] += action & 1; // 更新第 i 位 1 的个数之和
                action >>= 1;            // 第 i 位 --> 第 i 位
            }
        }
        int res = 0, m = 3;
        for(int i = 31; i >= 0; i--) {
            res <<= 1;
            res |= counts[i] % m;        // 恢复第 i 位
        }
        return res;
    }
};
```

## 方法二：位运算
```c++
// 位运算统计
// 位运算公式：
// x ^ 0 = x, x ^ 1 = ~x
// x & 0 = 0, x & 1 = x
// 有限状态机：https://leetcode.cn/problems/shu-zu-zhong-shu-zi-chu-xian-de-ci-shu-ii-lcof/solutions/215895/mian-shi-ti-56-ii-shu-zu-zhong-shu-zi-chu-xian-d-4/
// 考虑数字的二进制形式，对于出现三次的数字，各 二进制位 出现的次数都是 3 的倍数。因此，统计所有数字的各二进制位中 1 的出现次数，并对 3 求余，结果则为只出现一次的数字。
// 对3取余的状态：0，1，2，在此题情景下，只会有0，1两个状态
// 状态转化：00 -> 01 -> 10 -> 00 -> ...
// b2 = 0, b1 = 0，当输入n为 0 时， b2b1 = 00，当输入n=1时，b2b1 = 01;
// b2 = 0, b1 = 1，当输入n为 0 时， b2b1 = 01，当输入n=1时，b2b1 = 10;
// b2 = 1, b2 = 0，当输入n为 0 时， b2b1 = 10，当输入n=1时，b2b1 = 00;
// 推断出来：b1 = b1 ^ n & ~b2;  b2 = b2 ^ n & ~b1;
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
### 方法二：位运算
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
