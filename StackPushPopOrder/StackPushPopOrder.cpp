class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        int n = pushV.size();
        int m = popV.size();
        if (n!=m) return false;
        stack<int> s;
        int index = 0;
        for (int i=0;i<n;i++)
        {
            s.push(pushV[i]);
            while(!s.empty() && s.top()==popV[index])
            {
                s.pop();
                index++;
            }
        }
        return s.empty();
    }
};
