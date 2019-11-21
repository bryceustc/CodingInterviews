#include <iostream>
#include <vector>
#include <algorithm>
#include <tr1/unordered_map>
using namespace std;
using namespace std::tr1;


class Solution{
    public:
        bool Duplication1(vector<int> nums,int n, vector<int> &res){
            bool flag = false;
            if(nums.empty() || n < 0) return false;
            for (int i = 0; i < n; i++)
            {
                if (nums[i] < 1 || nums[i] > n)
                {
                    return false;
                } 
            }
            
            unordered_map<int,int> m;
            for (auto i : nums)
            {
                m[i]++;
                if(m[i]>1)
                {
                    res.push_back(i);
                    flag = true;
                }
            }
            return flag;
        }
        bool Duplication2(vector<int> nums,int n, vector<int> &res){
            bool flag = false;
            if (nums.empty()||n<1) return false;
            for (int i = 0; i < n; i++)
            {
                if (nums[i] < 1 || nums[i] > n )
                {
                    return false;
                }
            }
            sort(nums.begin(),nums.end());
            for (int i = 0; i < n; i++)
            {
                if (nums[i]==nums[i+1])
                {
                    res.push_back(nums[i]);
                    flag = true;
                }
            }
            return flag;
        }

        bool Duplication3(vector<int>nums,int n,vector<int> &res){
            bool flag = false;
            //异常值检测
            if (nums.empty() || n <= 0) return false;

            //越界检测
            for (int i = 0; i< n; i++)
            {
                if (nums[i]< 0 || nums[i] > n-1) 
                {
                    return false;
                }
                
            }
            for (int i = 0; i < n; i++)
            {
                //只要当前数值与索引不等，就要一直替换
                while (nums[i]!=i)
                {
                    //一旦遇到当前的数值与另外一个换位的值相等，就停止，说明找到了重复的数字
                    if (nums[i] == nums[nums[i]])
                    {
                        res.push_back(nums[i]);
                        break;
                        flag = true;  //return直接跳出所有循环
                    }
                    int temp = nums[i];
                    nums[i] = nums[temp];
                    nums[temp] = temp;
                }               
            }
            return flag;            
        }
};


int main()
{
    vector<int> nums = {2,3,5,4,3,2,6,7};
    int n = nums.size()-1;
    vector<int> res;
    //Solution().Duplication1(nums,n,res);
    Solution().Duplication2(nums,n,res);
    //Solution().Duplication3(nums,n,res);
    int m = res.size();
    for (int i = 0; i < m; i++)
    {
        cout << res[i]<< endl;
    }
    for (int i = 0; i < n+1; i++)
    {
        cout << nums[i] << endl;
    }
    
    system("pause");
    return 0;
}
