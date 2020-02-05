// Solution 1:
/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/
class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        vector<int> res;
        ListNode* p = head;
        if (p==NULL) return res;
        while(p!=NULL)
        {
            res.push_back(p->val);
            p = p->next;
        }
        // 逆序方法1：利用c++自带的库函数reverse
        reverse(res.begin(),res.end());
        
        // 逆序方法2：利用for循环
        // vector<int> temp;
        // for (int i=res.size()-1;i>=0;i--)
        //{
        //    temp.push_back(res[i]);
        //}
        // return temp;
        
        // 逆序方法3：vector迭代器
        //for (vector<int>::reverse_iterator it = res.rbegin(); it!= res.rend(); it++)
        {
        //    temp.push_back(*it);
        //}
        // return temp;
        
        // 逆序方法4：栈
        //std::stack<ListNode*> nodes;
        //ListNode *pNode = head;
        //while(pNode!=NULL)
        //{
        //    nodes.push(pNode);
        //    pNode = pNode->next;
        //}
        //while(!nodes.empty())
        //{
        //    pNode = nodes.top();
        //    temp.push_back(pNode->val);
        //    nodes.pop();
        //}
        // return temp;
        return res;
    }
};

  // Solution 2:
  /**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/
class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        vector<int> res;
        if (head==NULL)
            return res;
        ListNode* prev = head;
        ListNode* cur = head->next;
        ListNode* temp = head->next->next;
        while(cur)
        {
            temp = cur->next;//temp作为中间节点，记录当前结点的下一个节点的位置
            cur->next = prev;//当前结点指向前一个节点
            prev = cur;//指针后移
            cur = temp;// 指针后移,处理下一个节点
        }
        head->next = NULL; //while结束后，将翻转后的最后一个节点（即翻转前的第一个结点head）的链域置为NULL
        while(prev)
        {
            res.push_back(prev->val);
            prev = prev->next;
        }
        return res;
    }
};
