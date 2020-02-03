// C++ Solution 1:
class Solution {
public:
    void move(string &s)
    {
        int n = s.size();
        char temp = s[0];
        for (int i=0;i<n;i++)
        {
            if (i!=n-1)
                s[i]=s[i+1];
            else
                s[i]=temp;
        }
    }
    string LeftRotateString(string s, int n) {
        int m = s.size();
        if (m<n) return "";
        for (int i=0;i<n;i++)
        {
            move(s);
        }
        return s;
    }
};
// C++ Solution 2:
class Solution {
public:
    void Reverse(string &s，int i, int j)
    {
        while(i<j)
        {
            swap(s[i++],s[j--]);
        }
    }
    string LeftRotateString(string s, int n) {
        int m = s.size();
        if (m<n) return "";
        // 将字符分为两部分，一是移动的部分，二是剩余部分
        // 翻转需要移动的字符
        Reverse(s,0,n-1);
        // 翻转剩余部分字符
        Reverse(s,n,m-1);
        // 整体翻转
        Reverse(s,0,m-1);
        return s;
    }
};
// C++ Solution 3:
class Solution {
public:
    string LeftRotateString(string s, int n) {
        int m = s.size();
        if (m<n) return "";
        s+=s;
        int start = n%m;
        s = s.substr(start,m);
        return s;
    }
};
