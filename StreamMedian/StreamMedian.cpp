#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
class Solution {
public:
	int count = 0;   // count要声明为全局变量
	void Insert(int num) {
		if (count % 2 == 0) // 偶数放入最大堆
		{
			max.push(num);
			int max_num = max.top();
			max.pop();
			min.push(max_num);
		}
		else     // 奇数放入最小堆
		{
			min.push(num);
			int min_num = min.top();
			min.pop();
			max.push(min_num);
		}
		count++;
	}

	double GetMedian() {
		if (count % 2 == 0)
		{
			return ((max.top() + min.top()) / 2.0);
		}
		else
		{
			return (min.top());
		}

	}
private:
	priority_queue<int, vector<int>> max;  //大顶堆
	priority_queue<int, vector<int>, greater<int>> min;  // 小顶堆
};

int main()
{
	Solution* obj = new Solution();
	obj->Insert(5);
	obj->Insert(2);
	obj->Insert(3);
	double res = obj->GetMedian();
	cout << res << endl;
	system("pause");
	return 0;
}

//  Solution 2:
class Solution {
public:
	vector<double> store;
	void Insert(int num)
	{
		store.push_back(num);
	}

	double GetMedian()
	{
		sort(store.begin(), store.end());
		int n = store.size();
		if (n % 2 == 0)
		{
			return((store[n / 2] + store[n / 2 - 1]) / 2.0);
		}
		else
		{
			return (store[n / 2]);
		}
	}
};


// Solution 3：
class Solution {
public:
	vector<double> store;
	void Insert(int num)
	{
    	    if (store.empty())
		  store.push_back(num);
    	    else
      		  store.insert(lower_bound(store.begin(),store.end(),num),num);
	}

	double GetMedian()
	{
		int n = store.size();
		if (n % 2 == 0)
		{
			return((store[n / 2] + store[n / 2 - 1]) / 2.0);
		}
		else
		{
			return (store[n / 2]);
		}
	}
};
