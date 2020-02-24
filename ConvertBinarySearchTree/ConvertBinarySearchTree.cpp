class Solution {
public:
    TreeNode* Convert(TreeNode* root)
    {
        if (root == NULL)
            return NULL;
	// 定义一个pre指针
        TreeNode* pre = NULL;
        helper(root, pre);
        TreeNode* res = root; 
	// 寻找到头结点
        while (res->left)
        {
            res = res->left;
        }
        return res;
    }
    void helper(TreeNode* cur, TreeNode* &pre)  // 中序遍历
    {
        if (cur == NULL)
            return;
        // 先递归遍历左子树
        helper(cur->left, pre);
        // 修改为双向链表
	//左指针
        cur->left = pre;
	 //右指针
        if(pre != NULL)
        {
            pre->right = cur;
        }
	 //更新双向链表尾结点
        pre = cur;
        // 再递归遍历右子树
        helper(cur->right, pre);
    }
};
