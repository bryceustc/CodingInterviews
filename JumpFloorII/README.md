# 题目: 跳台阶

## 题目描述：
一只青蛙一次可以跳上1级台阶，也可以跳上2级。求该青蛙跳上一个n级的台阶总共有多少种跳法。
  
# 解题思路:
  首先我们考虑最简单的情况。如果只有1级台阶，那么显然只一种跳法。如果有2级台阶，那就有两种跳法：一种是分两次跳，每次跳1级；另一种是一次跳2级。

接着，我们来讨论一般情况。我们把n级台阶时的跳法看成是n的函数，记为f(n)。当n>2时，第一次跳的时候就有两种不同的选择：一是第一次只跳1级，此时跳法数目等于后面剩下的n-1级台阶的跳法数目，即为f(n-1)；另外一种选择是跳一次跳2级，此时跳法数目等于后面剩下的n-2级台阶的跳法数目，即为f(n-2)。因此n级台阶的不同跳法的总数f(n)=f(n-1)+f(n-2)。分析到这里，我们不难看出这实际上就是斐波那契数列了。

注意，f(2) = 2, f(1) =1,f(0) =0
# 时间复杂度：
 O(n);
# 空间复杂度
  O(1)
  
# 代码

[C++](./JumpFloor.cpp)

[Python](./JumpFloor.py)

# C++: 
###  动态规划
```c++
class Solution {
public:
    int jumpFloor(int n) {
        if (n<=2)
            return n;
        int fn_one = 2;
        int fn_two = 1;
        int fn = 0;
        for (int i=3;i<=n;i++)
        {
           fn = fn_one + fn_two;
            fn_two = fn_one;
            fn_one = fn;
        }
        return fn;
    }
};
```
# Python:
### 动态规划
```python
# -*- coding:utf-8 -*-
class Solution:
    def jumpFloor(self, n):
        # write code here
        if n<=2:
            return n
        fn_one = 2
        fn_two = 1
        fn = 0
        for i in range(3,n+1):
            fn = fn_one + fn_two
            fn_two = fn_one
            fn_one = fn
        return fn
```


