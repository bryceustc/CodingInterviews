/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
    ListNode* Merge(ListNode* l1, ListNode* l2)
    {
        ListNode* dummyhead = new ListNode(-1);
        ListNode* l3 = dummyhead;
        if (l1==NULL) return l2;
        if (l2==NULL) return l1;
        if (l1==NULL && l2==NULL) return NULL;
        while(l1 && l2)
        {
            if (l1->val<=l2->val)
            {
                l3->next = l1;
                l1 = l1->next;
            }
            else
            {
                l3->next = l2;
                l2 = l2->next;
            }
            l3 = l3->next;
        }
        if (l1==NULL) l3->next = l2;
        if (l2==NULL) l3->next = l1;
        return dummyhead->next;
    }
};

// Solution 2:
/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
    ListNode* Merge(ListNode* l1, ListNode* l2)
    {
        if (l1==NULL) return l2;
        if (l2==NULL) return l1;
        if (l1==NULL && l2==NULL) return NULL;
        if (l1->val <= l2->val)
        {
            l1->next = Merge(l1->next,l2);
            return l1;
        }
        else
        {
            l2->next = Merge(l1,l2->next);
            return l2;
        }
    }
};
