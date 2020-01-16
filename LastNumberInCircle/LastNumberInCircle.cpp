class Solution {
public:
    int LastRemaining_Solution(int n, int m)
    {
        int res =-1;
        if (n<=0 || m<0)
            return res;
        vector<int> nums;
        for (int i=0;i<=n;i++)
        {
            nums.push_back(i);
        }
        int start =0;
        while(nums.size()>1)
        {
            int end = (start+m-1)%(nums.size());
            nums.erase(nums.begin()+end);
            start = end;
        }
        res = nums[0];
        return res;
    }
};
