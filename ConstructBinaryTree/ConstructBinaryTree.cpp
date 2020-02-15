/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        if (pre.empty() || vin.empty())
            return NULL;
        int n = pre.size();
        // 前序遍历的第一个数字是根节点的值
        int root = pre[0];
        // 创建根节点
        TreeNode* t = new TreeNode(root);
        // 如果长度为1，直接返回根节点
        if (n==1) return t;
        // 找到root所在的位置，确定好前序和中序中左子树和右子树序列的范围
        int root_index = 0;
        for (int i=0;i<n;i++)
        {
            if (vin[i]==root)
            {
                root_index = i;
                break;
            }
        }
        // 左子树
        vector<int> left_pre,left_in, right_pre, right_in;
        for (int i=0;i<root_index;i++)
        {
            left_pre.push_back(pre[i+1]); // +1 是因为前序遍历的第一个节点是根节点
            left_in.push_back(vin[i]);
        }
        // 右子树
        for (int i=root_index+1;i<n;i++)
        {
            right_pre.push_back(pre[i]);
            right_in.push_back(vin[i]);
        }
        t->left = reConstructBinaryTree(left_pre,left_in);
        t->right = reConstructBinaryTree(right_pre,right_in);
        return t;
    }
};
