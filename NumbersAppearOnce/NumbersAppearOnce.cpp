class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for (int i = 0; i < 32; i++)
        {
            int count = 0;
            for (auto n : nums)
            {
                if ((1 << i ) & n) 
                    count++;
            }
            if (count % 3) 
                ans += (1 << i);
        }
        return ans;
    }
};
