class Solution {
public:
    int movingCount(int threshold, int rows, int cols)
    {
        int res = 0;
        vector<vector<int>> visited (rows, vector<int>(cols,0));
        res = helper(threshold, rows, cols,0, 0, visited);
        return res;
    }
    int helper(int threshold, int rows, int cols, int i, int j, vector<vector<int>> &visited)
    {
        int sum = bitSum(i) + bitSum(j);
        // 或者转成字符串来计算
        //string s1 = to_string(i);
        // string s2 = to_string(j);
        // int sum = 0;
        // for (int x =0; x<s1.size();x++)
        // {
        //     sum+=s1[x]-'0';
        // }
        // for (int y =0; y<s2.size();y++)
        // {
        //     sum+=s2[y]-'0';
        // }
        // if (sum> k|| i<0|| i>=m || j<0|| j>=n||visited[i][j]==1)
        // {
        //     return 0;
        // }
        if (sum > threshold || i<0 || i>=rows || j<0 || j>=cols || visited[i][j]==1)
            return 0;
        visited[i][j]=1;
        return helper(threshold, rows, cols,i-1, j, visited) + helper(threshold, rows, cols,i+1, j, visited) +
            helper(threshold, rows, cols,i, j-1, visited) + helper(threshold, rows, cols,i, j+1, visited) + 1;
    }
     //计算位置的数值
    int bitSum(int num)
    {
        int sum = 0;
        while(num>0)
        {
            sum+=num%10;
            num/=10;
        }
        return sum;
    }
};
