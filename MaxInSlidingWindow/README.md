# 题目:滑动窗口的最大值

## 题目描述：
给定一个数组 nums 和滑动窗口的大小 k，请找出所有滑动窗口里的最大值。
  
  **示例：**
  ```
输入: nums = [1,3,-1,-3,5,3,6,7], 和 k = 3
输出: [3,3,5,5,6,7] 
解释: 

  滑动窗口的位置                最大值
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7
  ```
  
# 解题思路:
我们可以使用一个双端队列deque。

我们可以用STL中的deque来实现，接下来我们以数组{2,3,4,2,6,2,5,1}为例，来细说整体思路。

数组的第一个数字是2，把它存入队列中。第二个数字是3，比2大，所以2不可能是滑动窗口中的最大值，因此把2从队列里删除，再把3存入队列中。第三个数字是4，比3大，同样的删3存4。此时滑动窗口中已经有3个数字，而它的最大值4位于队列的头部。

第四个数字2比4小，但是当4滑出之后它还是有可能成为最大值的，所以我们把2存入队列的尾部。下一个数字是6，比4和2都大，删4和2，存6。就这样依次进行，最大值永远位于队列的头部。

但是我们怎样判断滑动窗口是否包括一个数字？应该在队列里存入数字在数组里的下标，而不是数值。当一个数字的下标与当前处理的数字的下标之差大于或者相等于滑动窗口大小时，这个数字已经从窗口中滑出，可以从队列中删除。

整体过程示意图：

![](https://cuijiahua.com/wp-content/uploads/2018/02/basis_64_2.png)

# 时间复杂度：
O(n)
# 空间复杂度
 O(1)
# 代码

[C++](./MaxInSlidingWindow.cpp)

[Python](./MaxInSlidingWindow.py)

# C++: 
###  回溯
```c++
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        if (nums.empty())
            return res;
        int n = nums.size();
        //deque q中存储的是num的下标
        deque<int> q;
        for(int i=0;i<n;i++)
        {
            while(!q.empty() && nums[i]>nums[q.back()])  // 因为q中存的是下标，如果当前nums[i]更大，就从后面弹出队列中比num[i]小的元素
            {
                q.pop_back();
            }
            // 队列首部的下标超出滑动窗口范畴时就无效了 弹出
            while(!q.empty() && i-q.front()+1>k)
            {
                q.pop_front();
            }
            // 压入下标
            q.push_back(i);
            // 当下标大于滑动窗口的时候 才会滑动 压入结果
            if(i>=k-1)
            {
                res.push_back(nums[q.front()]);
            }
        }
        return res;
    }
};
```
# Python:
###  回溯
```python
class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        res = []
        if nums is None:
            return res
        q = collections.deque()
        n = len(nums)
        for i in range(n):
            while q and nums[i] > nums[q[-1]]:
                q.pop()
            while q and i-q[0]+1 > k:
                q.popleft()
            q.append(i)
            if i>=k-1:
                res.append(nums[q[0]])
        return res
```


