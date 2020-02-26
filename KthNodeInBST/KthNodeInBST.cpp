class Solution {
public:
    int kthLargest(TreeNode* root, int k) {
        int res = 0;
        if (root == NULL || k<1)
        {
            return res;
        }
        vector<int> out;
        helper(root, out);
        int n = out.size();
        res = out[n-k];
        return res;
    }
    void helper(TreeNode* root, vector<int> &v)
    {
        if (root==NULL)
            return;
        helper(root->left, v);
        v.push_back(root->val);
        helper(root->right,v);
    }
}


class Solution {
public:
    int kthLargest(TreeNode* root, int k) {
        if (root == NULL || k<1)
        {
            return 0;
        }
        helper(root, k);
        return res;
    }
    void helper(TreeNode* root, int k)
    {
        if (root==NULL)
            return;
        helper(root->right, k);
        if (++count==k)
        {
            res = root->val;
            return;
        }
        helper(root->left, k);
    }
private:
    int res = 0;
    int count = 0;
};

class Solution {
public:
    int kthLargest(TreeNode* root, int k) {
        int n=0;
        stack<TreeNode*> s;
        TreeNode* p = root;
        while (!s.empty() || p!=NULL)
        {
            while(p!=NULL)
            {
                s.push(p);
                p = p->right;
            }
            p =s.top();
            s.pop();
            if (++n==k)
            {
                return p->val;
            }
            p = p->left;
        }
        return 0;
    }
};

