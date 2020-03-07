# 题目:把数字翻译成字符串
## 题目描述：
给定一个数字，我们按照如下规则把它翻译为字符串：0 翻译成 “a” ，1 翻译成 “b”，……，11 翻译成 “l”，……，25 翻译成 “z”。一个数字可能有多个翻译。请编程实现一个函数，用来计算一个数字有多少种不同的翻译方法。

**示例：**
```
输入: 12258
输出: 5
解释: 12258有5种不同的翻译，分别是"bccfi", "bwfi", "bczi", "mcfi"和"mzi"
```

# 本题考点：
  
  动态规划。
  
# 解题思路:

  ![](https://github.com/bryceustc/CodingInterviews/blob/master/TranslateNum/1.jpg)
 
 **注意：dp范围那里应该是10-25之间**
  
# 代码

[C++](./TranslateNum.cpp)

[Python](./TranslateNum.py)

# C++: 
###  dp
```c++
class Solution {
public:
    int translateNum(int num) {
        string s = to_string(num);
        int n = s.size();
        vector<int> dp(n+1, 0); // dp[i]表示前i个数字的翻译种数，注意dp[i]对应的数字是s[i-1]
        dp[0] = 1;
        dp[1] = 1;
        for (int i =2;i<n+1;i++)
        {
            if (s[i-2] == '0' || s.substr(i-2, 2)>"25")
            {
                dp[i] = dp[i-1];
            }
            else
            {
                dp[i] = dp[i-1] + dp[i-2];
            }
        }
        return dp[n];
    }
};
```
# Python:
```python
class Solution:
    def translateNum(self, num: int) -> int:
        s = str(num)
        n = len(s)
        dp = [1 for _ in range(n+1)]
        for i in range(2,n+1):
            if s[i-2] == '0' or (s[i-2:i]>"25"):
                dp[i] = dp[i-1]
            else:
                dp[i] = dp[i-1] + dp[i-2]
        return dp[n]
```

