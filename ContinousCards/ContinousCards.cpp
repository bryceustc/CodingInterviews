class Solution {
public:
    bool IsContinuous( vector<int> nums ) {
        int n = nums.size();
        if (nums.empty()|| n!=5)
            return false;
        sort(nums.begin(),nums.end());
        int numZero = 0;
        int gap = 0;
        for (int i=0;i<n;i++)
        {
            if (nums[i]==0)
                numZero++;
        }
        for (int i=numZero, j=numZero+1;j<n;i++,j++)
        {
            if (nums[i]==nums[j]) return false;
            gap += nums[j]-nums[i]-1;
        }
        if (numZero<gap) return false;
        return true;
    }
};
