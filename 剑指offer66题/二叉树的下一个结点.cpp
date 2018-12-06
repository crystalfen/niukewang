/*
struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {

    }
};
*/

/*
��������������һ���ڵ㣬һ�������������
  1.������Ϊ�գ��򷵻ؿգ�
  2.�ڵ��Һ��Ӵ��ڣ�������һ��ָ��Ӹýڵ���Һ��ӳ�����һֱ����ָ�����ӽ���ָ���ҵ���Ҷ�ӽڵ㼴Ϊ��һ���ڵ㣻

  3.�ڵ㲻�Ǹ��ڵ㡣����ýڵ����丸�ڵ�����ӣ��򷵻ظ��ڵ㣻����������ϱ����丸�ڵ�ĸ��ڵ㣬�ظ�֮ǰ���жϣ����ؽ�����������£�
*/
class Solution {
public:
    // TreeLinkNode* pre; //pre��¼�ոշ��ʹ��Ľ��
    TreeLinkNode* GetNext(TreeLinkNode* pNode)
    {
     if(pNode==NULL) return NULL;
     //һ�������Һ��Ӵ���,�ȽϺ��ҵ���һ�����
     TreeLinkNode* p = pNode;
     if(p->right)
     {
         p = p->right;
         while(p->left)
         {
             p = p->left;
         }
         return p;
     }
     while(p->next)//p ���Ǹ��ڵ�
         // ���p���ҽڵ���null���Ϳ�p�ĸ��ڵ㡣�ҵ��������ӵĸ�n�ڵ㣬����
     {
         if(p->next->left==p)
             return p->next;
         p = p->next;
     }
     return NULL;
    }
};
