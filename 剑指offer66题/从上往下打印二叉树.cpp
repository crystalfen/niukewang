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
    vector<int> PrintFromTopToBottom(TreeNode* root) {
        //定义一个队列
        queue<TreeNode*> q;
        vector<int> res;
        if(root==NULL) return res;
        q.push(root);
        while(!q.empty())
        {
            TreeNode* tem = q.front();
            q.pop();
            res.push_back(tem->val);
            if(tem->left) q.push(tem->left);
            if(tem->right) q.push(tem->right);
        }
        return res;
    }
};
