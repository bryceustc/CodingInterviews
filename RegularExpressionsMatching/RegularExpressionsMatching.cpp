// C++ Solution 1:
class Solution {
public:
    bool match(char* str, char* pattern)
    {
        if (*str == '\0' && *pattern == '\0')
            return true;
        if (*str != '\0' && *pattern == '\0')
            return false;
        if (*(pattern +1) !='*')
        {
            if (* str == * pattern || (*str !='\0'&& *pattern =='.'))
                return match(str+1,pattern+1);
            else
                return false;
        }
        else
        {
            if (* str == * pattern || (*str!='\0')&& *pattern == '.')
                return (match(str,pattern+2) || match(str+1,pattern));
            else
                return (match(str,pattern+2));
        }
    }
};


// C++ Solution 2:
class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        vector<vector<bool>> dp(n+1,vector<bool>(m+1,false));
        dp[0][0]=true;
        s = ' '+s;
        p = ' '+p;
        for (int i=0;i<=n;i++)  // i从0开始，因为dp(0,j)有可能是有意义的
        {
            for(int j=1;j<=m;j++)
            {
                if (i>0 && (s[i]==p[j] || p[j]=='.'))
                {
                    dp[i][j] = dp[i][j] | dp[i-1][j-1];  // | 表示按位或
                }
                if (p[j]=='*')
                {
                    if (j>=2)
                    {
                        dp[i][j] = dp[i][j] | dp[i][j-2];
                    }
                    if (i>0 && (s[i]==p[j-1] || p[j-1]=='.'))
                    {
                        dp[i][j] = dp[i][j] | dp[i-1][j];
                    }
                }
            }
        }
        return dp[n][m];        
    }
};
