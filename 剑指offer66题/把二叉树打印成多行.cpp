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
class Solution
{
public:
    vector<vector<int> > Print(TreeNode* pRoot)
    {
        //借助队列
        vector<vector<int>> res;
        queue<TreeNode*> q;
        vector<int> arr;
        int n = 0;
        int m = 0; //m记录某层的结点数
        if(pRoot==NULL) return res;
        q.push(pRoot);//头结点入队
        n = 1;
        while(n>0)
        { // 某一层的结点依次出列，在出列前一刻先把该结点的左右孩子（如果存在）入队。
            TreeNode* tem = q.front();
            if(tem->left)
            {
                q.push(tem->left);
                m++;
            }
            if(tem->right)
            {
                q.push(tem->right);
                m++;
            }
            q.pop();
            arr.push_back(tem->val);
            n--;
            if(n==0) //当n=0时，说明某一层已遍历结束。重新准备下一层遍历。
            {
                res.push_back(arr);
                arr.clear(); // 清空arr数组
                n = m;
                m = 0; //清空结点数目m;
            }
        }
        return res;
    }
};


// 下面是看的讨论里别人写的代码，思路和我的是一样，但是他的看起来更整洁点，学习了。
class Solution {
public:
        vector<vector<int> > Print(TreeNode* pRoot) {
            vector<vector<int> > vec;
            if(pRoot == NULL) return vec;

            queue<TreeNode*> q;
            q.push(pRoot);

            while(!q.empty())
            {
                int lo = 0, hi = q.size();
                vector<int> c;
                while(lo++ < hi)
                {
                    TreeNode *t = q.front();
                    q.pop();
                    c.push_back(t->val);
                    if(t->left) q.push(t->left);
                    if(t->right) q.push(t->right);
                }
                vec.push_back(c);
            }
            return vec;
        }
};
