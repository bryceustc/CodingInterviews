class Solution {
public:
    double Power(double x, int n) {
        long a = n;
        if (x==0 && n<0)
            return 0.0;
        double res = 1.0;
        // 负数的右移操作不是除2，所以要先转换成非负
        if (n<0)
        {
            x = 1/x;
            a=-a;
        }
        while(a!=0)
        {
            if (a&1==1)
                res *= x;
            x*=x;
            a = a>>1;
        }
        return res;
    }
};
