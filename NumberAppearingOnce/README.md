# 题目: 数组中只出现一次的两个数字
## 题目描述：
一个整型数组 nums 里除两个数字之外，其他数字都出现了两次。请写程序找出这两个只出现一次的数字。要求时间复杂度是O(n)，空间复杂度是O(1)。

**示例1：**
```
输入：nums = [4,1,4,6]
输出：[1,6] 或 [6,1]
```
  
# 解题思路:
  方法一：次数问题第一时间就会想到哈希表，但是所需空间复杂度是O(n)
  
  方法二：异或 举例说明。

举例：{2,4,3,6,3,2,5,5}

这个数组中只出现一次的两个数分别是4和6。怎么找到这个两个数字呢？

我们先不看找到俩个的情况，先看这样一个问题，如何在一个数组中找到一个只出现一次的数字呢？比如数组：{4,5,5}，唯一一个只出现一次的数字是4。

我们知道异或的一个性质是：任何一个数字异或它自己都等于0。也就是说，如果我们从头到尾依次异或数组中的每一个数字，那么最终的结果刚好是那个只出现一次的数字。比如数组{4,5,5}，我们先用数组中的第一个元素4（二进制形式：0100）和数组中的第二个元素5（二进制形式：0101）进行异或操作，0100和0101异或得到0001，用这个得到的元素与数组中的三个元素5（二进制形式：0101）进行异或操作，0001和0101异或得到0100，正好是结果数字4。这是因为数组中相同的元素异或是为0的，因此就只剩下那个不成对的孤苦伶仃元素。

现在好了，我们已经知道了如何找到一个数组中找到一个只出现一次的数字，那么我们如何在一个数组中找到两个只出现一次的数字呢？如果，我们可以将原始数组分成两个子数组，使得每个子数组包含一个只出现一次的数字，而其他数字都成对出现。这样，我们就可以用上述方法找到那个孤苦伶仃的元素。

我们还是从头到尾一次异或数组中的每一个数字，那么最终得到的结果就是两个只出现一次的数组的异或结果。因为其他数字都出现了两次，在异或中全部抵消了。由于两个数字肯定不一样，那么异或的结果肯定不为0，也就是说这个结果数组的二进制表示至少有一个位为1。我们在结果数组中找到第一个为1的位的位置，记为第n位。现在我们以第n位是不是1为标准把元数组中的数字分成两个子数组，第一个子数组中每个数字的第n位都是1，而第二个子数组中每个数字的第n位都是0。

举例：{2,4,3,6,3,2,5,5}

我们依次对数组中的每个数字做异或运行之后，得到的结果用二进制表示是0010。异或得到结果中的倒数第二位是1，于是我们根据数字的倒数第二位是不是1分为两个子数组。第一个子数组{2,3,6,3,2}中所有数字的倒数第二位都是1，而第二个子数组{4,5,5}中所有数字的倒数第二位都是0。接下来只要分别两个子数组求异或，就能找到第一个子数组中只出现一次的数字是6，而第二个子数组中只出现一次的数字是4。

**trick:**
 
 lowbit1 : 是二进制表达式中最低位的 1 所对应的值
  
  求负数的二进制的步骤：给定一个数，比如 12，我们能求得它的二进制 1100，如何求 −12的二进制？实际上二进制前面有个符号位，正数前面符号位是 0，负数前面符号位是 1，12 的二进制实际上是 01100，那么求 −12的二进制有两步：

  - 首先把符号位从 0 改成 1，然后对 12 每位取反。变成 10011
  - 最后 +1，即 10011+1 = 10100，这就是 −12的二进制

再细节点：那么给定一个数字 x，它的第 k 位为 1，0～k−1位都为 0，对它进行取反，也就是 0 变 1，1 变 0的操作，得到 ～x的二进制表示中，第 k位为 0 ，第 0 至第 k−1位都为 1。再将 ～x 进行加 1 操作，～x+1的第 kkk 位变为 1，0～k−1位又都变为 000 了。实际上这就是我们求负数的过程，那么我们也就得到了一串 xxxxx10000这样的结果（xxxxx 是和正数对应的相反的哦），它再去和正数做与运算，我们就能得到 lowbit了。
  
  ```
  设x=8
8的二进制位：0 0 0 0 1 0 0 0
对8取反：1 1 1 1 0 1 1 1
取反后加1: 1 1 1 1 1 0 0 0

+8:0 0 0 0 1 0 0 0
-8:1 1 1 1 1 0 0 0
&: 0 0 0 0 1 0 0 0 

lowbit = 8 & (-8) = 8
  ```
# 时间复杂度：

  方法一：O(N)
  
  方法二：O(N)
  
# 空间复杂度
  方法一：O(n)
  
  方法二：O(1)
  
# 代码

[C++](./NumberAppearingOnce.cpp)

[Python](./NumberAppearingOnce.py)

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
