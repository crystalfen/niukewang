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
        //  1. 先统计先链表的长度len,再从前往后找到第len-k+1个（从1开始，头结点为1）
        /* ListNode* p = pListHead;
           int len = 0;
           while(p)
           {
               len++;
               p=p->next;
           }
           p = pListHead;
           int i = 0;
           //if(len-k < 0) return NULL; //这条判断为什么有何没有都行
           while(i<len && i<len-k)//k可能是负数。。。。
           {
               p = p->next;
               i++;
           }
           return p;*/

        // 2. 定义两个指针，一个比另一个先走k步，这样当先走的指针到达NULL时，后走的指针就是我们需要的
        //但是这个算法一定要先把特殊情况考虑好，1，空链表，2.k为负数。3.链表长度小于k
        if(pListHead==NULL || k<1)
            return NULL;
        ListNode* p = pListHead;
        ListNode* q = p;
        while(p && k > 0) //如果P是NULL指针了和k=0了都结束循环
        {
            k--;
            p=p->next;
        }
        //如果是因为p是NULL结束的，代表k>len,直接返回Null吧。否则，p,q先后移，直到p为空，才返回q
        if(!p && k > 0) return NULL;
        while(p)
        {
            p=p->next;
            q=q->next;
        }
        return q;
    }
};
