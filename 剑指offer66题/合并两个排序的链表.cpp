/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution
{
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        //新建一个链表，。。。
        ListNode* pHead = new ListNode(0);
        ListNode* p = pHead;
        while(pHead1 && pHead2)
        {
            if(pHead1->val <= pHead2->val)
            {
                p->next = pHead1;
                pHead1 = pHead1->next;
            }
            else
            {
                p->next = pHead2;
                pHead2 = pHead2->next;
            }
            p = p->next;
        }
        p->next = pHead1 ? pHead1 : pHead2;
        return pHead->next;
        /*
        //让pHead1指向最终的列表
        if(pHead1 == NULL) return pHead2;
        if(pHead2 == NULL) return pHead1;
        if(pHead1->val > pHead2->val)
        {
            ListNode* p = pHead1;
            pHead1 = pHead2;
            pHead2 = p;
        }
        ListNode* p = pHead1;
        ListNode* q = pHead2;
        while(p && q)
        {
            while(p->next && p->next->val<=q->val)//p指针向右移，直到它的下一节点就要大于q的值了或者到达终点
            {
                p=p->next;
            }
            if(p->next == NULL)
            {
                p->next = q;
                return pHead1;
            }
            ListNode* l = q;
           while(l->next  && l->next->val <= p->next->val)//l指针向右移，直到找到它的下一节点就要大于p->next的值了，或者到达终点
           {
                l=l->next;
           }
           // if(l->next == NULL)//此时l的值是小于p->next的值的
           //{
           //     l->next = p->next;
           //     p->next = q;
           //     return pHead1;
           // }
            ListNode* q2 = l->next;
            l->next = p->next;
            p->next = q;
            q = q2;
            p = l->next;
        }
         //if(p) return pHead1;
         return pHead1; */
    }
};
