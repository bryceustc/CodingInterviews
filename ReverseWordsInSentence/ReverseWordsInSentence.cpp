// Solution 1:
class Solution {
public:
    string ReverseSentence(string s) {
        string res="";
        int n = s.size();
        if (n==0)
            return res;
        if (n==1)
            return s;
        for (int i=n,j=n-1;j>=0;j--)
        {
            if (s[j]==' ')
            {
                for(int k=j+1;k<i;k++)
                {
                    res+=s[k];
                }
                res += s[j];
                i=j;
            }
            if (j==0 && res!="")
            {
                for (int x=j;x<i;x++)
                {
                    res+=s[x];
                }
            }
            if (j==0 && res=="")
            {
                res = s;
            }
        }
        return res;
    }
};
// Solution 2:
class Solution {
public:
    void Reverse(string &s, int start,int end)
    {
        while(start<end)
        {
            swap(s[start],s[end]);
            start++;
            end--;
        }
    }
    string ReverseSentence(string s) 
    {
        string res;
        int n = s.size();
        // 整体翻转整个句子
        Reverse(s,0,n-1);
        int i=0;
        int start = 0;
        int end = 0;
        while(i<n)
        {
            while(i<n && s[i]==' ') i++;
            start = end = i;
            while(i<n && s[i]!=' ')
            {
                i++;
                end++;
            }
            Reverse(s,start,end-1);
        }
        return s;
    }
};
