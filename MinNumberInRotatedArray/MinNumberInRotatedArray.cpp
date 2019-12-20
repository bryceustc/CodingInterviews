// C++ Solution 1:
class Solution {
public:
    int findMin(vector<int>& nums) {
        if (nums.empty()) return 0;
        int n = nums.size();     
        int res = nums[0];
        for (int i=1;i<n;i++)
        {
            if (res>nums[i])
                res = nums[i];
        }
        return res;
    }
};



// C++ Solution 2:
class Solution{
    public:
        int MinNumberInRotatedArray(vector<int>&nums)
        {
            if (nums.empty()) return 0;
            int n = nums.size();     
            int start = 0;
            int end = n-1;
            int res = nums[0];
            while (end>=start)
            {
                int mid = start + (end-start)/2;
                if (nums[mid]>=res)
                {
                    start = mid+1;
                }
                if (nums[mid]<res)
                {
                    end = mid-1;
                }
                res = min(res,nums[mid]);
                }
            return res;          
        }
};


// C++ Solution 3:
class Solution {
public:
    int findMin(vector<int>& nums) {
        if (nums.empty()) return 0;
        int res = 0;
        sort(nums.begin(),nums.end());
        res =nums[0];
        return res;
    }
};
