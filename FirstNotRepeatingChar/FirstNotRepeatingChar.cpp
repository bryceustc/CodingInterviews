class Solution {
public:
    int FirstNotRepeatingChar(string s) {
        int res = -1;
        int n = s.size();
        if (n==0) return res;
        unordered_map<char,int> m;
        for (int i=0;i<n;i++)
        {
            m[s[i]]++;
        }
        for (int i=0;i<n;i++) 
        {
            if (m[s[i]]==1)
            {
                return i;
            }
        }
        return res;
    }
};
