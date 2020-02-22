class Solution {
public:
    bool VerifySquenceOfBST(vector<int> sequence) {
        bool res = false;
        if (sequence.empty())
            return res;
        int n = sequence.size();
        res = helper(sequence,0,n-1);
        return res;
    }
    bool helper(vector<int> seq, int start, int end)
    {
        if (seq.empty() || start > end)
        {
            return false;
        }
        //根结点
        int root = seq[end];
        
        //在二叉搜索树中左子树的结点小于根结点
        int i = start;
        for (;i<end;i++)
        {
            if (seq[i]>root)
                break;
        }
        
        //在二叉搜索书中右子树的结点大于根结点
        for (int j =i;j<end;j++)
        {
            if (seq[j]<root)
                return false;
        }
        
        //判断左子树是不是二叉搜索树
        bool left = true;
        if (i>start)
        {
            left = helper(seq, start, i-1);
        }
        
        //判断右子树是不是二叉搜索树
        bool right = true;
        if (i < end-1)
        {
            right = helper(seq, i, end-1);
        }
        return left && right;
    }
};
