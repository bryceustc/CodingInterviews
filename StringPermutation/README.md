# 题目:字符串的排列
## 题目描述：
输入一个字符串,按字典序打印出该字符串中字符的所有排列。例如输入字符串abc,则打印出由字符a,b,c所能排列出来的所有字符串abc,acb,bac,bca,cab和cba。

```
输入一个字符串,长度不超过9(可能有字符重复),字符只包括大小写字母。
```
# 本题考点：
  
  字符串编程能力，正则表达式的理解，思维的全面性。
  
# 解题思路:
  类似LeetCode中46,47题。递归方法，DFS，深度优先遍历算法。
  
# 代码

[C++](./StringPermutation.cpp)

[Python](./StringPermutation.py)

# C++: 
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
# Python:
```python
# -*- coding:utf-8 -*-
class Solution:
    # s字符串
    def isNumeric(self, s):
        # write code here
        n = len(s)
        if n==0:
            return False
        sign = False
        decimal = False
        hasE = False
        for i in range(0,n):
            if s[i] == 'e' or s[i]=='E':
                if i == n-1:
                    return False
                if hasE:
                    return False
                hasE = True
            elif s[i]=='+' or s[i]=='-':
                if sign and s[i-1]!= 'e' and s[i-1] != 'E':
                    return False
                if not sign and i>0 and s[i-1] != 'e' and s[i-1]!='E':
                    return False
                sign = True
            elif s[i]=='.':
                if hasE or decimal:
                    return False
                decimal = True
            elif s[i]<'0' or s[i]>'9':
                return False
        return True
```

## 参考
  - [vector去除重复元素](https://blog.csdn.net/u010141928/article/details/78671603)

