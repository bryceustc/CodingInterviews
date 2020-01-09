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
    int GetUglyNumber_Solution(int n) {
        priority_queue<long,vector<long>,greater<long>> min; 
        //priority_queue<Type, Container, Functional>Type为数据类型，Container为保存数据的容器，Functional为元素比较方式。 如果不写后两个        // 参数，那么容器默认用的是vector，比较方式默认用operator<
        min.push(1);
        long long int res = 0;
        long long int num = 0;
        for (int i=0;i<n;i++)
        {
            res = min.top();
            min.pop();
            while (!min.empty() && res == num)
            {
                res = min.top();
                min.pop();
            }
             num = res;
             min.push(res*2);
             min.push(res*3);
             min.push(res*5);
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
## 方法一：直接法(未通过OJ，超时)
```python
# -*- coding:utf-8 -*-
class Solution:
    def isUgly(self, num: int) -> bool:
        if num <1:
            return False
        while num%5 == 0:
            num//=5
        while num%3 == 0:
            num//=3
        while num%2 == 0:
            num//=2
        return num==1
    def GetUglyNumber_Solution(self, n: int) -> int:
        i = 0
        num = 0
        while i<n:
            num+=1
            if self.isUgly(num):
                i+=1
        return num

if __name__ == '_ main__':
    nums = 10
    res = Solution().GetUglyNumber_Solution(n)    
    print(res)
```

## 方法二：动态规划
```python
# -*- coding:utf-8 -*-
class Solution:
    def GetUglyNumber_Solution(self, n):
        # write code here
        if n<=0:
            return 0
        dp = [0 for _ in range(n)]
        dp[0] = 1
        l_2 = 0
        l_3 = 0
        l_5 = 0
        for i in range(1,n):
            dp[i] = min(dp[l_2]*2,dp[l_3]*3,dp[l_5]*5)
            if dp[l_2]*2<=dp[i]:
                l_2+=1
            if dp[l_3]*3<=dp[i]:
                l_3+=1
            if dp[l_5]*5<=dp[i]:
                l_5+=1
        return dp[n-1]


if __name__ == '_ main__':
    nums = 10
    res = Solution().GetUglyNumber_Solution(n)    
    print(res)
```
## 方法三：小顶堆
```python
# -*- coding:utf-8 -*-
class Solution:
    def GetUglyNumber_Solution(self, n):
        # write code here
        import heapq
        if n<=0:
            return 0
        res = 0
        min_heap = []
        heapq.heappush(min_heap,1)
        for i in range (n):
            res = heapq.heappop(min_heap)
            while min_heap and res == min_heap[0]:
                res = heapq.heappop(min_heap)
            heapq.heappush(min_heap,res*2)
            heapq.heappush(min_heap,res*3)
            heapq.heappush(min_heap,res*5)
        return res


if __name__ == '_ main__':
    nums = 10
    res = Solution().GetUglyNumber_Solution(n)    
    print(res)
```



# 参考：
  -  [LeetCode_263题——丑数](https://github.com/bryceustc/LeetCode_Note/blob/master/cpp/Ugly-Number/README.md)
  -  [LeetCode_263题——丑数II](https://github.com/bryceustc/LeetCode_Note/blob/master/cpp/Ugly-Number-II/README.md)
