# 题目描述:数组中重复的数字

## 题目一：
在一个长度为n的数组里的所有数字都在0~n-1范围内。数组中某些数字是重复的，但不知道有几个数字重复了，也不知道每个数字重复了几次。
请找出数组中任意一个重复的数字。例如，如果输入长度为7的数组{2，3，1，0，2，5，3}，那么对应的输出是重复的数字2或者3

## 题目二：
在一个长度为n+1的数组里的所有数字都在1~n范围内。所以数组中至少有一个数是重复的。请找出数组中任意一个重复的数字，但不能修改输入的数组。
例如，输入长度为8的数组{2，3，5，4，3，2，6，7}，那么对应的输出是重复的数字2或者3。

# 本题考点：
  
  1). 一维数组的理解，一维数组在内存中占据连续空间，可以根据下标定位对应的元素
  
# 解题思路:
  1). 把输入的数组进行排序，排序后再判断有无重复数字，时间复杂度为O(n\*lgn)
  
  2). 使用哈希表来解决，时间复杂度为O(n)，但空间复杂度也为O(n)
  
  3). 第三种方法，把每个数字放回对应位置的方法。如果出现一个数字无法放回（所在位置已经是对应数字了），那么说明该数字重复

# 代码

[C++](DuplicationInArray.cpp)

## 方法一：排序后直接查找
```c++
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#include <iostream>
#include <vector>
#include <algorithm>
#include <tr1/unordered_map>
using namespace std;
using namespace std::tr1;


class Solution{
    public:
        bool Duplication2(vector<int> nums,int n, vector<int> &res){
            bool flag = false;
            if (nums.empty()||n<0) return false;
            for (int i = 0; i < n; i++)
            {
                if (nums[i] < 0 || nums[i] > n - 1)
                {
                    return false;
                }
            }
            sort(nums.begin(),nums.end());
            for (int i = 0; i < n-1; i++)
            {
                if (nums[i]==nums[i+1])
                {
                    res.push_back(nums[i]);
                    flag = true;
                }
            }
            return flag;
        }
};


int main()
{
    vector<int> nums = {2,3,1,0,2,5,3};
    int n = nums.size();
    vector<int> res;
    Solution().Duplication1(nums,n,res);
    int m = res.size();
    for (int i = 0; i < m; i++)
    {
        cout << res[i]<< endl;
    }
    system("pause");
    return 0;
}

```

## 方法二：利用哈希表
```c++
#include <iostream>
#include <vector>
#include <algorithm>
#include <tr1/unordered_map>
using namespace std;
using namespace std::tr1;

#include <iostream>
#include <vector>
#include <algorithm>
#include <tr1/unordered_map>
using namespace std;
using namespace std::tr1;


class Solution{
    public:
        bool Duplication2(vector<int> nums,int n, vector<int> &res){
            bool flag = false;
            if(nums.empty() || n < 0) return false;
            for (int i = 0; i < n; i++)
            {
                if (nums[i] < 0 || nums[i] > n-1)
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
};


int main()
{
    vector<int> nums = {2,3,1,0,2,5,3};
    int n = nums.size();
    vector<int> res;
    Solution().Duplication2(nums,n,res);
    int m = res.size();
    for (int i = 0; i < m; i++)
    {
        cout << res[i]<< endl;
    }
    system("pause");
    return 0;
}

```

## 方法三：
```c++
#include <iostream>
#include <vector>
#include <algorithm>
#include <tr1/unordered_map>
using namespace std;
using namespace std::tr1;


class Solution{
    public:
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
    vector<int> nums = {2,3,1,0,2,5,3};
    int n = nums.size();
    vector<int> res;
    Solution().Duplication3(nums,n,res);
    int m = res.size();
    for (int i = 0; i < m; i++)
    {
        cout << res[i]<< endl;
    }
    system("pause");
    return 0;
}
```

# 参考：
