#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    string PrintMinNumber(vector<int> nums) 
    {
        string res;
        int n = nums.size();
        sort(nums.begin(),nums.end(),compare);
        for (int i=0;i<n;i++)
        {
            res+=to_string(nums[i]);
        }
        return res;
    }
    static bool compare(int a, int b)
    {
        string sa = to_string(a);
        string sb = to_string(b);
        return sa+sb < sb+sa;
    }
};

int main()
{
    vector<int> nums = {3,1,2};
    string res = Solution().PrintMinNumber(nums);
    cout << res << endl;
    system ("pause");
    return 0;
}
