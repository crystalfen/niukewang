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
        // 若果一个二叉树是左中右遍历和右中左遍历一样，即是对称的
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
答案错误:您提交的程序没有通过所有的测试用例
case通过率为90.00%

测试用例:
{5,5,5,5,#,#,5,5,#,5}

对应输出应该为:

false

你的输出为:

true
*/


链接：https://www.nowcoder.com/questionTerminal/ff05d44dfdb04e1d83bdbdab320efbcb
来源：牛客网

/*思路：首先根节点以及其左右子树，左子树的左子树和右子树的右子树相同*
 左子树的右子树和右子树的左子树相同即可，采用递归*
 非递归也可，采用栈或队列存取各级子树根节点*/
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
