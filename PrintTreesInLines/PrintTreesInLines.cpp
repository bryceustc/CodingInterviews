// C++ Solution 1:
class Solution {
public:
        vector<vector<int> > Print(TreeNode* root) {
            vector<vector<int>> res;
            if (root==NULL)
                return res;
            queue<TreeNode*> q;
            q.push(root);
            while(!q.empty())
            {
                int count = q.size();
                vector<int> out;
                while(count>0)
                {
                    TreeNode* node = q.front();
                    q.pop();
                    out.push_back(node->val);
                    if (node->left)
                        q.push(node->left);
                    if (node->right)
                        q.push(node->right);
                    count--;
                }
                res.push_back(out);
            }
            return res;
        }
    
};
// C++ Solution 2:
class Solution {
public:
    vector<vector<int>> Print(TreeNode* root) {
        vector<vector<int>> res;
        if (root==NULL)
            return res;
        helper(root, res,0);
        return res;
    }

    void helper(TreeNode* root, vector<vector<int>> &res, int level)
    {
        if (root==NULL)
            return;
        if (res.size()==level)
            res.push_back(vector<int>());
        res[level].push_back(root->val);
        if (root->left)
            helper(root->left,res,level+1);
        if (root->right)
            helper(root->right,res,level+1);
    }
};
