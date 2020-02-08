/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
*/
class Solution {
public:
    ListNode* EntryNodeOfLoop(ListNode* head)
    {
        if (head==NULL || head->next==NULL)
            return NULL;
        ListNode* p = head;
        ListNode* q = head;
        while(q && q->next)
        {
            p = p->next;//慢指针走一步
            q = q->next->next;//快指针走两步
            if (p==q)  // 找到环中相遇点,如果没找到就会跳出循环，因为会指向NULL
            {
                p = head; //将两个指针设置为一个在开头，一个在相遇点
                // 并同时同步移动，再次相遇时就是环的入口节点
                while(p!=q)
                {
                    p = p->next;
                    q = q->next;
                }
                if (p==q)
                    return p;
            }
        }
        return NULL;
    }
};
