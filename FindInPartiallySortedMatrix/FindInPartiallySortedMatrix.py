## Python Solution 1：
# -*- coding:utf-8 -*-
class Solution:
    def Find(self, nums, target):
        m = len(nums)
        if m == 0:
            return False
        n = len(nums[0])
        for i in range(m):
            for j in range(n):
                if nums[i][j] == target:
                    return True
        return False

## Python Solution 2：
# -*- coding:utf-8 -*-
class Solution:
    def Find(self, nums, target):
        m = len(nums)
        if m == 0:
            return False
        n = len(nums[0])
        for i in range(m):
            start = 0
            end = n-1
            while end>=start:
                mid = start+(end-start)//2
                if nums[i][mid]==target:
                    return True
                if nums[i][mid]<target:
                    start=mid+1
                if nums[i][mid]>target:
                    end=mid-1
        return False
## Python Solution 3：
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
## Python Solution 4：
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
