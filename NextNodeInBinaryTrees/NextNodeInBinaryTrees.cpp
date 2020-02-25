class Solution {
public:
    TreeLinkNode* GetNext(TreeLinkNode* Node)
    {
        if (Node== NULL)
            return NULL;
        TreeLinkNode* res = NULL;
        // 当前结点有右子树，那么它的下一个结点就是它的右子树中最左子结点
        if (Node->right != NULL)
        {
            TreeLinkNode* pRight = Node->right;
            while(pRight->left!=NULL)
            {
                pRight = pRight->left;
            }
            res = pRight;
        }
        // 当前结点无右子树，则需要找到一个是它父结点的左子树结点的结点
        else if (Node->next!=NULL)
        {
            // 当前结点
            TreeLinkNode* pCur = Node;
            // 父节点
            TreeLinkNode* pNext = Node->next;
            while( pNext != NULL && pNext->right == pCur)
            {
                pCur = pNext;
                pNext = pNext->next;
            }
            res = pNext;
        }
        return res;
    }
};
