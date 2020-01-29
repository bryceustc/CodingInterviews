class Solution {
public:
    vector<string> Permutation(string str) {
        vector<string> res;
        int n = str.size();
        if (n==0) return res;
        // 数字排列时需要排序，不排序的话就重复了
        vector<int> visited(n,0);
        string out = "";
        DFS(str,res,0,visited,out);
        // 消除重复排列
        
        //unique只是去除（相邻）的重复元素，因此，为了去除重复的元素，应该，首先对数组/Vector进行排序，这样保证重复元素在相邻的位置。
        sort(res.begin(),res.end());
        // unique()函数将重复的元素放到vector的尾部 然后返回指向第一个重复元素的迭代器再用erase函数擦除从这个元素到最后元素的所有的元素
        res.erase(unique(res.begin(),res.end()),res.end());
        return res;
    }
    void DFS (string str,vector<string> &res, int level, vector<int> &visited,string &out)
    {
        int n = str.size();
        if (level == n)
        {
            res.push_back(out);
            return;
        }
        for (int i=0;i<n;i++)
        {
            if (i >=1 && str[i]==str[i-1]&&visited[i-1]==0)
                continue;
            if (visited[i]==1)
                continue;
            visited[i]=1;
            out += str[i];
            DFS(str,res,level+1,visited,out);
            out.pop_back();
            visited[i]=0;
        }
    }
};
