# 题目描述:构建乘积数组
## 题目：
给定一个数组A[0, 1, …, n-1]，请构建一个数组B[0, 1, …, n-1]，其中B中的元素B[i] =A[0]×A[1]×… ×A[i-1]×A[i+1]×…×A[n-1]。不能使用除法。
# 本题考点：
  
  约瑟夫环问题
  
# 解题思路:
  
  1.) 用数组列表模拟一下。创建一个数组存储0-n-1的数组，但数组长度大于1时，就计算end位置即为(start+m-i)%len(nums) ，删除该元素后然后start再等于之前end，最后数组中剩最后一个元素，返回nums[0]
  
  时间复杂度:O(n),空间复杂度:O(n)

# 代码

[C++](./ConstuctArray.cpp)

[Python](./ConstuctArray.py)

# C++:
```c++
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int LastRemaining_Solution(int n, int m)
    {
        int res =-1;
        if (n<=0 || m<0)
            return res;
        vector<int> nums;
        for (int i=0;i<=n;i++)
        {
            nums.push_back(i);
        }
        int start =0;
        while(nums.size()>1)
        {
            int end = (start+m-1)%(nums.size());
            nums.erase(nums.begin()+end);
            start = end;
        }
        res = nums[0];
        return res;
    }
};

int main()
{
    int n = 5;
    int m = 3;
    int res = 0;
    res = Solution().LastRemaining_Solution(n,m);
    cout <<res << endl;
    system("pause");
    return 0;
}
```

# Python:
```python
# -*- coding:utf-8 -*-
class Solution:
    def LastRemaining_Solution(self, n, m):
        # write code h;
        res = -1
        if n<=0 or m<0:
            return res
        nums =range(n)## 0-n-1数组
        start=0
        while len(nums)>1:
            end = (start+m-1)%(len(nums))
            del nums[end]
            start = end
        return nums[0]

if __name__ == '_ main__':
    n=5
    m=3
    res = Solution().LastRemaining_Solution(n,m)    
    print(res)
```
