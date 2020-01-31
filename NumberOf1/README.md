# 题目:1~n整数中1出现的次数
## 题目描述：
输入一个整数n,求1\~n这n个整数的十进制表示中1出现次数。例如，输入12，1\~12中包含1的数字有1，10,11和12，1一共出现了5次

# 本题考点：
  
  数学规律的发现，时间效率的提升。
  
# 解题思路:
  方法一：对1\~n的每一个数字都进行判断，从最高位一直判断到最低位，如果为1，数字就加1，最后每一个数字都这样判断，累加起来就是1出现的次数。时间复杂度O(nlogn),空间复杂度O(1)。
  
  方法二：数学之美中的方法，利用
  
# 代码

[C++](./NumberOf1.cpp)

[Python](./NumberOf1.py)

# C++: 
### 方法一：直接暴力法，时间复杂度O(nlogn)
```c++
class Solution {
public:
    int NumberOf1Between1AndN_Solution(int n)
    {
        int res = 0;
        if (n<1)
            return res;
        for (int i=1;i<=n;i++)
        {
            res += NumberOf1(i);
        }
        return res;
    }
    int NumberOf1(int n)
    {
        int num = 0;
        while (n)
        {
            if(n%10==1)
                num++;
            n /= 10;
        }
        return num;
    }
};
```
### 方法二：另一种递归方法
```c++
class Solution 
{
public:
    vector<string> Permutation(string str) {
        //判断输入
        if(str.length() == 0){
            return result;
        }
        PermutationCore(str, 0);
        //对结果进行排序
        sort(result.begin(), result.end());
        return result;
    }
    
private:
    void PermutationCore(string str, int begin){
        //递归结束的条件：第一位和最后一位交换完成
        int n = str.size();
        if(begin == n)
        {
            result.push_back(str);
            return;
        }
        for(int i = begin; i < n; i++){
            //如果字符串相同，则不交换
            if(i != begin && str[i] == str[begin]){
                continue;
            }
            //位置交换
            swap(str[begin], str[i]);
            //递归调用，前面begin+1的位置不变，后面的字符串全排列
            PermutationCore(str, begin + 1);
        }
    }
    vector<string> result;
};
```
# Python:
### 方法一：
```python
# -*- coding:utf-8 -*-
class Solution:
    def NumberOf1Between1AndN_Solution(self, n):
        # write code here
        res = 0
        for i in range(1,n+1):
            res += self.NumberOf1(i)
        return res
    def NumberOf1(self,n):
        num = 0
        while n>0:
            if n%10==1:
                num+=1
            n/=10
        return num
```
### 方法二：
```python
# -*- coding:utf-8 -*-
class Solution:
    def __init__(self):
        self.result = []
    def Permutation(self, ss):
        # write code here
        if len(ss) == 0:
            return []
        self.PermutationCore(ss, 0)
        sorted(self.result)
        return self.result
    def PermutationCore(self, str_, begin):
        if begin == len(str_):
            self.result.append(str_)
            return
        for i in range(begin, len(str_)):
            if i != begin and str_[i] == str_[begin]:
                continue
            str_list = list(str_)
            str_list[i], str_list[begin] = str_list[begin], str_list[i]
            str_ = ''.join(str_list)
            self.PermutationCore(str_, begin+1)
```
## 参考
  - [C++ vector去除重复元素](https://blog.csdn.net/u010141928/article/details/78671603)
  - [Python 字符串去除最后一个字符](https://www.codenong.com/15478127/)
  - [LeetCode—46题—全排列](https://github.com/bryceustc/LeetCode_Note/blob/master/cpp/Permutations/README.md)
  - [LeetCode—47题—全排列II](https://github.com/bryceustc/LeetCode_Note/blob/master/cpp/Permutations-II/README.md)


