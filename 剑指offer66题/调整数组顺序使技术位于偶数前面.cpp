class Solution {
public:
    void reOrderArray(vector<int> &array) {
        // 1. ��򵥵ķ��������½�������ֱ���������ż������ƴ��
        /*vector<int> odd;
        vector<int> even;
        for(int i = 0 ; i < array.size(); i++)
        {
            if(array[i] % 2 == 0)
                even.push_back(array[i]);
            else
                odd.push_back(array[i]);
        }
        for(int j = 0; j<even.size(); j++)
            odd.push_back(even[j]);
        for(int i = 0; i< array.size(); i++)
            array[i] = odd[i];
        return;*/

        //2. ��ǰ������ң����������䣬��ż�����������ң��ҵ��������Ѹ������嵽ǰ�档
        for(int i = 0; i< array.size(); i++)
        {
            if(array[i] % 2 == 0)
            {
                int j = i + 1;
                while(j<array.size() && array[j] % 2 == 0)
                {
                    j++;
                }
                if(j==array.size()) return;
                int val = array[j];
                for(int k = j; k > i; k--)
                    array[k] = array[k-1];
                array[i] = val;
            }

        }
    }
};
