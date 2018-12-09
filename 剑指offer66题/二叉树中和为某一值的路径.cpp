/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution
{
public:
    void FindPath(TreeNode* root, bool &flag, int &expectNumber, vector<int> &arr,vector<vector<int>>&res)
    {
        if(root==NULL && expectNumber==0 && !flag)
        {
            res.push_back(arr);
            flag = true;
            return;
        }
        if(root==NULL)
        {
            return;
        }
        //vector<int> arr;
        arr.push_back(root->val);
        expectNumber -= root->val;
        FindPath(root->left,flag,expectNumber,arr,res);
        if(root->left!=NULL)
        {
            arr.pop_back();
            flag = false;
            expectNumber += root->left->val;
        }
        FindPath(root->right,flag,expectNumber,arr,res);
        if(root->right!=NULL)
        {
            arr.pop_back();
            flag = false;
            expectNumber += root->right->val;
        }

    }

    vector<vector<int>> FindPath(TreeNode* root,int expectNumber)
    {
        vector<vector<int>> res;
        vector<int> arr;
        bool flag = false; // 避免路径重复。（叶子节点的左右子树都为空，路径会重复）
        if(root==NULL && expectNumber==0) return res;
        FindPath(root, flag, expectNumber, arr, res);
        return res;

    }

};



class Solution
{
    vector<vector<int> >allRes;
    vector<int> tmp;
    void dfsFind(TreeNode * node, int left)
    {
        tmp.push_back(node->val);
        if(left-node->val == 0 && !node->left && !node->right)
            allRes.push_back(tmp);
        else
        {
            if(node->left) dfsFind(node->left, left-node->val);
            if(node->right) dfsFind(node->right, left-node->val);
        }
        tmp.pop_back();
    }
public:
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber)
    {
        if(root) dfsFind(root, expectNumber);
        return allRes;
    }
};
