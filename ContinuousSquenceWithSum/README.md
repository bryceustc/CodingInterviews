# 题目描述:和为S的连续正数序列
## 题目：
小明很喜欢数学,有一天他在做数学作业时,要求计算出9~16的和,他马上就写出了正确答案是100。但是他并不满足于此,他在想究竟有多少种连续的正数序列的和为100(至少包括两个数)。没多久,他就得到另一组连续正数和为100的序列:18,19,20,21,22。现在把问题交给你,你能不能也很快的找出所有和为S的连续正数序列? Good Luck!

# 本题考点：
  
  1). 双指针
  
# 解题思路:
  
  1.) 双指针。时间复杂度:O(n),空间复杂度:O(n)

# 代码

[C++](./ContinuousSquenceWithSum.cpp)

[Python](./ContinuousSquenceWithSum.py)

# C++:
## 方法一：暴力遍历
```c++
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int> > FindContinuousSequence(int target) {
        //存放结果
        vector<vector<int>> res;
        //两个起点，相当于动态窗口的两边，根据其窗口内的值的和来确定窗口的位置和大小
        int low = 1;
        int high = 2;
        int sum = 3;
        while (high>low)
        {
            //由于是连续的，差为1的一个序列，那么求和公式是(a0+an)*n/2
            sum = (low+high)*(high-low+1)/2;
            //相等，那么就将窗口范围的所有数添加进结果集
            if (sum==target)
            {
                vector<int> out;
                for (int i=low;i<=high;i++)
                {
                    out.push_back(i);
                }
                res.push_back(out);
                low++;
            }
            //如果当前窗口内的值之和大于sum，那么左边窗口右移一下
            if (sum > target)
            {
                low++;
            }
            //如果当前窗口内的值之和小于sum，那么右边窗口右移一下
            if (sum < target)
            {
                high++;
            }
        }
        return res;
    }
};

int main()
{
    int target = 100;
    vector<vector<int> >res;
    res = Solution().FindContinuousSequence(target);
    system("pause");
    return 0;
}
```

# Python:
## 方法一：双指针
```python
# -*- coding:utf-8 -*-
class Solution:
    def FindContinuousSequence(self, target):
        # write code here
        res = []
        low = 1
        high = 2
        Sum = 3
        while high > low:
            Sum = (high+low)*(high-low+1)//2
            if Sum == target:
                out = []
                for i in range(low,high+1):
                    out.append(i)
                res.append(out[:])
                low+=1
            if Sum > target:
                low+=1
            if Sum < target:
                high+=1
        return res

if __name__ == '_ main__':
    target = 100
    res = Solution().FindContinuousSequence(target)    
    print(res)
```

# 参考：
  -  [剑指offer五十七题——和为s的两个数字](https://github.com/bryceustc/CodingInterviews/blob/master/TwoNumbersWithSum/README.md)
