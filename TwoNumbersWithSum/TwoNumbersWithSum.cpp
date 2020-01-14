class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> nums,int target) {
        int n = nums.size();
        vector<int> res;
        if (nums.empty()) 
            return res;
        for(int i=0;i<n;i++)
        {
            for (int j=i+1;j<n;j++)
            {
                if (nums[i]+nums[j]==target)
                {
                    res.push_back(nums[i]);
                    res.push_back(nums[j]);
                    return res;
                }
            }
        }
        return res;
    }
};
// C++ Solution 2:
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector <int> res (2,0);
        if (numbers.empty())
            return res;
        int n = numbers.size();
        unordered_map<int,int> record;
        for (int i=0;i<n;i++)
        {
            int complement = target -numbers[i];
            if (record.find(complement)!=record.end())
            {
                res[0] = complement;
                res[1] = nums[i];
                break;
            }
            record[numbers[i]] = i;
        }
        return res;
    }
};
// C++ Solution 3:
class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> nums,int target) {
        vector<int> res;
        if(nums.empty())
            return res;
        int n =nums.size();
        int left=0;
        int right=n-1;
        while (right>left)
        {
            if (nums[left]+nums[right]==target)
            {
                res.push_back(nums[left]);
                res.push_back(nums[right]);
                break;
            }
            if (nums[left]+nums[right]>target)
            {
                right--;
            }
            else
                left++;
        }
        return res;
    }
};
