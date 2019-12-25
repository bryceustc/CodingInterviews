# 题目描述:最小的k个数

## 题目：
输入n个整数，找出其中最小的K个数。例如输入4,5,1,6,2,7,3,8这8个数字，则最小的4个数字是1,2,3,4,。

# 本题考点：
  
  1). 哈希表
  
  
# 解题思路:
  1). 对数组排序，然后返回，前k个数
  

# 代码

[C++](MoreThanHalfNumber.cpp)

[Python](MoreThanHalfNumber.py)

# C++:
## 方法一：利用sort排序  时间复杂度为O(nlogn)
```c++
#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

class Solution {
public:
   vector<int> KLeastNumbers(vector<int>& nums,int k ) 
    {
        vector<int> res;
        if (nums.empty()) return res; 
        int n = nums.size();
        if (k>n) return res;
        sort(nums.begin(),nums.end());
        for (int i=0;i<k;i++)
        {
            res.push_back(nums[i]);
        }
        return res;
    }
};


int main()
{
   vector<int> nums = {4,5,1,6,2,7,3,8};
   int k = 4;
    vector<int>  res;
    res = Solution().KLeastNumbers(nums,k);
    int n = res.size();
    for (int i = 0; i < n; i++)
    {
        cout<< res[i]<<endl;
    }
    system("pause");
    return 0;
}
```


## 方法二：利用STL容器 priority_queue 大顶堆/小顶堆   时间复杂度O（nlogk）

### 大顶堆 (优先输出大数据)：
```c++
#include <iostream>
#include <vector>
#include <queue>
#include<algorithm>
using namespace std;

class Solution {
public:
   vector<int> KLeastNumbers(vector<int>& nums,int k ) 
    {
        vector<int> res;
        int n = nums.size();
        if (nums.empty() || k>n) return res;
        priority_queue<int> q;    // 大顶堆 优先输出大数据
        for (auto num : nums)
        {
            q.push(num);
            if (q.size()>k)
            {
                q.pop();
            }
        }
        while(!q.empty())
        {
            res.push_back(q.top());
            q.pop();
        }
        return res;
    }
};


int main()
{
    vector<int> nums = {4,5,1,6,2,7,3,8};
    int k = 4;
    vector<int>  res;
    res = Solution().KLeastNumbers(nums,k);
    int n = res.size();
    for (int i = 0; i < n; i++)
    {
        cout<< res[i]<<endl;
    }
    system("pause");
    return 0;
}
```
### 小顶堆(优先输出小数据)：
```c++
#include <iostream>
#include <vector>
#include <queue>
#include<algorithm>
using namespace std;

class Solution {
public:
   vector<int> KLeastNumbers(vector<int>& nums,int k ) 
    {
        vector<int> res;
        int n = nums.size();
        if (nums.empty() || k>n) return res;
        priority_queue<int,vector<int>, greater<int>> q;    // 小顶堆 优先输出小数据
        for (auto num : nums)
        {
            q.push(num);
            if (q.size()>n-k)
            {
                res.push_back(q.top());
                q.pop();
            }
        }
        return res;
    }
};


int main()
{
    vector<int> nums = {4,5,1,6,2,7,3,8};
    int k = 4;
    vector<int>  res;
    res = Solution().KLeastNumbers(nums,k);
    int n = res.size();
    for (int i = 0; i < n; i++)
    {
        cout<< res[i]<<endl;
    }
    system("pause");
    return 0;
}
```

## 方法三：基于函数Partition   平均时间复杂度为O(n)
```c++
#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

class Solution {
public:
   vector<int> KLeastNumbers(vector<int>& nums,int k ) 
    {
        vector<int> res;
        int n = nums.size();
        if (nums.empty() || k>n) return res; 
        int start = 0;
        int end = n-1;
        int index = Partition(nums,n,start,end);
        while(index!=k-1)
        {
            if (index >k-1)
            {
                end = index - 1;
                Partition(nums,n,start,end);
            }
            else
            {
                start = index+1;
                Partition(nums,n,start,end);
            }
        }
        for(int i = 0;i<k;i++)
        {
            res.push_back(nums[i]);
        }
        return res;
    }
    int Partition(vector<int> &nums,int n, int start, int end)
    {
        if(nums.empty() || n <=0 || start<0 || end >=n)
            return -1;
        int index = RandInRange(start,end);
        int pos = start - 1;
        swap(nums[index],nums[end]);
        for (int i= start;i<=end;i++)
        {
            if(nums[i]<nums[end])
            {
                pos++;
                swap(nums[pos],nums[i]);
            }
        }
        pos++;
        swap(nums[pos],nums[end]);
        return pos;
    }
    
    int RandInRange(int start,int end)
    {
        int dis = end - start;
        if (dis ==0) return 0;
        srand((unsigned) time (NULL));
        int res = (rand() %dis +start);
        return res;
    }
};


int main()
{
   vector<int> nums = {4,5,1,6,2,7,3,8};
   int k = 4;
    vector<int>  res;
    res = Solution().KLeastNumbers(nums,k);
    int n = res.size();
    for (int i = 0; i < n; i++)
    {
        cout<< res[i]<<endl;
    }
    system("pause");
    return 0;
}
```

## 方法四：红黑树：multise集合 利用仿函数改变排序顺序   平均时间复杂度为O(nlogk)
```c++
#include <iostream>
#include <vector>
#include<algorithm>
#include<set>
using namespace std;

class Solution {
public:
   vector<int> KLeastNumbers(vector<int>& nums,int k ) 
    {
        vector<int> res;
        int n = nums.size();
        if (nums.empty() || k>n) return res; 
        //仿函数中的greater<T>模板，从大到小排序
        multiset<int, greater<int> > leastNums;
        vector<int>::iterator vec_it=nums.begin();
        for(;vec_it!=nums.end();vec_it++)
        {
            //将前k个元素插入集合
            if(leastNums.size()<k)
                leastNums.insert(*vec_it);
            else
            {
                //第一个元素是最大值
                multiset<int, greater<int> >::iterator greatest_it=leastNums.begin();
                //如果后续元素<第一个元素，删除第一个，加入当前元素
                if(*vec_it<*(leastNums.begin()))
                {
                    leastNums.erase(greatest_it);
                    leastNums.insert(*vec_it);
                }
            }
        }
        res = vector<int>(leastNums.begin(),leastNums.end());
    }
};


int main()
{
   vector<int> nums = {4,5,1,6,2,7,3,8};
   int k = 4;
    vector<int>  res;
    res = Solution().KLeastNumbers(nums,k);
    int n = res.size();
    for (int i = 0; i < n; i++)
    {
        cout<< res[i]<<endl;
    }
    system("pause");
    return 0;
}
```

# Python:
## 方法一：直接法
```python
# -*- coding:utf-8 -*-
class Solution:
    def KLeastNumbers(self, nums, k):
        # write code here
        res = []
        n = len(nums)
        if n==0 or n<k:
            return res
        nums=sorted(nums)
        for i in range(k):
            res.append(nums[i])
        return res

if __name__ == '_ main__':
    nums = [4,5,1,6,2,7,3,8]
    res = Solution().KLeastNumbers(nums)
    print(res)
```

## 方法二：
```python
# -*- coding:utf-8 -*-
class Solution:
    def KLeastNumbers(self, nums, k):
        # write code here
        res = []
        n = len(nums)
        if n==0 or n<k:
            return res
        nums=sorted(nums)
        for i in range(k):
            res.append(nums[i])
        return res

if __name__ == '_ main__':
    nums = [4,5,1,6,2,7,3,8]
    res = Solution().KLeastNumbers(nums)
    print(res)
```



# 参考：
   - [LeetCode-169多数元素](https://github.com/bryceustc/LeetCode_Note/blob/master/cpp/Spiral-Matrix/README.md)
   - [C/C++ | STL | 大顶堆 | 小顶堆 | std::priority_queue](https://blog.csdn.net/stone_fall/article/details/89010656) 
   - [【c++】STL里的priority_queue用法总结](https://blog.csdn.net/xiaoquantouer/article/details/52015928) 
   - [set/multiset用法详解](https://blog.csdn.net/longshengguoji/article/details/8546286) 
   - [std::set与std::multiset使用总结](https://blog.csdn.net/CV_Jason/article/details/83048406) 
   - [C++ multiset通过greater、less指定排序方式，实现最大堆、最小堆功能](https://www.cnblogs.com/ficow/p/10045777.html) 
   



