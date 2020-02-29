# 题目: 求1+2+…+n

## 题目描述：
求 1+2+...+n ，要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A?B:C）。

**示例1：**
```
输入: n = 3
输出: 6
```
  
# 解题思路:
  利用&&就是逻辑与，逻辑与有个短路特点，前面为假，后面不计算。即递归终止条件
# 时间复杂度：
O(n)
  
# 空间复杂度
  O(1)
  
# 代码

[C++](./Accumulate.cpp)

[Python](./Accumulate.py)

# C++: 
###  
```c++
class Solution {
public:
    int sumNums(int n) {
        int res = n;
        res && (res += sumNums(n-1));
        return res;
    }
};
```
# Python:
### 
```python
class Solution:
    def sumNums(self, n: int) -> int:
        res = n
        if res:
            res+= self.sumNums(n-1)
        return res
```
