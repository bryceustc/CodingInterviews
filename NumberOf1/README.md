# 题目:1~n整数中1出现的次数
## 题目描述：
输入一个整数n,求1~n这n个整数的十进制表示中1出现次数。例如，输入12，1~12中包含1的数字有1，10,11和12，1一共出现了5次

# 本题考点：
  
  字符串编程能力，递归的理解，思维的全面性。
  
# 解题思路:
  类似LeetCode中46,47题。递归方法，DFS，深度优先遍历算法。
  
# 代码

[C++](./NumberOf1.cpp)

[Python](./NumberOf1.py)

# C++: 
### 方法一：DFS
```c++
class Solution {
public:
    vector<string> Permutation(string str) {
        vector<string> res;
        int n = str.size();
        if (n==0) return res;
        // 数字排列时需要排序，不排序的话就重复了
        vector<int> visited(n,0);
        string out = "";
        DFS(str,res,0,visited,out);
        // 消除重复排列
        
        //unique只是去除（相邻）的重复元素，因此，为了去除重复的元素，应该，首先对数组/Vector进行排序，这样保证重复元素在相邻的位置。
        sort(res.begin(),res.end());
        // unique()函数将重复的元素放到vector的尾部 然后返回指向第一个重复元素的迭代器再用erase函数擦除从这个元素到最后元素的所有的元素
        res.erase(unique(res.begin(),res.end()),res.end());
        return res;
    }
    void DFS (string str,vector<string> &res, int level, vector<int> &visited,string &out)
    {
        int n = str.size();
        if (level == n)
        {
            res.push_back(out);
            return;
        }
        for (int i=0;i<n;i++)
        {
            if (i >=1 && str[i]==str[i-1]&&visited[i-1]==0)
                continue;
            if (visited[i]==1)
                continue;
            visited[i]=1;
            out += str[i];
            DFS(str,res,level+1,visited,out);
            out.pop_back();
            visited[i]=0;
        }
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
    def Permutation(self, s):
        # write code here
        n = len(s)
        res = []
        if n==0:
            return res
        out = ""
        visited = [0 for _ in range(n)]
        self.DFS(s,0,visited,out,res)
        return res
    def DFS(self,s,level,visited,out,res):
        n = len(s)
        if level == n:
            res.append(out)
            return
        for i in range(n):
            if visited[i]==1:
                continue
            if i >= 1 and s[i]==s[i-1] and visited[i-1]==0:
                continue
            out += s[i]
            visited[i]=1
            self.DFS(s,level+1,visited,out,res)
            out = out[:-1]
            visited[i]=0
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


