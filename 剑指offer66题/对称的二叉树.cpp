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
    void firstTravel(TreeNode* p1, vector<int> &res1)
    {
        if(p1==NULL) return;
        firstTravel(p1->left, res1);
        res1.push_back(p1->val);
        firstTravel(p1->right, res1);
    }
    void lastTravel(TreeNode* p2, vector<int> &res2)
    {
        if(p2==NULL) return;
        lastTravel(p2->right, res2);
        res2.push_back(p2->val);
        lastTravel(p2->left, res2);
    }
    bool isSymmetrical(TreeNode* pRoot)
    {
        // ����һ���������������ұ��������������һ�������ǶԳƵ�
        vector<int> res1;
        vector<int> res2;
        TreeNode* p1 = pRoot;
        TreeNode* p2 = pRoot;
        firstTravel(p1, res1);
        lastTravel(p2, res2);
        for(int i = 0; i< res1.size(); i++)
        {
            if(res1[i]!=res2[i])
                return false;
        }
        return true;
    }

};

/*
�𰸴���:���ύ�ĳ���û��ͨ�����еĲ�������
caseͨ����Ϊ90.00%

��������:
{5,5,5,5,#,#,5,5,#,5}

��Ӧ���Ӧ��Ϊ:

false

������Ϊ:

true
*/


���ӣ�https://www.nowcoder.com/questionTerminal/ff05d44dfdb04e1d83bdbdab320efbcb
��Դ��ţ����

/*˼·�����ȸ��ڵ��Լ���������������������������������������������ͬ*
 ��������������������������������ͬ���ɣ����õݹ�*
 �ǵݹ�Ҳ�ɣ�����ջ����д�ȡ�����������ڵ�*/
public class Solution
{
    boolean isSymmetrical(TreeNode pRoot)
    {
        if(pRoot == null)
        {
            return true;
        }
        return comRoot(pRoot.left, pRoot.right);
    }
    private boolean comRoot(TreeNode left, TreeNode right)
    {

        //if(left== NULL && right==NULL) return true;
        //if(left==NULL || right==NULL) return false;
        if(left == null) return right==null;
        if(right == null) return false;
        if(left.val != right.val) return false;
        return comRoot(left.right, right.left) && comRoot(left.left, right.right);

    }
};
