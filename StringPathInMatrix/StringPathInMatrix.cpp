class Solution {
public:
    bool hasPath(char* matrix, int rows, int cols, char* str)
    {
        if(matrix == NULL || rows <1 || cols < 1 || str == NULL)
            return false;
        vector<vector<int>> visited (rows, vector<int>(cols,0));
        for (int i=0;i<rows;i++)
        {
            for (int j=0;j<cols;j++)
            {
                if (helper(matrix, rows, cols, i, j, str, 0, visited))
                {
                    return true;
                }
            }
        }
        return false;
    }
    bool helper(char* matrix, int rows, int cols, int i, int j, char* str, int k, vector<vector<int>> &visited)
    {
        //因为是一维数组存放二维的值，index值就是相当于二维数组的（i，j）在一维数组的下标
        int index = i*cols + j;
        if(i<0||i>=rows||j<0||j>=cols||matrix[index]!=str[k]||visited[i][j]==1)
            return false;
        //字符串已经查找结束，说明找到该路径了
        if (str[k+1]=='\0')
            return true;
        //标记访问过
        visited[i][j]=1;
        //向四个方向进行递归查找,向左，向右，向上，向下查找
        if (helper(matrix, rows, cols, i, j-1, str, k+1, visited)||
           helper(matrix, rows, cols, i, j+1, str, k+1, visited)||
           helper(matrix, rows, cols, i-1, j, str, k+1, visited)||
           helper(matrix, rows, cols, i+1, j, str, k+1, visited))
        {
            return true;
        }
        visited[i][j]=0;
        return false;
    }
};
