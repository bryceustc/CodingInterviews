#include <iostream>
#include <vector>

using namespace std;

class Solution{
  public:
    int getDuplication(const vector<int> nums, int n){
      if ( nums.empty() || n <=0) return -1;
      int start = 1;
      int end = n -1;
      while(end >= start)
      {
        int k = 0;
        int mid = start + (end-start)/2;
        for (int i=0;i<n;i++)
        {
            if (nums[i]>=start && nums[i]<=mid)
            {
              m++;
            }
            if (m > mid)
            {
              end = mid;
            }
            else
            {
              start = mid + 1;
            }
        }
      }
      return start;
    }
};

int main()
{
    vector<int> nums = {2,3,5,4,3,2,6,7};
    int n = nums.size()-1;
    cout<<Solution().getDuplication(nums,n)<<endl;
    system("pause");
    return 0;
}
