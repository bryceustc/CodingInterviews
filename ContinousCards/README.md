# 题目描述:和为S的连续正数序列
## 题目：
LL今天心情特别好,因为他去买了一副扑克牌,发现里面居然有2个大王,2个小王(一副牌原本是54张)... 他随机从中抽出了5张牌,想测测自己的手气,看看能不能抽到顺子,如果抽到的话,他决定去买体育彩票,嘿嘿！！“红心A,黑桃3,小王,大王,方片5”,“Oh My God!”不是顺子.....LL不高兴了,他想了想,决定大\小 王可以看成任何数字,并且A看作1,J为11,Q为12,K为13。上面的5张牌就可以变成“1,2,3,4,5”(大小王分别看作2和4),“So Lucky!”。LL决定去买体育彩票啦。 现在,要求你使用这幅牌模拟上面的过程,然后告诉我们LL的运气如何， 如果牌能组成顺子就输出true，否则就输出false。为了方便起见,你可以认为大小王是0。
# 本题考点：
  
  1). 双指针
  
# 解题思路:
  
  1.) 双指针。时间复杂度:O(n),空间复杂度:O(n)

# 代码

[C++](./ContinousCards.cpp)

[Python](./ContinousCards.py)

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

