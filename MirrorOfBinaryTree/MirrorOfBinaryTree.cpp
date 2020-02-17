/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
    void Mirror(TreeNode *root) {
        if (root ==NULL)
            return;
        //交换根节点的左右结点
        TreeNode* temp = root->left;
        root->left = root->right;
        root->right =temp;
        
        //递归左子树
        if (root->left)
            Mirror(root->left);
        
        //递归右子树
        if (root->right)
            Mirror(root->right);
    }
};
