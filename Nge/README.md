##题目描述

把n个骰子扔在地上，所有骰子朝上一面的点数之和为s。输入n，打印出s的所有可能的值出现的概率。

你需要用一个浮点数数组返回答案，其中第 i 个元素代表这 n 个骰子所能掷出的点数集合中第 i 小的那个的概率。


dp动态规划

定义状态：dp[i][j]表示掷第i枚骰子获得点数为j的次数

状态转移方程：
```
for (第n枚骰子的点数 i = 1; i <= 6; i ++) {
    dp[n][j] += dp[n-1][j - i]
}
```
初始化状态:
```
for (int i = 1; i <= 6; i ++) {
    dp[1][i] = 1;
}
```
```c++
class Solution {
public:
    vector<double> twoSum(int n) {
        vector<double> res;
        vector<vector<int>> dp(n+1, vector<int>(6*n+1,0));
        for (int i = 1; i <= 6; i++) {
            dp[1][i] = 1;
        }
        for (int i = 2; i <= n; i++) {
            for (int j = i; j <= 6 * i; j++) {
                for (int k = 1; k <= 6; k++) {
                    if (j > k) {
                        dp[i][j] += dp[i-1][j-k];
                    }
                }
            }
        }
        double base = pow(6, n) * 1.0;
        for (int i = n; i <= 6 * n; i++) {
            res.push_back(dp[n][i] / base);
        }
        return res;
    }
};
```
