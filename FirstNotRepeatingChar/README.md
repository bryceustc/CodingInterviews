# 题目:第一个只出现一次的字符
## 题目描述：
在一个字符串(0<=字符串长度<=10000，全部由字母组成)中找到第一个只出现一次的字符,并返回它的位置, 如果没有则返回 -1（需要区分大小写）.

# 本题考点：
  
  数组和字符串的编程能力，哈希表的理解运用。
  
# 解题思路:
  哈希表，C++利用unordered_map<int,int>来进行次数统计，可以用int类型是因为c++会自动将字符转成对应的ASCII码数字，可以利用unordered_map<char,int>来进行次数统计.Python 利用collections.Counter()模块进行次数统计。
  
  时间复杂度为O(n),空间复杂度O(n)。
  
 
  
# 代码

[C++](./FirstNotRepeatingChar.cpp)

[Python](./FirstNotRepeatingChar.py)

# C++: 
### 哈希表，时间复杂度O(n)，空间复杂度O(n)
```c++
class Solution {
public:
    int FirstNotRepeatingChar(string s) {
        int res = -1;
        int n = s.size();
        if (n==0) return res;
        unordered_map<char,int> m;
        for (int i=0;i<n;i++)
        {
            m[s[i]]++;
        }
        for (int i=0;i<n;i++) 
        {
            if (m[s[i]]==1)
            {
                return i;
            }
        }
        return res;
    }
};
```
# Python:
### 哈希表
```python
# -*- coding:utf-8 -*-
class Solution:
    def FirstNotRepeatingChar(self, s):
        # write code here
        import collections
        n = len(s)
        res = -1
        if n==0:
            return res
        count = collections.Counter(s)
        for index,ch in enumerate(s):
            if count[ch]==1:
                return index
        return res
```
## 参考
  -  [LeetCode—387题—字符串中第一个唯一字符](https://github.com/bryceustc/LeetCode_Note/blob/master/cpp/First-Unique-Character-In-A-String/README.md)
  -  [Python collections.Counter()方法](https://docs.python.org/zh-cn/3/library/collections.html)
  -  [Python collections.Counter()计数函数](https://blog.csdn.net/u014755493/article/details/69812244)

