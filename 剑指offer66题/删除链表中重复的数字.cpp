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
    ListNode* deleteDuplication(ListNode* pHead)
    {
        //有序的链表。只要下一个结点的值与当前节点相同时，就删除所有重复节点。
        //首先，需要把特殊的情况，即头结点元素就重复的话，需要移动头结点
        ListNode* p = pHead;
        ListNode* pre = pHead;
        while(p!=NULL)
        {
            if(p->next!=NULL && p->next->val==p->val)
            {
               ListNode* q = p->next;
               while(q->next != NULL && q->next->val == q->val)
               {
                    q = q->next;
               }
                if(p==pHead) {pHead = q->next; pre = pHead;} // 如果从结点就重复时，操作会有所不同
                else{pre->next = q->next;}
                p = q->next;
            }
            else
            {
               pre = p;
               p = p->next;
            }
        }
        return pHead;
    }
};
