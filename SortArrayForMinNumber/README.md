# 题目描述:把数组排成最小的数
## 题目：
输入一个正整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一个。例如输入数组{3，32，321}，则打印出这三个数字能排成的最小数字为321323。

# 本题考点：
  
  1). 定义一个新的比较规则来排序数组
  
  2). 证明规则是有效，数学功底和逻辑思维能力
  
  3). 大数问题，两个int型整数拼接数字可能超过int型数字能够表达的范围，从而导致数字溢出，用字符串表示数字
  
  
# 解题思路:
  此题与LeetCode第179题求最大数问题类似，都是要定义一个新的排序规则
  
  主要就是要给数组进行排序，但是排序方法不是普通的升序或者降序，对于两个数字a和b来说，如果将其都转为字符串，如果 ab < ba，则a排在前面，比如9和34，由于 934<349，所以34排在前面，再比如说 2 和3，由于 23<32，所以2排在 3 的前面。按照这种规则对原数组进行排序后，将每个数字转化为字符串再连接起来就是最终结果。时间复杂度:O(nlogn),空间复杂度O(n)

  排序规则数学证明：
  ![1](https://github.com/bryceustc/CodingInterviews/blob/master/SortArrayForMinNumber/Images/1.png)
  ![2](https://github.com/bryceustc/CodingInterviews/blob/master/SortArrayForMinNumber/Images/2.png)
  ![3](https://github.com/bryceustc/CodingInterviews/blob/master/SortArrayForMinNumber/Images/3.png)

# 代码

[C++](./SortArrayForMinNumber.cpp)

[Python](./SortArrayForMinNumber.py)

# C++:
## 自定义排序规则
```c++
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
```

# Python:
## python sorted函数自定义排序规则，python 2 的sorted各参数的用法
```python
# -*- coding:utf-8 -*-
class Solution:
    def PrintMinNumber(self, nums):
        # write code here
        res = ""
        #map(str,nums)
        nums=sorted(nums,cmp=self.compare)
        for num in nums:
            res+=str(num)
        return res
    def compare(self,a,b):
        sa = str(a)
        sb = str(b)
        if sa+sb < sb+sa: ### cmp,小于返回-1，大于返回1，等于返回0
            return -1
        return 1

if __name__ == '_ main__':
    nums = [3,2,1]
    res = Solution().PrintMinNumber(nums)    
    print(res)
```

## python sorted函数自定义排序规则
```python
# -*- coding:utf-8 -*-
class Solution:
    def PrintMinNumber(self, nums):
        # write code here
        res = ""
        nums = map(str,nums)
        nums=sorted(nums,lambda x, y: cmp(x+y,y+x))
        res = ''.join(nums)
        return res

if __name__ == '_ main__':
    nums = [3,2,1]
    res = Solution().PrintMinNumber(nums)    
    print(res)
```




# 参考：
   - [LeetCode-179最大数](https://github.com/bryceustc/LeetCode_Note/blob/master/cpp/Largest-Number/README.md)
   - [C++中 string对象的大小比较](https://blog.csdn.net/jason_cuijiahui/article/details/79038468)
  - [C++ algorithm sort自定义排序](https://blog.csdn.net/v_xchen_v/article/details/76615270)
  - [关于类中重载sort函数的报错问题（解决error: invalid use of non-static member function 'bool Solution::cmp(int, int)'）](https://blog.csdn.net/qq_41562704/article/details/95908736)
  - [python3与python2的不同定义排序](https://leetcode-cn.com/problems/largest-number/solution/python3yu-python2de-bu-tong-ding-yi-pai-xu-by-jixi/)
  - [Python3: 找回sort()中消失的cmp参数](https://www.polarxiong.com/archives/Python3-%E6%89%BE%E5%9B%9Esort-%E4%B8%AD%E6%B6%88%E5%A4%B1%E7%9A%84cmp%E5%8F%82%E6%95%B0.html)
  - [Python map()函数用法](https://www.runoob.com/python/python-func-map.html)
  - [Python sorted()函数用法](https://www.runoob.com/python/python-func-sorted.html) 






