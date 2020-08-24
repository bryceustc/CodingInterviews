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
