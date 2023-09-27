# 题目: 斐波那契数列

## 题目描述：
大家都知道斐波那契数列，现在要求输入一个整数n，请你输出斐波那契数列的第n项（从0开始，第0项为0）。
n<=39

![](https://cuijiahua.com/wp-content/uploads/2017/11/basis_7_3.jpg)
  
# 解题思路:
  1. 传统递归，复杂多较高
  
  2. 动态规划，避免用递归，只用前两个数计算节省空间。
# 时间复杂度：
1： O(2^n)
 
2:  O(n);
# 空间复杂度
  O(1)
  
# 代码

[C++](./Fibonacci.cpp)

[Python](./Fibonacci.py)

# C++: 
###  递归
```c++
class Solution {
public:
    int Fibonacci(int n) {
        if (n==0)
            return 0;
        if (n<=2)
            return 1;
        return Fibonacci(n-1) + Fibonacci(n-2);
    }
};
```
### 动态规划
```c++
class Solution {
public:
    int Fibonacci(int n) {
        if (n<2)
            return n;
        int fn_one = 1;
        int fn_two = 0;
        int fn = 0;
        for (int i=2;i<=n;i++)
        {
            fn = fn_one + fn_two;
            fn_two = fn_one;
            fn_one = fn;
        }
        return fn;
    }
};
```

### 矩阵快速幂
```c++
### 矩阵快速幂

```c++
// 定义矩阵
typedef long long ll;
ll mod = 1e9 + 7;
struct matrix {
    ll mat[2][2];
    matrix() { memset(mat, 0, sizeof(mat)); }//构造函数初始化
};
class Solution {
public:
    matrix res, transition;
    //矩阵乘法
    matrix mul(matrix A, matrix B) {  // return A * B
        matrix C;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                for (int k = 0; k < 2; k++) {
                    C.mat[i][j] += (A.mat[i][k] % mod * B.mat[k][j] % mod) % mod;
                    C.mat[i][j] %= mod;
                }
            }
        }
        return C;
    }
    //快速幂
    void fast_pow(int n) {
        while (n) {
            if (n & 1) {
                res = mul(res, transition);
            }
            transition = mul(transition, transition);
            n >>= 1;
        }
    }

    int fib(int n) {
        if (n < 2) return n;
        //初始化
        res.mat[0][0] = 1;
        transition.mat[0][0] = transition.mat[0][1] = transition.mat[1][0] = 1;
        fast_pow(n - 1);
        return res.mat[0][0];
    }
};
```
```
# Python:
###  递归 未通过OJ
```python
# -*- coding:utf-8 -*-
class Solution:
    def Fibonacci(self, n):
        # write code here
        if n<2:
            return n
        return self.Fibonacci(n-1) + self.Fibonacci(n-2)
```
### 动态规划
```python
# -*- coding:utf-8 -*-
class Solution:
    def Fibonacci(self, n):
        # write code here
        if n<2:
            return n
        fn_one = 1
        fn_two = 0
        fn = 0
        for i in range(2,n+1):
            fn = fn_one + fn_two
            fn_two = fn_one
            fn_one = fn
        return fn
```
