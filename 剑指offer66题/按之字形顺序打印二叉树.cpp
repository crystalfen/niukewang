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
    vector<vector<int> > Print(TreeNode* pRoot) {
        // 法一：借助两个堆栈
        stack<TreeNode*> sta1;
        stack<TreeNode*> sta2;
        vector<vector<int>> res;
        if(pRoot==NULL) return res;
        sta1.push(pRoot);
        while(!sta1.empty() || !sta2.empty())
        {
            vector<int> arr;
            while(!sta1.empty())
            {
                TreeNode* tem = sta1.top();
                arr.push_back(tem->val);
                sta1.pop();
                if(tem->left) sta2.push(tem->left);
                if(tem->right) sta2.push(tem->right);
            }
            res.push_back(arr);
            arr.clear();
            if(sta2.empty()) return res;
            while(!sta2.empty())
            {
                TreeNode* tem = sta2.top();
                arr.push_back(tem->val);
                sta2.pop();
                if(tem->right) sta1.push(tem->right);
                if(tem->left)  sta1.push(tem->left);
            }
            res.push_back(arr);
        }
        return res;
    }
};
