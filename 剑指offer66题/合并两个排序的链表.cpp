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
        //�½�һ������������
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
        //��pHead1ָ�����յ��б�
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
            while(p->next && p->next->val<=q->val)//pָ�������ƣ�ֱ��������һ�ڵ��Ҫ����q��ֵ�˻��ߵ����յ�
            {
                p=p->next;
            }
            if(p->next == NULL)
            {
                p->next = q;
                return pHead1;
            }
            ListNode* l = q;
           while(l->next  && l->next->val <= p->next->val)//lָ�������ƣ�ֱ���ҵ�������һ�ڵ��Ҫ����p->next��ֵ�ˣ����ߵ����յ�
           {
                l=l->next;
           }
           // if(l->next == NULL)//��ʱl��ֵ��С��p->next��ֵ��
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
