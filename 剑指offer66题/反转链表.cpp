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
    ListNode* ReverseList(ListNode* pHead)
    {
        //1. �������飬�Ƚ������Ԫ�ش�ͷ��β�浽������ٸ������鴴������
        /*
        vector<int> arrayList;
        ListNode* p = pHead;
        while(p)
        {
            arrayList.push_back(p->val);
            p = p->next;
        }
        if(arrayList.size()<1) return NULL;
        pHead->val = arrayList[arrayList.size()-1];
        // if(arrayList.size()==1) return pHead;
        p = pHead;
        //ListNode* q = p;
        for(int i = arrayList.size()-2; i>= 0; i--)
        {
            ListNode* q = new ListNode(arrayList[i]);
           // q->val = arrayList[i];
           // q->next = NULL;
            p->next = q;
            p = q;

        }
        return pHead;
        */
        //2. ��ͷ��ʼ���𽥽���ͷ��ת��ע���ڼ�ͷ��תǰ���ȼ�ס��һ�����
        if(pHead == NULL || pHead->next == NULL) return pHead;
        ListNode *pre = NULL; // ��ǰָ���ǰһָ��
        ListNode *pNode = pHead; //��ǰָ��
        while(pNode)
        {
            ListNode *pNext = pNode->next;
            pNode->next = pre;
            pre=pNode;
            if(pNext==NULL) return pre;
            pNode = pNext;
        }
        return pre; //�����³���ԣ�maybe.
    }
};
