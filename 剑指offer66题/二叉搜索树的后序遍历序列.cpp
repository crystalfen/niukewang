class Solution
{
public:
    bool VerifySquenceOfBST(vector<int> sequence)
    {
        //二叉搜索树的特点：左子树都比根节点小，右子树的值都比根节点的值大；中序遍历就是有序的

        /*BST的后序序列的合法序列是，对于一个序列S，最后一个元素是x（也就是根），
        如果去掉最后一个元素的序列为T，
        那么T满足：T可以分成两段，前一段（左子树）小于x，后一段（右子树）大于x，
        且这两段（子树）都是合法的后序序列。*/
        int len = sequence.size();
        if(len<1) return false;
        int l = 0, r = len - 1;
        bool res = VerifySquenceOFBST(sequence, l, r);
        return res;
    }

    bool VerifySquenceOFBST(vector<int> a, int l, int r)
    {
        while(l<r)
        {
            // 以根结点为参考，将原数组一分为二
            int i = r;
            while(i>l && a[i-1]> a[r]) i--;
            for(int j = l; j < i; j++)
            {
                if(a[j]>a[r])
                    return false;
            }
            return VerifySquenceOFBST(a,l,i-1) && VerifySquenceOFBST(a,i,r-1);

        }
        return true;
    }
};
