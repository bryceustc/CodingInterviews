class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
        if (root == NULL)
            return res;
        vector<int> path;
        dfs(root,path,expectNumber);
        return res;
    }
    void dfs(TreeNode* root, vector<int>& path, int expectNumber)
    {
        if (root == NULL)
            return;
        path.push_back(root->val);
        // 如果是叶节点，并且路径上的节点值的和为输入的值，就像结果中添加这一path
        bool isLeaf = (root->left == NULL && root->right == NULL);
        if (expectNumber == root->val && isLeaf)
        {
            res.push_back(path);
        }
        // 不是叶节点就遍历他的子节点
        dfs(root->left, path, expectNumber-root->val);
        dfs(root->right, path, expectNumber-root->val);
        // 到这一步说明不满足要求，要返回父节点，需要删除路径上的当前节点
        path.pop_back();
    }
};
