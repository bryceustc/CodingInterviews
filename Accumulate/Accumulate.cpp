class Solution {
public:
    int sumNums(int n) {
        int res = n;
        res && (res += sumNums(n-1));
        return res;
    }
};
