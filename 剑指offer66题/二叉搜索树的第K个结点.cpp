/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/
class Solution {
public:
    int count = 0;
    TreeNode* KthNode(TreeNode* pRoot, int k)
    {
        // 二叉搜索树按中序遍历就是已经排好序的。升序
        if(pRoot)
        {TreeNode *tem = KthNode(pRoot->left, k);
        if(tem) return tem;
        //k--;
         count++;
        if(count==k) return pRoot;
        tem = KthNode(pRoot->right, k);
        if(tem) return tem;
        }
        return NULL;
    }
};
