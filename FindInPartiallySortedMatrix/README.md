# 题目描述:二维数组中的查找

## 题目：
在一个二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。请完成一个函数，输入这样的一个二维数组和一个整数，
判断数组中是否含有该整数

# 本题考点：
  
  1). 一维数组的理解，一维数组在内存中占据连续空间，可以根据下标定位对应的元素
  
# 解题思路:
  1). 直接暴力遍历二维数组所有元素，时间复杂度为O(m\*n)
  
  2). 

# 代码

[C++](FindInPartiallySortedMatrix.cpp)

[Python](FindInPartiallySortedMatrix.py)

# C++:
## 方法一：暴力遍历
```c++
#include <iostream>
#include <vector>
#include <algorithm>
#include <tr1/unordered_map>
using namespace std;
using namespace std::tr1;


class Solution{
    public:
        bool Find(vector<vector<int>> &nums,int target)
        {
            if (nums.empty()) return false;
            int n = nums.size();       
            int m = nums[0].size();
            for (int i=0;i<m;i++)
            {
                for (int j=0;j<n;j++)
                {
                    if (nums[i][j]==target)
                    {
                        return true;
                    }                    
                }
            }
            return false;          
        }
};


int main()
{
    vector<vector<int>> nums = {{1,2,3},{4,5,6},{7,8,9}};
    int target = 5;
    bool res;
    res = Solution().Find(nums,target);
    cout<< res <<endl;
    system("pause");
    return 0;
}

```

# Python:
## 方法一：暴力遍历：
```python

```


# 参考：
 - [循环结构中break、continue、return和exit的区别](https://blog.csdn.net/hunanchenxingyu/article/details/8101795)
