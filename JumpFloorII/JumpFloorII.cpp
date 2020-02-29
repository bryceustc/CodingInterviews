class Solution {
public:
    int jumpFloorII(int n) {
        if (n==0)
            return 0;
        int res = 1;
        for (int i=1;i<n;i++)
        {
            res*=2;
        }
        return res;
    }
};
