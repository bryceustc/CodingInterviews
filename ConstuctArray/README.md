# 题目:构建乘积数组
## 题目描述：
给定一个数组A[0, 1, …, n-1]，请构建一个数组B[0, 1, …, n-1]，其中B中的元素B[i] =A[0]×A[1]×… ×A[i-1]×A[i+1]×…×A[n-1]。不能使用除法。
# 本题考点：
  
  约瑟夫环问题
  
# 解题思路:
  
  1.) 模拟法。B[i]公式中没有A[i]项，也就是说如果可以使用除法，就可以用公式B[i]=A[0]\*A[1]\*.....\*A[n-1]/A[i]来计算B[i]，但是题目要求不能使用，因此我们可以直观的用连乘n-1个数字得到B[i]。时间复杂度:O(n<sup>2<\sup>),空间复杂度:O(n)
  
  2.) 上三角与下三角连乘，可以把B[i]=A[0]\*A[1]\*.....\*A[i-1]\*A[i+1]\*.....\*A[n-1]。看成A[0]\*A[1]\*.....\*A[i-1]和A[i+1]\*.....A[n-2\*A[n-1]两部分的乘积。
  
  即通过A[i]项将B[i]分为两部分的乘积。效果如下图所示
  ![image](https://github.com/bryceustc/CodingInterviews/blob/master/ConstuctArray/Image/image.png)
  
  不妨设定C[i]=A[0]\*A[1]\*...\*A[i-1]，D[i]=A[i+1]\*...\*A[n-2]\*A[n-1]。C[i]可以用自上而下的顺序计算出来，即C[i]=C[i-1]\*A[i-1]。类似的，D[i]可以用自下而上的顺序计算出来，即D[i]=D[i+1]\*A[i+1]。
# 代码

[C++](./ConstuctArray.cpp)

[Python](./ConstuctArray.py)

# C++:
```c++
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> multiply(const vector<int>& A) {
        if (A.empty())
            return {};
        int n = A.size();
        vector<int> B (n,0);
        for (int i =0;i<n;i++)
        {
            int temp = 1;
            for (int j=0;j<n;j++)
            {
                if (j==i)
                    continue;
                temp *=A[j];
            }
            B[i] = temp;
        }
        return B;
    }
};

int main()
{
    vector<int> A = {0,1,2,3,4}; // n=5
    vector<int> B;
    B = Solution().multiply(A);
    for (int i=0;i<B.size();i++)
    {
        cout << B[i] << endl;
    }
    system("pause");
    return 0;
}
```

# Python:
```python
# -*- coding:utf-8 -*-
class Solution:
    def LastRemaining_Solution(self, n, m):
        # write code h;
        res = -1
        if n<=0 or m<0:
            return res
        nums =range(n)## 0-n-1数组
        start=0
        while len(nums)>1:
            end = (start+m-1)%(len(nums))
            del nums[end]
            start = end
        return nums[0]

if __name__ == '_ main__':
    n=5
    m=3
    res = Solution().LastRemaining_Solution(n,m)    
    print(res)
```
