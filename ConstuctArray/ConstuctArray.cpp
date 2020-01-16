// C++ Solution 1：
class Solution {
public:
    vector<int> multiply(const vector<int>& A) {
        if (A.empty())
            return {};
        int n = A.size();
        vector<int> B (n,0);
        for (int i =0;i<n;i++)
        {
            int temp = 1;
            for (int j=0;j<n;j++)
            {
                if (j==i)
                    continue;
                temp *=A[j];
            }
            B[i] = temp;
        }
        return B;
    }
};

// C++ Solution 2:
class Solution {
public:
    vector<int> multiply(const vector<int>& A) {
        if (A.empty())
            return {};
        int n = A.size();
        vector<int> B (n,0);
        //计算下三角连乘
        B[0]=1;
        for (int i=1;i<n;i++)
        {
            B[i] = B[i-1]*A[i-1];
        }
        // 计算上三角连乘
        int temp = 1;
        for (int i=n-2;i>=0;i--)
        {
            temp *= A[i+1];
            B[i] *= temp;
        }
        return B;
    }
};
