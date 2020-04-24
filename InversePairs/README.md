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
  
  「归并排序」是分治思想的典型应用，它包含这样三个步骤：

- 分解： 待排序的区间为 [l,r]，令 m = l+(r-l)/2，我们把 [l,r]分成 [l,m]和 [m+1,r]
- 解决： 使用归并排序递归地排序两个子序列
- 合并： 把两个已经排好序的子序列 [l,m] 和 [m+1,r]合并起来

在待排序序列长度为 1 的时候，递归开始「回升」，因为我们默认长度为 1的序列是排好序的。

那么求逆序对和归并排序又有什么关系呢？关键就在于「归并」当中「并」的过程。我们通过一个实例来看看。假设我们有两个已排序的序列等待合并，分别是 L={8,12,16,22,100} 和 R={9,26,55,64,91}。一开始我们用指针 l = 0 指向 L的首部，r= 0 指向 R的头部。记已经合并好的部分为 M。

```
L = [8, 12, 16, 22, 100]   R = [9, 26, 55, 64, 91]  M = []
     |                          |
     l                          r
```
我们发现 l 指向的元素小于 r 指向的元素，于是把 l 指向的元素放入答案，并把 l后移一位

```
L = [8, 12, 16, 22, 100]   R = [9, 26, 55, 64, 91]  M = [8]
        |                       |
        l                       r
```
这个时候我们把左边的 8 加入了答案，我们发现右边没有数比 8小，所以 8 对逆序对总数的「贡献」为 0。

接着我们继续合并，把 9 加入了答案，此时 l指向 12，r指向 26。

```
L = [8, 12, 16, 22, 100]   R = [9, 26, 55, 64, 91]  M = [8, 9]
        |                          |
        l                          r
```

此时 l 比 r小，把 l对应的数加入答案，并考虑它对逆序对总数的贡献为 r相对R首位置的偏移 1（即右边只有一个数比 12小，所以只有它和 12构成逆序对），以此类推。

我们发现用这种「算贡献」的思想在合并的过程中计算逆序对的数量的时候，只在l右移的时候计算，是基于这样的事实：当前 l指向的数字比r小，但是比R中 [0 ... r - 1] 的其他数字大，[0 ... r - 1] 的其他数字本应当排在l对应数字的左边，但是它排在了右边，所以这里就贡献了r个逆序对。

利用这个思路，可以写出如下代码。

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

### 方法二：典型归并排序
```c++
class Solution {
public:
    int reversePairs(vector<int>& nums) {
        if (nums.empty()) return 0;
        int n = nums.size();
        int res = 0;
        mergesort(nums,0,n-1, res);
        return res;
    }

    void mergesort(vector<int>& nums, int start, int end, int& res)
    {
        if (start<end)
        {
            int mid = start + (end-start)/2;
            mergesort(nums,start,mid,res);
            mergesort(nums,mid+1,end,res);
            merge(nums,start,end,res);
        }
    }

    void merge(vector<int>& nums, int start, int end,int& res)
    {
        int temp[end+1];
        int i =0;
        int mid = start + (end-start)/2;
        int l = start;
        int r = mid+1;
        while(l<=mid&&r<=end)
        {
            if (nums[l]>nums[r])
            {
                temp[i++] = nums[r++];
            }
            else
            {
                temp[i++] = nums[l++];
                res+= r-(mid+1);  // 关键点，也是归并排序添加的唯一一行代码。
            }
        }
        while(l<=mid)
        {
            temp[i++] = nums[l++];
            res += r-(mid+1);
        }
        while(r<=end)
        {
            temp[i++] = nums[r++];
        }
        i = 0;
        while(start<=end)
        {
            nums[start++] = temp[i++];
        }
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
