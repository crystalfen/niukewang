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
        //1. 借助数组，先将链表的元素从头到尾存到数组里，再根据数组创建链表
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
        //2. 从头开始，逐渐将箭头翻转，注意在箭头翻转前，先记住下一个结点
        if(pHead == NULL || pHead->next == NULL) return pHead;
        ListNode *pre = NULL; // 当前指针的前一指针
        ListNode *pNode = pHead; //当前指针
        while(pNode)
        {
            ListNode *pNext = pNode->next;
            pNode->next = pre;
            pre=pNode;
            if(pNext==NULL) return pre;
            pNode = pNext;
        }
        return pre; //程序的鲁棒性，maybe.
    }
};
