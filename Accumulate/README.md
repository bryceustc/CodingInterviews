# 题目: 求1+2+…+n

## 题目描述：
求 1+2+...+n ，要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A?B:C）。

**示例1：**
```
输入: n = 3
输出: 6
```
  
# 解题思路:
  方法一：次数问题第一时间就会想到哈希表，但是所需空间复杂度是O(n)
  
  方法二：异或 举例说明。

# 时间复杂度：

  方法一：O(N)
  
  方法二：O(N)
  
# 空间复杂度
  方法一：O(n)
  
  方法二：O(1)
  
# 代码

[C++](./Accumulate.cpp)

[Python](./Accumulate.py)

# C++: 
###  哈希表
```c++
class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {
        vector<int> res;
        unordered_map<int,int> m;
        int n = nums.size();
        for (int i=0;i<n;i++)
        {
            m[nums[i]]++;
        }
        for (auto num :  nums)
        {
            if (m[num]==1)
            {
                res.push_back(num);
            }
        }
        return res;
    }
};
```
###   异或(复杂版)
```c++
class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {
        vector<int> res;
        int n = nums.size();
        int num_xor = 0, num1 = 0, num2 =0;
        // 对原始数组每个元素求异或
        for (int i=0;i<n;i++)
        {
            num_xor^=nums[i];
        }
        int idx = FindFirstBits1(num_xor);
        for (int j=0;j<n;j++)
        {
            if (IsBit1(nums[j], idx))
            {
                num1 ^= nums[j];
            }
            else
            {
                num2 ^= nums[j];
            }
        }
        res.push_back(num1);
        res.push_back(num2);
        return res;
    }
private:
    // 找到二进制数num第一个为1的位数，比如0010，第一个为1的位数是2。
    int FindFirstBits1(int num)
    {
        int idxBit = 0;
        // 只判断一个字节的
        while((num&1)==0 && (idxBit < 8 * (sizeof(int)))
        {
            num = num>>1;
            idxBit++;
        }
        return idxBit;
    }
    // 判断第indexBit位是否为1
    bool IsBit1(int num, int idx)
    {
        num = num>>idx;
        return num&1;
    }
};
```
### 异或 (简洁版）
```c++
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> res (2,0);
        int number = 0;
        int n = nums.size();
        for (int i=0;i<n;i++)
        {
            number ^= nums[i];
        }
        // lowbit1 : 是二进制表达式中最低位的 1 所对应的值
        int lowbit1 = number&(-number);
        for (int num : nums)
        {
            if ((num & lowbit1) == lowbit1)
            {
                res[0] ^= num;
            }
            else
            {
                res[1]^= num;
            }
        }
        return res;
    }
};
```
# Python:
### 异或
```python
class Solution:
    def singleNumbers(self, nums: List[int]) -> List[int]:
        number = 0
        res = [0,0]
        for num in nums:
            number ^= num
        pos = 1
        while (number&pos) == 0:
            pos <<=1
        for num in nums:
            if (num&pos) == pos:
                res[0] ^= num
            else:
                res[1] ^= num
        return res
```
## 参考
  -  [LeetCode-260题-只出现一次的数字 III](https://github.com/bryceustc/LeetCode_Note/blob/master/cpp/Single-Number-III/README.md)

