// C++ Solution 1:
class Solution {
public:
    vector<int> PrintFromTopToBottom(TreeNode* root) {
        vector<int> res;
        if (root==NULL)
            return res;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode* temp = q.front();
            q.pop();
            res.push_back(temp->val);
            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
        }
        return res;
    }
};
// C++ Solution 2:
class Solution {
public:
    vector<int> PrintFromTopToBottom(TreeNode* root) {
        vector<int> res;
        if (root==NULL)
            return res;
        deque<TreeNode*> q;
        q.push_back(root);
        while(q.size())
        {
            TreeNode* temp = q.front();
            q.pop_front();
            res.push_back(temp->val);
            if (temp->left)
                q.push_back(temp->left);
            if (temp->right)
                q.push_back(temp->right);
        }
        return res;
    }
};
