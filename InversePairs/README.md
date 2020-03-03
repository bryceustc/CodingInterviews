# 题目描述:数组中的逆序对
## 题目：
在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。输入一个数组，求出这个数组中的逆序对的总数。

**示例：**
```
输入: [7,5,6,4]
输出: 5
```

# 本题考点：
  
  归并排序的思想
  
# 解题思路:
  
  我们以数组{7,5,6,4}为例来分析统计逆序对的过程。每次扫描到一个数字的时候，我们不拿ta和后面的每一个数字作比较，否则时间复杂度就是O(n^2)，因此我们可以考虑先比较两个相邻的数字。
  
  ![](https://uploadfiles.nowcoder.com/files/20180504/7491640_1525400721676_20170710223428592)

(a) 把长度为4的数组分解成两个长度为2的子数组；

(b) 把长度为2的数组分解成两个成都为1的子数组；

(c) 把长度为1的子数组 合并、排序并统计逆序对 ；

(d) 把长度为2的子数组合并、排序，并统计逆序对；

在上图（a）和（b）中，我们先把数组分解成两个长度为2的子数组，再把这两个子数组分别拆成两个长度为1的子数组。接下来一边合并相邻的子数组，一边统计逆序对的数目。在第一对长度为1的子数组{7}、{5}中7大于5，因此（7,5）组成一个逆序对。同样在第二对长度为1的子数组{6}、{4}中也有逆序对（6,4）。由于我们已经统计了这两对子数组内部的逆序对，因此需要把这两对子数组 排序 如上图（c）所示， 以免在以后的统计过程中再重复统计。

接下来我们统计两个长度为2的子数组子数组之间的逆序对。合并子数组并统计逆序对的过程如下图如下图所示。

我们先用两个指针分别指向两个子数组的末尾，并每次比较两个指针指向的数字。如果第一个子数组中的数字大于第二个数组中的数字，则构成逆序对，并且逆序对的数目等于第二个子数组中剩余数字的个数，如下图（a）和（c）所示。如果第一个数组的数字小于或等于第二个数组中的数字，则不构成逆序对，如图b所示。每一次比较的时候，我们都把较大的数字从后面往前复制到一个辅助数组中，确保 辅助数组（记为copy） 中的数字是递增排序的。在把较大的数字复制到辅助数组之后，把对应的指针向前移动一位，接下来进行下一轮比较。

![](https://uploadfiles.nowcoder.com/files/20170711/7491640_1499735690500_20170711085550783)

过程：先把数组分割成子数组，先统计出子数组内部的逆序对的数目，然后再统计出两个相邻子数组之间的逆序对的数目。在统计逆序对的过程中，还需要对数组进行排序。如果对排序算法很熟悉，我们不难发现这个过程实际上就是归并排序

# 代码

[C++](./InversePairs.cpp)

[Python](./InversePairs.py)

## C++:
### 方法一：暴力遍历（未通过OJ）
```c++
class Solution {
public:
    int reversePairs(vector<int>& nums) {
        int count = 0;
        if (nums.empty()) return count;
        int n = nums.size();
        for (int i=0;i<n;i++)
        {
            for (int j=0;j<n;j++)
            {
                if (i<j && nums[i]>nums[j])
                {
                    count++;
                }
            }
        }
        return count;
    }
};
```

### 方法二：归并排序
```c++
class Solution {
public:
    int reversePairs(vector<int>& nums) {
        int count = 0;
        if (nums.empty()) return count;
        int n = nums.size();
        vector<int> temp;
        for (int i=0;i<n;i++)
        {
            temp.push_back(nums[i]);
        }
        count = helper(nums, temp, 0, n-1);
        return count;
    }
    int helper(vector<int> &nums, vector<int> &temp, int start, int end)
    {
        if (start==end)
        {
            temp[start] = nums[start];
            return 0;
        }
        int mid = start + (end-start)/2;
        int left = helper(temp, nums, start, mid);
        int right = helper(temp, nums, mid+1, end);

        int i = mid;
        int j = end;
        int index = end;
        int count = 0;
        while (i>=start && j>=mid+1)
        {
            if (nums[i]>nums[j])
            {
                temp[index--] = nums[i--];
                count += j-mid;
            }
            else
            {
                temp[index--] = nums[j--];
            }
        }
        while(i>=start) temp[index--] = nums[i--];
        while(j>=mid+1) temp[index--] = nums[j--];
        return left + right + count;
    }
};
```



## Python:
### 归并排序
```python
class Solution:
    def reversePairs(self, nums: List[int]) -> int:
        if nums ==[]:
            return 0
        temp = [i for i in nums]
        count = 0
        n = len(nums)
        count = self.helper(nums, temp, 0, n-1)
        return count
    def helper(self, nums, temp, start, end):
        if start == end:
            temp[start] = nums[start]
            return 0
        mid = start + (end-start)//2
        left = self.helper(temp, nums, start, mid)
        right = self.helper(temp, nums, mid+1, end)
        
        i = mid
        j = end
        index = end
        count = 0
        while i>=start and j>=mid+1:
            if nums[i] > nums[j]:
                temp[index] = nums[i]
                index-=1
                i-=1
                count+=j-mid
            else:
                temp[index] = nums[j]
                index-=1
                j-=1
        while i>=start:
            temp[index] = nums[i]
            index-=1
            i-=1
        while j>=mid+1:
            temp[index] = nums[j]
            index-=1
            j-=1
        return left + right + count
```

# 参考：
   - [题解讨论](https://www.nowcoder.com/questionTerminal/96bd6684e04a44eb80e6a68efc0ec6c5?f=discussion)
