/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/
class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        ListNode* p = head;
        vector<int> arrayList;
        while(p)
        {
            arrayList.push_back(p->val);
            p = p->next;
        }
        //�ȴ�ͷ��β��ӡ��������ת��
        reverse(arrayList.begin(), arrayList.end());
        return arrayList;

    }
};
