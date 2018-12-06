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
        //��������
        vector<vector<int>> res;
        queue<TreeNode*> q;
        vector<int> arr;
        int n = 0;
        int m = 0; //m��¼ĳ��Ľ����
        if(pRoot==NULL) return res;
        q.push(pRoot);//ͷ������
        n = 1;
        while(n>0)
        { // ĳһ��Ľ�����γ��У��ڳ���ǰһ���ȰѸý������Һ��ӣ�������ڣ���ӡ�
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
            if(n==0) //��n=0ʱ��˵��ĳһ���ѱ�������������׼����һ�������
            {
                res.push_back(arr);
                arr.clear(); // ���arr����
                n = m;
                m = 0; //��ս����Ŀm;
            }
        }
        return res;
    }
};


// �����ǿ������������д�Ĵ��룬˼·���ҵ���һ�����������Ŀ�����������㣬ѧϰ�ˡ�
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
