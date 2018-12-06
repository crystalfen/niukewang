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
分析二叉树的下一个节点，一共有以下情况：
  1.二叉树为空，则返回空；
  2.节点右孩子存在，则设置一个指针从该节点的右孩子出发，一直沿着指向左子结点的指针找到的叶子节点即为下一个节点；

  3.节点不是根节点。如果该节点是其父节点的左孩子，则返回父节点；否则继续向上遍历其父节点的父节点，重复之前的判断，返回结果。代码如下：
*/
class Solution {
public:
    // TreeLinkNode* pre; //pre记录刚刚访问过的结点
    TreeLinkNode* GetNext(TreeLinkNode* pNode)
    {
     if(pNode==NULL) return NULL;
     //一个结点的右孩子存在,比较好找到下一个结点
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
     while(p->next)//p 不是根节点
         // 如果p的右节点是null，就看p的父节点。找到是有左孩子的父n节点，返回
     {
         if(p->next->left==p)
             return p->next;
         p = p->next;
     }
     return NULL;
    }
};
