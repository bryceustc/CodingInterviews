class Solution {
public:
    bool IsBalanced_Solution(TreeNode* root) {
        if (root == NULL)
            return true;
        int left = TreeDepth(root->left);
        int right = TreeDepth(root->right);
        if (left-right > 1 || left-right<-1)
            return false;
        return IsBalanced_Solution(root->left) && IsBalanced_Solution(root->right);
    }
    int TreeDepth(TreeNode* root)
    {
        if (root == NULL)
            return 0;
        int left = TreeDepth(root->left);
        int right = TreeDepth(root->right);
        return max(left, right) + 1;
    }
};


class Solution {
public:
    bool IsBalanced_Solution(TreeNode* root) {
        if (root == NULL)
            return true;
        int depth = 0;
        return helper(root, depth);
    }
    bool helper(TreeNode* root, int &depth)
    {
        if (root == NULL)
        {
            depth = 0;
            return true;
        }
        int left, right;
        if (helper(root->left, left) && helper(root->right, right) && abs(left-right)<=1)
        {
            depth = max(left,right)+1;
            return true;
        }
        return false;
    }
};
