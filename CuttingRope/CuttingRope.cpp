class Solution {
public:
    int cuttingRope(int n) {
        vector<int> dp (n+1,0); // # dp[0] dp[1]其实没用
        dp[2] = 1;
        for (int i=3;i<=n;i++)
        {
            for(int j=1;j<=i-1;j++)
            {
                dp[i] = max(dp[i], max(j*(i-j), j*dp[i-j]));
            }
        }
        return dp[n];
    }
};

// Solution 2:
class Solution {
public:
    int cuttingRope(int n) {
        vector<int> dp(3,1);
        dp[0] = 0;
        for (int i=3;i<=n;i++)
        {
            dp[i % 3] = max((max(dp[(i-1)%3],i-1)),
            max((2*max(dp[(i-2)%3], i-2)), (3*max(dp[(i-3)%3]
            i-3))));
        }
        return dp[n%3];
    }
};

// Solution 3:
class Solution {
public:
    int cuttingRope(int n) {
        if (n<=3)
            return n-1;
        int a = n/3;
        int b = n%3;
        if (b==0)
            return pow(3,a);
        if (b==1)
            return pow(3,a-1)*4;
        return pow(3,a)*2;
    }
};
