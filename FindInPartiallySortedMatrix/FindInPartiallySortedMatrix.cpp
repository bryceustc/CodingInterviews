// C++ Solution 1:
class Solution{
    public:
        bool Find(vector<vector<int>> &nums,int target)
        {
            if (nums.empty()) return false;
            int m = nums.size();       
            int n = nums[0].size();
            for (int i=0;i<m;i++)
            {
                for (int j=0;j<n;j++)
                {
                    if (nums[i][j]==target)
                    {
                        return true;
                    }                    
                }
            }
            return false;          
        }
};
// C++ Solution 2:
class Solution{
    public:
        bool Find(vector<vector<int>> &nums,int target)
        {
            if (nums.empty()) return false;
            int n = nums.size();       
            int m = nums[0].size();
            for (int i=0;i<n;i++)
            {
                int start = 0;
                int end = m-1;
                while (end>=start)
                {
                    int mid = start + (end-start)/2;
                    if (nums[i][mid]==target)
                        return true;
                    if (nums[i][mid]<target)
                        start = mid+1;
                    if (nums[i][mid]>target)
                        end = mid-1;
                }
            }
            return false;          
        }
};
// C++ Solution 3:
// 右上角开始查找
class Solution{
    public:
        bool Find(vector<vector<int>> &nums,int target)
        {
            if (nums.empty()) return false;
            int m = nums.size();       
            int n = nums[0].size();
            int i=0,j=n-1;
            while (i<m && j>=0)
            {
                if (nums[i][j]==target)
                    return true;
                else if (nums[i][j]>target)
                    j--;//左移
                else
                    i++;//下移
            }
            
            return false;          
        }
};
// C++ Solution 4:
class Solution{
    public:
        bool Find(vector<vector<int>> &nums,int target)
        {
            if (nums.empty()) return false;
            int m = nums.size();       
            int n = nums[0].size();
            int i=m-1,j=0;
            while (i>=0 && j<n)
            {
                if (nums[i][j]==target)
                    return true;
                if (nums[i][j]>target)
                    i--;//上移
                else
                    j++;//右移
            }
            
            return false;          
        }
};
