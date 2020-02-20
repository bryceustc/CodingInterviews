/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/
class Solution {
public:
    vector<vector<int> > Print(TreeNode* root) {
        vector<vector<int>> res;
        if (root==NULL)
            return res;
        deque<TreeNode*> q;
        q.push_back(root);
        bool zigzag = true; // 从右打印为True，从左打印为False
        while (!q.empty())
        {
            int count = q.size();
            vector<int> out;
            TreeNode* node;
            while (count>0)
            {
                if (zigzag) //前取后放：从左向右，所以从前边取，后边放入
                {
                    node = q.front();
                    q.pop_front();
                    if (node->left)
                        q.push_back(node->left);
                    if (node->right)
                        q.push_back(node->right);
                } 
                else  // 后取前放：从右向左，从后边取，前边放入
                {
                    node = q.back();
                    q.pop_back();
                    if (node->right)
                        q.push_front(node->right);
                    if (node->left)
                        q.push_front(node->left);
                }
                out.push_back(node->val);
                count--;
            }
            res.push_back(out);
            zigzag = !zigzag;
        }
        return res;
    }
};
