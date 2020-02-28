# 题目: 二进制中1的个数
## 题目描述：
请实现一个函数，输入一个整数，输出该数二进制表示中 1 的个数。例如，把 9 表示成二进制是 1001，有 2 位是 1。因此，如果输入 9，则该函数输出 2。
# 本题考点：
  
  二进制与位运算的理解。
  
# 解题思路:

根据 与运算 定义，设二进制数字 n ，则有：
    - 若 n&1=0 ，则 n 二进制 最右一位 为 0
    - 若 n&1=1 ，则 n 二进制 最右一位 为 1

如果一个整数不为0，那么这个整数至少有一位是1。如果我们把这个整数减1，那么原来处在整数最右边的1就会变为0，原来在1后面的所有的0都会变成1(如果最右边的1后面还有0的话)。其余所有位将不会受到影响。

举个例子：一个二进制数1100，从右边数起第三位是处于最右边的一个1。减去1后，第三位变成0，它后面的两位0变成了1，而前面的1保持不变，因此得到的结果是1011.我们发现减1的结果是把最右边的一个1开始的所有位都取反了。这个时候如果我们再把原来的整数和减去1之后的结果做与运算，从原来整数最右边一个1那一位开始所有位都会变成0。如1100&1011=1000.也就是说，把一个整数减去1，再和原整数做与运算，会把该整数最右边一个1变成0.那么一个整数的二进制有多少个1，就可以进行多少次这样的操作。

  如图所示：
  ![](https://pic.leetcode-cn.com/abfd6109e7482d70d20cb8fc1d632f90eacf1b5e89dfecb2e523da1bcb562f66-image.png)
  
# 代码

[C++](./NumberOf1InBinary.cpp)

[Python](./NumberOf1InBinary.py)

# C++: 
###  尝试一：只能通过正数情况，负数右移不是除以2，未通过OJ
```c++
class Solution {
public:
     int  NumberOf1(int n) {
         int count = 0;
         while(n!=0)
         {
             if (n&1==1)
                 count++;
             n = n>>1;
         }
         return count;
     }
};
```
###  数字右移不行，换个思路，1左移
```c++
class Solution {
public:
     int  NumberOf1(int n) {
         int count = 0;
         unsigned int flag = 1;
         // 循环次数等于二进制整数的位数
         while(flag)
         {
             if (n&flag)
                 count++;
             flag = flag << 1;
         }
         return count;
     }
};
```
###  最优解法
```c++
class Solution {
public:
     int  NumberOf1(int n) {
         int count = 0;
         while(n)
         {
             count++;
             n = (n-1)&n;
         }
         return count;
     }
};
```
# Python:
###   
```python
class Solution:
    def NumberOf1(self, n: int) -> int:
        res = 0
        while n:
            res += n&1
            n = n>>1
        return res
```
### 
```python
class Solution:
    def hammingWeight(self, n: int) -> int:
        count= 0
        while n:
            count+=1
            n&=n-1
        return count
```
## 参考
  -  [LeetCode-191题-位1的个数](https://github.com/bryceustc/LeetCode_Note/blob/master/cpp/Number-Of-1-Bits/README.md)
