/*
struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};
*/
class Solution {
public:
    RandomListNode* Clone(RandomListNode* head)
    {
        if (head==NULL) return NULL;
        RandomListNode* cur = head;
        //复制next 如原来是A->B->C 变成A->A'->B->B'->C->C'
        while(cur)
        {
            RandomListNode* temp = new RandomListNode(cur->label);
            temp->next = cur->next;
            cur->next = temp;
            cur = temp->next;
        }
        cur = head;
        //复制random cur是原来链表的结点 cur->next是复制cur的结点
        while(cur)
        {
            RandomListNode* temp = cur->next;
            if (cur->random)
            {
                temp->random = cur->random->next;
            }
            cur = temp->next;
        }
        // 拆分链表，将链表拆分为原链表和复制后的链表
        cur = head;
        RandomListNode* p = head->next;
        while(cur)
        {
            RandomListNode* temp = cur->next;
            cur->next = temp->next;
            if (temp->next!=NULL)
                temp->next = temp->next->next;
            cur = cur->next;
        }
        return p;
    }
};
