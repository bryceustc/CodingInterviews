# 题目:打印从1到最大的n位数
## 题目描述：

输入数字 n，按顺序打印出从 1 到最大的 n 位十进制数。比如输入 3，则打印出 1、2、3 一直到最大的 3 位数 999。

**示例1：**
```
输入: n = 1
输出: [1,2,3,4,5,6,7,8,9]
```
# 本题考点：
  
  字符串编程能力，递归的理解，思维的全面性。
  
# 解题思路:
1、针对本题的常规思路，利用pow函数，秒解

2、假设可能出现大数（本题不可能），转换为大数问题求解,  通过使用string进行求解

3、递归求解

我们发现数的每一位都是0到9，所以可以利用全排列的思想，凭借递归的优雅实现达到目的。比如输入3，我们数的打印顺序为：
```c++
001
002
…
010
011
012
…
100
101
…
999
我们从高位开始，对于每一位都递归的用0-9填充，最后递归结束条件为已考察到所有的位，打印并且回溯到最后一位，重新对该位赋予下一个值。
```
  
# 代码

[C++](./PrintNumbers.cpp)

[Python](./PrintNumbers.py)

# C++: 
### 方法一：暴力遍历
```c++
class Solution {
public:
	vector<int> printNumbers(int n) {
		vector<int> res;
		if (n == 0) return res;
		//打印到数组中
		for (int i=1,max=pow(10,n);i<max;i++)
		{
			res.push_back(i);
		}
		return res;
	}
}; 
```
### String 求解
```c++
class Solution {
public:
    vector<int> res;
    vector<int> printNumbers(int n) {
        if (n<=0) return res;
        //创建一个能容纳最大值的字符数组 初始全部设置为0
        string number(n+1, '0');
        while(!Increment(number))
        {
            saveNumber(number);
        }
        return res;
    }
    bool Increment(string &number)
    {
        int carry = 0;
        int m = number.size();
        for (int i=m- 1; i>=0;i--)
        {
            int temp = number[i] - '0' + carry;
            if (i==m-1)
            {
                temp++;
            }
            carry  = temp/10;
            temp %=10;
            number[i] = temp+ '0';
        }
        return number[0]=='1';// 判断是否溢出
    }
    void saveNumber (string number) //由于此处输出，不需要修改number，因此不需要加引用
    {
        string s = "";
        int index = 0;
        // 找到第一不为'0'的位数
        for (;index<number.size();index++)
        {
            if (number[index]!='0')
            {
                break;
            }
        }
        // 拼接成一个完整数字
        for (; index<number.size();index++)
        {
            s+=number[index];
        }
        // 转为整数存入结果
        int num = stoi(s);
        res.push_back(num);
    }
};
```
### 递归
```c++
class Solution {
public:
    vector<int> res;
    vector<int> printNumbers(int n) {
        if (n<=0) return res;
        string number(n, '0');
        helper(0, n, number);
        return res;
    }
    void helper(int index, int n, string &number)
    {
        if (index == n)
        {
            saveNumber(number);
            return;
        }
        for (int i=0;i<=9;i++)
        {
            number[index] = i +'0';
            helper(index+1, n, number);
        }
    }
    void saveNumber (string number) //由于此处输出，不需要修改number，因此不需要加引用
    {
        string s = "";
        int index = 0;
        // 找到第一不为'0'的位数
        for (;index<number.size();index++)
        {
            if (number[index]!='0')
            {
                break;
            }
        }
        // 拼接成一个完整数字
        for (; index<number.size();index++)
        {
            s+=number[index];
        }
        // 转为整数存入结果  因为存在"0000"这中情况 所以需要判断一下
        if (s!="")
        {
            int num = stoi(s);
            res.push_back(num);
        }
    }
};
```
# Python:
### 
```python
class Solution:
    def printNumbers(self, n: int) -> List[int]:
        res = []
        m = 1
        while n:
            m*=10
            n-=1
        for i in range(1,m):
            res.append(i)
        return res
```
### 递归
```python
class Solution:
    def __init__(self):
        self.res = []
    def printNumbers(self, n: int) -> List[int]:
        self.res = []
        if n<=0:
            return self.res
        numer = ['0' for _ in range(n)]
        self.helper(0, n, numer)
        return self.res;
    def helper(self, index, n, numer):
        if index == n:
            self.saveNumber(numer)
            return
        for i in range(10):
            numer[index] = str(i)
            self.helper(index+1, n, numer)
    def saveNumber(self, numer):
        index = 0
        s = ""
        while (index<len(numer)):
            if (numer[index]!='0'):
                break
            index+=1
        while (index<len(numer)):
            s+=numer[index]
            index+=1
        if s:
            num = int(s)
            self.res.append(num)
```
## 参考
  - [剑指Offer-14-打印1到最大的n位数](https://blog.csdn.net/dawn_after_dark/article/details/80719740)
  - [题解](https://leetcode-cn.com/problems/da-yin-cong-1dao-zui-da-de-nwei-shu-lcof/solution/c-3chong-jie-fa-by-xdb/)
