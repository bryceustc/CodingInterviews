// C++ Solution 1:
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
    ListNode* FindFirstCommonNode( ListNode* l1, ListNode* l2) {
        if (l1==NULL || l2 == NULL) return NULL;
        ListNode* p = l1;
        ListNode* q = l2;
        while(p)
        {
            q = l2;
            while(q)
            {
                if (p->val==q->val)
                {
                    return p;
                }
                else
                {
                    q = q->next;
                }
            }
            p = p->next;
        }
        return NULL;
    }
};
// C++ Solution 2:
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
    ListNode* FindFirstCommonNode( ListNode* l1, ListNode* l2) {
        if (l1==NULL || l2 == NULL) return NULL;
        ListNode* p = l1;
        ListNode* q = l2;
        int n=0,m=0;
        // 计算l1链表的长度
        while (p)
        {
            n++;
            p = p->next;
        }
        // 计算l2链表的长度
        while(q)
        {
            m++;
            q = q->next;
        }
        // 如果链表长度不一样，计算两个链表长度的差值
        int k = 0;
        ListNode* temp_long = l1;
        ListNode* temp_short = l2;
        if (n>=m)
        {
            k = n-m;
        }
        else
        {
            k = m-n;
            temp_long = l2;
            temp_short = l1;
        }
        // 长的链表先移动差值k,剩余长度与短链表的长度一致
        for (int i=0;i<k;i++)
        {
            temp_long = temp_long->next;
        }
        // 然后同时移动，判断是否有公共节点
        while(temp_long && temp_short && temp_short!=temp_long)
        {
            temp_short = temp_short->next;
            temp_long = temp_long->next;
        }
        ListNode* res = temp_long;
        return res;
    }
};
