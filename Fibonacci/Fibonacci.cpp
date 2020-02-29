class Solution {
public:
    int Fibonacci(int n) {
        if (n<2)
            return n;
        int fn_one = 1;
        int fn_two = 0;
        int fn = 0;
        for (int i=2;i<=n;i++)
        {
            fn = fn_one + fn_two;
            fn_two = fn_one;
            fn_one = fn;
        }
        return fn;
    }
};
