# 题目描述:圆圈中最后剩下的数字
## 题目：
每年六一儿童节,牛客都会准备一些小礼物去看望孤儿院的小朋友,今年亦是如此。HF作为牛客的资深元老,自然也准备了一些小游戏。其中,有个游戏是这样的:首先,让小朋友们围成一个大圈。然后,他随机指定一个数m,让编号为0的小朋友开始报数。每次喊到m-1的那个小朋友要出列唱首歌,然后可以在礼品箱中任意的挑选礼物,并且不再回到圈中,从他的下一个小朋友开始,继续0…m-1报数….这样下去….直到剩下最后一个小朋友,可以不用表演,并且拿到牛客名贵的“名侦探柯南”典藏版(名额有限哦!!)。请你试着想下,哪个小朋友会得到这份礼品呢？(注：小朋友的编号是从0到n-1)
如果没有小朋友，请返回-1
# 本题考点：
  
  1). 双指针
  
# 解题思路:
  
  1.) 注意理解题意，输入为5个数字的数组，判断是否是一个顺子序列。以大小王为0,0可以代替任何数字。先对序列进行排序，然后算数组中0的个数，然后计算差值，如果后面一个数比前面一个数大于1以上，那么中间的差值就必须用0来补了，计算数组空缺总数，如果空缺总数大于0的个数，不是顺子，否则是顺子。注意如果5张牌发现有 对子，肯定不是顺子
  时间复杂度:O(n),空间复杂度:O(n)

# 代码

[C++](./LastNumberInCircle.cpp)

[Python](./LastNumberInCircle.py)

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

