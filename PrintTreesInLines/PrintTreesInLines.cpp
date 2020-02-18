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
