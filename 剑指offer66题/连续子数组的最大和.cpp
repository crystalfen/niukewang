//������Ŀ������Ļش�����ø���ǰ��ĺͼ��ϸø��������Ǵ���0�����������Աߵ�����ȥ�ֲ�����
//��������ø���ǰ��ĺͼ��ϸø���С��0���������´��Աߵ�������ʼ�㡣
class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
    //��������������һ����¼���յ����ֵ��һ�����嵱ǰ���ֵ������ǰ���ֵ<0ʱ����0���¿�ʼ
        int Max = array[0];
        int curMax = array[0];
        //if(array.size()==1) return Max;
        for(int i = 1; i < array.size(); i++)
        {
           if(curMax<0) curMax = array[i];
           else
           {
               curMax += array[i];
           }
           Max = Max< curMax ? curMax : Max;
        }
        return Max;
    }
};
