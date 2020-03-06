class Solution {
public:
    int findNthDigit(int n) {
        if (n<0)
            return -1;
        if (n<10)
            return n;
        int digits = 1;
        long number = 9;
        while  (n>digits*number)
        {
            n-=digits*number;
            digits++;
            number*=10;
        }
        n-=1; // 计算时从1开始，但实际是从0开始，所以要减1
        int  a = n / digits;
        int  idx = n%digits;
        int num = int (pow(10, digits-1)) + a;
        int idxFromRight = digits-idx;
        for (int i=1;i<idxFromRight;i++)
        {
            num/=10;
        }
        return num%10;
        // string s = to_string(num);
        // return s[idx]-'0';
    }
};
