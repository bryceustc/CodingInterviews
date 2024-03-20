# 题目描述:顺时针打印矩阵

## 题目：
给定一个未排序的整数数组 nums ，找出数字连续的最长序列（不要求序列元素在原数组中连续）的长度。

请你设计并实现时间复杂度为 O(n) 的算法解决此问题。

示例 1：

输入：nums = [100,4,200,1,3,2]
输出：4
解释：最长数字连续序列是 [1, 2, 3, 4]。它的长度为 4。


示例 2：

输入：nums = [0,3,7,2,5,8,4,6,0,1]
输出：9
  
  
# 解题思路:
  在一个未排序的整数数组 nums中 ，找出最长的数字连续序列，朴素的做法是：枚举nums中的每一个数x，并以x起点，在nums数组中查询x + 1,x + 2，，，x + y是否存在。假设查询到了 x + y，那么长度即为 y - x + 1，不断枚举更新答案即可。

如果每次查询一个数都要遍历一遍nums数组的话，时间复杂度为O(n) ，其实我们可以用一个哈希表来存贮数组中的数，这样查询的时间就能优化为O(1) 。

如何每次只枚举连续序列的起始数字x？

其实只需要每次在哈希表中检查是否存在 x−1即可。如果x-1存在，说明当前数x不是连续序列的起始数字，我们跳过这个数。

具体过程如下：

1、定义一个哈希表hash，将nums数组中的数都放入哈希表中。

2、遍历哈希表hash，如果当前数x的前驱x-1不存在，我们就以当前数x为起点向后枚举。

3、假设最长枚举到了数y，那么连续序列长度即为y-x+1。

4、不断枚举更新答案。

# 代码
```c++
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> hash;
        for(auto x : nums) hash.insert(x);    //放入hash表中
        int res = 0;
        for(auto x : hash)
        {
            // 前一个存在，说明会计算到，直接跳过
            if(!hash.count(x-1))
            {
                int y = x;   //以当前数x向后枚举
                while(hash.count(y + 1)) y++;
                res = max(res, y - x + 1);  //更新答案
            }
        }
        return res;
    }
};

```

# 参考：
   - [LeetCode旋转矩阵](https://github.com/bryceustc/LeetCode_Note/blob/master/cpp/Spiral-Matrix/README.md) 

