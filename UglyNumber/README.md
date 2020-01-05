# 题目描述:丑数
## 题目：
把只包含质因子2、3和5的数称作丑数（Ugly Number）。求按从小到大的顺序的第N个丑数。例如6、8都是丑数，但14不是，因为它包含质因子7。 习惯上我们把1当做是第一个丑数。

# 本题考点：
  
  1). 丑数概念的理解
  
  2). 动态规划
  
  3). 最小堆
  
  
# 解题思路:
  此题与LeetCode第263题和264题丑数相关问题类似
  
  1.) 想要判断一个数的因子是否为2,3,5只需要判断对这个几个数进行取模看是否能够整除然后再除以这几个数，直到最后为1即是丑数，不是1则不为丑数。然后从1开始按照顺序判断每一个数是不是丑数。无法准确分析时间复杂度:至少O(n<sup>3</sup>),空间复杂度O(1)
  
  2.) 利用动态规划的思想，假设要找下标i对应的丑数dp[i],可以用i之前的所有丑数乘若干个2直到大于上一个丑数dp[i-1]，记此数为num1;同理用i之前的所有丑数乘若干个3直到大于上一个丑数dp[i-1]，记此数为num2；用i之前的所有丑数乘若干个5直到大于上一个丑数dp[i-1]，记此数为num3。这三个数中的最小数字就是第i个丑数dp[i]。其实没必要把i之前的所有丑数乘2或者乘3或者乘5。在i之前的丑数中，肯定存在一个丑数（下标记为index2），乘2以后正好大于i的上一个丑数dp[i-1],index2之前的丑数乘2都小于等于dp[i-1];我们只需要记录index2，每次直接用这个下标对应的数乘2就行，并且在下标不满足时更新下标。同理我们也要记录乘3和乘5对应的下标。时间复杂度:O(n),空间复杂度:O(n)
  
  3). 最小堆

# 代码

[C++](./UglyNumber.cpp)

[Python](./UglyNumber.py)

# C++:
## 方法一：按顺序判断(时间复杂度非常高，未通过OJ)
```c++
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
class Solution {
public:
    bool isUgly(int num)
    {
        if (num < 1)
            return false;
        while (num % 5 == 0)
        {
            num /= 5;
        }
        while (num % 3 == 0)
        {
            num /= 3;
        }
        while (num % 2 == 0)
        {
            num /= 2;
        }
        return num == 1;
    }
    int GetUglyNumber_Solution(int index) {
        if (index < 0)
            return 0;
        int i = 0;
        int number = 0;
        while (i<index)
        {
            number++;
            if (isUgly(number))
            {
                i++;
            }
        }
        return number;
    }
};


int main()
{
	int index = 6;
	int res = Solution().GetUglyNumber_Solution(index);
	cout << res << endl;
	system("pause");
	return 0;
}
```

## 方法二：动态规划
```c++
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
class Solution {
public:
    int GetUglyNumber_Solution(int n) {
    // 0-6的丑数分别为0-6
		if (n < 7)
			return n;
		vector<int>dp (n,0);
        dp[0]=1;
        int l_2 = 0;
        int l_3 = 0;
        int l_5 = 0;
        for (int i=1;i<n;i++)
        {
            dp[i] = My_min(dp[l_2]*2,dp[l_3]*3,dp[l_5]*5);
            while(dp[l_2]*2<=dp[i])
            {
                l_2++;
            }
            while(dp[l_3]*3<=dp[i])
            {
                l_3++;
            }
            while(dp[l_5]*5<=dp[i])
            {
                l_5++;
            }
        }
        return dp[n-1];
	}

    int My_min(int a, int b, int c)
    {
        int res = min(a,b);
        res = min(res,c);
        return res;
    }
};


int main()
{
	int index = 6;
	int res = Solution().GetUglyNumber_Solution(index);
	cout << res << endl;
	system("pause");
	return 0;
}
```

## 方法三：小顶堆
```c++
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
class Solution {
public:
    int nthUglyNumber(int n) {
        priority_queue<int,vector<int>,greater<int>> min; 
        //priority_queue<Type, Container, Functional>Type为数据类型，Container为保存数据的容器，Functional为元素比较方式。 如果不写后两个        // 参数，那么容器默认用的是vector，比较方式默认用operator<
        min.push(1);
        int res = 0;
        int num = 0;
        vector<int> temp;
        for (int i=0;i<n;i++)
        {
            res = min.top();
            min.pop();
            while (!min.empty() && res == num)
            {
                res = min.top();
                min.pop();
            }
            // temp.push_back(res*2);
            // temp.push_back(res*3); 
            // temp.push_back(res*5);
            // for (int i=0;i<3;i++)
            // {
            //     min.push(temp[i]);
            // }
            // num = res;
            // min.push(res*2);
            // min.push(res*3);
            // min.push(res*5);
        }
        return res;
    }
};


int main()
{
	int index = 6;
	int res = Solution().GetUglyNumber_Solution(index);
	cout << res << endl;
	system("pause");
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
