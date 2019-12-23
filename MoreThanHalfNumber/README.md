# 题目描述:数组中出现次数超过一半的数字

## 题目：
数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。例如输入一个长度为9的数组{1,2,3,2,2,2,5,4,2}。由于数字2在数组中出现了5次，超过数组长度的一半，因此输出2。如果不存在则输出0。

# 本题考点：
  
  1). 思维能力找规律
  
  
# 解题思路:
  1). 寻找边界条件，寻找最小元素，首先设定上下左右边界,其次向右移动到最右，此时第一行因为已经使用过了，可以将其从图中删去，体现在代码中就是重新定义上边界,判断若重新定义后，上下边界交错，表明螺旋矩阵遍历结束，跳出循环，返回答案,若上下边界不交错，则遍历还未结束，接着向下向左向上移动，操作过程与第一，二步同理,不断循环以上步骤，直到某两条边界交错，跳出循环，返回答案,时间复杂度为O(n)

# 代码

[C++](MoreThanHalfNumber.cpp)

[Python](MoreThanHalfNumber.py)

# C++:
```c++
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> printMatrix(vector<vector<int>> matrix) {
        vector<int> res;
        if (matrix.empty()) return res;
        int m = matrix.size();
        int n = matrix[0].size();
        int u = 0;
        int d = m-1;
        int l = 0;
        int r = n-1;
        while(true)
        {
          for (int i=l;i<=r;i++) res.push_back(matrix[u][i]);//向右移动至最右
          if (++u > d) break;//重新定义上边界
          for (int i=u;i<=d;i++) res.push_back(matrix[i][r]);//向下
          if (--r < l) break;//重新定义右边界
          for (int i=r;i>=l;i--) res.push_back(matrix[d][i]);//向左
          if (--d < u) break;//重新定义下边界
          for (int i=d;i>=u;i--) res.push_back(matrix[i][l]);//向上
          if (++l > r) break;//重新定义左边界
        }
        return res;
    }
};


int main()
{
    vector<vector<int>> nums = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
    vector<vector<int>> res;
    res = Solution().printMatrix(nums);
    for (int i=0;i<res.size()i++)
    {
        cout<< res[i] <<endl;
    }
    system("pause");
    return 0;
}

```

# Python:
```python
# -*- coding:utf-8 -*-
class Solution:
    def printMatrix(self, matrix):
        res = []
        m = len(matrix)
        if m==0:
            return res
        n = len(matrix[0])
        u = 0
        d = m-1
        l = 0
        r = n-1
        while (true):
            for i in range(l,r+1):
                res.append(matrix[u][i])
            u+=1
            if u>d:
                break
            for i in range(u,d+1):
                res.append(matrix[i][r])
            r-=1
            if r<l:
                break
            for i in range(r,l-1,-1):
                res.append(matrix[d][i])
            d-=1
            if d<u:
                break
            for i in range(d,u-1,-1):
                res.append(matrix[i][l])
            l+=1
            if l>r:
                break
        return res


if __name__ == '_ main__':
    nums = [[1,2,3,4],[5,6,7,8,[9,10,11,12],[13,14,15,16]]
    res = Solution().printMatrix(nums)
    print(res)
```

# 参考：
   - [LeetCode旋转矩阵](https://github.com/bryceustc/LeetCode_Note/blob/master/cpp/Spiral-Matrix/README.md) 


