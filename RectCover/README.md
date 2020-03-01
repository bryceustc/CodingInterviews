# 题目: 矩形覆盖

## 题目描述：
我们可以用2\*1的小矩形横着或者竖着去覆盖更大的矩形。请问用n个2\*1的小矩形无重叠地覆盖一个2\*n的大矩形，总共有多少种方法？

比如n=3时，2\*3的矩形块有3种覆盖方法：

![](https://uploadfiles.nowcoder.com/images/20200218/6384065_1581999858239_64E40A35BE277D7E7C87D4DCF588BE84)
  
# 解题思路:
  实质还是斐波那契数列
  
  使用动态规划，避免用递归，只用前两个数计算节省空间。
# 时间复杂度：
O(n);
# 空间复杂度
  O(1)
  
# 代码

[C++](./RectCover.cpp)

[Python](./RectCover.py)

# C++: 
### 动态规划
```c++
class Solution {
public:
    int rectCover(int n) {
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
    def rectCover(self, n):
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
