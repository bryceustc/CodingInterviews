#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> nums) {
        int res = nums[0];
        int n = nums.size();
        //dp[i]表示nums中以nums[i]结尾的最大子序和
        vector<int> dp(n);
        dp[0] = nums[0];
        for (int i=1;i<n;i++)
        {
            dp[i] = max(dp[i-1]+nums[i],nums[i]);
            res = max(res,dp[i]);
        }
        return res;
    }
};

int main()
{
    vector<int> nums = {-2,1,4};
    int res = Solution().FindGreatestSumOfSubArray(nums);
    cout << res << endl;
    system ("pause");
    return 0;
}

// C++ Solution 1:
class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> nums) {
        int res = nums[0];
        int n = nums.size();
        int dp= nums[0];
        for (int i=1;i<n;i++)
        {
            dp = max(dp+nums[i],nums[i]);
            res = max(res,dp);
        }
        return res;
    }
};

// C++ Solution 2:
class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> nums) {
        int res = nums[0];
        int n = nums.size();
        int sum = nums[0];
        for (int i=1;i<n;i++)
        {
            if (sum > 0)
                sum+=nums[i];
            else
                sum = nums[i];
            res = max(res,sum);
        }
        return res;
    }
};

// C++ Solution 3:
class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int>& nums) 
    {
        int res = nums[0];
        int n = nums.size();
        res = maxSubArrayHelper(nums,0,n-1);
        return res;
    }
    
    int maxSubArrayHelper(vector<int> &nums, int left, int right)
    {
        if (left == right)
        {
            return nums[left];
        }
        int mid = (left + right)/2;
        int leftSum = maxSubArrayHelper(nums,left,mid);
        //注意这里应是mid + 1，否则left + 1 = right时，会无限循环
        int rightSum = maxSubArrayHelper(nums,mid+1,right);
        int midSum = findMaxCrossingSubarray(nums,left,mid,right);
        int res = max(leftSum,rightSum);
        res = max(res,midSum);
        return res;
    }

    int findMaxCrossingSubarray(vector<int> &nums, int left, int mid, int right)
    {
        int leftSum = nums[mid];
        int sum = 0;
        for (int i = mid; i >= left; i--)
        {
            sum += nums[i];
            leftSum = max(leftSum, sum);
        }
        int rightSum = nums[mid+1];
        sum = 0;
        //注意这里i = mid + 1，避免重复用到nums[i]
        for (int i = mid + 1; i <= right; i++)
        {
            sum += nums[i];
            rightSum = max(rightSum, sum);
        }
        return (leftSum + rightSum);
    }
};

// C++ Solution 4:
class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> nums) {
        int res = nums[0];
        int n = nums.size();
        for (int i=0;i<n;i++)
        {
            int sum = 0;
            for (int j=i;j<n;j++)
            {
                sum+=nums[j];
                res = max(sum,res);
            }
        }
        return res;
    }
};
