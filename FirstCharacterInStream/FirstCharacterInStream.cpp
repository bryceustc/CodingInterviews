class Solution
{
public:
  //Insert one char from stringstream
    unordered_map<char,int> m;
    string s;
    void Insert(char ch)
    {
        s += ch;
        m[ch]++;
    }
  //return the first appearence once char in current stringstream
    char FirstAppearingOnce()
    {
        char res = '#';
        int n = s.size();
        for (int i=0;i<n;i++)
        {
            if (m[s[i]]==1)
                return s[i];
        }
        return res;
    }
};
