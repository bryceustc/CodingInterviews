// C++ Solution 1:
class Solution {
public:
    int GetNumberOfK(vector<int> nums ,int k) {
        int res = 0;
        if (nums.empty())
            return 0;
        int n = nums.size();
        for (int i=0;i<n;i++)
        {
            if (nums[i]==k)
                res++;
        }
        return res;
    }
};

// C++ Solution 2:
class Solution {
public:
    int GetNumberOfK(vector<int> nums ,int k) {
        int res = 0;
        if (nums.empty())
            return 0;
        int n = nums.size();
        int start = 0;
        int end = n;
        while (end > start)
        {
            int mid = start + (end-start)/2;
            if (nums[mid]==k)
                end=mid;
            if (nums[mid]<k)
                start = mid+1;
            if (nums[mid]>k)
                end = mid;
        }
        int temp1 = start;
        start = 0;
        end = n;
        while (end > start)
        {
            int mid = start + (end-start)/2;
            if (nums[mid]==k)
                start=mid+1;
            if (nums[mid]<k)
                start = mid+1;
            if (nums[mid]>k)
                end = mid;
        }
        int temp2 = start;
        res = temp2-temp1;
        return res;
    }
};
