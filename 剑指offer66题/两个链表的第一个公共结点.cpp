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
        //双重循环。还有种方法是计算两个链表的长度，长的先走几步（长度的差值），然后再一起遍历，找到相等的。此法在这里就不写了
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
