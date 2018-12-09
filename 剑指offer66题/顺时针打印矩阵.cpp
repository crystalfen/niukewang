class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
    int start = 0;
    int rend = matrix.size();
    int lend = matrix[0].size();
    vector<int> res;
    while(start<rend && start<lend)
    {
        int i = start;
        int j = start;
        for(; j < lend; j++)
        {
            res.push_back(matrix[start][j]);
        }
        // ��ʱ j = lend;����j--;
        j--;
        i++;
        for(; i < rend; i++)
        {
            res.push_back(matrix[i][j]);//���һ��Ԫ������push������
        }
        // ��ʱ i = rend;����i--��
        i--;
        j--;
        if(i==start)
            break;
        for(;j>=start;j--)
        {
            res.push_back(matrix[i][j]);
        }
        j++;
        i--;
        if(j==lend-1)
            break;
        for(;i>start;i--)
        {
            res.push_back(matrix[i][j]);
        }
        start++;
        lend--;
        rend--;


    }
        return res;
    }
};


/*����˼·��˳ʱ���ӡ���ǰ�Ȧ��ѭ����ӡ��һȦ�������л������У�
�ڴ�ӡ��ʱ������ĳһȦ��ֻ����һ�У�
Ҫ�жϴ������Ҵ�ӡ�ʹ��������ӡ��ʱ���Ƿ������ظ���ӡ��
ͬ��ֻ����һ��ʱ��Ҫ�жϴ������´�ӡ�ʹ������ϴ�ӡ��ʱ���Ƿ������ظ���ӡ�����*/
class Solution
{
public:
    vector<int> printMatrix(vector<vector<int> > matrix)
    {
        vector<int>res;
        res.clear();
        int row=matrix.size();//����
        int collor=matrix[0].size();//����
        //�����ӡ��Ȧ��
        int circle=((row<collor?row:collor)-1)/2+1;
        //Ȧ��
        for(int i=0; i<circle; i++)
        {
            //�������Ҵ�ӡ
            for(int j=i; j<collor-i; j++)
                res.push_back(matrix[i][j]);
            //�������µ�ÿһ������
            for(int k=i+1; k<row-i; k++)
                res.push_back(matrix[k][collor-1-i]);
            //�ж��Ƿ���ظ���ӡ(���������ÿ������)
            for(int m=collor-i-2; (m>=i)&&(row-i-1!=i); m--)
                res.push_back(matrix[row-i-1][m]);
            //�ж��Ƿ���ظ���ӡ(�������ϵ�ÿһ������)
            for(int n=row-i-2; (n>i)&&(collor-i-1!=i); n--)
                res.push_back(matrix[n][i]);
        }
        return res;
    }
};
