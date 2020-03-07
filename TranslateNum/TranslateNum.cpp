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
