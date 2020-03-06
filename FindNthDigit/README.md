# 题目:数字序列中某一位的数字
## 题目描述：
数字以0123456789101112131415…的格式序列化到一个字符序列中。在这个序列中，第5位（从下标0开始计数）是5，第13位是1，第19位是4，等等。

请写一个函数，求任意第n位对应的数字。

**示例1：**
```
输入：n = 3
输出：3
```

# 本题考点：
  
  数学规律的发现，时间效率的提升。
  
# 解题思路:

  ![](https://pic.leetcode-cn.com/4f913f7a795d55038dc3a480c8268d8cc3367b14cb0cb4a7ea0c9d23f26fff9b-1.png)
  
对于第 n 位对应的数字，我们令这个数字对应的数为 target，然后分三步进行。

  -  首先找到这个数字对应的数是几位数，用 digits 表示；
  -  然后确定这个对应的数的数值 target；
  -  最后确定返回值是 target 中的哪个数字。
  
# 代码

[C++](./FindNthDigit.cpp)

[Python](./FindNthDigit.py)

# C++: 
### 
```c++
class Solution {
public:
    int findNthDigit(int n) {
        if (n<0)
            return -1;
        if (n<10)
            return n;
        int digits = 1;
        long number = 9;
        while  (n>digits*number)
        {
            n-=digits*number;
            digits++;
            number*=10;
        }
        n-=1; // 计算时从1开始，但实际是从0开始，所以要减1
        int  a = n / digits;
        int  idx = n%digits;
        int num = int (pow(10, digits-1)) + a;
        int idxFromRight = digits-idx;
        for (int i=1;i<idxFromRight;i++)
        {
            num/=10;
        }
        return num%10;
        // string s = to_string(num);
        // return s[idx]-'0';
    }
};
```
# Python:
```python
class Solution:
    def findNthDigit(self, n: int) -> int:
        if n<0:
            return -1
        if n<10:
            return n
        digits = 1
        numbers = 9
        while n>digits*numbers:
            n-=digits*numbers
            digits+=1
            numbers*=10
        n-=1
        a = n//digits
        b = n%digits
        num = int(pow(10,digits-1) + a)
        idx = digits-b
        for i in range(1, idx):
            num//=10
        return num%10
        # s = str(num)
        # res = int(s[b])
        # return res
```
