class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> res (2,0);
        int number = 0;
        int n = nums.size();
        for (int i=0;i<n;i++)
        {
            number ^= nums[i];
        }
        // lowbit1 : 是二进制表达式中最低位的 1 所对应的值
        int lowbit1 = number&(-number);
        for (int num : nums)
        {
            if ((num & lowbit1) == lowbit1)
            {
                res[0] ^= num;
            }
            else
            {
                res[1]^= num;
            }
        }
        return res;
    }
};
