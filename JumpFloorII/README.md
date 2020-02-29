# 题目: 变态跳台阶

## 题目描述：
一只青蛙一次可以跳上1级台阶，也可以跳上2级……它也可以跳上n级。求该青蛙跳上一个n级的台阶总共有多少种跳法。
  
# 解题思路:
  我想说，这青蛙真变态，真能跳。

  - 当n=1时，结果为1；
  - 当n=2时，结果为2；
  - 当n=3时，结果为4；
  
以此类推，我们使用数学归纳法不难发现，跳法f(n)=2^(n-1)。
# 时间复杂度：
 O(n);
# 空间复杂度
  O(1)
  
# 代码

[C++](./JumpFloorII.cpp)

[Python](./JumpFloorII.py)

# C++: 
###  通项公式
```c++
class Solution {
public:
    int jumpFloorII(int n) {
        if (n==0)
            return 0;
        int res = 1;
        for (int i=1;i<n;i++)
        {
            res*=2;
        }
        return res;
    }
};
```
# Python:
### 通项公式
```python
# -*- coding:utf-8 -*-
class Solution:
    def jumpFloorII(self, n):
        # write code here
        if n==0:
            return 0
        res = 1
        for i in range(1,n):
            res *= 2
        return res
```
