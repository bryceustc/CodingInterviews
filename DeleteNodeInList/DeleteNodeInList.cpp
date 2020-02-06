void DeleteNode(ListNode* head,ListNode* ToBeDeleted)
{
    if (head == NULL ||ToBeDeleted == NULL)
        return;
    // 删除节点不是尾节点
    if (ToBeDeleted->next != NULL)
    {
        ListNode* p = ToBeDeleted->next;
        ToBeDeleted->val = p->val;
        ToBeDeleted->next = p->next;
        delete p;
        p = NULL;
    }
    // 链表只有一个节点，既是头结点，又是尾节点
    if (head == ToBeDeleted)
    {
        delete ToBeDeleted;
        ToBeDeleted = NULL;
        head = NULL;
    }
    // 链表中有多个节点，删除尾节点
    else
    {
        ListNode* p = head;
        while(p->next)
        {
            if (p->next != ToBeDeleted)
            {
                p = p->next;
            }
            p->next = NULL;
            delete ToBeDeleted;
            ToBeDeleted = NULL;
        }
    }
}
