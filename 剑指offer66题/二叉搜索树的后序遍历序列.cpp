class Solution
{
public:
    bool VerifySquenceOfBST(vector<int> sequence)
    {
        //�������������ص㣺���������ȸ��ڵ�С����������ֵ���ȸ��ڵ��ֵ������������������

        /*BST�ĺ������еĺϷ������ǣ�����һ������S�����һ��Ԫ����x��Ҳ���Ǹ�����
        ���ȥ�����һ��Ԫ�ص�����ΪT��
        ��ôT���㣺T���Էֳ����Σ�ǰһ�Σ���������С��x����һ�Σ�������������x��
        �������Σ����������ǺϷ��ĺ������С�*/
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
            // �Ը����Ϊ�ο�����ԭ����һ��Ϊ��
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
