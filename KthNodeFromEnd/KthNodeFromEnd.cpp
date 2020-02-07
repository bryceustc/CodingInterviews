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
    ListNode* FindKthToTail(ListNode* head, unsigned int k) {
        if (head==NULL || k<=0)
            return NULL;
        int n = 0;
        for (ListNode* temp = head;temp!=NULL;temp=temp->next)
        {
            n++;
        }
        if (n<k) return NULL;
        ListNode* p = head;
        for (int i=0;i<n-k;i++)
        {
            p = p->next;
        }
        return p;
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
    ListNode* FindKthToTail(ListNode* head, unsigned int k) {
        if (head==NULL || k<=0)
            return NULL;
        ListNode* p = head;
        ListNode* q = head;
        // 从第1一个节点开始计数，所以走k-1步到达k节点，注意判断k是否超过链表总长度
        for (int i=0;i<k-1;i++)
        {
            if (q->next!=NULL)
                q = q->next;
            else
                return NULL;
        }
        while(q->next!=NULL)
        {
            p = p->next;
            q = q->next;
        }
        return p;
    }
};
