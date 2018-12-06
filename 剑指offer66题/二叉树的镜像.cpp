/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:

    void Mirror(TreeNode *pRoot) {
        // 发现互为镜像的两个二叉树中序遍历出来的数组互为倒序
        // 法一：先中序遍历原树，再翻转，重新构建树(满二叉树才行)
        // 递归
        if(pRoot==NULL) return;
        TreeNode* tem = pRoot->left;
        pRoot->left = pRoot->right;
        pRoot->right = tem;
        Mirror(pRoot->left);
        Mirror(pRoot->right);


    }
};
