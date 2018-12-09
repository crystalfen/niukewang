/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
/*
class Solution {
public:
    int TreeDepth(TreeNode* pRoot)
    {
      //法一： 不用递归，借助队列
      int depth = 0;
      queue<TreeNode*>q;
      if(pRoot==NULL) return depth;
      q.push(pRoot);
      while(!q.empty())
      {
          int lo = 0, len = q.size();
          while(lo++<len)
          {
              TreeNode* tem = q.front();
              q.pop();
              if(tem->left) q.push(tem->left);
              if(tem->right) q.push(tem->right);
          }
          depth++;

      }
      return depth;

    }
};
*/
class Solution {
public:
    int TreeDepth(TreeNode* pRoot)
    {
      //法二： 使用递归法
        if(pRoot==NULL)
        {
            return 0;
        }
       return max(1+TreeDepth(pRoot->left), 1+TreeDepth(pRoot->right));
    }
};
