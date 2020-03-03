class Solution {
public:
    int reversePairs(vector<int>& nums) {
        int count = 0;
        if (nums.empty()) return count;
        int n = nums.size();
        vector<int> temp;
        for (int i=0;i<n;i++)
        {
            temp.push_back(nums[i]);
        }
        count = helper(nums, temp, 0, n-1);
        return count;
    }
    int helper(vector<int> &nums, vector<int> &temp, int start, int end)
    {
        if (start==end)
        {
            temp[start] = nums[start];
            return 0;
        }
        int mid = start + (end-start)/2;
        int left = helper(temp, nums, start, mid);
        int right = helper(temp, nums, mid+1, end);

        int i = mid;
        int j = end;
        int index = end;
        int count = 0;
        while (i>=start && j>=mid+1)
        {
            if (nums[i]>nums[j])
            {
                temp[index--] = nums[i--];
                count += j-mid;
            }
            else
            {
                temp[index--] = nums[j--];
            }
        }
        while(i>=start) temp[index--] = nums[i--];
        while(j>=mid+1) temp[index--] = nums[j--];
        return left + right + count;
    }
};
