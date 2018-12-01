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
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
        //˫��ѭ���������ַ����Ǽ�����������ĳ��ȣ��������߼��������ȵĲ�ֵ����Ȼ����һ��������ҵ���ȵġ��˷�������Ͳ�д��
        ListNode* p = pHead1;
        while(p)
        {
           ListNode* q = pHead2;
            while(q)
            {
                if(p==q) return p;
                q=q->next;
            }
            p=p->next;
        }
        return NULL;
    }
};
