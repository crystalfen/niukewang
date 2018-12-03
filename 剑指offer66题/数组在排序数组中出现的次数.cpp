class Solution {
public:
    int GetNumberOfK(vector<int> data ,int k) {
        //��û��˵�������ǽ���
        //�ȴ����ң��ҵ�һ������k��ֵ���������ҵ�������k��ֵ
        int left = 0;
        while(left < data.size() && data[left] != k)
        {
            left++;
        }
        if(left==data.size()) return 0; //û�ҵ�
        int right = left;//��һ������k��ֵ���±�
        while(right < data.size() && data[right] == k)
        {
            right++;
        }
        return right-left;

    }
};
