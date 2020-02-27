// Solution 1:
class Solution {
public:
    int TreeDepth(TreeNode* root)
    {
        if (root == NULL)
            return 0;
        int left = TreeDepth(root->left);
        int right = TreeDepth(root->right);
        return max(left, right) + 1;
    }
};
// Solution 2:
class Solution {
public:
    int TreeDepth(TreeNode* root)
    {
        int depth = 0;
        if (root == NULL)
            return depth;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            int count = q.size();
            while(count>0)
            {
                TreeNode* node = q.front();
                q.pop();
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
                count--;
            }
            depth++;
        }
        return depth;
    }
};
