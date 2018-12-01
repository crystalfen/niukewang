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
        //���������ֻҪ��һ������ֵ�뵱ǰ�ڵ���ͬʱ����ɾ�������ظ��ڵ㡣
        //���ȣ���Ҫ��������������ͷ���Ԫ�ؾ��ظ��Ļ�����Ҫ�ƶ�ͷ���
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
                if(p==pHead) {pHead = q->next; pre = pHead;} // ����ӽ����ظ�ʱ��������������ͬ
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
