// Solution 1:
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
    ListNode* deleteDuplication(ListNode* head)
    {
        if (head == NULL || head->next == NULL)
            return head;
        ListNode* p = new ListNode(-1);
        p->next = head;
        ListNode* prev = p;
        ListNode* cur = head;
        while(cur && cur->next)
        {
            if (cur->val == cur->next->val)
            {
                while(cur->next && cur->val == cur->next->val)
                {
                    cur = cur->next;
                }
                prev->next = cur->next;
            }
            else
            {
                prev = cur;
            }
            cur = cur->next;
        }
        return p->next;
    }
};
// Solution 2:
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplication(ListNode* head) {
        if(head==NULL || head->next == NULL)
            return head;
        //如果是这种情况
        //      1 --> 1 --> 1 --> 2 --> 3
        //     head  next
        //1.则需要移动next直到出现与当前head.value不相等的情况（含null）
        //2.并且此时的head已经不能要了，因为已经head是重复的节点
        //--------------else-------------
        //      1 --> 2 --> 3
        //     head  next
        //3.如果没有出现1的情况，则递归返回的节点就作为head的子节点
        if (head->val == head->next->val)
        {
            // 1
            while(head->next && head->val == head->next->val)
            {
                head = head->next;
            }
            // 2
            head = deleteDuplicates(head->next);
        }
        else
        {
            // 3
            head->next = deleteDuplicates(head->next);
        }
        return head;
    }
};
