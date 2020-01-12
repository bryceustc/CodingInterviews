class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int res = 0;
        if (nums.empty())
            return 0;
        unordered_map<int,int> map;
        for (int i=0;i<n;i++)
        {
            map[nums[i]]++;
        }
        for (int num=0;num<=n;num++)
        {
            if (map[num]==0)
                return num;
        }
        return res;
    }
};

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int res = 0;
        int n = nums.size();
        unordered_set<int> set;
        for(auto num : nums)
        {
            set.insert(num);
        }
        for (int i=0;i<=n;i++)
        {
            if (set.count(i)==0)
            {
                res = i;
                break;
            }
        }
        return res;
    }
};
// C++ Solution 2:
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int res =0;
        int n = nums.size();
        int sum_num = 0;
        int Sum = 0;
        for (int i=0;i<n;i++)
        {
            sum_num+=nums[i];
        }
        for (int i=0;i<=n;i++)
        {
            Sum += i;
        }
        res = Sum - sum_num;
        return res;
    }
};


class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int res = n;
        for (int i = 0; i < n; i++)
        {
            res ^= nums[i];
            res ^= i;
            // 异或满足交换律，i和nums[i]是肯定有重复的，剩下的只有一个那就是nums中缺失的
        }
        return res;
    }
};
// C++ Solution 3:
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int res = 0;
        if (nums[n-1]!=n)
        {
            return n;
        }
        for (int i=0;i<n;i++)
        {
            if (nums[i]!=i)
            {
                res = i;
                break;
            }
        }
        return res;
    }
};
