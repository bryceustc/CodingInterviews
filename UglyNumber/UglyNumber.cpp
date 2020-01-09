// C++ Solution 1:
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
// C++ Solution 2:
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
// C++ Solution 3:
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
