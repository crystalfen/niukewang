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
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k)
    {
        //  1. ��ͳ��������ĳ���len,�ٴ�ǰ�����ҵ���len-k+1������1��ʼ��ͷ���Ϊ1��
        /* ListNode* p = pListHead;
           int len = 0;
           while(p)
           {
               len++;
               p=p->next;
           }
           p = pListHead;
           int i = 0;
           //if(len-k < 0) return NULL; //�����ж�Ϊʲô�к�û�ж���
           while(i<len && i<len-k)//k�����Ǹ�����������
           {
               p = p->next;
               i++;
           }
           return p;*/

        // 2. ��������ָ�룬һ������һ������k�������������ߵ�ָ�뵽��NULLʱ�����ߵ�ָ�����������Ҫ��
        //��������㷨һ��Ҫ�Ȱ�����������Ǻã�1��������2.kΪ������3.������С��k
        if(pListHead==NULL || k<1)
            return NULL;
        ListNode* p = pListHead;
        ListNode* q = p;
        while(p && k > 0) //���P��NULLָ���˺�k=0�˶�����ѭ��
        {
            k--;
            p=p->next;
        }
        //�������Ϊp��NULL�����ģ�����k>len,ֱ�ӷ���Null�ɡ�����p,q�Ⱥ��ƣ�ֱ��pΪ�գ��ŷ���q
        if(!p && k > 0) return NULL;
        while(p)
        {
            p=p->next;
            q=q->next;
        }
        return q;
    }
};
