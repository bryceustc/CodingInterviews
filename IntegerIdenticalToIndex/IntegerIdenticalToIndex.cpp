class Solution {
public:
    int IntegerIdenticalToIndex(vector<int>& nums) {
        int n = nums.size();
        int res = 0;
        if (nums.empty())
            return 0;
        for (int i=0;i<n;i++)
        {
            if (nums[i]==i)
	    {
	    	res = nums[i];
		break;
	    }
        }
        return res;
    }
};

// C++ Solution 2:
class Solution {
public:
    int IntegerIdenticalToIndex(vector<int>& nums) {
        int res = 0;
        int n = nums.size();
        int start = 0;
	int end = n-1;
	while(end>=start)
	{
	    int mid = start + (end -start) /2;
	    if (nums[mid]==mid)
	    {
	    	res = mid;
		break;
	    }
	    if (nums[mid]>mid)
	    {
	    	end = mid-1;
	    }
	    else
	    {
	    	start = mid +1;
	    }
	}
        return res;
    }
};
