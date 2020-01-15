# 题目描述:扑克牌顺子
## 题目：
LL今天心情特别好,因为他去买了一副扑克牌,发现里面居然有2个大王,2个小王(一副牌原本是54张)... 他随机从中抽出了5张牌,想测测自己的手气,看看能不能抽到顺子,如果抽到的话,他决定去买体育彩票,嘿嘿！！“红心A,黑桃3,小王,大王,方片5”,“Oh My God!”不是顺子.....LL不高兴了,他想了想,决定大\小 王可以看成任何数字,并且A看作1,J为11,Q为12,K为13。上面的5张牌就可以变成“1,2,3,4,5”(大小王分别看作2和4),“So Lucky!”。LL决定去买体育彩票啦。 现在,要求你使用这幅牌模拟上面的过程,然后告诉我们LL的运气如何， 如果牌能组成顺子就输出true，否则就输出false。为了方便起见,你可以认为大小王是0。
# 本题考点：
  
  1). 双指针
  
# 解题思路:
  
  1.) 注意理解题意，输入为5个数字的数组，判断是否是一个顺子序列。以大小王为0,0可以代替任何数字。先对序列进行排序，然后算数组中0的个数，然后计算差值，如果后面一个数比前面一个数大于1以上，那么中间的差值就必须用0来补了，计算数组空缺总数，如果空缺总数大于0的个数，不是顺子，否则是顺子。注意如果5张牌发现有 对子，肯定不是顺子
  时间复杂度:O(n),空间复杂度:O(n)

# 代码

[C++](./ContinousCards.cpp)

[Python](./ContinousCards.py)

# C++:
```c++
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool IsContinuous( vector<int> nums ) {
        int n = nums.size();
        if (nums.empty()|| n!=5)
            return false;
        sort(nums.begin(),nums.end());
        int numZero = 0;
        int gap = 0;
        for (int i=0;i<n;i++)
        {
            if (nums[i]==0)
                numZero++;
        }
        for (int i=numZero, j=numZero+1;j<n;i++,j++)
        {
            if (nums[i]==nums[j]) return false;
            gap += nums[j]-nums[i]-1;
        }
        if (numZero<gap) return false;
        return true;
    }
};

int main()
{
    vector<int> nums = {1,3,0,7,0};
    bool res;
    res = Solution().IsContinuous(nums);
    cout << res << endl;
    system("pause");
    return 0;
}
```

# Python:
```python
# -*- coding:utf-8 -*-
class Solution:
    def IsContinuous(self, nums):
        # write code here
        n = len(nums)
        if nums is None or n!=5:
            return False
        nums = sorted(nums)
        numZero = 0
        gap = 0
        for num in nums:
            if num ==0:
                numZero+=1
        for i in range(numZero,n-1):
            j=i+1
            if nums[j]==nums[i]:
                return False
            gap += nums[j]-nums[i]-1
        if gap > numZero:
            return False
        return True

if __name__ == '_ main__':
    nums = [1,3,0,7,0]
    res = Solution().IsContinuous(nums)    
    print(res)
```
