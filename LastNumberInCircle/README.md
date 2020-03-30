## 题目:圆圈中最后剩下的数字
### 题目描述：
0,1，···n-1这n个数字排成一个圆圈，从数字0开始，每次从这个圆圈里删除第m个数字。求出这个圆圈里剩下的最后一个数字。
## 本题考点：
  
  约瑟夫环问题
  
## 解题思路:
  
  1.) 模拟法
  
  用数组列表模拟一下。创建一个数组存储0-n-1的数组，但数组长度大于1时，就计算end位置即为(start+m-1)%len(nums) ，删除该元素后然后start再等于之前end，最后数组中剩最后一个元素，返回nums[0]
  
  时间复杂度O(n),空间复杂度O(n)
  
  2.) 数学方法：
  
  将上述问题建模为函数 f(n, m)，该函数的返回值为最终留下的元素的序号。
  
  每删除一个元素，下一个元素成为最开始的头，相当于把数组向前移动m位。若已知n-1个人时，删除下标位置位f(n−1,m)，则n个人的时候，就是往后移动m位，(因为有可能数组越界，超过的部分会被接到头上，所以还要模n)，既f(n,m) = (f(n-1,m) + m) % n
  
  递归公式为：
  
$$
f(n, m)=(f(n-1, m)+m) \% n
$$
  
  时间复杂度O(n),空间复杂度O(n)
## 代码

[C++](./LastNumberInCircle.cpp)

[Python](./LastNumberInCircle.py)

### C++:
#### 方法一：模拟法
```c++
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int LastRemaining_Solution(int n, int m)
    {
        int res =-1;
        if (n<=0 || m<=0)
            return res;
        vector<int> nums;
        for (int i=0;i<n;i++)
        {
            nums.push_back(i);
        }
        int start =0;
        while(nums.size()>1)
        {
            int end = (start+m-1)%(nums.size());
            nums.erase(nums.begin()+end);  // vector插入删除操作时间复杂度是O(n) 
            start = end;
        }
        res = nums[0];
        return res;
    }
};

int main()
{
    int n = 5;
    int m = 3;
    int res = 0;
    res = Solution().LastRemaining_Solution(n,m);
    cout <<res << endl;
    return 0;
}
```
#### 方法二：数学法

迭代：空间复杂度O(1)
```c++
class Solution {
public:
    int lastRemaining(int n, int m) {
        int res = 0;
        for(int i=2;i<=n;i++)
        {
            res = (res+m)%i;
        }
        return res;
    }
};
```

递归：空间复杂度O(n)
```c++
class Solution {
public:
    int lastRemaining(int n, int m) {
        return f(n,m);
    }

    int f(int n, int m)
    {
        if (n==1)
        {
            return 0;
        }
        return (f(n-1,m) + m) %n;
    }
};
```
